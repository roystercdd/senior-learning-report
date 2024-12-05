#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: a点b分, t分钟后是几点几分, 考虑进位
  
 */

const int N=1e5+5;

int a,b,t;

int main() {
	cin>>a>>b>>t;
	b+=t;
//	cout<<b<<'\n';
	a+=b/60;
//	cout<<a<<'\n';
	b%=60;
	a%=24; // 天数无需进位
	cout<<a<<'\n'<<b;	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
