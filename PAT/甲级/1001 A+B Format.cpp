#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string c = to_string(a + b);
    int n = c.size();
    for (int i = 0; i < n; ++i)
    {
        cout << c[i];
        if (c[i] != '-' && (n - i - 1) % 3 == 0 && i != n - 1)
            cout << ',';
    }
    return 0;
}