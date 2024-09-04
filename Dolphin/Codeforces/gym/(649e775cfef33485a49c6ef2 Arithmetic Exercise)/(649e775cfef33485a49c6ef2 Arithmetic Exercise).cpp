#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
const int N = 2e5+7,mod = 1e9+7;
using namespace std;
int main()
{
  int a,b,k;
  cin >> a >> b >> k;
  if(a == b)
  {
      cout << 1 << ".";
      for(int i=0 ; i < k ; i++)
      cout << 0;
  }
  else
  {
      int c=1;
      cout << 0 << ".";
      while(c!=k)
      {
          if(a < b)
          a *= 10;
          cout << a/b;
          a %= b;
          c++;
      }

      if(a < b) a*=10;
      int l1 = a/b;
      a %= b;
      if(a < b) a*=10;
      int l2 = a/b;
      if(l2 >= 5 && l2 <= 9)
      l1++;
      cout << l1;
  }
}
