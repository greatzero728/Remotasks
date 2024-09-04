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

#define TIMESTAMP(x) fprintf(stderr,"["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

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


ll calc(int n,int* b,int val){
	static int _cnt[2*MAXN];
	static int* cnt = _cnt + MAXN;
	memset(cnt - n, 0, sizeof(cnt)*(2*n+1));
	
	
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


int main(){
  #ifndef NOFILES
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  	int n;
  	while (scanf("%d %*d",&n) == 1){

    	for (int i = 0; i < n; i++)
    		scanf("%d",&a[i]);

    	vector<int> colors(a,a+n);
    	sort(colors.begin(),colors.end());
    	colors.erase(unique(colors.begin(),colors.end()),colors.end());

//    	TIMESTAMP(read);

    	ll ans = 0;

    	for (int i = 0; i < (int)colors.size(); i++){
    		ll tmp = calc(n,a,colors[i]);
    		ans += tmp;
//    		eprintf("%d -> "LLD"\n", colors[i], tmp);
    	}
    		
    	printf(LLD"\n",ans);      
        TIMESTAMP(end);
    }
    return 0;
}