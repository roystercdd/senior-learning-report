#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 像这种拆分, 不妨倒着枚举
  
 */

const int N=2e3+10;

int n,a[N];
bool st[N]; // st[1]: 表示平方和组成数
int cnt;

int main() {
	// 看看a能取多大, 看看sqrt2021等于夺少
//	cout<<sqrt(2021)<<'\n'; // 为44.几
	for(int i=0;i<=45;i++) {
		for(int j=0;j<=45;j++) {
			st[i*i+j*j]=true;
		}
	}
	// 枚举1~2021
	for(int i=1;i<=2021;i++) if(st[i]) cnt++;
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
