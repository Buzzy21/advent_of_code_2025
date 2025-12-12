#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> ranges;
    string s;
    while(getline(cin,s)) {
        if(s.size()==0) break;
        int left = 0, right = 0, idx = 0;
        for(; s[idx] != '-'; idx++) left = left * 10 + (s[idx]-'0');
        idx++;
        for(; idx < s.size(); idx++) right = right * 10 + (s[idx]-'0');

        ranges.push_back({left,right});
    }
    sort(ranges.begin(),ranges.end());

    int ans = 0, prevRight = 0;
    for(auto [left,right] : ranges) {
        bool shifted = prevRight >= left;
        left = max(left,prevRight);
        ans += max(0ll,right-left+!shifted);
        prevRight = max(right,prevRight);
    }
    cout << ans << endl;
}