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

    int ans = 0, n = v.size(), m = v[0].size();
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'S' || v[i][j] == '|') {
                if(v[i+1][j] != '^') {
                    v[i+1][j] = '|';
                }
                else {
                    ans++;
                    if(j-1>=0) v[i+1][j-1] = '|';
                    if(j+1<m) v[i+1][j+1] = '|';
                }
            }
        }
    }
    cout << ans << endl;
}