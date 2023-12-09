// luogu-p3865
// [ac]
#include <iostream>
#include <cmath>
#include <cstdio>
#include <array>
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

int n, m;
array<array<int, 21>, 100005> a;
int main(){
    fiostream fcin;
    fcin >> n >> m;
    for (int i = 1; i <= n; i++)
        fcin >> a[i][0];
    for (int j = 1; j < 21;j++)
        for (int i = 1; i + (1 << j) <= n + 1; i++)
            a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; i++){
        int l, r, k;
        fcin >> l >> r;
        k = log2(r - l + 1);
        cout << max(a[l][k], a[r - (1 << k) + 1][k]) << "\n";
    }
    return 0;
}