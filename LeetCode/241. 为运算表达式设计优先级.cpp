class Solution {
public:
    unordered_map<string, vector<int>> m;
    vector<int> diffWaysToCompute(string input) {
        if (m.count(input))
            return m[input];
        vector<int> c;
        for (int i = 0; i < input.size(); ++i)
            if (!isdigit(input[i])) {
                vector<int> a(diffWaysToCompute(input.substr(0, i)));
                vector<int> b(diffWaysToCompute(input.substr(i + 1)));
                for (int j = 0; j < a.size(); ++j)
                    for (int k = 0; k < b.size(); ++k) {
                        if (input[i] == '+')
                            c.emplace_back(a[j] + b[k]);
                        else if (input[i] == '-')
                            c.emplace_back(a[j] - b[k]);
                        else
                            c.emplace_back(a[j] * b[k]);
                    }
            }
        if (c.empty())
            c.emplace_back(stoi(input));
        m[input] = c;
        return c;
    }
};