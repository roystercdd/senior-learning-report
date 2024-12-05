---
title: 线性DP
date: 2024-11-07 21:08:21
categories: 学习
tags:
    - 算法竞赛
    - 动态规划
    - 线性DP
---

<meta name="referrer" content="no-referrer" />

# 线性DP

<!-- toc -->

<!-- more -->



## 1. 数字三角形

### 1.1. 顺推

* 顺推比较需要注意的问题就是边界问题，因为从上往下推每个元素会用到上方元素和左上方元素
  * 对于某一行的最后一个元素，那么上方的元素是没有被初始化的
  * 对于某一行的第一个元素，那么左上方的元素是没有被初始化的
  * 为了保证这两种情况一定不选择未被初始化的元素，所以首先把 $f$ 数组初始化为 $-INF$
* 随后把 $f[1,1]$ 初始化为 $a[1,1]$，因为从第二行开始计算，这样计算出来的值就是正常值，最后从最后一行的出口中枚举找一个最大值

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=5e2+5;
const int INF=1e9;
int f[N][N];
int a[N][N];
int n;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			scanf("%d",&a[i][j]);
		}	
	}
	// 如果顺推,每个元素应该考虑上方和左上方元素
	// 如果当前计算元素的[i,j]刚好i==j即最后一个时,则上方无元素,会遇到边界问题
	// 为了一定不选择这个边界,可以把其初始化为-INF(因为三角形中数字可能有负值)
	// 别忘了左上角,所以ij均从0开始
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=i+1;j++) {
			f[i][j]=-INF;
		}
	}
	f[1][1]=a[1][1]; // 从a[1][1]开始算,边界依然为-INF
	// 从第二行开始
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			f[i][j]=max(f[i-1][j]+a[i][j],f[i-1][j-1]+a[i][j]);
		}	
	}
	int ans=INT_MIN;
	// 对出口求最大值,即为最大路径数字和
	for(int i=1;i<=n;i++) {
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
}
```



### 1.2. 逆推

* 从上往下有五个出口，最终要用 $O(n)$ 的时间来判断谁的值更大，如果从下往上那么出口只有一个，无需比较；并且从下往上逆推不会遇到边界问题，用到的每个元素都刚好有初始值，可以手动模拟一下为什么没有边界问题

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 经典数字三角形

const int N=5e2+5;
const int INF=1e9;
int n;
int a[N][N];

int main() {
	// 逆推,从下往上那么出口只有一个,注意元素只从下方和右下方来
	// 从下往上没有边界问题
	cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			scanf("%d",&a[i][j]);
		}	
	}
	// 从倒数第二行开始
	for(int i=n-1;i>=1;i--) {
		// 每一行的元素的个数应该就是i
		for(int j=1;j<=i;j++) {
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
		}
	}
	cout<<a[1][1]<<endl;
	return 0;
}
```

* 若需要输出路径，可以用 $b$ 数组 $memcpy$ 原二维数组，因为加和是直接在原数组上进行操作的，另外用 $p$ 表示前驱数组用来记录路径，在记录时只需要记录在列方向的偏移量即可，比如往右下则 $p[i,j]=1$，往下 $p[i,j]=0$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 经典数字三角形

const int N=5e2+5;
const int INF=1e9;
int n;
int a[N][N];

int p[N][N]; // 记录最大值路径
int b[N][N]; // 备份数组,路径跟踪

