//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "prediction"

typedef long long ll;
typedef long double ld;

const int MAXN = 510000;

int a[MAXN];  
int b[MAXN];


ll calc(int n,int* b,int val){
	static int _cnt[2*MAXN];
	static int* cnt = _cnt + MAXN;
	memset(cnt - n, 0, sizeof(cnt[0])*(2*n+1));
	ll ans = 0;
	int cur = 0;
	int pos = 0;
	cnt[0]++;
	for (int i = n-1; i >= 0; i--){
		if (b[i] == val){
			cur += cnt[pos];   
			++pos;          
			cnt[pos]++;
		} else {       
			--pos;          
			cur -= cnt[pos];
			cnt[pos]++;     
		}
		ans += cur;
	}

	return ans;
}

vector<int> g[MAXN];



int main(){
  #ifndef NOFILES
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int tid = 0;
  	int n,m;
  	while (scanf("%d %d",&n,&m) == 2){
  	    ++tid;
    	for (int i = 0; i < n; i++)
    		scanf("%d",&a[i]),--a[i];

    	for (int i = 0; i < m; i++)
    		g[i].clear();

    	for (int i = 0; i < n; i++)
    		g[a[i]].pb(i);

//    	TIMESTAMP(read);

    	ll ans = 0;

    	int __debug_sum = 0;

    	for (int i = 0; i < m; i++){
//                fprintf (stderr, "i=%d\n", i);
    		 vector<pair<int,int> > p;
    		 int last = -1;
    		 for (int j = 0; j < (int)g[i].size(); j++){
    		 	int pos = g[i][j];
    		 	if (p.size() && last >= pos) continue;
    		 	int rpos = pos;
    		 	int sum = 0;
    		 	while (rpos < n && sum >= 0){
    		 		sum += 2*(a[rpos] == i) -1;
    		 		rpos++;
    		 	}
    		 	p.pb(mp(max(0,pos),min(rpos + 1,n-1)));
    		 	last = rpos-1;
    		 }
    		 if (p.empty()) continue;
    	     reverse(p.begin(),p.end());
    	     int ptr = 0;

    	     {
  	  	     int curr = p.front().second;
    		     int curl = p.front().first - (p.front().second - p.front().first) - 1;

  		     for (int i = 1; i < (int)p.size(); i++){
      	     	if (curl <= p[i].second){
      	     		curl = min(curl,p[i].first - (curr - p[i].first) - 1);
      	     	} else {    
  	  				for (int j = curr; j >= curl && j >= 0; j--)    
    						b[ptr++] = a[j];
      	     		curr = p[i].second;
      	     		curl = p[i].first - (p[i].second - p[i].first) - 1;
      	     	}
      	     }               
  			 for (int j = curr; j >= curl && j >= 0; j--)
  				b[ptr++] = a[j];
           }               

  		 reverse(b,b+ptr);	

  		 __debug_sum += ptr;
                       
    	     ll temp = calc(ptr,b,i); 
    	     ans += temp;
  //  	     eprintf("%d -> "LLD"\n",i+1,temp);
    	}

//    	fprintf(stderr,"ptr = %d, n = %d, m = %d\n",__debug_sum, n, m);
    		
    	printf(LLD"\n",ans);      

    	if (tid == 1760 || tid == 3520 || tid == 522529 || tid == 526048 || tid == 1045057 || tid == 1046817){
    		fprintf(stderr,"%d %d\n",n,m);
    		for (int i = 0; i < n; i++)
    			fprintf(stderr,"%d ",a[i]+1);
    		fprintf(stderr,"\n");
    	}
        TIMESTAMP(end);
    }
    return 0;
}
