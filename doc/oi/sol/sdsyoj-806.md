[在 SYOJ 提交](http://oj.sdshiyan.cn/problem/806)

## 前置知识

倍增

## 题意

将长度为$N$的$1, 2, \ldots , N$序列进行$K$轮固定的翻转，每轮翻转$M$次，每次翻转序列中$L_M$到$R_M$的区间，求翻转后序列。

## 思路

观察数据范围发现$M$较小而$K$较大（可达$10^9$），因此选择暴力处理出一轮的数列翻转结果，再使用倍增得到最终结果。

## 实现

```cpp
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
int n, m, k, l, r;
array<array<int, (int)1e5 + 5>, 32> q;
array<int, (int)1e5 + 5> a;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        q[0][i] = a[i] = i;
    for (int i = 0; i < m; i++)
        cin >> l >> r, reverse(q[0].begin() + l, q[0].begin() + r + 1);
    for (int j = 1; j <= 31; j++)
        for (int i = 1; i <= n; i++)
            q[j][i] = q[j - 1][q[j - 1][i]];
    for (int j = 31; j >= 0; j--)
        if (k & (1 << j))
            for (int i = 1; i <= n; i++)
                a[i] = q[j][a[i]];
    for (int i = 1; i <= n; i++)
        cout << a[i] << '\n';
    return 0;
}
```
