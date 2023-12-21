// luogu-p8666
// [wip]
#include <iostream>
#include <array>
#include <tuple>
using namespace std;
int a, b, c,m;

array<tuple<int, int, int, int, int, int>, 1000006> q;
array<int, 1000006> g;

bool chk(int x)
{
    array<int, 1000006> k;
    for (int i = 0; i < x; i++)

}

istream& operator>>(istream& i, tuple<int, int, int, int, int, int> &t){
    int a, b, c, d, e, f;
    i >> a >> b >> c >> d >> e >> f;
    t = make_tuple(a, b, c, d, e, f);
    return i;
}

int main()
{

    cin >> a >> b >> c >> m;
    int n = a * b * c;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    for (int i = 1; i <= m; i++)
        cin >> q[i];
        
}