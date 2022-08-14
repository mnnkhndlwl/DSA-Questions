class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        // Idea: Construct a graph with each word in the wordList plus beginWord, endWord as a node.
        // The edges go between nodes that are a single transformation away.
        // Then run Dijkstra (would be better to run BFS, really, but this works too) with every existing edge having weight 1

        // To improve performance, we transfer the words into a vector. This way, we have linear access (improves cache performance),
        // and we won't be computing hashes of the strings all the time -- we use their indices instead.
        // Each node in the graph is identified by the index that its word carries in this vector.
        // We put beginWord and endWord into this list at first and last positions respectively, so we know where they are.
        std::vector<std::string> words;
        words.reserve( wordList.size() + 2 );
        words.push_back( beginWord );
        for( const auto& word : wordList )
            words.push_back( word );
        words.push_back( endWord );
        
        // We represent the graph using an adjacency vector
        std::vector<std::vector<int>> neighbors( words.size(), std::vector<int>() ); // neighbors of each node in the graph
        
        // This lambda tells us in O( string length ) as to whether the string b is reachable (i.e. single transformation away) from string a or not.
        auto editNeighbor = []( const std::string &a, const std::string &b ) {
            bool foundOneEdit = false;
            assert( a.length() == b.length() );
            for( int i = 0; i < a.length(); ++i )
                if( a[i] != b[i] )
                    if( !foundOneEdit )
                        foundOneEdit = true;
                    else
                        return false; // found more than one edit
            return foundOneEdit;
        };
        
        // We now make our graph's connections by checking for the transformation. Takes O(N^2 * string length)
        for( int i = 0; i < words.size(); ++i )
            for( int j = 0; j < i; ++j ) {
                if( editNeighbor( words[i], words[j] ) ) {
                    neighbors[ i ].push_back( j );
                    neighbors[ j ].push_back( i );
                }
            }
        
        // Here is a distance vector. The index identifies the vertex, and the value is the distance. We initialize to maxint - 1
        std::vector<int> distances( words.size(), std::numeric_limits<int>::max() - 1 );
        
        // This is the vector we use to keep track of our return path. Using unordered_set<int> to store possible parent vertices avoids duplicates
        std::vector<std::unordered_set<int>> parents( words.size(), std::unordered_set<int>() );
        
        // Here's the priority queue for Dijkstra, that makes sure we select the vertices in a greedy manner
        auto priorityLess = []( const std::pair<int,int> &x, const std::pair<int,int> &y ) { return x.second > y.second; };
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype( priorityLess )> processQueue( priorityLess );
        
        // We initialize distance of the beginWord to zero and push it onto the processing queue
        distances[ 0 ] = 0;
        processQueue.push( make_pair(0, distances[0]) );

        // Here's standard Dijkstra with a small difference -- we will revisit nodes at the same (BFS) level to gather all possible parents.
        while( !processQueue.empty() ) {
            int currentWord = processQueue.top().first; // Be greedy: take the closest vertex
            processQueue.pop();
            for( auto neighbor : neighbors[ currentWord ] ) {
                int level = distances[ currentWord ] + 1; // This is the distance we are looking at
                if( distances[ neighbor ] < level ) // already processed, continue -- this might be a previous traversed edge being looked at backwards
                    continue;
                if( level <= distances[ neighbor ] ) { // This is <= as opposed to < because we want to keep track of all possible parents
                    if( level < distances[ neighbor ] ) {
                        distances[ neighbor ] = level; // Relax the edge
                    }
                    parents[ neighbor ].insert( currentWord ); // keep track of the parent map
                    processQueue.push( make_pair( neighbor, distances[ neighbor ] ) ); // put the new node into the processing queue
                }
            }
        }
        
        // To reconstruct the result, we go follow the parent map from the endWord using a recursive lambda (reconstruct)
        // Note: This can be made more efficient by pre-allocating resultEntry and pushing at the front, which avoids the std::reverse seen later
        std::vector<std::vector<std::string>> result; // This is the final result we must return
        std::function<void(int)> reconstruct; // This is a lambda that reconstructs the path
        std::vector<std::string> resultEntry; // This is a stack that keeps track of the parents we have followed from endWord
        reconstruct = [&reconstruct, &parents, &result, &resultEntry, &beginWord, &words]( int index ) {
            resultEntry.push_back( words[ index ] ); // push the current word on the stack
            if( index == 0 ) { // if the current word is beginWord, we've found a path, so push that onto the result
                result.push_back( resultEntry );
            }
            else { // we are still in the process of finding a path, recurse on all parent nodes
                for( int nextIndex : parents[ index ] ) {
                    reconstruct( nextIndex );
                }
            }
            resultEntry.pop_back(); // pop the current word off the stack
        };
        
        // We call reconstruct on endWord
        reconstruct( words.size() - 1 );
        
        // Since we used a stack, the entries are in reverse order, i.e. endWord is first and beginWord is last. Must call std::reverse
        for( auto& entry : result )
            std::reverse( entry.begin(), entry.end() );

        return result;
    }
};