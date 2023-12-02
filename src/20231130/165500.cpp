// sdsyoj-1817
// [uke]
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
long long n, k, b[500005], q[100005], r;
unsigned long long m;
set<long long> s;
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        q[b[i]]++;
    }
    for (int i = 0; i < k; i++)
    {
        q[b[i]]--;
        if (s.find(b[i]) == s.end())
        {
            r++;
            if (s.size() == m)
            {
                auto lb = s.begin();
                for (auto z = s.begin(); z != s.end(); z++)
                    if (q[*z] < q[*lb])
                        lb = z;
                s.erase(lb);
            }
            s.insert(b[i]);
        }
    }
    cout << r << endl;
    return 0;
}