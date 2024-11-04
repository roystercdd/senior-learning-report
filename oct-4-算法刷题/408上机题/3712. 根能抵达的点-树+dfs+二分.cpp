#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 图的常数比较大, 一般来说是O(n), 也可以是O(nlogn)
  
  
 */

const int N=2e4+5, M=N*2;

int n,m;
int h[N],e[M],ne[M],w[M],idx;

void add(int a,int b,int c) {
	e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

// 根节点是u, 删边权重为mid
// 无向图遍历为保证不失序, 加上父节点fa限制遍历顺序
// 得到的是所有>mid的边数(并不是真正删边,只是统计>mid的边数量)
int dfs(int u,int mid,int fa) {
	int res=1; // 根节点也算
	for(int i=h[u];~i;i=ne[i]) {
		int j=e[i];
		// 删掉严格小于mid的边
		if(j==fa || w[i]<mid) continue;
		res+=dfs(j,mid,u);	
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		scanf("%d%d",&n,&m);
		memset(h,-1,sizeof h);
		idx=0;
		// 树, n点 n-1条边, 无向, 最多2*(n-1)
		for(int i=0;i<n-1;i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		int l=0,r=1e8; // 最大是1e7, 当mid=1e7时删掉所有边, 故r比mid即可
		// 找到最小的边权X, 使得到达节点数不超过m, 答案在右边
		while(l<=r) {
			int mid=l+r>>1;
			// 从下标0开始, 根节点的父节点为-1, 每次不超过mid
			if(dfs(0,mid,-1)<=m) r=mid;
			else l=mid;
		}
		printf("%d\n", r);
	}
	return 0;
}
