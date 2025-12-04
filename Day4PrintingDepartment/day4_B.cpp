#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};

int n,m;
bool good(int i, int j, vector<string> &grid) {
    int cnt = 0;
    for(auto [a,b] : dirs) {
        int ni = i + a, nj = j + b;
        if(ni<0||nj<0||ni>=n||nj>=m) continue;
        cnt += grid[ni][nj] == '@';
    }
    return cnt < 4;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> grid;
    string s;
    while(cin >> s) {
        grid.push_back(s);
    }

    n = grid.size(); m = grid[0].size();
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j]=='.') continue;
            if(good(i,j,grid)) {
                q.push({i,j});
            }
        }
    }

    int ans = 0;
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        if(grid[u.first][u.second] == '.') continue;

        ans++;
        grid[u.first][u.second] = '.';
        for(auto [a,b] : dirs) {
            int ni = u.first + a, nj = u.second + b;
            if(ni<0||nj<0||ni>=n||nj>=m) continue;
             
            if(good(ni,nj,grid)) {
                q.push({ni,nj});
            }
        }
    }

    cout << ans << endl;
}