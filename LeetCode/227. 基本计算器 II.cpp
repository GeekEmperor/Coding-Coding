class Solution {
public:
    int calculate(string s) {
        s += '+';
        int i = 0, j = 0, n = s.size();
        stack<int> num;
        stack<char> op;
        while (j < n) {
            if (isspace(s[j]))
                ++j;
            else if (isdigit(s[j])) {
                i = j;
                while (j < n && isdigit(s[j]))
                    ++j;
                num.push(stoi(s.substr(i, j - i)));
            }
            else if (op.empty() || (s[j] == '*' || s[j] == '/') && (op.top() == '+' || op.top() == '-'))
                op.push(s[j++]);
            else {
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                switch (op.top()) {
                    case '+':
                        num.push(a + b);
                        break;
                    case '-':
                        num.push(a - b);
                        break;
                    case '*':
                        num.push(a * b);
                        break;
                    case '/':
                        num.push(a / b);
                        break;
                }
                op.pop();
            }
        }
        return num.top();
    }
};