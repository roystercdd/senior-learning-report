---
title: 树形DP
date: 2024-11-07 22:00:09
categories: 学习
tags:
    - 算法竞赛
    - 动态规划
    - 树形DP
---

<meta name="referrer" content="no-referrer" />

# 树形DP

<!-- toc -->

<!-- more -->



## 1. 树的重心

> 推荐学习视频：[E32 树形DP 树的重心_bilibili](https://www.bilibili.com/video/BV14K4y1f7Uf/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)，模拟过程从 $10:00$ 起

* 重心定义：指树中的一个结点，将这个点删除后剩余各个连通块中点数的最大值最小，那么这个结点就是树的重心
* 思路，任取一点 $u$，若以 $u$ 为重心，则分为两类
  * 一类是 $u$ 的子树，需要计算出 $u$ 的最大子树的节点数 $size$ 和以 $u$ 为根的子树的结点数 $sum$
  * 另一类是 $u$ 上面的部分，直接通过 $n-sum$ 得到
* 下面的子树部分在深搜回溯时完成，上方部分用做差的方法来计算，在深搜每个结点时，不断取每个结点 $size$ 和 $n-sum$ 中的最大值来更新结果

![image-20240415212508027](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240415212508027.png)

* 如上图中将结点 $6$ 作为树的重心，那么其左子树 $\{7,\ 8,\ 9\}$ 的结点个数为 $3$，其右子树 $\{3\}$ 结点个数为 $1$，则 $sum$ 为 $1+3+1(自身)=5$，其上方部分为 $\{1,\ 2,\ 4,\ 5\}$ 结点个数为 $4$，$ans=min(max(1,3),9-sum)=4$

``` c
#include<bits/stdc++.h>
#define x first
#define y second
		
using namespace std;
		
typedef long long ll;
typedef pair<int,int> PII;
		
// 解题思路: 
		
const int N=1e5+5;
int n,ans; // ans记录答案,也就是剩余各个连通块中点数的最大值
bool vis[N]; // 避免重复搜索,只能自上往下
int h[N],e[2*N],ne[2*N],idx; // 链式前向星邻接表
		
void add(int a,int b) {
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
		
// 以u为根的子树的节点数
int dfs(int u) {
	vis[u]=true;
	int size=0; // 记录u的最大子树的结点数
	int sum=1; // 记录以u为根的子树的结点数
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i]; // 取邻点
		if(vis[j]) continue; // 因为是无向图建边,避免往回走陷入死循环
		int s=dfs(j); // s是以j为根的子树的结点数
		// 入下回离,回时更新维护size和sum
		size=max(size,s); // 最大子树的结点数
		sum+=s; // 子树的结点总数
		cout<<"u="<<u<<", size="<<size<<", sum="<<sum<<endl;
	}
	// 当所有临边访问完后,也就是"离"开u结点的时候,更新答案
	ans=min(ans,max(size,n-sum)); // 最小最大值
	cout<<"u="<<u<<", size="<<size<<", sum="<<sum<<", ans="<<ans<<endl;
	return sum; // 返回以u为根的子树的结点个数
}
		
int main() {
	memset(h,-1,sizeof h);
	cin>>n;
	ans=n;
	// n结点共n-1条边
	for(int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	dfs(1); // 从任意结点开始深搜,不影响结果
	cout<<ans<<endl;
	return 0;
}
		
/*
9
1 4
1 2
2 6
2 5
6 3
6 7
7 9
7 8
*/
```



## 2. 树的直径

> 推荐学习视频：[E33 树形DP 树的直径_bilibili](https://www.bilibili.com/video/BV1ni4y157s3/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)，模拟过程从 $9:45$ 起

* 树的直径：即树的最长路径，在一棵树中使得路径两端点之间的距离最远，注意路径中可只包含一个点
* 思路，任取一点 $u$，从 $u$ 往下搜，返回时收集边权并记录两条路径
  * $d1$：从 $u$ 往下走的最长路径的长度
  * $d2$：从 $u$ 往下走的次长路径的长度
  * 那么 $d1+d2$ 代表的就是悬挂在结点 $u$ 上的最长路径的长度，用一个临时变量 $ans$ 维护最大路径长度即可，$ans=max(ans,d1+d2)$

![image-20240415224030562](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240415224030562.png)

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e4+5;
const int M=2*N;
int n,ans; // ans记录最长路径的长度
bool vis[N]; // 避免往下走
int h[N],e[M],ne[M],w[M],idx;

void add(int a,int b,int c) {
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}

// 返回从u点往下走的最大长度
int dfs(int u) {
	vis[u]=true;
	int d1=0; // 从u往下走的最大长度
	int d2=0; // 从u往下走的次大长度
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i]; // 取出邻接点
		if(vis[j]) continue; // 无向图双向建边,只能从上往下避免往回走
		int d=dfs(j)+w[i]; // 从u经j点向下走的最大长度
		// 如果d比最大长度还大,那么d变最大,最大变次大
		if(d>=d1) d2=d1,d1=d;
		// 如果d比次大大,那么d变次大
		else if(d>d2) d2=d;
		// 回的时候更新u的最大边和次大边
		cout<<"u="<<u<<", d1="<<d1<<", d2="<<d2<<endl;
	}
	// 入下回离,离的时候更新答案
	ans=max(ans,d1+d2);
	cout<<"u="<<u<<", d1="<<d1<<", d2="<<d2<<", ans="<<ans<<endl;
	return d1; // 返回从u往下走的最大长度,先有最大边,再遍历其他边,从而找新最大和次大
}

