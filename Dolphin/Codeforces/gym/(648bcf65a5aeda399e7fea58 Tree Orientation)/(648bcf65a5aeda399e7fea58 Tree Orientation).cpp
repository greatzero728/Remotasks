#include<bits/stdc++.h>
using namespace std;


const int mod = 1e9+7;
const int mx = 1e3+7;

vector<int> graph[mx];
int siz[mx];

long long fd[mx][mx][2], fp[mx][mx];


void dfs(int u, int f) {
	siz[u] =1;
	fd[u][1][1] = 1;
	
	fp[u][0] = 1;
	
	for(auto &v : graph[u]) {
		if(v==f) continue;
		
		dfs(v,u);
		
		memset(fd[0],0,sizeof(fd[0]));
		memset(fp[0],0,sizeof(fp[0]));
		
		for(int i=siz[u];i>=0;i--) {
			for(int j=siz[v];j>=0;j--) {
				(fd[0][i+j][0] += (fd[u][i][0] * (fd[v][j][0] + fd[v][j][1] + fp[v][j])))%=mod;
				
				if(i+j>0) (fd[0][i+j-1][0] =	fd[0][i+j-1][0] + fd[u][i][1] * (fd[v][j][0] + fd[v][j][1]))%=mod;
				
				(fd[0][i+j][1] =  fd[0][i+j][1] + fd[u][i][1] * fp[v][j])%=mod;
				(fp[0][i+j] = fp[0][i+j] + fp[u][i] * (fd[v][j][0] + fd[v][j][1] + fp[v][j]))%=mod;
			}
		}
	
		memcpy(fd[u],fd[0],sizeof(fd[0]));
		memcpy(fp[u],fp[0],sizeof(fp[0]));
		siz[u] = siz[u] + siz[v];
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1,0);
	long long  ans = (fd[1][m][0] + fd[1][m][1])%mod;   
	cout<<ans<<endl;
}