#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 多起点洪泛,并且带次数限制 用pair来存储起点洪泛即可
  
 */

const int N=1e2+5;
const int dx[]={0,-1,1,0,0};
const int dy[]={0,0,0,1,-1};

int n,m;
int t; // 出水管个数
bool g[N][N]; // g[i][j]=1: 被灌溉好了
int k; // k分钟后
vector<PII> tube; // 存储起点坐标

int cnt; // 有多少个被灌溉

// 从坐标(x,y)开始洪泛找点, 步数限制是k
void dfs(int x,int y,int k) {
	queue<PII> q;
	q.push({x,y}); // 起点
	cnt++; // 起点怎么不算呢!
	g[x][y]=true;
	
	// 记录答案, 包含起点, 此处不再是!q.empty()
	while(k--) {
		PII t=q.front();
		q.pop();
		// 遍历四个方向
		for(int i=1;i<=4;i++) {
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			// 越界处理
			if(xx<1 || yy<1 || xx>n || yy>m) continue;
			// 已经为1
			if(g[xx][yy]) continue;
			// 渲染为1 并加入队列
			g[xx][yy]=1;
			q.push({xx,yy});
			cnt++;
		}
	}
}

int main() {
	cin>>n>>m;
	cin>>t;
	while(t--) {
		int x,y;
		cin>>x>>y;
		tube.push_back(make_pair(x,y));
	}
	cin>>k;
	// 多起点bfs, 还有次数限制
	for(auto tb:tube) {
		int x=tb.x;
		int y=tb.y;
		dfs(x,y,k);
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  3 6
  2
  2 2
  3 4
  1
  输出样例:
  9
 */
