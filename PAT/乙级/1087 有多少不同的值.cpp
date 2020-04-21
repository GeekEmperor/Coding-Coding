#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i, j, k = -1, count = 0;
    for (i = 1; i <= n; ++i)
    {
        j = i / 2 + i / 3 + i / 5;
        if (j != k)
        {
            ++count;
            k = j;
        }
    }
    cout << count;
}