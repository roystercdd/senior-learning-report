---
title: 背包DP
date: 2024-11-07 20:52:22
categories: 学习
tags:
    - 算法竞赛
    - 动态规划
    - 背包DP
---

<meta name="referrer" content="no-referrer" />

# 背包DP

<!-- toc -->

<!-- more -->



## 1. 01背包

### 1.1. 二维数组

> 时间复杂度：$O(n^2)$，空间复杂度：$O(n^2)$

* 非常熟悉和基础，没什么可讲的

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
const int M=1e3+5;

int n,m;
int v[N],w[N];
int f[N][M];

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&v[i],&w[i]); // v:重量,w:价值
	}
	// 枚举物品
	for(int i=1;i<=n;i++) {
		// 枚举背包容量
		for(int j=0;j<=m;j++) {
			f[i][j]=f[i-1][j];
			// 如果能拿物品i
			if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]); // v:体积,w:价值
		}	
	}
	int res=0;
	// 当取n个物品时最大总价值,其实也就是f[n][m]
	for(int i=0;i<=m;i++) res=max(res,f[n][i]);
	cout<<res<<endl;
	cout<<f[n][m]<<endl;
	return 0;
}
```



### 1.2. 一维数组

> 时间复杂度：$O(n^2)$，空间复杂度：$O(n)$

* 因为 $f[i][j]$ 只与 $f[i-1][j]$ 、$f[i-1][j-v[i]]+w[i]$ 有关，即只与上一个状态（上一次选择）有关，那么我们只需要开一个一维数组记录上一次选择即可，这个数组名为滚动数组
* 由于滚动数组已经表示了上一次选择的状态，所以代码 $f[i][j]=f[i-1][j]$ 可以去掉
* 枚举背包体积时必须从大到小，原因已经在代码中解释，如果还是 $for(int\ j=0;j<=m;j++)$ ，那么用到的实际上还是 $f[i]$ 这个状态而不是 $f[i-1]$ 这个状态
* 如果把所有的 $f[i]$ 都初始化为 $0$，那么 $f[m]$ 表示的是当背包体积 $<=m$ 时的最大价值是多少；如果只把 $f[0]$ 初始化为 $0$ ，而其他初始化为 $-INF$，那么 $f[m]$ 表示的是体积刚好等于 $m$ 时的最大价值，所以全部初始化为 $0$ 的话 $f[m]$ 就是答案

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5; // 最大物品数
const int M=1e3+5; // 最大容量
int n,m;
int f[M]; // f[i]:物品容量为i时的背包最大容量
int v[N],w[N];

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&v[i],&w[i]);	
	}
	for(int i=1;i<=n;i++) {
		// 因为f[i][j]只与f[i-1][j]/f[i-1][j-v[i]]+w[i],只与上一个状态有关
		// 所以二维数组中有很多空间被浪费,计算完就可以丢掉了
		// 所以用滚动数组,但是在枚举背包体积的时候必须从大到小排序,若顺序的话再用到上一个状态时就已经被更新过了
		for(int j=m;j>=v[i];j--) 
			f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
	int res=0;
	for(int i=0;i<=m;i++) res=max(res,f[i]);
	cout<<res<<endl;
	cout<<f[m]<<endl;
	return 0;
}
```



## 2. 完全背包

### 2.1. 朴素做法

> 时间复杂度：$O(n^3)$，空间复杂度：$O(n^2)$

* 时间复杂度和空间复杂度都较高，手动枚举每个物品可选择数量

``` c++
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
const int M=1e3+5;
int f[N][M];
int n,m;
int v[N],w[N];

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&v[i],&w[i]);
	}
	// 朴素做法,枚举物品
	for(int i=1;i<=n;i++) {
		// 枚举背包容量
		for(int j=0;j<=m;j++) {
			// 枚举物品可挑选数量
			for(int k=0;k*v[i]<=j;k++) {
				f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
			}
		}	
	}
	cout<<f[n][m]<<endl;
	return 0;
}
```



### 2.2. 公式优化

> 时间复杂度：$O(n^2)$，空间复杂度：$O(n)$

