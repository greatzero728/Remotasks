#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> p, sz;
    int comp;
    void init(int n) {
        p = vector<int>(n+1); sz = vector<int>(n+1,1); comp = n;
        for(int i = 1; i <= n; i++) p[i] = i;
    }
    int get(int x) { return (x==p[x]?x:p[x]=get(p[x])); }
    void unite(int x, int y) {
        x = get(x); y = get(y);
        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            p[y] = x; sz[x] += sz[y]; comp--;
        }
    }
} d1, d2;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> edge(q);
    vector<int> type(q), answer(q, -1);
    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if(s[0] == '+') {
            type[i] = 1;
            cin >> edge[i].first >> edge[i].second;
            if(edge[i].first > edge[i].second) swap(edge[i].first, edge[i].second);
            mp[edge[i]] = i;
        }
        else if(s[0] == '-') {
            type[i] = 2;
            cin >> edge[i].first >> edge[i].second;
            if(edge[i].first > edge[i].second) swap(edge[i].first, edge[i].second);
            int last = mp[edge[i]];
            type[last] = 3; edge[last] = edge[i]; mp.erase(edge[i]);
        }
        else type[i] = 4;
    }
    d1.init(n); d2.init(n);
    for(auto x : mp) {
        d1.unite(x.first.first, x.first.second);
    }
    for(int i = 0; i <; i++) {
        if(type[i] <= 2) d2.unite(edge[i].first, edge[i].second);
        else if(type[i] == 4) answer[i] = d1.comp;
    }
    d1.init(n);
    for(auto x : mp) {
        d1.unite(x.first.first, x.first.second);
    }
    for(int i = q-1; i >= 0; i--) {
        if(type[i] == 1) d1.unite(edge[i].first, edge[i].second);
        else if(type[i] == 3) {
            d1.unite(edge[i].first, edge[i].second);
            d2.unite(edge[i].first, edge[i].second);
        }
        else if(type[i] == 4) answer[i] = d1.comp - d2.comp + 1;
    }
    for(int i = 0; i <; i++) {
        if(answer[i] != -1) cout << answer[i] << "\n";
    }
    return 0;
}
