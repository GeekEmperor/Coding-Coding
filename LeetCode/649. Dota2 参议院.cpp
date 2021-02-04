class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size(), radiants = 0, dires = 0, block1 = 0, block2 = 0;
        for (int i = 0; i < n; ++i)
            if (senate[i] == 'R')
                ++radiants;
            else
                ++dires;
        int i = 0;
        while (radiants && dires) {
            if (senate[i] == 'R') {
                if (block1 == 0)
                    ++block2;
                else {
                    --block1;
                    senate[i] = 'X';
                    --radiants;
                }
            }
            else if (senate[i] == 'D') {
                if (block2 == 0)
                    ++block1;
                else {
                    --block2;
                    senate[i] = 'X';
                    --dires;
                }
            }
            if (++i >= n)
                i = 0;
        }
        return radiants ? "Radiant" : "Dire";
    }
};