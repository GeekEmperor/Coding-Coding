#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k, n;
    float d;
    vector<float> v(1005, 0);
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> d;
        v[n] += d;
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> d;
        v[n] += d;
    }
    int count = 0;
    for (int i = 0; i < 1005; ++i)
        if (v[i])
            ++count;
    cout << count;
    for (int i = 1004; i >= 0; --i)
        if (v[i])
            printf(" %d %.1f", i, v[i]);
    return 0;
}