// sdsyoj-1822
// [uk]
#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <array>
using namespace std;

int n;
unsigned long long r = 0;
array<int, 100005> a;
queue<int> q;

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

int main(){
    fiostream fcin;
    fcin >> n;
    for (int i = 0; i < n; i++)
        fcin >> a[i];
    sort(a.begin(), a.begin() + n);
    for (int i = 0; i < n; i++){
        while (!q.empty() && (double)q.front() < (double)a[i] * 0.9)
            q.pop();
        r += q.size();
        q.push(a[i]);
    }
    cout << r;
    return 0;
}