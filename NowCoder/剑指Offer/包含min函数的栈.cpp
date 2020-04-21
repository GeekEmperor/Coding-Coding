class Solution {
private:
    stack<int> a;
    stack<int> b;
public:
    void push(int value) {
        a.push(value);
        if (b.empty() || value <= b.top())
            b.push(value);
    }
    void pop() {
        if (!b.empty() && a.top() == b.top())
            b.pop();
        a.pop();
    }
    int top() {
        return a.top();
    }
    int min() {
        return b.top();
    }
};