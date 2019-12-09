class Solution {
public:
    int romanToInt(string s) {
        int res = 0, i = 0;
        int map[128];
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        for (i = 0; i < s.size() - 1; ++i)
            if (map[s[i]] >= map[s[i + 1]])
                res += map[s[i]];
            else
                res -= map[s[i]];
        res += map[s[i]];
        return res;
    }
};