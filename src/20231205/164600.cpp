// sdsyoj-904
// [uke]
#include <iostream>
#include <iomanip>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;
int c, r, x, y;
array<int, 27> f;
string s;
priority_queue<int, vector<int>, greater<int>> p;
int ptop(){auto _=p.top();p.pop();return _;}
int main()
{
    while (getline(cin, s), s != "END")
    {
        c = 1;
        sort(s.begin(), s.end());
        for (unsigned int i = 1; i < s.length();i++)
            (s[i] == s[i - 1]) ? c++ : (p.push(c), c = 1);
        p.push(c);
        r = p.size() == 1 ? s.length() : 0;
        while (p.size() > 1)
            p.push(((r += (x = ptop()) + (y = ptop())), x + y));
        cout << fixed << setprecision(0) << s.length() * 8 << " " << r << " " << setprecision(1) << (double)s.length() * 8 / r << "\n";
        p.pop();
    }
    return 0;
}