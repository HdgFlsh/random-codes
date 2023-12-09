// sdsyoj-1819 / luogu-p3378
// [ac]
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<long long, vector<long long>, greater<long long>> p;
    long long n, op, x;
    cin >> n;
    while (n--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x;
            p.push(x);
            break;
        case 2:
            cout << p.top() << "\n";
            break;
        case 3:
            p.pop();
        default:
            break;
        }
    }
    return 0;
}