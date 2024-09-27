class MyCalendarTwo {
    map<int, int> mp;
public:
    MyCalendarTwo() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
    
    bool book(int start, int end) {
        mp[start] += 1;
        mp[end] -= 1;
        int active = 0;
        for(auto &it : mp) {
            active += it.second;
            if(active > 2) {
                mp[start] -= 1;
                mp[end] += 1;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */