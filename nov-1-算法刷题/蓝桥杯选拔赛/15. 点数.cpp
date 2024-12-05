#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 不就一个反向嘛, 当结点数为n时, 最大边数为n×(n-1)/2
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	n=2020;
	int ans;
	// 遍历嘛, 从两个点开始
	int last=0; // 1个点
	for(int i=2;i<=n;i++) {
		int tmp=i*(i-1)/2;
		if(tmp>=2020 && last<=2020) {
			ans=i;
			break;
		}
		last=tmp;
	}
	cout<<ans;	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
