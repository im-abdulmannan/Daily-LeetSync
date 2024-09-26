class MyCalendar {
    vector<pair<int, int>> bookings;
public:
    MyCalendar() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
    
    bool book(int start, int end) {
        for (auto &x: bookings) {
            int existStart = x.first;
            int existEnd = x.second;

            if(start < existEnd && end > existStart) return false;
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */