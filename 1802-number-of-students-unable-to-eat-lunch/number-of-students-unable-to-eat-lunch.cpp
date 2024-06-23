class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s;
        queue<int> q;
        reverse(sandwiches.begin(), sandwiches.end());

        int count = 0;
        for (int& sandwich : sandwiches) s.push(sandwich);
        for (int& student : students) q.push(student);

        while (!s.empty() || !q.empty()) {
            if (s.top() == q.front()) {
                s.pop(), q.pop();
                count = 0;
            } else {
                q.push(q.front());
                q.pop();
                count++;
            }

            if (count >= q.size()) break;
        }

        return q.size();
    }
};