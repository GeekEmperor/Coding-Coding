#include <iostream>
using namespace std;
bool isprime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return n > 1;
}
int main()
{
    int n, d;
    while (cin >> n >> d)
    {
        if (!isprime(n))
        {
            cout << "No\n";
            continue;
        }
        int m = 0;
        while (n)
        {
            m = m * d + n % d;
            n /= d;
        }
        if (isprime(m))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}