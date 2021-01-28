#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size(), i = 0;
        if (abs(m-n) > 1)
            return false;
        while (first[i] == second[i])
            ++i;
        return first.substr(i + 1) == second.substr(i + 1) ||
            first.substr(i) == second.substr(i + 1) ||
            first.substr(i + 1) == second.substr(i);
    }
};