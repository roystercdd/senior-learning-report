#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 根本考的就不是链表哈
  直接数组根据输入的问题规模的奇偶性对特定位置进行swap操作即可
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	// 取出所有奇数位置
	for(int i=1;i<=n;i+=2) {
		// 如果n是奇数
		if(i==n && n%2) continue;
		swap(a[i],a[i+1]);
	}
	for(int i=1;i<=n;i++) {
		cout<<a[i]<<' ';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