int main() {
	// 逆推,从下往上那么出口只有一个,注意元素只从下方和右下方来
	// 从下往上没有边界问题
	cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			scanf("%d",&a[i][j]);
		}	
	}
	// 拷贝
	memcpy(b,a,sizeof a); // 从a拷到b
	
	// 从倒数第二行开始
	for(int i=n-1;i>=1;i--) {
		// 每一行的元素的个数应该就是i
		for(int j=1;j<=i;j++) {
//			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
			if(a[i+1][j]>=a[i+1][j+1]) {
				a[i][j]+=a[i+1][j];
				p[i][j]=0; // 来自下方,y轴增量为0
			} else {
				a[i][j]+=a[i+1][j+1];
				p[i][j]=1; // 来自右下,y轴增量为1
			}
		}
	}
	cout<<a[1][1]<<endl;
	int i,j;
	// 输出最大数的路径(行数一直增大,列数根据存储的增量变化)
	for(i=1,j=1;i<=n-1;i++) {
		cout<<b[i][j]<<"->";
		j+=p[i][j];
	}
	cout<<b[n][j];
	return 0;
}
```



## 2. 最长上升子序列

### 2.1. 线性DP做法

> 时间复杂度：$O(n^2)$

* 如果不理解状态转移方程，可以 [E03 线性DP 最长上升子序列 bilibili](https://www.bilibili.com/video/BV1KK4y1e7t7/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1) $4:00$ 起看该问题的模拟过程

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;
int a[N];
int f[N]; // 以第i个元素结尾的LIS(最长上升子序列)长度
int n;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	int res=INT_MIN;
	for(int i=1;i<=n;i++) {
		f[i]=1; // 所有元素起码可以以自身结尾
		// 遍历i之前的元素,如果比i小则可以拼接
		for(int j=1;j<=i;j++) {
			// 不理解可以看视频中的模拟过程
			if(a[j]<a[i]) {
				f[i]=max(f[i],f[j]+1);
			}
		}
		res=max(res,f[i]);
	}
	cout<<res<<endl;
	return 0;
}
```



### 2.2. 二分优化

> 时间复杂度：$O(nlog^n)$，因为二分查找是 $O(log^n)$

* 模拟过程在 [E04 线性DP 最长上升子序列 二分优化 bilibili](https://www.bilibili.com/video/BV1Kp4y1e77H/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1) $6:15$ 起
* 唯一比较疑惑的地方在于，为什么是找到第一个大于等于 $a[i]$ 的元素做替换而不是大于呢？翻了一下评论区搞明白了，比如 $\{1\  2\  6\  7\  2\  3\}$ 的话，如果大于 $x$，那么序列中可能出现重复元素，最长上升子序列为 $1\ 2\ 2\ 3$，这样就不是严格单调递增的了

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;
int a[N];
int b[N]; // 有序子序列
int len;
int n;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	// 遍历a中每一个元素,构造有序子序列
	len=1;
	b[1]=a[1];
	// 1)如果a中元素大于b中最后一个元素,则添加到末尾
	// 2)如果a中元素小于等于b中最后一个元素,则在b数组中找到第一个大于等于a的元素进行替换
	// 比如a[i]替换掉b[j]后,b[j]变小,则b[1...j]的结尾元素更小,则更可能续其他元素,使ILS更大
	for(int i=2;i<=n;i++) {
		if(a[i]>b[len]) {
			b[++len]=a[i];
		} else {
			// 用二分找到第一个大于等于a[i]的元素(答案在左边,压缩右边界)
			int l=1,r=len;
			while(l<=r) {
				int mid=l+r>>1;
				if(b[mid]>=a[i]) {
					r=mid-1;
				} else {
					l=mid+1;
				}
			}
			// l是答案
			b[l]=a[i];
		}
	}
	// 最终len的长度就是答案
	cout<<len<<endl;
	return 0;
}
```



## 3. 最长公共子序列

* 为什么没有 a[i]≠b[j]，且 a[i], b[j] 都不在公共子序列的情况？其实可以把这种情况归为第 2, 3 种情况之一
* 为什么没有 a[i]≠b[j]，且 a[i], b[j] 都不在公共子序列的情况？其实可以把这种情况归为第 2, 3 种情况之一

![image-20240411143809881](E:\Typora\图片\image-20240411143809881.png)

* 一边 $dp$ 一边打标记记录状态转移，其中从左上方转移过来的元素即为 $LCS$ 中的公共元素

![image-20240411144744745](E:\Typora\图片\image-20240411144744745.png)



* 只要理解了状态转移方程，代码就很简单

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5; // 字符串最大长度
int f[N][N]; // f[i][j]:序列a[1...i]和b[1...j]的最长公共子序列的长度(LCS)
char a[N],b[N];
int n,m;

int main() {
	cin>>a+1>>b+1; // 从下标1开始存储
	n=strlen(a+1); // 起始位置是a+1
	m=strlen(b+1);
	// 初始化 f[0][j]=0,f[i][0]=0,即i和j中有未指向任意元素的指针存在时
    // 但是全局变量本身初始化为0,所以无需初始化
    // 枚举字符串a
	for(int i=1;i<=n;i++) {
        // 枚举字符串b
		for(int j=1;j<=m;j++) {
			if(a[i]==b[j]) {
				f[i][j]=f[i-1][j-1]+1;
			} else {
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
```

