class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        int n = deck.size();

        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        vector<int> result(n, 0);
        int i = 0;

        while(!q.empty()) {
            int k = q.front();
            result[k] = deck[i];
            q.pop();

            if(!q.empty()) {
                int x = q.front();
                q.push(x);
                q.pop();
            }
            i++;
        }

        return result;
    }
};