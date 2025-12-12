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
    
    vector<vector<int>> events; // {position, type (-1 = start, 1 = close, 0 = ingredient)}
    int x;
    while(cin >> x) {
        events.push_back({x,0});
    } 
    for(const pair<int,int>& p : ranges) {
        events.push_back({p.first,-1});
        events.push_back({p.second,1});
    }
    sort(events.begin(),events.end());

    int cnt = 0, ans = 0;
    for(const vector<int>&e : events) {
        int pos = e[0], type = e[1];
        cnt += type;
        if(type==0) ans += cnt < 0;
    }
    cout << ans << endl;
}