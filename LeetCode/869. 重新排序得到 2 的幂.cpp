class Solution {
public:
    bool reorderedPowerOf2(int N) {
        set<string> s = {"0112344778","011237","0122579","012356789","0124","0134449",
                         "0145678","01466788","0248","0368888","0469","1","112234778",
                         "11266777","122446","125","128","1289","13468","16","2",
                         "224588","23","23334455","234455668","23678","256","35566",
                         "4","46","8"};
        int x = 1;
        for (int i = 0; i < 31; ++i) {
            string t(to_string(x));
            sort(t.begin(), t.end());
            s.insert(t);
            x <<= 1;
        }
        string t(to_string(N));
        sort(t.begin(), t.end());
        return s.count(t);
    }
};