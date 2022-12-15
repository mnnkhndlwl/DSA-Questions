    class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int i, n = deck.size(),j = 0;
        vector<int> newDeck(n,0);
        deque<int> dq;
        for(i = 0; i < n; i++) dq.push_back(i);
        for(int card : deck){//increasing order at difference of 1 index from 0 to end so the outcome is in increasing order as we wont take every second element;
            newDeck[dq.front()] = card; 
            dq.pop_front();
            if(dq.size()){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return newDeck;
    }
};