#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using DO = long double;

const DO eps = 1e-7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	DO a, b, c, radius; cin>>a>>b>>c>>radius;
	if(a > b) swap(a, b);
	if(a > c) swap(a, c);
	if(b > c) swap(b, c);
	
	if(a + b < c + eps) {
		puts("Circle doesn't get into the triangle");
		puts("Triangle doesn't get into the circle");
		return 0;
	}
	
	DO p = (a + b + c) / 2;
	DO s = sqrtl(p * (p - a) * (p - b) * (p - c));
	DO r = s / (a + b + c);
	DO R = a * b * c / 4 / s;
	
	if(radius < r + eps) puts("Circle gets into the triangle");
	else puts("Circle doesn't get into the triangle");
	
	if(radius > R - eps) puts("Triangle gets into the circle");
	else puts("Triangle doesn't get into the circle");
	return 0;
}
