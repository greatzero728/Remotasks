// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    map<int,int> M;
    vector<int> div;
    for(int i =1; i*i <= N; i++) if(N%i == 0) {
    	div.push_back(i);
    	if(N != i*i) div.push_back(N/i);}
    sort(div.begin(),div.end());
	
	ALL_THE(div,it) {
		int x =(*it)/2+1;
		for(int i =2; i*i <= *it; i++) 
			if((*it)%i == 0 && i < *it) x =min(x,M[i]*M[(*it)/i]);
		M[*it] =x;}
	cout << M[N] << "\n";
	return 0;
}