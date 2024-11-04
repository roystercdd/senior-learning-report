#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 在已有边的基础上还有建多少边才能让城镇之间互通
  其实就是按边建的并查集
  
 */

const int N=1e3+5;
const int M=1e4+5;

int fa[N];

int find(int x) {
	if(x==fa[x]) return x; // 本身就是这个集合的根节点
	else return fa[x]=find(fa[x]); // 路径压缩
}

void merge(int x,int y) {
	x=find(x);
	y=find(y);
	if(x!=y) fa[x]=y; // 把y变成x的根节点
}

int n,m;

int main() {
	cin>>n>>m;
	// 并查集初始化
	for(int i=1;i<=n;i++) {
		fa[i]=i;	
	}
	while(m--) {
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
	// 计算连通块的个数
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(fa[i]==i) cnt++;
 	}
	// 将cnt个连通块连接起来还需要cnt-1条边
	cout<<cnt-1;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
