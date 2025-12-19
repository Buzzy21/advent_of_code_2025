
#include <bits/stdc++.h>
using namespace std;
#define int long long

void process(const string &s, vector<vector<int>>& targets, vector<vector<vector<int>>>& presses) {
    int idx = 1;
    while(s[idx] != '(') idx++;
    
    presses.push_back({});
    targets.push_back({});

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
    n=0;

    idx++;
    while(s[idx] != '}') {
        if(s[idx] == ',') {
            targets.back().push_back(n);
            n = 0;
        }
        else n = n * 10 + s[idx]-'0';
        idx++;
    }
    targets.back().push_back(n);
    return;
}

int solveFor(const vector<int>& target, const vector<vector<int>>& presses) {

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> targets;
    vector<vector<vector<int>>> presses;

    string s;
    while(getline(cin,s)) {
        if(s.size()==0) break;
        process(s,targets,presses);
    }

    int ans = 0;
    for(int i = 0; i < presses.size(); i++) {
    
    }
    cout << ans << endl;
}