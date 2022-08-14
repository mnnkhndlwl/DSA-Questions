Prerequisite -> https://leetcode.com/problems/word-ladder/

Word Ladder just requires you to find the min no of steps to convert beginWord into endWord using wordList.

Here, I have used the same concept of Word Ladder but instead of taking queue(string).

I have used queue(vector(string))), which will basically store the path after each level order traversal.

And I have introduced a visited set, which will be erased after each level of traversal.

This will guarentee that we will have the paths that are of min length. Since, after getting the first occurance of endWord, we are inserting it into our visited set, then after traversing all the nodes at that particular level we will be erasing this visited endWord from our set st, which will now does not contain the endWord in it.

Thus we will be only getting the min length paths in it and the loop will never satisfy the condition that st.count(temp) == 1, and we will be removing our extra paths from the queue and at the end the queue will become empty and we will return our vector of vector of string ans.

I hope the soln is now clear to everyone.

class Solution {
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(), wordList.end());
        set<string>visited;
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({beginWord});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<string> currPath = q.front();
                q.pop();
                string s = currPath.back();
                for(int i=0;i<s.size();i++){
                    for(char c = 'a'; c<='z'; c++){
                        string temp = s;
                        temp[i] = c;
                        if(st.count(temp)!=0){
                            vector<string>newPath = currPath;
                            newPath.push_back(temp);
                            visited.insert(temp);
                            if(temp==endWord)
                                ans.push_back(newPath);
                            else
                                q.push(newPath);
                        }
                    }
                }
            }
            for(auto i:visited){
                st.erase(i);
            }
        }
        return ans;
    }
};
