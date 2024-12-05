#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 长度为5, 1~10, 严格递增
  搞错了 不是严格递增, 怪不得交上去不对
  题目说后面的数大于等于前面的数, 相当于限制你必须写代码
  
 */

const int N=1e5+5;

int n;
int cnt;

int x[N]; // x[i]:第i位数字是1~10中的哪个数字

// 长度为u(u==1)时开始寻找序列个数,fa是用过的上一个数字
// 回到最外层的时候 fa=1
void dfs(int u,int fa) {
	// 边界条件, 当序列长度u>5
	if(u>5) {
		cnt++;
		for(int i=1;i<=5;i++) cout<<x[i]<<' ';
		puts("");
		return;
	}
	// 遍历所有情况
	for(int i=fa;i<=10;i++) {
		x[u]=i;
		dfs(u+1,i); // 遍历下一层, 记录当前使用的数字是i
		x[u]=0;
	}
}

int main() {
	dfs(1,1); // 从第一个数起, 从0开始, +1就是1
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
