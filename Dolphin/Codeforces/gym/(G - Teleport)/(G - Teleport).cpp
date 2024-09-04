#include<bits/stdc++.h>
using namespace std;
const int N=500002;
int a,b,c,d,e,i,j,ii,jj,zx,xc,f[500009],cnt,p[500009],pi,F[500009],pr[500009],I;
pair <int, int> fx[500009],dp[1000009];
long long pas,jm;
void CL(int q){
	if(dp[q].first!=cnt){
		dp[q].first=cnt;
		dp[q].second=0;
	}
}
void rec(int q, int w){
//	cout<<q<<" "<<w<<endl;
	if(q>w) return;
	if(q==w){
		pas++;
		return;
	}
	cnt++;
	int md=(q+w)/2;
	int h=0;
	int mx=0;
	fx[mx].first=cnt;fx[mx].second=0;
	pi=0;
	for(h=md+1; h<=w; h++){
		if(fx[f[h]].first!=cnt){
			fx[f[h]].first=cnt;fx[f[h]].second=0;
		}
		fx[f[h]].second++;
		if(fx[mx].second<fx[f[h]].second) mx=f[h];
		if(mx==f[h]){
			if(F[f[h]]!=cnt){
				F[f[h]]=cnt;
				pi++;
				p[pi]=f[h];
			}
		}
	}
	//
	cnt++;
	mx=0;
	fx[mx].first=cnt;fx[mx].second=0;
	for(h=md; h>=q; h--){
		if(fx[f[h]].first!=cnt){
			fx[f[h]].first=cnt;fx[f[h]].second=0;
		}
		fx[f[h]].second++;
		if(fx[mx].second<fx[f[h]].second) mx=f[h];
		if(mx==f[h]){
			if(F[f[h]]!=cnt&&F[f[h]]!=cnt-1){
				F[f[h]]=cnt;
				pi++;
				p[pi]=f[h];
			}
		}
	}
	//
	for(ii=1; ii<=pi; ii++){
		//cout<<q<<" "<<w<<"   "<<p[ii]<<endl;
		cnt++;
		c=p[ii];
		pr[q-1]=0;
		dp[N].first=cnt;dp[N].second=1;
		I=N-1;jm=0;
		CL(I);
		for(i=q; i<=w; i++){
			if(f[i]==c){
				pr[i]=pr[i-1]+1;
				I++;
				CL(I);
				jm+=dp[I].second;
				if(i>md){
					pas+=jm;
				}
				if(i<md){
					CL(pr[i]+N);
					dp[pr[i]+N].second++;
					if(pr[i]+N<=I) jm++;
				}
			}else{
				pr[i]=pr[i-1]-1;
				CL(I);
				jm-=dp[I].second;
				I--;
				if(i>md){
					pas+=jm;
				}
				if(i<md){
					CL(pr[i]+N);
					dp[pr[i]+N].second++;
					if(pr[i]+N<=I) jm++;
				}
			}
		}
	}
	rec(q,md);
	rec(md+1,w);
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("prediction.in","r",stdin);
	freopen("prediction.out","w",stdout);
	cin>>a>>b;
	for(i=1; i<=a; i++){
		cin>>f[i];
	}
	rec(1,a);
	cout<<pas;
	return 0;
}