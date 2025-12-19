#include <bits/stdc++.h>
using namespace std;
#define int long long

void process(const string &s, vector<vector<bool>>& targets, vector<vector<vector<int>>>& presses) {
    int idx = 1;
    vector<bool> target;
    while(s[idx] != ']') {
        if(s[idx++] == '#') target.push_back(true);
        else target.push_back(false);
    }
    targets.push_back(target);
    presses.push_back({});

    vector<int> curr; int n = 0;
    while(s[idx] != '{') {
        if(s[idx] == '(') {
            n = 0;
            curr = {};
        }
        else if(s[idx] == ')') {
            curr.push_back(n);
            presses.back().push_back(curr);
        }
        else if(s[idx] == ',') {
            curr.push_back(n);
            n = 0;
        }
        else if(s[idx] != ' ') {
            n = n * 10 + s[idx]-'0';
        }
        idx++;
    }
    return;
}

int solveFor(const vector<bool>& target, const vector<vector<int>>& presses) {
    int res = INT_MAX;
    for(int mask = 0; mask < 1<<(presses.size()); mask++) {
        int cnt = 0;
        vector<bool> curr(target.size(),false);
        for(int i = 0; i < presses.size(); i++) {
            if(mask&(1<<i)) {
                cnt++;
                for(int button : presses[i]) curr[button] = !curr[button]; 
            }
        }

        if(target==curr) res = min(res,cnt);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<bool>> targets;
    vector<vector<vector<int>>> presses;

    string s;
    while(getline(cin,s)) {
        if(s.size()==0) break;
        process(s,targets,presses);
    }

    int ans = 0;
    for(int i = 0; i < presses.size(); i++) {
        ans += solveFor(targets[i],presses[i]);
    }
    cout << ans << endl;
}