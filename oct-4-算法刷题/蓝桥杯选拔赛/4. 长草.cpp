#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 一眼洪泛阿 Easy
  
 */

const int N=1e3+5;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int n,m,k; // 行n列m
char g[N][N]; // "g"是草, "."是海
queue<PII> q; // 队列存需要扩展的位置

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>g[i][j];
		}
	}
	cin>>k;
	while(k--) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(g[i][j]=='g') {
					q.push(make_pair(i,j));
				}
			}	
		}
		// 取出坐标进行扩展
		while(!q.empty()) {
			auto idx=q.front();
			q.pop();
			for(int i=0;i<4;i++) {
				int xx=idx.x+dx[i];
				int yy=idx.y+dy[i];
				if(xx<1 || yy<1 || xx>n || yy>m) continue;
				g[xx][yy]='g';
			}
		}
	}
	// 输出整张图
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cout<<g[i][j];
		}	
		puts("");
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
