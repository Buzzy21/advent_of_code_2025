#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> v;
    string s;
    while(getline(cin,s)) {
        if(s.size()==0) break;
        int a = 0, b = 0;
        int idx = 0;
        while(s[idx] != ',') a = a*10+s[idx++]-'0';
        idx++;
        while(idx < s.size()) b = b*10+s[idx++]-'0';
        v.push_back({a,b});
    }

    int ans = 0, n = v.size();
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) ans = max(ans,(abs(v[i].first-v[j].first)+1)*(abs(v[i].second-v[j].second)+1));
    cout << ans << endl;
}