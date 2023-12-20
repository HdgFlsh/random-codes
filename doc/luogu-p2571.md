[洛谷](https://www.luogu.com.cn/problem/P2571)

## 前置知识

三分法

## 题意

已知线段$AB$、$CD$，点分别在$AB$、$CD$及其它位置上的移动速度分别为$P$，$Q$及$R$，求点从A到D的最少用时。

## 思路

容易证明用时最少时移动路径包括（不一定全部包含）：
- 从$A$出发，沿$AB$移动一段
- 从$AB$上某点离开，直接移动到$CD$上某点
- 从该点沿$CD$移动至$D$点

因此我们需要得到离开$AB$和到达$CD$的两个点，这里分别记作$X$和$Y$；

### 暴力枚举

复杂度$O(不知道)$

### 三分法

用$XY$表示点$X$到点$Y$的距离；则用时可表示为

$$\frac{AX}{P}+\frac{XY}{R}+\frac{YD}{Q}$$

三分套三分即可。

## 实现

```cpp
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
```
