class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (!size || size > num.size())
            return {};
        list<int> l(num.begin(), num.begin() + size);
        l.sort();
        vector<int> v = { l.back() };
        for (int i = size; i < num.size(); ++i) {
            auto it = l.begin();
            while (it != l.end() && *it < num[i])
                ++it;
            l.insert(it, num[i]);
            l.remove(num[i - size]);
            v.push_back(l.back());
        }
        return v;
    }
};