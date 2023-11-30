// luogu-p1090 / luogu-p6033 / sdsyoj-283 / sdsyoj-261 / noip-2004-s-merge
// [ac]
#pragma GCC optimize("O3")
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
long long n, ai, aj;
deque<long long> a, b;
int cnt[(int)1e5 + 10];
long long r;
long long fffread()
{
    char ch;
    long long r = 0;
    bool s = false;
    while ((ch = getchar()) < '0' || ch > '9')
        s |= ch == '-';
    do
        r = r * 10 + ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9');
    return r * (s ? -1 : 1);
}
long long gmin()
{
    long long t;
    if (a.empty())
    {
        t = b.front();
        b.pop_front();
    }
    else if (b.empty())
    {
        t = a.front();
        a.pop_front();
    }
    else if (a.front() < b.front())
    {
        t = a.front();
        a.pop_front();
    }
    else
    {
        t = b.front();
        b.pop_front();
    }
    return t;
}
int main()
{
    n = fffread();
    while (n--)
        cnt[fffread()]++;
    for (int i = 0; i < (int)1e5 + 10; i++)
        for (int j = 0; j < cnt[i]; j++)
            a.push_back(i);
    while (a.size() + b.size() != 1)
    {
        r += ai = gmin() + gmin();
        b.push_back(ai);
        // cout << "a.size = " << a.size() << " b.size = " << b.size() << endl;
    }
    cout << r << endl;
    return 0;
}
