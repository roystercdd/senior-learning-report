#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 自己做的时候害卡住了属是不应该,简单题哈
  1) 最简单也是最快的做法,用优先队列分别维护每一行的最大值和每一列的最小值
  2) 除输入外再枚举一遍数组a,如果a[i][j]同时等于这一行的最大值或者这一列的最小值,那么输出
  
 */

const int N=1e2+5;

int n,m,a[N][N];
int cnt; // 鞍点个数

priority_queue<int,vector<int>,less<int>> mmax[N]; // 大根堆(每行的最大值)
priority_queue<int,vector<int>,greater<int>> mmin[N]; // 小根堆(每列的最小值)

int main() {
	cin>>n>>m;
	// 枚举行
	for(int i=1;i<=n;i++) {
		// 枚举列
		for(int j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);	
			mmax[i].push(a[i][j]); // 第i行的最大值,新增结点a[i][j]
			mmin[j].push(a[i][j]); // 第j列的最小值,新增结点a[i][j]
		}
	}
	// 再枚举一遍
	// 枚举行
	for(int i=1;i<=n;i++) {
		int x=mmax[i].top(); // 取出这一行的最大值
		for(int j=1;j<=m;j++) {
			int y=mmin[j].top(); // 取出这一列的最小值
			
			if(a[i][j]==x && a[i][j]==y) {
				cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';
				cnt++;
			}
		}
	}
	if(cnt==0) cout<<"NO";
	return 0;
}

/*
  输入样例:
  3 4
  1 2 3 4
  1 2 3 4
  1 2 3 4
  输出样例: 第1行第4列是鞍点(同行最大且同列最小)
  1 4 4
  2 4 4
  3 4 4
 */
