class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "/") {
                stk.push(stoi(tokens[i]));
            }
            else
            {
                int operand1 = stk.top();
                stk.pop();
                int operand2 = stk.top();
                stk.pop();
                if(tokens[i] == "+") {
                    stk.push(operand2 + operand1);
                }
                else if(tokens[i] == "-") {
                    stk.push(operand2 - operand1);
                }
                else if(tokens[i] == "*") {
                    stk.push(operand2 * operand1);
                }
                else if(tokens[i] == "/") {
                    stk.push(operand2 / operand1);
                }
            }
        }

        return stk.top();
    }
};