* 如果要带路径输出呢？同理，开一个数组 $p$ 用来记录取得 $LCS$ 的路径，注意，只有来自左上方的元素是 $LCS$ 中的元素

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5; // 字符串最大长度
int f[N][N]; // f[i][j]:序列a[1...i]和b[1...j]的最长公共子序列的长度(LCS)
char a[N],b[N];
int p[N][N]; // 前驱数组
int n,m;

int main() {
	cin>>a+1>>b+1; // 从下标1开始存储
	n=strlen(a+1); // 起始位置是a+1
	m=strlen(b+1);
	// 初始化 f[0][j]=0,f[i][0]=0,即i和j中有未指向任意元素的指针存在时
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i]==b[j]) {
				f[i][j]=f[i-1][j-1]+1;
				p[i][j]=1; // 来自↖
			} else if(f[i-1][j]>f[i][j-1]) {
				f[i][j]=f[i-1][j];
				p[i][j]=2; // 来自←
			} else {
				f[i][j]=f[i][j-1];
				p[i][j]=3; // 来自↑
			}
		}
	}
	cout<<f[n][m]<<endl; // 最长长度
	int i=n,j=m,k=f[n][m];
	vector<char> path;
	// i或j中任意一个元素=0时退出
	while(i>0 && j>0) {
		// 左上方
		if(p[i][j]==1) {
			path.push_back(a[i]); // LCS中
			i--,j--;
		} 
		// 上方
		else if(p[i][j]==2) {
			i--;
		}
		// 左方
		else {
			j--;
		}
	}
	reverse(path.begin(),path.end());
	for(auto x:path) {
		cout<<x<<' ';
	}
	cout<<endl;
	return 0;
}
```



## 4. 最长公共子串

* 这一题和上一题有什么区别呢？序列可以是不连续的，但是串一定是连续的，区别就在此
* 最长公共子序列中 $f[i,j]$ 表示序列 $a[1...i]$ 和 $b[1...j]$ 的最长公共子序列的长度
* 最长公共子串中 $f[i,j]$ 表示以 $a[i]$ 和 $b[j]$ 为结尾的公共子串的长度

![image-20240411161150378](E:\Typora\图片\image-20240411161150378.png)

![image-20240411164021914](E:\Typora\图片\image-20240411164021914.png)

* 则可以得到状态转移方程
  * 若 $a[i]==b[j]$，构成公共子串，$f[i,j]=f[i-1,j-1]+1$
  * 若 $a[i]!=b[j]$，不能构成公共子串，$f[i,j]=0$（为什么不记录为最大值呢？因为串必须是连续的）

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
int n,m;
char a[N],b[N];
int f[N][N]; // 以a[i]和b[j]结尾的最长公共子串的长度

int main() {
	cin>>a+1>>b+1;
	n=strlen(a+1);
	m=strlen(b+1);
	// 无需初始化,全局变量
    int len=INT_MIN; // 最长公共子串长度 
    int st=0; // 起始点
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			// 必须要连续才相加
			if(a[i]==b[j]) {
				f[i][j]=f[i-1][j-1]+1;
			} else {
				f[i][j]=0;
			}
            
            // 保存第一个最长公共子串
            if(f[i][j]>=len) {
                len=f[i][j];
                st=i-len+1;
            }
			// ans=max(ans,f[i][j]);
		} 
	}
	// 以最后一个元素结尾的不一定是最长公共子串的长度
	cout<<len<<'\n';
    for(int i=st;i<=st+len-1;i++) {
        cout<<a[i];
    }
	return 0;
}
```



