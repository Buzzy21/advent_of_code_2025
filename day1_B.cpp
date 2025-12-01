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
        
        if(dir=='L') { // hey dont mind me brute forcing this
            int original = n;
            while(c--) {
                n=((n-1)+100)%100;
                cnt += n==0;
            }
        }
        else {
            n += c;
            cnt += n/100;
            n%=100;
        }
    }
    cout<<cnt;
}
