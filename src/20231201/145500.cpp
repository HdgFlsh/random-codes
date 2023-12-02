// sdsyoj-771
// [uk]
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int n, x;
long long m;
set<long long> b[40010];
int main()
{
    ifstream fin("c.in");
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "num " << i;
        fin >> x;
        for (long long j = 1; x > 0; j++)
            if ((b[i - 1].find(j) == b[i - 1].end()) && (i != n || b[1].find(j) == b[1].end()))
                b[i].insert(j), x--, m = max(m, j);
    }
    cout << m;
    return 0;
}