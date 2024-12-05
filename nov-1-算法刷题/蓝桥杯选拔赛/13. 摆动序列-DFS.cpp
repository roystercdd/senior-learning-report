#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 奇数项都比前一项大, 偶数项都比前一项小
  长度为m,每个数都在1~n之间的摆动序列有多少个
  可以用DFS吗?
  
 */

const int N=1e5+5;

int n,m,x[N];

// 放第x个元素, 上一个奇数是a, 上一个偶数是b
// f表示下标, 存储对应位置的元素
void dfs(int u,int a,int b,int f) {
	// 临界条件 x>n
	if(u>n) {
		for(int i=1;i<=n;i++) {
			cout<<x[i]<<' ';
		}
		puts("");
		return;	
	}
	if(f&1) {
		x[f]=a+1;
		f++;
		dfs(u+1,a+1,b,2);
		f--;
	}
	else {
		x[f]=b+1;
		f++;
		dfs(u+1,a,b+1,1);
		f--;
	}
}

int main() {
	cin>>m>>n; // 长度为m, 每个数在1~n
	dfs(1,0,0,1); // 从第一个数字开始放 
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
