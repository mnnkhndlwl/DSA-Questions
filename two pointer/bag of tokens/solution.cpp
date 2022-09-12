class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(), token.end());
        int l=0,r=token.size()-1;
        int score = 0;
        int max_score = 0;
        while(l<=r){
             if (token[l] <= power) {
                // case 1. play l-th tokens face up if its power <= the current power
                // ---
                // losing tokens[l] power
                power -= token[l];
                // and gaining 1 score
                score += 1;
                // cur_score can be mx_score potentially
                max_score = max(max_score, score);
                // move the pointer to the right
                l += 1;
            } else if (score >= 1) {
                // case 2. play r-th tokens face down if the current score is at least 1
                // ---
                // gaining tokens[r] power
                power += token[r];
                // and losing 1 score
                score -= 1;
                // move the pointer to the left
                r -= 1;
            } else {
                // case 3. impossible to play
				// ---
                // either you don't enough power or enough score
                break;
            }
        }
        return max_score;
    }
};