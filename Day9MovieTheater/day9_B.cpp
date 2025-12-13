#include <bits/stdc++.h>
using namespace std;
#define int long long

bool covered(const pair<int,int>& target, const vector<pair<int,int>>& v) {
    if(v.empty()) return false;

    pair<int,int> curr = v[0];
    for(auto [l,r] : v) {
        if(l > curr.second) curr = {l,r};
        else curr.second = max(curr.second,r);

        if(curr.first <= target.first && curr.second >= target.second) {
            return true;
        }
    }

    return false;
}

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
    int n = v.size();

    vector<pair<pair<int,int>,pair<int,int>>> lines;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            pair<int,int> a = v[i], b = v[j];
            if(a.first==b.first || a.second==b.second) lines.push_back({a,b}); 
        }
    }
   
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            vector<pair<int,int>> leftCovers, rightCovers, topCovers, bottomCovers;
            pair<int,int> a = v[i], b = v[j];
            for(const auto [c,d] : lines) {
                if(c.first == d.first) {
                    int l = min(c.second,d.second), r = max(c.second,d.second);
                    if(c.first <= min(a.first,b.first)) topCovers.push_back({l,r});
                    if(c.first >= max(a.first,b.first)) bottomCovers.push_back({l,r});
                }
                if(c.second == d.second) {  
                    int l = min(c.first,d.first), r = max(c.first,d.first);
                    if(c.second <= min(a.second,b.second)) leftCovers.push_back({l,r});
                    if(c.second >= max(a.second,b.second)) rightCovers.push_back({l,r});
                }
            }

            sort(leftCovers.begin(),leftCovers.end()); sort(rightCovers.begin(),rightCovers.end());
            sort(topCovers.begin(),topCovers.end()); sort(bottomCovers.begin(),bottomCovers.end());

            pair<int,int> heightSpan = {min(a.first,b.first),max(a.first,b.first)}, widthSpan = {min(a.second,b.second),max(a.second,b.second)};
            if(!covered(heightSpan,leftCovers) || !covered(heightSpan,rightCovers) || 
            !covered(widthSpan,topCovers) || !covered(widthSpan,bottomCovers)) continue; 

            ans = max(ans,(abs(v[i].first-v[j].first)+1)*(abs(v[i].second-v[j].second)+1));
        }
    }

    cout << ans << endl;
}