* $f[i,j]=max(f[i-1,j],f[i-1,j-v]+w,\ f[i-1,j-2v]+2w,\ f[i-1,j-3v]+3v,\ ...)$，①$f[i,j-v]=max(f[i-1,j-v],f[i-1,j-2v]+w,\ f[i-1,j-3v]+2w,\ f[i-1,j-4v]+3w,\ ...)$②，
* 可以看出②式是①式第二项起 $+w$ 的结果，所以 $f[i,j]=max(f[i-1,j],\ f[i,j-v]+w)$，即转移时与上一个状态无关，所以我们就可以顺序枚举物品容量

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
const int M=1e3+5;
int n,m;
int v[N],w[N];
int f[N][M];

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&v[i],&w[i]);	
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			f[i][j]=f[i-1][j];
			// 至少能装下一个
			if(j>=v[i]) f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]); // 和01背包的区别就在于可以与当前状态有关
		}	
	}
	cout<<f[n][m]<<endl;
	return 0;
}
```



### 2.3. 再优化一维数组

> 时间复杂度：$O(n^2)$，空间复杂度：$O(n)$

* 注意注释中是如何分析当 $f$ 数组是一维时状态转移的是当前状态还是上一次的状态
* 因为滚动数组本身代表上一次的状态，所以 $f[i,j]=f[i-1,j]$ 直接优化成 $f[j]=f[j]$，无意义，所以不用写

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
const int M=1e3+5;
int n,m;
int v[N],w[N];
int f[M];

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&v[i],&w[i]);	
	}
	for(int i=1;i<=n;i++) {
		// f[i][j]=f[i-1][j]直接删掉一维,即f[j]=f[j](一维滚动数组直接代表上一次的状态,所以不需要这句代码)
		// j是从小到大枚举的
		for(int j=v[i];j<=m;j++) {
			// j-v[i]是<j的,所以算f[j]的时候f[j-v[i]]已经被算过了,所以是第i层的f[i][j-v[i]]
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}	
	}
	cout<<f[m]<<endl;
	return 0;
}
```



## 3. 多重背包

### 3.1. 朴素做法

> 时间复杂度：$O(n^3)$，空间复杂度：$O(n^2)$

* 类似于完全背包的朴素做法，直接第三层去枚举物品的个数，不过多了一个限制条件，$k<=s[i]$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e2+5;
const int M=1e2+5;
int n,m;
int v[N],w[N],s[N];
int f[N][M];

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&v[i],&w[i],&s[i]);	
	}
	// 枚举物品
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			// 能拿的个数从0~s[i],且k*v[i]能被背包装下
			for(int k=0;k<=s[i] && k*v[i]<=j;k++) {
				f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
			}
		}	
	}
	cout<<f[n][m]<<endl;
	return 0;
}
```



### 3.2. 二进制优化

> 时间复杂度：$O(n^2log^n)$，空间复杂度：$O(n)$

* 如果按照类似于完全背包从状态转移方程式入手的角度来优化是不可行的，因为完全背包问题不会多最后一项出来，多了一个 $if$ 的判定条件，最后一项会因为超出了 $j$ 而被舍去

* 如何优化呢？若 $s=1023$，那么 $1023$ 能由其 $sum(2^n)<=1023$ 的这 $n$ 个 $2$ 的指数组成（$n=9$），把 $1023$ 个物品当作是 $1023$ 次 $01$ 背包，再通过二进制优化的方式把从枚举 $1023$ 次转换为只需要枚举 $9$ 次（倍增法思想）
* 比如 $s=200$，$\sum_{i=1}^n\ 2^i<=200$ 可得 $\{1,\ 2,\ 4,\ 8,\ 16,\ 32,\ 64\}$，这几个数字之和为 $127$，则只需要再来一个 $73$ 就可以凑出 $[0,200]$ 的数字；即对于任意一个 $s$ ，我们可以凑成 $\{1,\ 2,\ 4,\ 8,\ ...,\ 2^k,\ c\}$，其中 $c<2^{k+1}$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=2e4+5; // 1000*log(2000),2w4左右
const int M=2e3+5;
int n,m;
int v[N],w[N];
int f[N];

int main() {
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		int a,b,s;
		scanf("%d%d%d",&a,&b,&s);
		int k=1; // 从2^0开始,每组初始物品数
		while(k<=s) {
			// 每次把k个第i个物品打包在一起
			cnt++; // 编号++
			v[cnt]=a*k;
			w[cnt]=b*k;
			s-=k;
			k*=2;
		}
		// 补常数
		if(s>0) {
			cnt++; // 第i个物品的最后一次分组
			v[cnt]=a*s;
			w[cnt]=b*s;
		}
	}
	n=cnt; // 物品个数变成总的打包数
	for(int i=1;i<=n;i++) {
		// 至少能拿一个物品,所以j>=v[i]
		// 从大到小枚举
		for(int j=m;j>=v[i];j--) {
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}	
	}
	cout<<f[m]<<endl;
	return 0;
}
```