int main() {
	memset(h,-1,sizeof h);
	cin>>n;
	// n点 n-1边
	for(int i=1;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1); // 任选一点开始深搜结果相等
	cout<<ans<<endl;
	return 0;
}

/*
6
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
 */
```



## 3. 树的中心

> 推荐学习视频：[E34 树形DP 树的中心_bilibili](https://www.bilibili.com/video/BV1FT4y1M7R6/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)，模拟过程从 $14:20$ 起

* 树的中心：到树中其他点的最远距离最近

* 思路，若以每个点为根，分别求出从根向下走的最远距离，然后循环 $n$ 个点，求出各点最远距离的最小值，这样相当于 $n$ 遍 $dfs$，时间复杂度 $O(n^2)$ 会超时，该思路可以由两遍 $dfs$ 代替

* 从 $u$ 到其他结点的最远距离可以分为两类
  * 从 $u$ 点向下走的最远距离，用 $d1[u]$ 表示，自下而上递推，由子结点信息更新父结点信息，在返回时实现，属于入下回离中的回，即在 $dfs$ 之后实现
    * 从 $u$ 向下走的最大长度：$d1[u]=d1[j]=w[i]$
    * 从 $u$ 向下走的次长长度：$d2[u]=d2[j]+w[i]$
  * 从 $u$ 点向上走的最远距离，用 $up[u]$ 表示，自上而下递推，由父结点信息更新子结点信息，在下行时实现，属于入下回离中的下，即在 $dfs$ 之前实现
    * 如果 $j$ 在从 $u$ 向下走的最长路径上，$up[j]=w[i]+max(up[u],d2[u])$，即当前边权 $+$ 次长边
    * 如果 $j$ 不在从 $u$ 向下走的最长路径上，$up[j]=w[i]+max(up[u],d1[u])$，即当前边权 $+$ 最长边



### 3.1. 第一次深搜 dfs_d（down）

* 子结点更新父结点，向上传递，故“回” 时传递信息

``` c
// 第一遍dfs
// 维护u向下走的最远距离d1[u]和次大距离d2[u]
// 维护从u向下走的最长路径是从哪个点下去的,即可在第二遍dfs中判断结点是否在最长路径上
// u:当前访问结点,fa:父结点,代替vis数组避免往回走的情况,其实就是树的直径升级版
int dfs_d(int u,int fa) {
	// 最长与次长初始化为0
	d1[u]=0;
	d2[u]=0;
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i]; // 取出邻接点
		if(j==fa) continue; // 避免向上查找
		int d=dfs_d(j,u)+w[i]; // 从u经j向下走的最长长度+边权
        // 为什么是d>=d1[u]?因为最长长度可能由多条,为了次大和最大长度不相等,每次遍历到≥d1[u]的边时直接覆盖
		if(d>=d1[u]) d2[u]=d1[u],d1[u]=d,p1[u]=j; // 最长路径是从j下去的
		else if(d>d2[u]) d2[u]=d;
	}
	// 离开结点时输出每个结点向下走的最大长度和次大长度
	printf("u=%d, d1[%d]=%d, d2[%d]=%d\n",u,u,d1[u],u,d2[u]);
	return d1[u]; // 返回向下走的最长长度
}
```



### 3.2. 第二次深搜 dfs_u（up）

* 父结点更新子结点，向下传递，故“下”时传递信息

``` c
// 维护每个结点向上走的最大长度
void dfs_u(int u,int fa) {
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i];
		if(j==fa) continue;
		// 如果j在u往下走的最大路径上,用次大边更新
		if(p1[u]==j) up[j]=max(up[u],d2[u])+w[i];
		// 下行传递信息
		// 如果j不在y往下走的最大路径上,用最大边更新
		else up[j]=max(up[u],d1[u])+w[i];
		printf("u=%d, up[%d]=%d, up[%d]=%d\n",u,j,up[j],u,up[u]);
		dfs_u(j,u); // 深搜u的子结点j
	}
}
```

![image-20240416102410939](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240416102410939.png)

* 如上图树结构在第一次 $dfs$ 结束后得到每个结点向下走的最大长度和次长长度如每个结点下方的第一关键字和第二关键字所示
* 现进行第二次 $dfs$，因为是向下传递，所以我们只看入下回离中的“下”
  * 先经过结点 $5$，由于 $5$ 不在其父结点 $1$ 的最长路径上，所以 $up[5]=d1[1]+w[i]=3+1=4$（$1$ 向下走的最长长度 $+$ 边权）
  * 再经过结点 $2$，由于 $2$ 在父结点 $1$ 的最长路径上，所以 $up[2]=d2[1]+w[i]=1+1=2$（$1$ 向下走的次大长度 $+$ 边权）
  * 再经过结点 $3$，由于 $3$ 在父结点 $2$ 的最长路径上，所以 $up[3]=max(up[2],d2[2])+w[i]=max(2,0)+1=3$（父结点 $2$ 向上走的最大距离或者向下走的次大距离中的最大值，即 $\{2→\ 1→\ 5\}$ 这条路 $+$ $\{2→3\}$的边权）
  * 最后经过结点 $4$，由于 $4$ 在父结点 $3$ 的最长路径上，所以 $up[4]=max(up[3],d2[3])+w[i]=max(3,0)+1=4$

* 最终输入完整的模拟结果如下：

![image-20240416104618207](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240416104618207.png)

* 完整代码如下：

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;
const int M=2*N;

// 链式前向星
int h[N];
int e[M];
int ne[M];
int w[M];
int idx;

void add(int a,int b,int c) {
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}

int d1[N]; // 存储从u点向下走的最大长度
int d2[N]; // 存储从u点向下走的次大长度
int p1[N]; // 记录从u点向下走的最长路径是从哪个点下去的
int up[N]; // 记录从u点向上走的最大路径长度

// 第一遍dfs
// 维护u向下走的最远距离d1[u]和次大距离d2[u]
// 维护从u向下走的最长路径是从哪个点下去的,即可在第二遍dfs中判断结点是否在最长路径上
// u:当前访问结点,fa:父结点,代替vis数组避免往回走的情况,其实就是树的直径升级版
int dfs_d(int u,int fa) {
	// 最长与次长初始化为0
	d1[u]=0;
	d2[u]=0;
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i]; // 取出邻接点
		if(j==fa) continue; // 避免向上查找
		int d=dfs_d(j,u)+w[i]; // 从u经j向下走的最长长度+边权
		if(d>=d1[u]) d2[u]=d1[u],d1[u]=d,p1[u]=j; // 最长路径是从j下去的
		else if(d>d2[u]) d2[u]=d;
	}
	// 离开结点时输出每个结点向下走的最大长度和次大长度
	printf("u=%d, d1[%d]=%d, d2[%d]=%d\n",u,u,d1[u],u,d2[u]);
	return d1[u]; // 返回向下走的最长长度
}

// 维护每个结点向上走的最大长度
void dfs_u(int u,int fa) {
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i];
		if(j==fa) continue;
		// 如果j在u往下走的最大路径上,用次大边更新
		if(p1[u]==j) up[j]=max(up[u],d2[u])+w[i];
		// 下行传递信息
		// 如果j不在y往下走的最大路径上,用最大边更新
		else up[j]=max(up[u],d1[u])+w[i];
		printf("u=%d, up[%d]=%d, up[%d]=%d\n",u,j,up[j],u,up[u]);
		dfs_u(j,u); // 深搜u的子结点j
	}
}

int n;

int main() {
	memset(h,-1,sizeof h);
	cin>>n;
	// n顶点 n-1条边
	for(int i=1;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);
	}
	// 深搜入口父结点定义为-1,因为编号为-1的点根本不存在,根节点无父结点,相当于把1作为根节点的意思
	dfs_d(1,-1); // 第一次深搜 
	dfs_u(1,-1); // 第二次深搜
	int res=INT_MAX;
	// 对每个结点
	// (往上走距离的最大值,往下走距离的最大值)的最大值即结点i到树中其他结点的最大距离
	// 对每个结点的最大值取最小值
	for(int i=1;i<=n;i++) {
		res=min(res,max(up[i],d1[i]));
	}
	cout<<res<<endl; // 输出到中心到其他结点的最大距离
	return 0;
}

/*
5
2 1 1
3 2 1
4 3 1
5 1 1
*/
```



## 4. 例题

### 4.1. 没有上司的舞会

> 推荐学习视频：[E17 树形DP Luogu P1352 没有上司的舞会 bilibili](https://www.bilibili.com/video/BV1eK411N7Ly/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)，模拟过程从 $6:50$ 开始

* 先从根到叶一路深搜，再从叶到根做后
* 序 $DP$，每次用子树的 $f$ 值更新当前结点的 $f$ 值，兜了一圈回到根节点，根节点的 $f$ 值就是全局最优解

![image-20240421234506971](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240421234506971.png)
