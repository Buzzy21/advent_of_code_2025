#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = 0;
void process(int l, int r) {
    for(int i = l; i <= r; i++) {
        string s = to_string(i);
        int n = s.size();
        bool good = false;

        for(int sz = 1; sz < n; sz++) {
            if(good) break;
            if(n%sz!=0) continue;
            bool valid = true;

            string sub = s.substr(0,sz);
            for(int j = sz; j+sz <= n; j+=sz) {
                string sub2 = s.substr(j,sz);
                if(sub!=sub2) {
                    valid = false;
                    break;
                }
            }
            if(valid) good = true;
        }
        if(good) {
            ans += i;
            // cout << i << endl;
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

    cout<<ans<<endl;
}