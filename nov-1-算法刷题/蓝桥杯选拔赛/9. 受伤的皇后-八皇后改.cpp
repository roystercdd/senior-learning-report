#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 八皇后, 但是可以在对角线上, 只要行号差值≥3
  
 */

const int N=10+5;

int n,a[N];
int x[N]; // x[i]: 第i个皇后在第i行的列数
int ans; // 方案总数

// 判断当前放置的皇后与前i行的皇后是否冲突了
bool place(int i) {
	for(int j=1;j<=i-1;j++) {
		// 列冲突或对角线冲突(i-j小于3表示冲突)
		if(x[i]==x[j] || (abs(i-j)==abs(x[i]-x[j]) && i-j<3)) {
			return false;	
		}
	}
	return true;
}

// 递归求方案总数, 从第i个皇后开始放
void dfs(int i) {
	// 1. 边界条件
	if(i>n) {
		ans++;
//		for(int j=1;j<=n;j++) {
//			cout<<x[j]<<' ';
//		}
//		cout<<'\n';
		return;
	}
	// 2. 遍历所有方案, 试探
	// n皇后, n×n棋盘, 每种皇后n种方法
	for(int j=1;j<=n;j++) {
		x[i]=j; // 占据方案
		if(place(i)) dfs(i+1); // 如果能放 到下一种方案
		x[i]=0; // 回溯
	}
}

int main() {
	cin>>n; // 最多十皇后
	dfs(1);
	cout<<ans;
	return 0;
}

/*
  输入样例:
  4
  输出样例:
  2
 */
