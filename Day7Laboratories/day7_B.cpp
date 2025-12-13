#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> v;
    string s;
    while(getline(cin,s)) {
        if(s.size()==0) break;
        v.push_back(s);
    }

    int n = v.size(), m = v[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'S') {
                dp[i][j] += 1;
            }
            if(v[i+1][j] == '^') {
                if(j-1>=0) dp[i+1][j-1] += dp[i][j];
                if(j+1<n) dp[i+1][j+1] += dp[i][j];
            }
            else dp[i+1][j] += dp[i][j];
        }
    }
    
    int ans = 0;
    for(int j = 0; j < m; j++) ans += dp[n-1][j];
    cout << ans << endl;
}