class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token: tokens) {
            if(isdigit(token[0]) || token[0] == '-' && token[1] != 0)
                s.push(stoi(token));
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(token[0] == '+')
                    s.push(a + b);
                else if(token[0] == '-')
                    s.push(a - b);
                else if(token[0] == '*')
                    s.push(a * b);
                else if(token[0] == '/')
                    s.push(a / b);
            }
        }
        return s.top();
    }
};
