#include<bits/stdc++.h>
using namespace std;
const int N=305;
const double inf=1e9,eps=1e-10;
int n,vy;
double a;
vector<pair<double,double>>f[N][N],g,g2;
struct nd{int x,y,d;}p[N];
double sg(double x){return (x>eps)-(x<-eps);}
pair<double,double> cal(pair<double,double> y,double t,double x)
{
	t/=vy;
	if(!sg(t))
		return sg(x)?(make_pair(inf,-inf)):y;
	y.first=max(y.first,x/t-a*t/2);
	y.second=min(y.second,x/t+a*t/2);
	if(sg(y.first-y.second)>0)
		return {inf,-inf};
	pair<double,double>o;
	o.first=y.second+a*t-sqrt(max(0.0,a*a*t*t*2+y.second*a*t*4-a*x*4));
	o.second=y.first-a*t+sqrt(max(0.0,a*a*t*t*2-y.first*a*t*4+a*x*4));
	return o;
}
void mg(vector<pair<double,double>>&a)
{
	if(!a.size())
		return;
	auto d=a;
	a.clear();
	sort(d.begin(),d.end());
	for(auto i:d)
	{
		for(;a.size()&&sg(a.back().second-i.first)>=0;a.pop_back())
			i.first=a.back().first,i.second=max(i.second,a.back().second);
		a.push_back(i);
	}
}
void zz(int h)
{
	int x=0;
	g.push_back({0,0});
	for(int c=h-1;c>=0;c--)
	{
		int y,z=n+1;
		for(int i=x+1;i<=n;i++)
		{
			if(p[i].d<z)
			{
				int fl=0;
				for(auto r:g)
				{
					auto o=cal(r,p[i].y-p[x].y,p[i].x-p[x].x);
					if(sg(o.first-o.second)>0)
						continue;
					for(auto j:f[i][c])
					{
						if(sg(max(o.first,j.first)-min(o.second,j.second))<=0)
						{
							fl=1;
							break;
						}
					}
					if(fl)
					{
						y=i;
						z=p[i].d;
						break;
					}
				}
			}
		}
		printf("%d ",z);
		g2.clear();
		for(auto h:g)
		{
			auto o=cal(h,p[y].y-p[x].y,p[y].x-p[x].x);
			if(sg(o.first-o.second)>0)
				continue;
			for(auto j:f[y][c])
				if(sg(max(o.first,j.first)-min(o.second,j.second))<=0)
					g2.push_back({max(o.first,j.first),min(o.second,j.second)});
		}
		x=y;
		g=g2;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	ios::sync_with_stdio(0);
	cin>>n>>vy>>a;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y,p[i].d=i;
	sort(p+1,p+n+1,[&](nd a,nd b){return a.y<b.y||a.y==b.y&&a.d<b.d;});
	for(int i=n;i>=0;i--)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(f[j][k-1].size())
				{
					for(auto l:f[j][k-1])
					{
						auto o=cal(l,p[j].y-p[i].y,p[j].x-p[i].x);
						if(sg(o.first-o.second)<=0)
							f[i][k].push_back(o);
					}
				}
			}
			mg(f[i][k]);
		}
		f[i][0].push_back({-inf,inf});
	}
	for(int i=n;i>=1;i--)
	{
		for(auto l:f[0][i])
		{
			if(sg(l.first)<=0&&sg(l.second)>=0)
			{
				zz(i);
				return 0;
			}
		}
	}
	puts("Cannot visit any targets");
	return 0;
}