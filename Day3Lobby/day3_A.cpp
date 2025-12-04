#include <bits/stdc++.h>
using namespace std;
#define int long long

int process(string s) {
    // find first digit
    int mxIdx = 0;
    for(int i = 1; i < s.size()-1; i++) {
        if(s[i]>s[mxIdx]) mxIdx = i;
    }

    // find second digit
    int scIdx = mxIdx+1;
    for(int i = mxIdx+2; i < s.size(); i++) {
        if(s[i] > s[scIdx]) scIdx = i;
    }

    int ans = (s[mxIdx]-'0')*10+(s[scIdx]-'0');
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int ans = 0;
    while(cin >> s) {
        ans += process(s);
    }
    cout<<ans<<endl;
}