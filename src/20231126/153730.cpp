// sdsyoj-1815
// [ac]
#include <iostream>
using namespace std;
int n;
long long r, c;
string s;
int main()
{
    cin >> n >> s;
    for (auto z : s)
        c += r = (z == '>') ? r + 1 : 0;
    cout << c << endl;
    return 0;
}