### 3.3. 单调队列优化

* 看不懂，溜了溜了



## 4. 混合背包	

> 时间复杂度：$O(n^2log^2)$，空间复杂度：$O(n)$

* 关键点在于将多重背包二进制优化后变成 $01$背包和 $01$背包一起处理，完全背包单独处理，其实就是混合考了几种背包的处理方式

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 三种物品三种放法,运用每组问题的解题思路即可

const int N=1e3+5;

int n,m;
int f[N];

struct Thing {
	int kind; // 01?完全?多重?
	int v,w;
};
vector<Thing> things;

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		int v,w,s;
		scanf("%d%d%d",&v,&w,&s);
		// 01背包问题
		if(s<0) things.push_back({-1,v,w});
		// 完全背包问题
		else if(s==0) things.push_back({0,v,w});
		// 多重背包问题
		else {
			for(int k=1;k<=s;k*=2) {
				s-=k;
				things.push_back({-1,v*k,w*k}); // 转换成01背包
			}
			if(s>0) things.push_back({-1,v*s,w*s});
		}
	}
		
	// 处理所有thing
	for(auto item:things) {
		// 01背包/多重背包的处理→
		if(item.kind<0) {
			for(int j=m;j>=item.v;j--) {
				f[j]=max(f[j],f[j-item.v]+item.w);
			}
		}
		// 完全背包的处理→
		else {
			for(int j=item.v;j<=m;j++) {
				f[j]=max(f[j],f[j-item.v]+item.w);
			}
		}
	}
	cout<<f[m]<<endl;
	return 0;
}
```



## 5. 二维费用背包

> 时间复杂度：$O(n^3)$，空间复杂度：$O(n^2)$

* 除了体积限制外加入了重量限制，处理方法和 $01$背包完全类似，只不过多了一重循环，和一维空间

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
const int V=1e2+5; // 最大体积
const int M=1e2+5; // 最大载重
int n,v,m;
int f[V][M]; // 体积是i重量是j的最大价值

int main() {
	cin>>n>>v>>m;
	for(int i=1;i<=n;i++) {
		// 边输入边处理
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int j=v;j>=a;j--) {
			for(int k=m;k>=b;k--) {
				f[j][k]=max(f[j][k],f[j-a][k-b]+c);
			}
		}
	}
	cout<<f[v][m]<<endl;
	return 0;
}
```



## 6. 带依赖的背包

> 时间复杂度：$O(n^3)$，空间复杂度：$O(n)$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 选子物品前必须要选父物品

const int N=1e2+5;
int n,m;
int h[N],e[N],ne[N],idx;
int v[N],w[N];
int f[N][N]; // f[i][j]:在选节点j的情况下总体积<=j,以i为根的子树的最大总收益是多少?

// 每个子节点是一个物品组,每个组里面只能选一个,就变成了分组背包问题

