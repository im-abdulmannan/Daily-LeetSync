class AllOne {
    unordered_map<string, int> freq;
public:
    AllOne() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
    
    void inc(string key) {
        freq[key]++;
    }
    
    void dec(string key) {
        freq[key]--;
    }
    
    string getMaxKey() {
        int mx = 0;
        string ans = "";
        for(auto &val : freq) {
            if(val.second > mx) {
                mx = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        int mn = INT_MAX;
        string ans = "";
        for(auto &val : freq) {
            if(val.second != 0 && val.second < mn) {
                mn = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */