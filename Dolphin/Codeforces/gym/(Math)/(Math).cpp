#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector> 
#include<cstring>
#include<string>
#define mp make_pair
#define scn second
#define frs first
#define pb push_back
using namespace std;
const unsigned long long P=239017, MaxN=2100000, INF=100000000;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;

char s[1000101];
int n;
vector<int> arr, p[1000000];
int can_n[1000000], can_b[1000000], can[1000000], was_b[1000000], was_n[1000000];
int mx, f[1000000];

int main(){
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
	freopen("math.in", "r", stdin); 
	freopen("math.out", "w", stdout); 
#endif
	
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i) {
		if (s[i] != '^')
			continue;
		++i;
		int a = 0;
		while (a < 1000000 && i < len && s[i] <= '9' && s[i] >= '0')
			a = a * 10 + s[i] - '0', ++i;
		arr.pb(a);
	}
	was_b[0] = 1;
	for (int i = 0; i < arr.size(); ++i) { 
		if (arr[i] > 1000000)
			continue;
		if (was_b[arr[i] - 1])
			can_b[i] = 1;
		if (can_b[i])
			was_b[arr[i]] = 1;
		mx = max(can_b[i] * arr[i], mx);
	}
	was_n[mx + 1] = 1;
	for (int i = arr.size() - 1; i >= 0; --i) {
		if (arr[i] > 1000000)
			continue;		
		if (was_n[arr[i] + 1])
			can_n[i] = 1;
		if (can_n[i])
			was_n[arr[i]] = 1;
	}
	for (int i = 0; i < arr.size(); ++i) 
		if (can_n[i] && can_b[i])
			can[i] = 1, ++f[arr[i]];
	n = arr.size();
	printf("%d\n", arr.size());
	for (int i = 0; i < n; ++i) {
		if (can[i] && f[arr[i]] == 1)
			printf("N");
		else
			printf("Y");			
	}	
	printf("\n");
	for (int i = 0; i < n; ++i) {
		if (can[i])
			printf("Y");
		else
			printf("N");			
	}	
	return 0;
}