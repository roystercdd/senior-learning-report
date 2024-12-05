#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 很显而易见的动态规划, 要先递增再递减, 长度最长
  最开始还想长度最长是不是要用二分来找
  定义left和rigth数组, 存储以每个元素结尾的
  最长递减子序列长度 和 最长递增子序列长度
  
 */

const int N=1e5+5;

int n,a[N],l[N],r[N];

int main() {
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	
	// 初始化一下
	for(int i=1;i<=n;i++) l[i]=r[i]=1;
	
	// 注意方向
	// DP 找left数组, 对每个元素找前面有多少个元素比它大(递减)
	for(int i=2;i<=n;i++) {
		for(int j=1;j<i;j++) {
			// a[i]<a[j] 说明j可以拼在i的后面(最长递减子序列)
			if(a[j]>a[i]) l[i]=max(l[i],l[j]+1);
		}
	}
//	for(int i=1;i<=n;i++) cout<<l[i]<<' ';
//	puts("");
	
	// DP 找right数组, 对每个元素找前面有多少个元素比它小(递增)
	for(int i=n-1;i>=1;i--) {
		for(int j=n;j>i;j--) {
			if(a[j]>a[i]) r[i]=max(r[i],r[j]+1); // 拼在后面
		}
	}
//	for(int i=1;i<=n;i++) cout<<r[i]<<' ';
//	puts("");
	
	// 最后长度为多少,即是看这个元素前面多少个,后面多少个
	int ans=INT_MIN;
	for(int i=1;i<=n;i++) {
		if(l[i]+r[i]-1>=ans) ans=l[i]+r[i]-1;
	}
	cout<<ans;
	return 0;
}

/*
  输入样例:
  10
  2 1 4 7 4 8 3 6 4 7
  输出样例:
  5
 */
