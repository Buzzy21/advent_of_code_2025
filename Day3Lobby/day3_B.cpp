#include <bits/stdc++.h>
using namespace std;
#define int long long

int process(string s) {
    vector<string> dp(13); // dp might be overkill since i think greedy works too
    for(int i = 0; i < s.size(); i++) {
        for(int j = min(i+1,12ll); j >= 1; j--) {
            string cand = dp[j-1]+s[i];
            if(cand>dp[j]) dp[j] = cand;
        }
    }

    return stoll(dp[12]);
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