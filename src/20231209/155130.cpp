// sdsyoj-1823
// [wip]
#include <iostream>
#include <array>
using namespace std;
int n, iqi, eqi;
long long a, b, c;
array<pair<int, int>, 5005> s;

int main(){
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i ++){
        cin >> iqi >> eqi;
        s[i] = make_pair(iqi, eqi);
    }


}