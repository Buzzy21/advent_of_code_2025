#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> parent, sizes;

int find(int u) {return u==parent[u]?u:parent[u]=find(parent[u]);}

int unite(int u, int v) {
    u = find(u), v = find(v);
    if(u==v) return 0;
    if(sizes[v] > sizes[u]) swap(u,v);

    sizes[u] += sizes[v];
    parent[v] = u;
    
    return 1;
}

vector<int> process(string s) {
    int x=0,y=0,z=0;
    int idx = 0;
    while(s[idx] != ',') {
        x = x*10+s[idx++]-'0';
    }   
    idx++;
    while(s[idx] != ',') {
        y = y*10+s[idx++]-'0';
    }
    idx++;
    while(idx < s.size()) {
        z = z*10+s[idx++]-'0';
    }
    return {x,y,z};
}

int dist(vector<int> &a, vector<int> &b) {
    return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1]) * (a[1]-b[1]) + (a[2]-b[2]) * (a[2]-b[2]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> coords;
    string s;
    while(getline(cin,s)) {
        if(s.size()==0) break;
        coords.push_back(process(s));
    }
    int n = coords.size();
    parent.resize(n+1); sizes.resize(n+1,1);
    for(int i = 0; i <= n; i++) parent[i] = i;

    vector<vector<int>> possibleConnections;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            possibleConnections.push_back({dist(coords[i],coords[j]),i,j});
        }
    }
    sort(possibleConnections.begin(),possibleConnections.end());
    pair<int,int> last;
    for(int i = 0;;i++) {
        int u = possibleConnections[i][1], v = possibleConnections[i][2];
        unite(u,v);
        last = {u,v};
        if(sizes[find(u)] == n) break;
    }

    cout << coords[last.first][0] * coords[last.second][0] << endl;
}