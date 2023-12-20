// sdsyoj-1827? / sdsyoj-781 / hdoj-3400? / luogu-p2571
// [ac]
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct point
{
    double x, y;
} a, b, c, d;
double operator-(const point &y, const point &z)
{
    return sqrt(pow(y.x - z.x, 2) + pow(y.y - z.y, 2));
}

int p, q, r;
double k, l;
double f(point x, point y)
{
    return (a - x) / p + (x - y) / r + (y - d) / q;
}
double f(point x){
    point l = c, r = d, ml, mr;
    while (l - r > 1e-10)
        (f(x, (ml.x = l.x + (r.x - l.x) / 3.0, ml.y = l.y + (r.y - l.y) / 3.0, ml)) > f(x, (mr.x = r.x - (r.x - l.x) / 3.0, mr.y = r.y - (r.y - l.y) / 3.0, mr))) ? l = ml : r = mr;
    return f(x, l);
}
int main()
{
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> p >> q >> r;
    point l = a, r = b, ml, mr;
    while (l - r > 1e-10)
        (f((ml.x = l.x + (r.x - l.x) / 3.0, ml.y = l.y + (r.y - l.y) / 3.0, ml)) > f((mr.x = r.x - (r.x - l.x) / 3.0, mr.y = r.y - (r.y - l.y) / 3.0, mr))) ? l = ml : r = mr;
    cout << fixed << setprecision(2) << f(l);
    return 0;
}