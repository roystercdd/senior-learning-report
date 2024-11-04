#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 线性dp经典例题, 最长上升子串
  
 */

const int N=1e5+5;

int n,a[N];
int f[N]; // f[i]:遍历到a[i]时最长递增子串的长度

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	// 遍历然后求递增子串长度
	int ans=1; // 初始长度为1
	int last=a[1]; // 上一个元素值
	int mmax=INT_MIN;
	// 直接从长度为2开始 就不用特判了
	for(int i=2;i<=n;i++) {
		if(a[i]>last) {
			ans++;
			if(ans>mmax) mmax=ans;
		} else {
			ans=1; // 清零重新记
		}
		last=a[i]; // 记录上一个值
	}
	cout<<mmax<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
