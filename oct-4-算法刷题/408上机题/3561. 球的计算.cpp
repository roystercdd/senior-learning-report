#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 球面一点和中心直接确定半径,有半径可以直接求体积
  
 */

const int N=1e5+5;

int n,T,a[N];

int main() {
	cin>>T;
	while(T--) {
		double x0,y0,z0,x1,y1,z1;
		cin>>x0>>y0>>z0>>x1>>y1>>z1;
		double dx=x0-x1;
		double dy=y0-y1;
		double dz=z0-z1;
		double r=sqrt(dx*dx+dy*dy+dz*dz);
		double V=4.0/3*acos(-1)*r*r*r;
		cout<<fixed<<setprecision(2)<<r<<' '<<V<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
