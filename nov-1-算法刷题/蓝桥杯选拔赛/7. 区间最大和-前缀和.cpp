#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 莫想复杂了, 虽然单调队列好像是可以维护固定区间内的最大和
  但是这道题O(n)的复杂度再遍历一遍不就可以了嘛, 毕竟是连续的
  
 */

const int N=1e5+5;

int n,k,a[N],s[N];

signed main() {
	cin>>n>>k; // 区间长度为k
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);		
		s[i]=s[i-1]+a[i]; // 前缀和
	}
	int res=INT_MIN;
	// 再遍历一次, n-k+1 是最后一个遍历因子的位置
	for(int i=1;i<=n-k+1;i++) {
		res=max(res,s[i+k]-s[i]);
	}
	cout<<res;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
