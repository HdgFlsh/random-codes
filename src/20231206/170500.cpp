// luogu-p1801
// [uke]
#include <iostream>
#include <array>
#include <vector>
#include <queue>
using namespace std;
unsigned int m, n, ii;
int ai;
array<unsigned int, 200005> u;
queue<int> a;
priority_queue<int> hge;
priority_queue<int, vector<int>, greater<int>> hle;
int main()
{
    cin >> m >> n;
    for (unsigned int i = 0; i < m; i++)
    {
        cin >> ai;
        a.push(ai);
    }
    for (unsigned int i = 0; i < n; i++)
        cin >> u[i];
    for (unsigned int i = 0; i < m; i++)
        while ((m - a.size() < u[i]) ? true : (cout << hle.top() << "\n", hge.push(hle.top()), hle.pop(), false))
            hge.push(a.front()), a.pop(), ((hge.size() == i) ? (hle.push(hge.top()), hge.pop(), 0) : 0);
    return 0;
}