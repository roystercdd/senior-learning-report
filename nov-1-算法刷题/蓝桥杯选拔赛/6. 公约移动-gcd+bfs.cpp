#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 一个BFS嘛, 只是移动的临界条件变了
  
 */

const int N=1e3+5;
const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,1,-1};

int n,m,g[N][N];
bool st[N][N]; // 1:访问过了
int x,y; // 起点

int cnt; // 所能到达的块数

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}

// 从(x,y)开始宽搜
void bfs(int x,int y) {
	queue<PII> q;
	q.push({x,y});
	st[x][y]=true;
	
	while(!q.empty()) {
		PII t=q.front();
		q.pop();
		cnt++;
		// 遍历四个方向
		for(int i=1;i<=4;i++) {
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			// 越界处理
			if(xx<1 || yy<1 || xx>n || yy>m) continue;
			// 如果最大公约数大于1则移动
			if(gcd(g[xx][yy],g[t.x][t.y])<=1) continue;
			// 如果遍历过了就不访问
			if(st[xx][yy]) continue;
			q.push({xx,yy});
			st[xx][yy]=true;
		}
	}
}

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>g[i][j];
		}	
	}
	cin>>x>>y;
	bfs(x,y);
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
