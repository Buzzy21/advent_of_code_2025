#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> grid;
    string s;
    while(cin >> s) {
        grid.push_back(s);
    }

    int n = grid.size(), m = grid[0].size(), ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j]=='.') continue;
            int cnt = 0;
            for(auto [a,b] : dirs) {
                int ni = i + a, nj = j + b;
                if(ni<0||nj<0||ni>=n||nj>=m) continue;
                cnt += grid[ni][nj] == '@';
            }

            if(cnt < 4) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}