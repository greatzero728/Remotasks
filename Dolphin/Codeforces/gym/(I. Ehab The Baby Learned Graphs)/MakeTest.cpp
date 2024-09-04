#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int a[1010][1010];
int main() {
	freopen("in.txt", "w", stdout);
	
	srand(time(0));
	
	int n = 100;
	for(int i = 1; i < n; i++) {
		a[i][i + 1] = a[i + 1][i] = 1;
	}
	cout<<n<<endl;
	for(int i =1 ; i <= n; i++, puts("")) for(int j = 1; j<= n; j++) cout<<a[i][j]<<' ';
	return 0;
}
