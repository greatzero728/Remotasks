#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using DO = double;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	string s, a, b; vector<string> vec;
	while(cin>>s) vec.push_back(s);
	
	DO x;
	for(int i = vec.size(); i--; ) if(vec[i].back() == ',') {
		x = atof(vec[i - 1].c_str());
		a = vec[i], a.resize(2);
		b = vec[i + 3], b.resize(2);
		
		if(a == "in") x *= 0.08333;
		if(a == "me") x *= 3.28084;
		if(a == "ce") x *= 0.0328084;
		if(a == "mi") x *= 5280;
		if(a == "ki") x *= 3280.84;
		
		if(b == "in") x /= 0.08333;
		if(b == "me") x /= 3.28084;
		if(b == "ce") x /= 0.0328084;
		if(b == "mi") x /= 5280;
		if(b == "ki") x /= 3280.84;
		
		cout<<x<<' '<<vec[i + 3]<<endl;
		return 0;
	}
}