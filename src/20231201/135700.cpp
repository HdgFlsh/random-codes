// sdsyoj-134
// [wip]
#include <iostream>
#include <map>
#include <array>
using namespace std;
int n, m, a;
unsigned long long ri;
array<short, 32> s;
map<array<short, 32>, pair<int, int>> q;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ri;
        short mi = 0x7fff;
        for (int j = 0; j < m; j++)
            mi = min((1 << j & ri) ? ++s[j] : --s[j], mi);
        for (int j = 0; j < m; j++)
            s[j] -= mi;
        if (q.find(s) == q.end())
            q[s] = make_pair(i, i);
        else
            q[s] = make_pair(q[s].first, i);
    }
    a = -1;
    for (auto z : q)
        a = max(z.second.second - z.second.first, a);
    cout << a << endl;
    return 0;
}