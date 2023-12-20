// luogu-p3382
// [ac]
#include <iostream>
#include <array>
using namespace std;
long long n;
long double l, r, ml, mr;
array<long double, 15> a;
long double f(long double x)
{
    long double r = 0;
    for (int i = 0; i <= n; i++)
        r = r * x + a[i];
    return r;
}
int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    while (r - l > 1e-6l)
        (f(ml = l + (r - l) / 3.0) > f(mr = r - (r - l) / 3.0)) ? r = mr : l = ml;
    cout << l;
    return 0;
}
