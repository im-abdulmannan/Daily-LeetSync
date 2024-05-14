class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;

        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }

        vector<int> res(deck.size(), 0);
        int idx = 0;
        while(!q.empty()) {
            int k = q.front();
            res[k] = deck[idx];
            q.pop();

            if(!q.empty()) {
                int x = q.front();
                q.push(x);
                q.pop();
            }
            idx++;
        }

        return res;
    }
};