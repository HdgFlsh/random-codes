// sdsyoj-1428
// [wa][tle]
#pragma GCC optimize("O3")
#include <iostream>
#include <set>
using namespace std;
long long n, hi;
set<pair<long long, long long>> ql;

int main()
{
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> hi;
        if (i != 0)
        {
            auto z = ql.lower_bound(make_pair(hi, -1));
            auto zz = z;
            if (zz == ql.begin())
                z++;
            else if (zz == ql.end()--)
                z--;
            else
            {
                auto zzz = zz;
                auto zzv = (*(zz--)).first;
                auto zzzv = (*(zzz++)).first;
                if (hi - zzv <= zzzv - hi)
                    z = zz;
                else
                    z = zzz;
            }
            cout << abs((*z).first - hi) << ' ' << (*z).second + 1 << '\n';
        }
        ql.insert(make_pair(hi, i));
    }
    return 0;
}