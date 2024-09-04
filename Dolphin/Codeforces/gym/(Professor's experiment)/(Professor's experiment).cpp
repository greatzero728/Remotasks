#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <fstream>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
#endif
	
    int n,q;
    cin>>n>>q;
    vector<set<int> > a(3,set<int>());
    vector<int> b(n),c(3,0),d(3,0);
    for(int i=0;i<n;i++) {
        int j;
        cin>>j;
        a[j-1].insert(i);
        c[j-1]++;
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        d[b[i]-1]++;
    }
    bool state=true;
    for(int i=0;i<q;i++) {
        int x,y;
        cin>>x>>y;
        if(c[x-1]==0){state=false;break;}
        c[x-1]--;
        c[y-1]++;
        for(set<int>::iterator j=a[x-1].begin();j!=a[x-1].end();j++) a[y-1].insert(*j);
    }
    if(state) {
        for(int i=0;i<3;i++) if(d[i]!=c[i]) state=false;
        for(int i=0;i<n;i++) {
            if(a[b[i]-1].find(i)==a[b[i]-1].end()) state=false;
        }
    }
    if(state) cout<<"YES";
    else cout<<"NO";
    return 0;
}