## 5. 字符串编辑距离

* $f[i,j]$ 表示从 $a[1...i]$ 变成 $b[1...j]$ 的编辑距离
* 若 $a[i]=b[j]$，$f[i,j]=f[i-1,j-1]$ ：因为新位置 $i$ 和 $j$ 的元素是相等的，无需编辑转移
* 若 $a[i]!=b[j]$
  * 修改，即 $a$ 中前 $i-1$ 项 和 $b$ 中前 $j-1$ 项已然相等，只需要把最后一项修改为 $b[j]$ 即可，所以有 $f[i,j]=f[i-1,j-1]+1$
  * 插入，即 $a$ 中前 $i$ 项和 $b$ 中前 $j-1$ 项相等，只需要再插入一项 $b[j]$ 即可，所以有 $f[i,j]=f[i,j-1]+1$
  * 删除，即 $a$ 中前 $i-1$ 项和 $b$ 中前 $j$ 项相等，但是多了一项，所以有 $f[i,j]=f[i-1,j]+1$
  * 由于属性是取最小值，所以三者中取 $min$ 即可

![image-20240411171937474](E:\Typora\图片\image-20240411171937474.png)

* 二维数组的常规做法如下，关于滚动数组优化这里不做解释，因为自己都搞得不是很清楚

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+5;
int n,m;
char a[N],b[N];
int f[N][N];

int main() {
	cin>>a+1>>b+1;
	n=strlen(a+1);
	m=strlen(b+1);
	// 从a[1...i]变成空串,需要是删除i次
	for(int i=1;i<=n;i++) {
		f[i][0]=i;
	}
	// 从空串变成b[1...j],需要添加j次
	for(int j=1;j<=m;j++) {
		f[0][j]=j;
	}
	// 状态转移
	// 如果记录一下状态转移就可以输出变化过程
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			// 末尾相等,无需添加
			if(a[i]==b[i]) {
				f[i][j]=f[i-1][j-1];
			} else {
				f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1; // 三种操作的最小值
			}
		}	
	}
	cout<<f[n][m]<<endl;
	return 0;
}
```



## 6. 股票问题

### 6.1. 股票交易

> 推荐学习视频：[E22 线性DP 股票买卖_bilibili](https://www.bilibili.com/video/BV1iK4y177jT/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)

* 状态表示：
  * $f[i][0]$：第 $i$ 天手中无票时获取的最大利润
  * $f[i][1]$：第 $i$ 天手中有票时获取的最大利润
* 状态属性：$max$

* 状态转移：

  * 当前手中无票，可能是上一个状态未买入股票，故有 $f[i][0]=f[i-1][0]$；也可以前一天有票，但是卖出了，此时收入为 $f[i][0]=f[i-1][1]+w[i]$，所以无票时状态转移方程为：$f[i][0]=max(f[i-1][0],f[i-1][1]+w[i])$

  * 当前手中有票，可能是上一个状态手中本来有票，但未卖出股票，故有 $f[i][1]=f[i-1][1]$；也可以前一天无票，但是买入了，此时收入为 $f[i][1]=f[i-1][0]-w[i]$，为何是减呢？因为买入嘛，我们的收益减去 $w[i]$，所以有票时状态转移方程为：$f[i][1]=max(f[i-1][1],f[i-1][0]-w[i])$

![image-20240426153152625](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426153152625.png)

* 边界初值：
  * 第 $1$ 天无票：$f[1][0]=0$
  * 第 $1$ 天有票：$f[1][1]=-w[i]$

* 目标值：
  * 第 $n$ 天事件结束时手上无票：$f[n][0]$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;
int n;
int w[N];
int f[N][2]; // f[i][0]:第i天手上没有股票的最大利润,f[i][1]:第i天手上有股票

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>w[i];	
	}
	// 初始化
	f[1][0]=0;
	f[1][1]=-w[1]; // 买下
	
	for(int i=2;i<=n;i++) {
		// 第i天无股票,可能是第i-1天无股票或者有股票卖了转移来的
		// 第i天有股票,可能是第i-1天有股票没卖或者无股票才买来的
		f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
	}
	cout<<f[n][0]; // 第n天无股票一定最大
	return 0;
}
```



