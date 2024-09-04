#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

bool prime(int n) {
	for(int i = 2; i < n; i++) if(n % i == 0) {
		return 0;
	}
	return 1;
}

int main() {
	
	for(int i = 2; i <= 100; i++) {
		if(prime(i)) cerr<<i<<endl;
	}
	return 0;
}
