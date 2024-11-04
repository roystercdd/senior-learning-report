#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 最开始以为是高精度排列数+lowbit,结果是数论,并且这个思路也太diao了
  一个十进制数末尾有多少个0取决于,因子中能分解出多少个10
  那么转换成二进制数后看末尾有多少个0,取决于因子能分解出多少个2
  从1~n中所有数分解出p的个数的公式是: n/p+n/p^2+n/p^3+...
  所以P(n,m)中包含2的个数=n!×(n-m!)=n!包含2的个数-(n-m)包含2的个数
  
 */

const int N=1e5+5;

int n,m;

// 容斥原理计算数字n中包含多少个质因子p
int f(int n,int p) {
	int res=0;
	while(n) res+=n/p,n/=p;
	return res;
}


int main() {
	// n和m同时为0结束输入
	while(cin>>n>>m,n || m) {
		cout<<f(n,2)-f(n-m,2)<<'\n';
	} 
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
