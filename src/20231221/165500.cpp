// luogu-p3397 / sdsyoj-1829
// [ac]
#include <iostream>
#include <array>
using namespace std;
int n, m, ax, ay, bx, by;
array<array<int, 1005>, 1005> g;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> ax >> ay >> bx >> by, g[ax][ay]++, g[ax][by + 1]--, g[bx + 1][ay]--, g[bx + 1][by + 1]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < n; j++)
            g[i][j + 1] += g[i][j];
    for (int j = 1; j <= n; j++)
        for (int i = 1; i < n; i++)
            g[i + 1][j] += g[i][j];
    for (int i = 1; i <= n; i++, cout << '\n')
        for (int j = 1; j <= n; j++)
            cout << g[i][j] << ' ';
    return 0;
}