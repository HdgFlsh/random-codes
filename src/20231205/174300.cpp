// sdsyoj-904 / luogu-2168
// [wa]
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, wi, c, r;
int x[10];
priority_queue<int, vector<int>, greater<int>> w;

int ptop()
{
    auto _ = w.top();
    w.pop();
    return _;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        w.push((cin >> wi, wi));
    r = 0;
    while (w.size() >= k)
    {
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += x[i] = ptop();
        w.push(((r += sum), sum));
    }
    cout << r << "\n";
    return 0;
}