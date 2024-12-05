#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 一眼考的最小连通子图的最小总距离→最小生成树
  但是记不住板子啊啊啊 当复习了, 然后这道题没有边权 要手动计算
  这道题没有具体的边, 最大边数为n-1, 严格意义上说是稀疏图
  所以是Kruskal, 然后需要用一个邻接表去存到其他点的距离, 带排序
  
 */

const int N=1e3+5;
const int M=N*N; // 无向图

int n,a[N]; 

struct village {
	int x;
	int y;
	int h;
}vil[N];

struct edge {
	int a;
	int b;
	double val;
}e[M]; // 转换成边

// 边权小在前
bool cmp(edge a,edge b) {
	return a.val<b.val;
}

int fa[N]; // fa[i]: 顶点i的连通分量

double ans; // 最终最小距离

int idx; // 建边

// 找结点x的父节点
int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]); // 路径压缩
}

bool kruskal() {
	int cnt=0;
	// 取出每一条边
	for(int i=1;i<=idx;i++) {
		int a=e[i].a, b=e[i].b;
		double w=e[i].val;
		// 如果a和b已经相连, 跳过
		if(find(a)==find(b)) continue;
		// 输出一下这条边
//		cout<<a<<"--"<<b<<endl;
		// 选择这条边后的信息维护
		fa[find(a)]=find(b);
		ans+=w;
		cnt++;
	}
	if(cnt==n-1) return true; // 能找到tree
	return false;
}

// 计算村庄x和y之间的距离
double get_dis(int a, int b) {
	return sqrt(pow(vil[a].x - vil[b].x, 2) + pow(vil[a].y - vil[b].y, 2)) + pow(vil[a].h - vil[b].h, 2);
}
int main() {
	cin>>n;
	// 初始化并查集
	for(int i=1;i<=n;i++) {
		fa[i]=i;	
	}
	for(int i=1;i<=n;i++) {
		int x,y,h;
		cin>>x>>y>>h;	
		vil[i]={x,y,h};
	}
	// 计算两两村庄之间的距离
	for(int i=1;i<=n-1;i++) {
		for(int j=i+1;j<=n;j++) {
			double dis=get_dis(i,j);
			// 终究要转换成边才能套用最小生成树的模板啊
			e[++idx]={i,j,dis};
//			e[++idx]={j,i,dis};
		}	
	}
	// 对e排序
	sort(e+1,e+1+idx,cmp);
	// 输出边距
//	for(int i=1;i<=idx;i++) cout<<e[i].a<<' '<<e[i].b<<' '<<e[i].val<<'\n';
//	puts("");
	if(kruskal()) printf("%.2lf",ans);
	else cout<<"orz";
	return 0;
}

/*
  输入样例:
  4
  1 1 3
  9 9 7
  8 8 6
  4 5 4
  输出样例:
  17.41
 */
