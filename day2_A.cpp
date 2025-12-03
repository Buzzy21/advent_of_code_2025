#include <bits/stdc++.h>
using namespace std;
#define int long long

set<int> works;
void process(int l, int r) {
    for(int i = l; i <= r; i++) {
        string s = to_string(i);
        int n = s.size();
        if(n%2==1) continue;
        if(s.substr(0,n/2) == s.substr(n/2,n/2)) {
            works.insert(i);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<pair<int,int>> ranges;
    int curr = 0; 
    for(char c : s) {
        if(c=='-') {
            ranges.push_back({curr,0});
            curr=0;
        }
        else if(c==','){
            ranges.back().second = curr;
            curr = 0;
        }
        else {
            curr *= 10;
            curr += c-'0';
        }
    }
    ranges.back().second=curr;

    for(pair<int,int> p : ranges) {
        process(p.first,p.second);
    }

    int ans = 0;
    for(int i : works) {
        ans += i;
    }
    cout<<ans<<endl;
}