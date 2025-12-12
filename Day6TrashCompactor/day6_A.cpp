#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> process(string s) {
    int curr = 0;
    vector<int> res;
    for(char c : s) {
        if(c==' ' && curr) {
            res.push_back(curr);
            curr=0;
        }
        else if(c!=' ') curr = curr*10+(c-'0');
    }
    if(curr) res.push_back(curr);

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> v;
    vector<char> operations;
    string s;
    while(getline(cin,s)) {
        if(s[0] == '*' || s[0] == '+') {
            for(char c : s) {
                if(c=='*' || c=='+') operations.push_back(c);
            }
        }
        else {
            v.push_back(process(s));
        }
    }

    int ans = 0;
    for(int i = 0; i < v[0].size(); i++) {
        int total = 0;
        for(int j = 0; j < v.size(); j++) {
            if(operations[i] == '+') {
                total += v[j][i];
            }
            else {
                total = max(v[j][i],total*v[j][i]);
            }
        }
        ans += total;
    }
    cout<<ans<<endl;
}