### 6.2. 股票买卖 $k$ 笔交易

> 推荐学习视频：[E23 线性DP 股票买卖K笔交易_bilibili](https://www.bilibili.com/video/BV1ka4y1s7ER/?spm_id_from=333.788.recommend_more_video.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)

#### 6.2.1. 三维数组

* 状态表示：
  * $f[i][j][0]$：前 $i$ 天已经进行了 $j$ 次交易，当前手中无票，能获取的最大利润
  * $f[i][j][1]$：前 $i$ 天已经进行了 $j$ 次交易，当前手中有票，能获取的最大利润
* 状态属性：$max$

* 状态转移：

  * 当前手中无票，可能昨天也无票，并且没有买入，故有 $f[i][j][0]=f[i-1][j][0]$；也可能前一天有票，但是卖出了，正好完成了第 $j$ 交易，此时收入为 $f[i][j][0]=f[i-1][j][1]+w[i]$，所以无票时状态转移方程为：$f[i][0]=max(f[i-1][j][0],f[i][j][0]=f[i-1][j][1]+w[i])$

  * 当前手中有票，可能是上一个状态手中本来有票，但未卖出股票，故有 $f[i][j][1]=f[i-1][j][1]$；也可以前一天无票，但是买入了，那么说明前 $j-1$ 次交易已完成，当前正要计算的是第 $j$ 次交易，故有 $f[i][j][1]=f[i-1][j-1][0]-w[i]$，所以有票时状态转移方程为：$f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]-w[i])$

![image-20240426155643592](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426155643592.png)

* 边界初值：
  * 第 $0$ 天无票：$f[0][j][0]=0$，第 $0$ 天有票：$f[0][j][1]=-1e6$（该状态非法，且我们要找最大值，所以赋一个极小值）
  * 每一天还未进行交易时：$f[i][0][0]=0$

* 目标值：
  * 第 $n$ 天事件结束时刚好进行了 $k$ 次交易且手上无票：$f[n][k][0]$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+2; // 最大天数
const int M=1e2+2; // 最大交易次数

int f[N][M][2];

int w[N]; // 每天股票的价格

int n,k; // 天数和交易次数

int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>w[i];	
	}
	// 初始化第0天的情况
	// 合法则赋可取的有限值
	// 非法则赋负无穷(找最大值)或正无穷(找最小值)
	memset(f,0,sizeof f);
	// 第0天,手中无票,初值为0,手中有票,状态非法,负无穷(为找最大值)
	for(int j=0;j<=k;j++) f[0][j][1]=-1e6;
	// 第0笔,f[i][0][0]=0, 已经memset了
	
	// 三维数组!!!
	// 第1~n天,交易次数为1~k
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k;j++) {
			// 1) 前一天没买股票
			// 2) 前一天卖了股票,完成第j次交易
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]+w[i]);
			// 1) 前一天没卖股票
			// 2) 前一天买了股票,说明前一天已经完成了前j-1次交易,今天买股票处在第j次交易之中
			f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]-w[i]);
		}	
	}
	cout<<f[n][k][0]; // 第n天完成k次交易且手中无票
	return 0;
}
```



#### 6.2.2. 二维数组

* 观察三维数组的代码我们会发现，当前状态只与上一层状态有关，所以可以类似于 $01$ 背包那样优化掉一维，直接把第一维去掉即可，那为什么不用像 $01$ 背包那样逆序遍历背包容量呢？

![image-20240426161021747](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426161021747.png)

* 继续观察三维时的状态转移方程，会发现 $f[i][j][0]$ 和 $f[i][j][1]$ 都独立的用上一层的两个状态来进行更新，二者之间没有相互影响，所以无论是逆序还是正序都不会出错

![image-20240426161330033](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426161330033.png)

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e3+2; // 最大天数
const int M=1e2+2; // 最大交易次数

int f[N][M][2];
int ff[N][2];

int w[N]; // 每天股票的价格

int n,k; // 天数和交易次数

int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>w[i];	
	}
	// 二维滚动数组优化!!!注意听为什么不用逆序
	// 直接去掉第一维即可 且不逆序
	// 关于为什么直接去掉一维就可以了我也不得而知啊啊啊 dp有点难
	memset(ff,0,sizeof ff);
	for(int j=0;j<=k;j++) ff[j][1]=-1e6;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k;j++) {
			ff[j][0]=max(ff[j][0],ff[j][1]+w[i]);
			ff[j][1]=max(ff[j][1],ff[j-1][0]-w[i]);
		}
	}
	cout<<ff[k][0];
	return 0;
}
```



