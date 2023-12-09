// sdsyoj-941
// [wip]
#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <set>
using namespace std;
int n, k, mi, mii;
array<set<long long>, 65> s;

struct fiostream
{
    int q;
};

template <typename T>
fiostream &operator>>(fiostream &input, T &r)
{
    char ch;
    r = 0;
    bool s = false;
    while ((ch = getchar()) < '0' || ch > '9')
        s |= ch == '-';
    do
        r = r * 10 + ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9');
    r *= (s ? -1 : 1);
    return input;
}

bool chk(long long length, int color, const multiset<long long> choosed)
{
    if (color == k)
        return true;
    for (auto i : s[color])
    {
        if (choosed.empty() || (*choosed.begin() + length >= i && *(choosed.end()--) + length <= i))
        {
            auto tchoosed = choosed;
            tchoosed.insert(i);
            if (chk(length, color + 1, tchoosed))
                return true;
        }
    }
    return false;
}

int main()
{
    fiostream fcin;
    fcin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        fcin >> mi;
        for (int j = 0; j < mi; j++)
        {
            fcin >> mii;
            s[i].insert(mii);
        }
    }
    unsigned long long l = 0, r = 0x7fffffffffffffff, m;
    multiset<long long> tmz;
    while (l < r)
        (chk(m = (l + r) / 2, 0, tmz)) ? (cerr << "[true] l = " << l << ", r = " << r << endl,
                                          r = m)
                                       : (cerr << "[false] l = " << l << ", r = " << r << endl, l = m + 1);
    // (chk(m = (l + r) / 2, 0, tmz)) ? r = m : l = m + 1;
    cout << l;
    return 0;
}

/*
x x x x x x x x x
              8 9
1               9
11      5
*/