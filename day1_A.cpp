#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 50, cnt = 0;
    string s = "  ";
    while(cin >> s) {
        char dir = s[0];
        int c = 0;
        for(int i = 1; i < s.size(); i++) {
            c *= 10;
            c += s[i]-'0';
        }
        
        if(dir=='L') {
            n=((n-c)+100)%100;
        }
        else {
            n = (n+c)%100;
        }
        cnt += n==0;
    }
    cout<<cnt;
}
