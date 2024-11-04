#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 其实是一个类斐波那契问题
  f[1]表示2×1的地板,只能竖着铺
  f[2]表示2×2的地板,可以两个横的,也可以两个竖的
  从f[3]开始每次最后一行新增一列,只能放竖的,所以取决于之前有多少种方法
  
 */

const int N=1e4+5;
const int MOD=999983;

int n;
int f[N]; 

int main() {
	f[1]=1;
	f[2]=2;
	cin>>n;
	for(int i=3;i<=n;i++) {
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	cout<<f[n];
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
