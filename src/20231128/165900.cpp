// sdsyoj-1398
// [wa][tle]
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int t, n, h[10005];
int m, cr, cc;
vector<int> gr, le;
vector<int> a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
            (h[i] > cr) ? gr.push_back(cr), 0 : (h[i] < cr) ? le.push_back(cr), 0 : cc++;
        }
    }
}