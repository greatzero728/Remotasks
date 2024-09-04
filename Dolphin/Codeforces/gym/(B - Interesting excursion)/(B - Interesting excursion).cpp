#include <bits/stdc++.h>
using namespace std;

#define ar array

const int N = 2e5 + 5;
set<ar<int, 2>> edges[N][3];
int par[N], col[N], uu[N];
ar<int, 2> v[N], rr;

void upd(int id, int nw){
	edges[v[id][0]][uu[id]].erase({col[id], id});
	edges[v[id][0]][nw].insert({col[id], id});
	uu[id] = nw;
}

int get(int u, int c, int j){
	auto it = edges[u][j].upper_bound({c, N});
	if(it != edges[u][j].end()) return (*it)[1];
	it = edges[u][j].lower_bound({c, -1});
	if(it == edges[u][j].begin()) return -1;
	--it;
	return (*it)[1];
}

void dfs(int u){
	upd(u, 1);
	if(get(v[u][1], col[u], 1) != -1){
		int l = get(v[u][1], col[u], 1);
		rr = {l, u};
		return;
	}
	
	int nxt = get(v[u][1], col[u], 0);
	while(nxt != -1){
		par[nxt] = u;
		dfs(nxt);
		if(~rr[0]) return;
		nxt = get(v[u][1], col[u], 0);
	}
	
	upd(u, 2);
}

void solve(){
	int n, m; cin>>n>>m;
	for(int i=0;i<=max(m, n);i++){
		for(int j=0;j<3;j++) edges[i][j].clear();
	}
	for(int i=0;i<m;i++){
		cin>>v[i][0]>>v[i][1]>>col[i];
		uu[i] = 0, par[i] = -1;
		edges[v[i][0]][0].insert({col[i], i});
	}
	
	rr = {-1, -1};
	for(int i=0;i<m;i++){
		dfs(i);
		if(~rr[0]){
			break;
		}
	}
	
	if(rr[0] == -1){
		cout<<-1<<"\n";
		return;
	}
	
	vector<int> res;
	while(rr[1] != rr[0]){
		//~ cout<<rr[1]<<endl;
		res.push_back(rr[1]);
		rr[1] = par[rr[1]];
	} res.push_back(rr[0]);
	reverse(res.begin(), res.end());
	cout<<(int)res.size()<<"\n";
	for(auto x : res) cout<<x + 1<<" ";
	cout<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin>>T;
	while(T--){
		solve();
	}
}