### 6.3. 股票买卖含冷冻期

> 推荐学习视频：[E24 线性DP 股票买卖含冷冻期 bilibili](https://www.bilibili.com/video/BV15v411r7WD/?spm_id_from=333.999.0.0&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)

* 引入了一天的冷冻期之后，我们在状态转移时就不能单单从昨天来看，要引入新一天：前天

* 状态表示：
  * $f[i][0]$：第 $i$ 天手中无票时获取的最大利润
  * $f[i][1]$：第 $i$ 天手中有票时获取的最大利润
* 状态属性：$max$

* 状态转移：

  * 当前手中无票，可能是上一个状态未买入股票，故有 $f[i][0]=f[i-1][0]$；也可以前一天有票，但是卖出了，此时收入为 $f[i][0]=f[i-1][1]+w[i]$，所以无票时状态转移方程为：$f[i][0]=max(f[i-1][0],f[i-1][1]+w[i])$

  * 当前手中有票，可能是上一个状态手中本来有票，但未卖出股票，故有 $f[i][1]=f[i-1][1]$；也可能是之前无票，但是买入了股票，注意此时只能从 $i-2$ （前天）的状态转移，因为如果昨天恰好是卖出股票的第一天，就出大问题了，此时收入为 $f[i][1]=f[i-2][0]-w[i]$，所以有票时状态转移方程为：$f[i][1]=max(f[i-1][1],f[i-2][0]-w[i])$
  * 那么这个状态转移方程就和第一个问题的方程非常非常类似了

![image-20240426155643592](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240426155643592.png)

* 边界初值：
  * 为何要从第 $0$ 天开始判断？因为我们引入了前天的概念
  * 第 $0$ 天无票：$f[0][0]=0$
  * 第 $0$ 天有票：$f[0][1]=-1e6$，状态非法，又因为找最大值所以给极小值（$DP$ 问题初始化技巧）

* 目标值：
  * 第 $n$ 天事件结束时手上无票：$f[n][0]$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 加了一个限制,卖出股票后第二天不能买入股票(1天冷冻期)
// 所以需要考虑的状态有前天,昨天和今天

const int N=1e5+5;
int f[N][2]; // f[i][0]:第i天手上无票,f[i][1]:第i天手上有票
int w[N];
int n;

/*
7
5 2 6 1 3 4 6
*/

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>w[i];	
	}
	// 1)初始化
	f[0][0]=0; // 第0天手上无票自然为0,dp入口
	f[0][1]=-1e9; // 第0天手上有票为非法状态,因为找最大值所以初始化为负无穷
	// 2)dp
	for(int i=1;i<=n;i++) {
		// 第i天无票,前一天本身无票或前一天卖出
		f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
		// 第i天有票,前一天有票未卖出或前两天买入(有冷冻期存在)
		f[i][1]=max(f[i-1][1],f[i-2][0]-w[i]);
		cout<<"第"<<i<<"天:"<<" f[0]="<<f[i][0]<<" ,f[1]="<<f[i][1]<<endl;
	}
	cout<<f[n][0];
	return 0;
}
```
