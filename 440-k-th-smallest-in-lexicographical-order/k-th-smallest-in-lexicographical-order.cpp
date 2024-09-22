#define ll long long
class Solution {
public:
    int findKthNumber(int n, int k) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int curr = 1; k--;
        while(k) {
            ll steps = getSteps(n, curr, curr+1);
            if(steps <= k) {curr++; k-= steps;}
            else {curr*=10; k--;}
        }
        return curr;
    }

    ll getSteps(ll n, ll curr, ll next) {
        ll steps = 0;
        while(curr<=n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};