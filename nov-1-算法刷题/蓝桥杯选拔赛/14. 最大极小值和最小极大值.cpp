#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 枚举的时候下标从2到n-1
  
 */

const int N=1e5+5;

int n,a[N];


int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	int mmax=INT_MIN; // 最大极小值
	int mmin=INT_MAX; // 最小极大值
	for(int i=2;i<=n-1;i++) {
		// 找到一个极小值
		if(a[i]<a[i+1] && a[i]<a[i-1]) {
			mmax=max(mmax,a[i]);
		}
		// 找到一个极大值
		if(a[i]>a[i+1] && a[i]>a[i-1]) {
			mmin=min(mmin,a[i]);
		}
	}
	cout<<mmax<<' '<<mmin;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
