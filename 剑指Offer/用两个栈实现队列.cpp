class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        int value;
        if (stack2.empty())
            while (!stack1.empty()) {
                value = stack1.top();
                stack1.pop();
                stack2.push(value);
            }
        value = stack2.top();
        stack2.pop();
        return value;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};