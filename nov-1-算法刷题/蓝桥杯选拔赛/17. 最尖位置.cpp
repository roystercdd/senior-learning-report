#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 泰简单辣 枚举一次即可
  
 */

const int N=1e5+5;

int n,a[N];

signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);	
	}
	int mmax=0; // 找不到输出0
	// 枚举所有可能位置
	for(int i=2;i<=n-1;i++) {
		if(a[i-1]<=a[i] || a[i+1]<=a[i]) continue;
		int tmp=(a[i-1]-a[i])*(a[i+1]-a[i]);
		if(tmp>mmax) {
//			cout<<i-1<<' '<<i<<' '<<i+1<<' '<<tmp<<' '<<mmax<<'\n';
			mmax=tmp;
		}
	}
	cout<<mmax;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
