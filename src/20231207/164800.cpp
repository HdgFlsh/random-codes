// sdsyoj-1821
// [uke]
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

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

int n, s, c = 1;
long long ai;
bool d = true;
array<pair<long long, long long>, 10000005> a;
vector<pair<long long, long long>> v;
vector<pair<long long, pair<long long, long long>>> o;
int main()
{
    fiostream fcin;
    fcin >> n >> s;
    for (int i = 0; i < n; i++)
        a[i] = make_pair((fcin >> ai, ai), i);
    sort(a.begin(), a.begin() + n);
    for (int i = 1; i < n; i++)
        (a[i] == a[i - 1]) ? c++ : (v.push_back(make_pair(i - 1, c)), c = 1);
    v.push_back(make_pair(n - 1, c));
    n = v.size();
    for (int i = 0, j = n - 1; i <= j; (a[v[i].first].first + a[v[j].first].first > s) ? j-- : i++)
        if (a[v[i].first].first + a[v[j].first].first == s)
            if (i == j)
                for (int k = v[i].first; k == v[i].first || a[k].first == a[k - 1].first; k++)
                    for (int l = k + 1; l = v[i].first || a[l].first == a[l - 1].first; l++)
                        o.push_back(make_pair(a[k].second, make_pair(a[k].first, a[v[j].first].first)));
            else
                for (int k = v[i].first; k == v[i].first || a[k].first == a[k - 1].first; k++)
                    for (int l = v[j].first; l == v[j].first || a[l].first == a[l - 1].first; l++)
                        o.push_back(make_pair(a[k].second, make_pair(a[k].first, a[v[j].first].first)));

    if (o.empty())
        cout << -1 << "\n";
    else
    {
        sort(o.begin(), o.end());
        for(auto z : o)
            cout << z.second.first << " " << z.second.second << "\n";
    }
    return 0;
}