void add(int a,int b) {
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dfs(int u) {
	// 循环物品组
	for(int i=h[u];i!=-1;i=ne[i]) {
		int son=e[i]; 
		dfs(son);
		// 枚举背包容量,因为一定要选择根节点
		// 所以j-v[u],01背包从大到小枚举
		for(int j=m-v[u];j>=0;j--) {
			// 枚举决策,这个组里面选哪个
			// 枚举这个子节点用哪个体积
			for(int k=0;k<=j;k++) {
				f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
			}
		}
	}
	// 如果体积大于等于当前物品体积,把之前空出来的位置把物品价值加进去
	for(int i=m;i>=v[u];i--) f[u][i]=f[u][i-v[u]]+w[u];
	// 如果体积小于当前物品体积,整棵子树一个点都不能选
	for(int i=0;i<v[u];i++) f[u][i]=0;
}

int main() {
	memset(h,-1,sizeof h);
	cin>>n>>m;
	int root;
	for(int i=1;i<=n;i++) {
		int p;
		scanf("%d%d%d",&v[i],&w[i],&p); // p表示依赖关系
		if(p==-1) root=i; // -1表示根节点
		else add(p,i);
	}
	dfs(root);
	cout<<f[root][m]<<endl; // 根节点为root背包最大容量为m的最大价值
	return 0;
}
```



## 7. 背包求方案数

> 时间复杂度：$O(n^2)$，空间复杂度：$O(n)$

* 在 $01$ 背包的基础上要求求出能得到最大价值的方案数共有多少种
* 若初始化 $f[1]$ 到 $f[m]$，那么 $f[j]$ 代表的是背包容量不超过 $j$ 时所得最大价值，为了便于统计，我们想让 $f[j]$ 表示背包容量恰为 $j$ 时的最大价值，所以需要把 $f[1]$ 到 $f[m]$ 初始化为 $-INF$
* 因为最优解不一定在 $f[m]$ 空间不一定用完，所以还需要枚举出最大价值，再把最大价值对应的方案数累加起来，才是最终结果

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 求最大价值的选法有多少种
// 为了便于统计,我们要让物理意义变为背包容量恰为j时的最大价值
// 所以要初始化为负无穷

const int N=1e3+5;
const int mod=1e9+7; // 答案很大
const int INF=1e6;

int n,m;
int f[N],g[N];

int main() {
	cin>>n>>m;
	g[0]=1; // 初始化,背包容量为0时方案数是1
	// 背包容量为[1,m]时最大价值初始化为-INF
	for(int i=1;i<=m;i++) {
		f[i]=-INF;
	}
	for(int i=0;i<n;i++) {
		int v,w;
		cin>>v>>w;
		for(int j=m;j>=v;j--) {
			// 选与不选的最大值
			int t=max(f[j],f[j-v]+w);
			int s=0;
			// 看哪种方案更优,把其方案数拿过来
			// 因为有可能f[j]=f[j-v]+w,即从两个状态转移过来都可以
			// 所以写两个并列的if,可以都加
			if(t==f[j]) s+=g[j];
			if(t==f[j-v]+w) s+=g[j-v];
			if(s>=mod) s-=mod; // 手动取模
			f[j]=t;
			g[j]=s;
		}
	}
	int maxw=0;
	// 求最优解,最优解不一定是m,因为物理意义变了
	for(int i=0;i<=m;i++) maxw=max(maxw,f[i]);
	int res=0;
	// 求总的方案数
	for(int i=0;i<=m;i++) {
		if(maxw==f[i]) {
			res+=g[i];
			if(res>=mod) res-=mod;
		}
	}
	cout<<res<<endl;
	return 0;
}
```



## 8. 背包求具体方案

> 时间复杂度：$O(n^2)$，空间复杂度：$O(n^2)$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 要求输出字典序最小的一种选法(123<31)按位比
// 看f[n][m]是从哪个状态转移过来的,若为f[n-1][m](没选),若为f[n-1][m-v[i]]+w[i](选了)
// 贪心求,如果能选第一个物品,那么必须选第一个物品,这样字典序是最小的,前面的物品能选则选
// 从后往前推,求方案从前往后推

const int N=1e3+5;
int n,m;
int v[N],w[N],f[N][N]; // 前i个物品中背包容量不超过j的方案

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&v[i],&w[i]);	
	}
	// 从后往前推,这样求出来的方案才是字典序最小的
	for(int i=n;i>=1;i--) {
		// 二维
		for(int j=0;j<=m;j++) {
			f[i][j]=f[i+1][j];
			if(j>=v[i]) {
				f[i][j]=max(f[i][j],f[i+1][j-v[i]]+w[i]);
			}
		}
	}
	int i=1,j=m; // 从后往前推,最大值是f[1][m]
	// 从前往后推最大值
	while(i<=n) {
		if(j>=v[i] && f[i+1][j-v[i]]+w[i]>=f[i+1][j]) {
			cout<<i<<' ';
			j-=v[i];
			i++;
		} else {
			i++;
		}
	}
	return 0;
}
```
