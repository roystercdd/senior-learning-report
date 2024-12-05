---
title: 区间DP
date: 2024-11-07 21:17:37
categories: 学习
tags:
    - 算法竞赛
    - 动态规划
    - 区间DP
---

<meta name="referrer" content="no-referrer" />

# 区间DP

<!-- toc -->

<!-- more -->



## 1. 石子合并

> 题目链接：[P1775 石子合并（弱化版） - 洛谷 ](https://www.luogu.com.cn/problem/P1775)，推荐学习视频：[E28【模板】区间DP 石子合并_bilibili](https://www.bilibili.com/video/BV1gz4y1y7Rv/?spm_id_from=333.999.0.0)

* 如果石子可以不相邻，那么很显然是一个哈夫曼树，直接贪心即可，但是石子必须相邻取，情况太多了我们无法预知哪种取法是最优的
* 区间 $dp$ 的思想也很简单，第一层枚举区间长度，第二层枚举区间起点，区间起点和区间长度共同决定了区间终点，第三层枚举的是分割点，分割点的取值是 $[区间起点，区间终点]$，以空间换时间动态求得最小值，如果要求最大值只需要把 $min$ 改为 $max$ 即可，注意如果要求最小值则初始化 $f$ 数组为极大值，再对边界赋初始值

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 如果可以不相邻,那么贪心就是哈夫曼树

const int N=3e2+5;
int n;
int a[N];
int s[N]; // 前缀和数组
int f[N][N]; // f[l,r]:把l到r合并成一堆的最小代价

int main() {
	cin>>n;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
		s[i]=s[i-1]+a[i]; // 便于求解合并的区间和
		f[i][i]=0; // 合并自身初值为0
	}
	// 区间DP
	// 1) 枚举区间长度
	for(int len=2;len<=n;len++) {
		// 2) 枚举区间起点
		for(int l=1;l+len-1<=n;l++) {
			int r=l+len-1; // 区间终点
			// 3) 枚举分割点
			for(int k=l;k<r;k++) {
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
```



## 2. 环形石子合并

> 题目链接：[P1880 [NOI1995] 石子合并 - 洛谷 ](https://www.luogu.com.cn/problem/P1880)，推荐学习视频：[E29 区间DP 环形石子合并_bilibili](https://www.bilibili.com/video/BV1oK4y1j7W3/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)

* 和上一题比起来只改变了一个条件，那就是石子是环形摆放的，比如 $\{4,\ 5,\ 9,\ 4\}$ 队列首尾两个 $4$ 是相邻的，上一题是链式石子合并

* 基础思路：我们可以在环形石子中定义一个缺口，如按照下图的模式划分，则会将环形石子变成一个链式石子，就可以用上一个模板，我们额外添加一层循环来枚举这个缺口，当有 $n$ 个石子的时候可以枚举的缺口数是 $n$ 个，再从每种方案中枚举求到最大值，这样能做，但是时间复杂度上升为 $O(n^4)$，显然会 $TLE$

![image-20240426095023268](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426095023268.png)

``` c
// 1) 枚举缺口
for(int i=1;i<=n;i++) {
    // 2) 枚举区间长度
	for(int len=2;len<=n;len++) {
		// 3) 枚举区间起点
		for(int l=1;l+len-1<=n;l++) {
			int r=l+len-1; // 区间终点
			// 4) 枚举分割点
			for(int k=l;k<r;k++) {
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
}
```

* 所以不妨换一个做法，如果我们把数组复制一份使长度变为 $2n$，就可以在不改变时间复杂度的情况下模拟得到相同的效果，将 $\{4,\ 5,\ 9,\ 4\}$ 复制为 $\{4,\ 5,\ 9,\ 4,\ 4,\ 5,\ 9,\ 4\}$，区间长度依然从 $2$ 枚举到 $4$，区间左端点从 $1$ 到 $4$，即可得到长链 $\{4,\ 5,\ 9,\ 4\}$、$\{5,\ 9,\ 4,\ 4\}$、$\{9,\ 4,\ 4,\ 5\}$、$\{4,\ 4,\ 5,\ 9\}$，限制右端点 $l+len-1<=2n$，即可在上一个模板中仅改变区间左端点的枚举范围解出环形石子 $DP$ 问题的答案
* 注意最大值需要从 $f[1][n],\ f[2][n+1],\ ...\ ,f[n][2×n-1]$ 中枚举打擂得到，因为有这么多条链

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 
// 环形→链型
// 对于环形,我们从任意一个石子后对其切割得到链型,此时就能用链式区间DP,不过枚举缺口需要O(n),总时间复杂度是O(n^4)
// 所以将链型再复制一份,比如 1 4 2 5 3 变成 1 4 2 5 3 1 4 2 5 3, 

const int N=2*(2e2+10);
int a[N]; // 每堆石子数量
int s[N]; // 前缀和数组
int f[N][N]; // 环形石子DP最小值
int g[N][N]; // 环形石子DP最大值
int n;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		// 复制一边区间
		a[i+n]=a[i];
	}
	memset(f,0x3f,sizeof f); // 找最大
	memset(g,-0x3f,sizeof g); // 找最小
	// 预处理
	for(int i=1;i<=2*n;i++) {
		s[i]=s[i-1]+a[i];
		g[i][i]=0,f[i][i]=0;
	}
	// 状态计算(除了区间左端点,其他都不变)
	for(int len=2;len<=n;len++) {
		// 区间起点枚举范围扩展到2n
		for(int l=1;l+len-1<=2*n;l++) {
			int r=l+len-1;
			for(int k=l;k<r;k++) {
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
				g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	// 目标输出
	int minv=INT_MAX,maxv=INT_MIN;
	// 必须枚举每一种状态,直接输出f[1][n]的不是最大值因为不连续
	// 计算的时候是 f[1][n],f[2][n+1],...,f[n][2*n-1]这样来算的
	for(int i=1;i<=n;i++) {
		minv=min(minv,f[i][i+n-1]); // f[1,n],f[2,n+1],...,f[n,2*n-1]
		maxv=max(maxv,g[i][i+n-1]);
	}
	cout<<minv<<endl<<maxv<<endl;
	return 0;
}
```



## 3. 能量项链

> 题目链接：[P1063 [NOIP2006 提高组] 能量项链 - 洛谷 ](https://www.luogu.com.cn/problem/P1063)，推荐学习视频：[E30 区间DP 能量项链_bilibili](https://www.bilibili.com/video/BV19t4y1a7xF/?spm_id_from=333.999.0.0)

* 题目非常长，从样例入手，$4$ 颗珠子中，前一颗珠子的尾标记是下一颗石子的头标记，现在给出 $4$ 颗珠子的头标记为 $\{2,\ 3,\ 5,\ 10\}$，实则告诉我们 $4$ 颗珠子为 $(2,3),(3,5),(5,10),(10,2)$，要合并两颗珠子的代价类似于线代中的矩阵乘法，如合并 $1,2$ 两颗珠子释放的能量就是 $2×3×5=30$，现在题目要让我们找一种释放能量最大的方法，那么就和环形石子 $DP$ 是相当类似的
* 不过要用环形石子 $DP$ 模板之前我们还要讨论一下区间长度、区间左端点、分割点是否还相同？
* $n$ 颗珠子只需要合并 $n-1$ 次就能得到最终的一颗珠子，比如 $2×3×5$ 合并 $1,2$ 颗珠子后得到珠子 $(2,5),(5,10),(10,2)$ 此时释放的能量是 $30$，继续合并得到 $(2,10),(10,2)$ 此时释放的总能量是 $2×5×10+30=130$，继续合并得到 $(2,2)$ 此时释放总能量是 $2×10×2+130=170$，我们会发现 $2$ 这个数字在运算中用到了两次，所以我们区间 $DP$ 的数字是  $\{2,\ 3,\ 5,\ 10,\ 2\}$，即区间长度是 $n+1$
* 我们仍然对数组进行一次复制，左端点区间枚举范围是 $for(int\ l=1;l+len-1<=2×n;l++)$，$dp$ 数组 $f[l][r]$ 的状态转移方程是 $f[l][k]+f[k][r]+a[i]×a[k]×a[r]$，即先将 $[l,k]$ 的珠子合并，再把 $[k,r]$ 的珠子合并，最后将 $[l,r]$ 合并，为什么不是 $f[k+1][r]$ 呢？因为计算乘法的时候 $k$ 这个数字会被用到两次
* 同样的最后枚举得到最终结果，可以说这道题就是环形石子 $DP$ 的变形

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 聚会后释放的能量数有点像矩阵乘法,类似环形石子DP
// 若有 2 3 5 10,则有四颗珠子为(2,3),(3,5),(5,10),(10,2)
// 相邻两颗珠子合并后释放能量 2*3*5,并合并为(2,5),同样的复制为 2 3 5 10 2 3 5 10
// 模拟一下可知需要合并n+1次,所以len最大为n+1,右端点最多枚举到2*n,l<k<r
// k=2,表明珠子1~珠子2先合并,珠子3~珠子n先合并,最后合并这两个大珠子,用分治的思想来理解

const int N=2*(2e2+5);
int n;
int a[N]; // a[i]:第i颗珠子的头标记,第i-1颗珠子的尾标记(i>=2)
int f[N][N]; // f[l,r]:合并[l,r]得到的能量最大值

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i+n]=a[i]; // 环形石子DP复制一份
	}
	// 状态计算,注意len为n+1,模拟一遍就知道了
	for(int len=3;len<=n+1;len++) {
		for(int l=1;l+len-1<=2*n;l++) {
			int r=l+len-1;
			// 中间的数字会被用到两次,所以这里是f[l][k]和f[k][r]
			// 这道题里和自己合并是非法的
			for(int k=l+1;k<r;k++) {
				f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[k]*a[r]); // 合并代价i,j,k
			}
		}
	}
	// 枚举找最大值
	int res=INT_MIN;
	for(int i=1;i<=n;i++) {
		res=max(res,f[i][i+n]);
	}
	cout<<res<<endl;
	return 0;
}

/*
输入：
4
2 3 5 10
输出：
710
 */
```



## 4. 凸多边形的最优三角形划分

* 用两个不相邻的顶点之间组成的弦可以把一个凸多边形划分成两个多边形

![image-20240426142014884](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426142014884.png)

* 用多条弦就可以把一个凸多边形划分为互不相交的三角形，那么把多边形分割为互不相交的三角形的弦的集合，就叫做凸多边形的三角剖分
* 每一组弦的集合会把凸多边形切割成不同的三角形，这些三角形的周长之和就是我们的代价，那么能使这个代价最小的一组弦的集合，就是凸多边形的最优三角形划分
* 我们可以推导一下代价的计算公式，对于下面的两幅图，很容易看出，各个三角形的周长之和，其实就是每条 $蓝色的弦的长度 \ ×2 \ + 凸多边形的周长$

![image-20240426142114525](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426142114525.png)

* 初始化：因为最少三个点才能组成三角形，$len=3$ 时就是最底层最初始的状态，$f[1][3],k=2$ 实则就为顶点 $v1,v2,v3$ 构成的三角形的周长，当然这一步不用特地初始化，可以在区间 $DP$ 时直接计算作为底层状态了，真正的初始化是把 $len=1\ || \ len=2$ 时的各个状态下的 $f$ 定义为 $0$，因为此时根本无法构成三角形，所以第一层枚举区间长度的时候直接从 $len=3$ 开始
* 这个问题其实和分治法很类似，可以从最外层 $f[1][6]$ 来看，找到合适的分割点 $k=4$ 可以切割为 $f[1][4]$ 和 $[5][6]$，后者无法构成三角形在最初初始化的时候已然为 $0$，对于前者 $f[1][4]$ 在之前 $len=4$ 的时候已然被计算过了，他也有最佳切割点 $k=3$，那么又可以切割为 $f[1][3]$ 和 $f[3][4]$ 以此类推，**所以我们可以把区间 $DP$ 理解为分治法 $+$ 递推**

``` c
#include<bits/stdc++.h> 
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路:

const int N=1e3+5; // 最大顶点数
// 状态表示
int f[N][N]; // f[i][j]:从顶点vi~vj构成的多边形的最优三角剖分的最小值
int s[N][N]; // s[i][j]:满足f[i][j]最小的分割点k的值,即方案
int g[N][N]; // g[i][j]:邻接矩阵,记录vi到vj的距离
int n;

// 返回 vx,vy,vz 三个点构成的三角形的边长
int get_val(int x,int y,int z) {
	return g[x][y]+g[x][z]+g[y][z];
}

vector<int> v; // 保存点集

// 回溯求解出划分点集
void backtrack(int l,int r) {
	int k=s[l][r]; // 这一步的切割点
	if(k==0) return;
	if(l==r) return;
	// 若k=0了说明走到边界了
	// k>l+1为了只输出弦
	if(k>l+1) {
		cout<<l<<' '<<k<<endl;
	} 
	// k+1<r是为了只输出弦
	if(k+1<r) {
		cout<<k<<' '<<r<<endl;
	}
	backtrack(l,k);
	backtrack(k+1,r);
}


int main() {
	cin>>n;
	// 输入邻接矩阵
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin>>g[i][j];
		}
	}
	// 初始化
	for(int i=1;i<=n;i++) {
		f[i][i]=0;
//		f[i-1][i]=0;
		s[i][i]=0;
	}
	// 两个点的情况
	for(int i=1;i<=n-1;i++) {
		f[i][i+1]=0;
	}
	f[1][n]=0;
	// 区间dp
	// 1) 第一层枚举区间长度
//	int ans=INT_MAX; // 记录最终结果,最小的边权和
	for(int len=3;len<=n;len++) {
		// 2) 枚举左端点
		for(int l=1;l+len-1<=n;l++) {
			int r=l+len-1; // 区间长度和左端点决定右端点
			// 3) 枚举分割点
			f[l][r]=INT_MAX; // 这里设置为最大值,一旦找到更小值就可以对其进行替换
			s[l][r]=l+1;
			for(int k=l+1;k<r;k++) {
				// 区间dp第三步,
				int tmp=f[l][k]+f[k][r]+get_val(l,k,r);
				if(tmp<f[l][r]) {
					f[l][r]=tmp; // 更新为最小值
					s[l][r]=k; // 记录方案
				}
			}
		}
	}
	cout<<f[1][n]<<endl; // 从1~n中选出 v1,vn,以及一个点vk,此时最小的权值和
	
	// 最后选出点的集合是 v1, v4, v6, v3
	cout<<g[1][4]<<' '<<g[4][6]<<' '<<g[1][3]<<endl;
	cout<<(g[1][4]+g[4][6]+g[1][3])*2+g[1][2]+g[1][6]+g[2][3]+g[3][4]+g[4][5]+g[5][6]<<endl;
	cout<<f[1][4]+f[4][6]+get_val(1,4,6)<<endl;
	
	// 输出f数组
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	// 输出s策略数组
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<s[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	backtrack(1,n); // 找切割点集
	for(auto x:v) {
		cout<<x<<' ';
	}
	return 0;
}

/*
输入：
6
0 2 3 1 5 6
2 0 3 4 8 6
3 3 0 10 13 7
1 4 10 0 12 5
5 8 13 12 0 3
6 6 7 5 3 0
*/
```
