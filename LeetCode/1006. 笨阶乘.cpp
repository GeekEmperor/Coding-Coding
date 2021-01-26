class Solution {
public:
    int clumsy(int N) {
        int rate = N, ans = 0, pot = 0;
        for(int i = N - 1; i >= 1; i--) {
            switch(pot++) {
                case 0:
                    rate *= i;
                    break;
                case 1:
                    rate /= i;
                    break;
                case 2:
                    ans += rate + i;
                    rate = 0;
                    break;
                case 3:
                    rate = -i;
                    break;
            }
            pot %= 4;
        }
        ans += rate;
        return ans;
    }
};