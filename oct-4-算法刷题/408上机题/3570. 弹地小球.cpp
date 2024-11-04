#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;
const double eps=1e-2; // 误差

int T,n;

int main() {
	cin>>T;
	double H;
	while(T--) {
		cin>>H>>n;
		double ans=0;
		ans+=H;
		// 第一次弹地H,还剩n-1次
		for(int i=1;i<=n-1;i++) {
			ans+=H; // 往返一次是H
			H/=2;
		}
		cout<<fixed<<setprecision(2)<<ans<<'\n';
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
