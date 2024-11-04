#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 其实就是Kruskal中将所有边加入并查集中
  但是确实忘了怎么写了,各个顶点之间联通都可互达就是连通图
  
 */

const int N=1e3+5;

int n,m,fa[N]; // fa[i]:顶点i的父结点

// 路径压缩find
int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int main() {
	while(cin>>n>>m) {
		for(int i=1;i<=n;i++) {
			fa[i]=i; // 并查集初始化	
		}
		while(m--) {
			int a,b;
			cin>>a>>b; // a,b之间可达
			fa[find(a)]=find(b); // a的祖先变为b的祖先
		}
		bool flag=true;
		// 检验是否所有顶点都在一个集合内
		for(int i=2;i<=n;i++) {
			if(find(i)!=find(1)) {
				flag=false;
				break;
			}
		}
		if(flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
