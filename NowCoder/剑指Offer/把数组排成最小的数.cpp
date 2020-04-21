class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int n = numbers.size();
        vector<string> temp(n);
        for (int i = 0; i < n; ++i)
            temp[i] = to_string(numbers[i]);
        sort(temp.begin(), temp.end(), [](auto& a, auto& b) { return a + b < b + a;});
        string res;
        for (int i = 0; i < n; ++i)
            res += temp[i];
        return res;
    }
};