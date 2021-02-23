#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestGoodBase(string n) {
        long long m = stoll(n);
        for (int k;;++k) {
            long long t = 0;
            while (++t < m)
                t *= k;
            if (t == m)
                return to_string(k);
        }
    }
};