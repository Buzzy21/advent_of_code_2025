#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v;
    string s;
    vector<char> operations;
    while(getline(cin,s)) {
        if(s[0] == '+' || s[0] == '*') {
            for(char c : s) {
                if(c=='+' || c=='*') operations.push_back(c);
            }
            break;
        }
        v.push_back(s);
    }

    vector<vector<int>> vals = {{}};
    for(int i = v[0].size()-1; i >= 0; i--) {
        bool fullyEmpty = true;
        for(int j = 0; j < v.size(); j++) if(v[j][i] != ' ') fullyEmpty = false;
        if(fullyEmpty) {
            vals.push_back({});
            continue;
        }

        int res = 0;
        for(int j = 0; j < v.size(); j++) {
            if(v[j][i] == ' ') {
                continue;
            }
            res = res*10+(v[j][i]-'0');
        }
        vals.back().push_back(res);
    }
    reverse(vals.begin(),vals.end());

    int ans = 0;
    for(int i = 0; i < vals.size(); i++) {
        char op = operations[i];
        int res = 0;
        for(int val : vals[i]) {
            if(op=='+') res += val;
            else res = max(val,res*val);
        }
        ans += res;
    }
    cout<<ans<<endl;
}