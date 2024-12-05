#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 台阶问题, 动态规划, 但是带限制, 步数不超过6
  没有限制步数不超过六步
  第一道做不出来的题 我醉了, DP真不太会
  
 */

const int N=1e5+5;
const int a[]={0,1,2,1,1,1,1,5,5,4,-1,-1,-2,-3,-1,-9};

int f[N]; // f[i]: 走到第i步时的最大得分

int main() {
	int len=sizeof(a)/sizeof(a[0])-1;
	f[0]=0;
	cout<<len<<'\n';
	
	for(int i=1;i<=len;i++) {
		// 最大走4步
		for(int j=1;j<=4;j++) {
			f[i]=max(f[i],f[i-j]+a[i]); // 取最大值
		}
	}
	cout<<f[len];
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
