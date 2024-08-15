class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (auto bill : bills) {
            if(bill == 5) five++;
            else if (bill == 10) {
                if(five == 0) return false;
                five--;
                ten++;
            } else if (bill == 20) {
                if(five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if(five > 2) {
                    five -= 3;
                } else return false;
            }
        }

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return true;
    }
};