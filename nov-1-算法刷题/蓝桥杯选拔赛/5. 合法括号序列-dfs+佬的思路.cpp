#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路:
  1对括号合法序列: ()
  2对括号合法序列: (()), ()()
  3对括号合法序列: ((())), ()()(), (())(), ()(()) 4种
  这道题其实用dfs可以解决, 暴搜写少了 真不懂, 佬的思路
  
 */

const int N=1e5+5;
int cnt;

// l: 所用左括号次数
// r: 所用右括号次数
void dfs(int l,int r) {
	// 左括号和右括号达到4
	if(l==4 && r==4) cnt++;
	// 右括号数量大于左括号就return 因为先添的左括号哇
	if(l<r) return;
	// 左括号或右括号大于4就return
	if(l>4 || r>4) return;
	
	dfs(l+1,r); // 添一个左括号
	dfs(l,r+1); // 添一个右括号
}

int main() {
	dfs(0,0); // 最开始啥都没有
	cout<<cnt<<endl;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
