#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 间隔为1的k个数之和最大
  你的意思是可能有10^6个大小为10^5个数相加!天呐!long long
  
 */

const int N=1e5+5;

int n,a[N],k;

signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);	
	}
	cin>>k;
	int ans=LONG_LONG_MIN;
	
	// 遍历数组
	// 遍历起点, 且限制边界
	for(int i=1;i+2*k<=n;i++) {
		int tmp=0;
		// 遍历次数, i, i+1*k, i+2*k
		for(int j=0;j<k;j++) {
			tmp+=a[i+j*k];
		}
		// 打擂
		if(tmp>ans) {
			ans=tmp;
		}
	}
	cout<<ans;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
