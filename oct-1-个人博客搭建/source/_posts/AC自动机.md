---
title: AC自动机
date: 2024-10-05 16:14:41
categories: 学习
tags:
    - 算法竞赛
    - 字符串
    - 数据结构
---

<meta name="referrer" content="no-referrer" />



# AC自动机

<!-- toc -->



> 跟学视频：[F08【模板】AC自动机_](https://www.bilibili.com/video/BV1tF41157Dy/?spm_id_from=333.337.search-card.all.click&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)

## 0. 概述

* $AC$自动机是多模式匹配算法，给定$n$个模式串和一个主串，查找有多少个模式串在主串中出现过。



> 复习一下字典树吧：[【C++算法模板】字典树，超详细注释带例题讲解-CSDN博客](https://blog.csdn.net/qq_63586399/article/details/136725155?spm=1001.2014.3001.5502)

### 1. 构建Trie树

* 我们先用n个模式串构造一颗Trie。
* Trie中的一个节点表示一个从根到当前节点的字符串。
* 根节点表示空串，节点⑤表示“s”，节点6表示“sh”，节点7表示“she”。
* 如果节点是个模式串，则打个标记。例如，cnt[7]=1。

![image-20240213085433083](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213085433083.png)

``` c++
// 用Trie树的题目一定限制了字符的个数
const int N=1e5+5;

// ch[i][j]=2:i是层数(根节点从0开始),j表示字母,下标0表示'a',2是当前记录到哪个点的编号
// cnt[i]=1,以当前点结尾的串是一个模式串
// idx:下标是0的点,既是根节点,也是空节点
int ch[N][26],cnt[N],idx;

// 建树的insert函数
void insert(char s[]) {
	int p=0; // 从根节点开始遍历
	for(int i=0;s[i];i++) { // 遍历主串
		int j=s[i]-'a'; // a~z映射到下标0~25
		if(!ch[p][j]) ch[p][j]=++idx; // 如果没有孩子节点,则创建一个
		p=ch[p][j]; // 走到p的子节点,继续往下遍历和创建
	}
	cnt[p]++; // 以节点p结尾的单词个数+1,标记从根节点出发到该节点是一个模式串
}
```



### 2. 构造AC自动机

* 构造AC自动机的过程就是在Trie树上构建两类边：**回跳边**和**转移边**



#### 2.1. 回跳边

* 开一个数组ne[]，ne[v] 存节点v的回跳边的终点，如：ne[7]=3，表示节点7的回跳边的终点是3

* 回跳边指向**父节点的回跳边所指节点的儿子**，对于ne[7]=3来说，7的父节点是6，6的子节点是3，所以7指向3，此时四个点$(v,u,ne[u],ch[][])$构成四边形

  <img src="https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213091335787.png" alt="image-20240213091335787" style="zoom:80%;" />

* 并且回跳边所指节点一定是当前节点的**最长后缀**，cnt[7]=1，代表模式串是she，cnt[3]=1，代表模式串是he，此时he是she的最长后缀，下图中绿色边代表回跳边。

<img src="https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213090937272.png" alt="image-20240213090937272" style="zoom:80%;" />



#### 2.2. 转移边

* 转移边指向的是**当前节点的回跳边所指节点的儿子**，转移边和树边共同存储在数组$ch[][]$中
  * $ch[u][i]$存节点u的树边的终点，如$ch[6][e]=7$，节点6走e边到达节点7
  * $ch[u][i]$存节点u的转移边的终点，如$ch[7][r]$=4，节点7的回跳边是3，节点3的儿子是节点4，注意上图中没有画出转移边，只有树边和回跳边
* 此时三个点$(u,ne[u],ch[][])$构成三角形

![image-20240213092022148](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213092022148.png)

* 转移边所指节点一定是当前节点的**最短路**，比如$ch[7][r]=4$，那么从节点7到达节点4的最短路就是这条直通的r，而不是回溯到根节点再重新匹配到节点4



#### 2.3. 用BFS构造AC自动机

1. 初始化，把根节点的儿子们入队（枚举26次，因为只有26个字母）
2. 只要队不空，队头节点u出队，枚举u的26个儿子
   1. 若儿子存在，则爹帮儿子建回跳边，并把儿子入队
   2. 若儿子不存在，则爹自建转移边

<img src="https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213090937272.png" alt="image-20240213090937272" style="zoom:80%;" />

* 上图对应的完整建边过程如下，这里只模拟节点1和节点2的建边过程：
* 1）对节点1：
  1. 节点1出队，但是节点1下没有儿子，所以不用给他的儿子建回跳边，但是图中节点1的回跳边指向节点0，这是因为ne[]数组是全局变量默认初始化为0，或者可以这样想，根节点代表的是空串，此时节点1的最长后缀也就是空串
  2. 现在建转移边，因为节点1的父节点的儿子就是本身，所以建立26条转移边，有$ch[1][e]=1$，既节点1的转移边指向自己，对于遍历到父节点的下一条树边h时，当前节点的转移边指向父节点的儿子，所以有$ch[1][h]=2$，同理有$ch[1][s]=5$，那么对于父节点0的其他边(即不存在的边)有$ch[1][···]=0$，指向咱们的根节点
* 2）对节点2：
  1. 节点2出队，因为节点2下的有儿子节点3，所以先为节点3建立回跳边为节点3的父节点的回跳边指向的儿子，其实就是节点1，所以有$ne[3]=1$，并且将节点3入队
  2. 因为只有这一个儿子，随后建立25条转移边，节点2的父节点0在e之后(因为e已经用于做最长后缀去建回跳边了)的树边有h和s，对h和s建立回跳边的过程同上，所以有$ch[2][h]=2$、$ch[2][s]=5$、$ch[2][···]=0$

<img src="https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213094042809.png" alt="image-20240213094042809" style="zoom:80%;" />

* 时间复杂度O(26n)，一共需要入队出队n个字符，n是模式串所有的总长度，每个节点都要枚举26次，要么帮儿子建回跳边，要么自己建转移边

``` c++
// 用Trie树的题目一定限制了字符的个数
const int N=1e5+5;

// ch[i][j]=2:i是层数(根节点从0开始),j表示字母,下标0表示'a',2是当前记录到哪个点的编号
// cnt[i]=1,以当前点结尾的串是一个模式串
// idx:下标是0的点,既是根节点,也是空节点
int ch[N][26],cnt[N],idx;
int ne[N]; // 存储回跳边的数组

// 构建AC自动机
void build() {
	queue<int> q;
	// 1:将根节点的儿子入队
	for(int i=0;i<26;i++) 
		if(ch[0][i]) q.push(ch[0][i]);
	// 2:当队列非空,取队头,建回跳边和转移边
	while(q.size()) {
		int u=q.front();q.pop();
		for(int i=0;i<26;i++) {
			int v=ch[u][i]; // 取出儿子节点
			// 如果有儿子节点,构建v的回跳边为父节点的回跳边所指向的儿子
			if(v) ne[v]=ch[ne[u]][i],q.push(v);
			// 如果没有儿子节点,构建u的转移边为回跳边所指向节点的儿子
			else ch[u][i]=ch[ne[u]][i]; 
		}
	}
}
```



### 3. 查找单词出现次数

* 匹配的方式和$KMP$类似，是一个双指针匹配，首先扫描主串，依次取出字符s[k]
* 1）i 指针走主串对应的节点，沿着**树边**或**转移边**走，保证不回退
* 2）j 指针沿着**回跳边**搜索模式串，每次从当前节点走到根节点，把当前节点中的所有**后缀模式串**一网打尽，保证不漏解。
* 3）扫描完主串，返回答案
* 算法一边走串，一边把当前串的所有后缀串搜出来，实在是强，对于此过程的模拟，建议听原视频（因为太复杂了不想写）

* [F08【模板】AC自动机_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1tF41157Dy/?spm_id_from=333.337.search-card.all.click&vd_source=b8e5916fcec63c0b6234c190e1ec6dd1)，从$24:48$ 开始

![image-20240213101043808](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213101043808.png)

* 时间复杂度$O(n+m)$，m是主串长度，n是所有模式串的总长度

``` c++
// 查找单词出现次数
int query(char s[]) {
	int ans=0;
	for(int k=0,i=0;s[k];k++) {
		i=ch[i][s[k]-'a']; // i指针指向s[k]这个字符对应的节点
		for(int j=i;j&&~cnt[j];j=ne[j]) // j指针从当前指针开始,沿沿着回跳边跑
			ans+=cnt[j],cnt[j]=-1; // 如果有标记,则累加答案,无论有无标记,都把标记清空,注意这里的写法不是固定的,如果题目要求出现几次就累计几次,那么cnt[j]是不用清空的
	}
	return ans;
}
```



### 4. KMP与AC自动机对比

<img src="https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213102219322.png" alt="image-20240213102219322" style="zoom: 80%;" />



### 5. 【例】洛谷P3808 AC自动机(简单)

* 给定 $n$ 个模式串 $s_i$ 和一个文本串 $t$，求有多少个不同的模式串在文本串里出现过，当两个模式串编号不同时即视为不同的模式串。
* 注意：$s_2$ 与 $s_3$ 编号（下标）不同，因此各自对答案产生了一次贡献。

![image-20240213103041931](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213103041931.png)

* 注意：$s_1$，$s_2$，$s_4$ 都在串$abcd$里出现过

<img src="https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20240213103223172.png" alt="image-20240213103223172" style="zoom:80%;" />

``` c++
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

// 题目描述: 

// 用Trie树的题目一定限制了字符的个数
const int N=5e5+10;

// ch[i][j]=2:i是层数(根节点从0开始),j表示字母,下标0表示'a',2是当前记录到哪个点的编号
// cnt[i]=1,以当前点结尾的串是一个模式串
// idx:下标是0的点,既是根节点,也是空节点
int ch[N][26],cnt[N],idx;
int ne[N]; // 存储回跳边的数组

int n; // 模式串个数
const int MAX_LEN=1e6+10; // 模式串最长长度
char str[MAX_LEN]; // 存储模式串

// 建树的insert函数,传入字符串
void insert(char s[]) {
	int p=0; // 从根节点开始遍历
	for(int i=0;s[i];i++) { // 遍历主串
		int j=s[i]-'a'; // a~z映射到下标0~25
		if(!ch[p][j]) ch[p][j]=++idx; // 如果没有孩子节点,则创建一个
		p=ch[p][j]; // 走到p的子节点,继续往下遍历和创建
	}
	cnt[p]++; // 以节点p结尾的单词个数+1,标记从根节点出发到该节点是一个模式串
}

// 构建AC自动机
void build() {
	queue<int> q;
	// 1:将根节点的儿子入队
	for(int i=0;i<26;i++) 
		if(ch[0][i]) q.push(ch[0][i]);
	// 2:当队列非空,取队头,建回跳边和转移边
	while(q.size()) {
		int u=q.front();q.pop();
		for(int i=0;i<26;i++) {
			int v=ch[u][i]; // 取出儿子节点
			// 如果有儿子节点,构建v的回跳边为父节点的回跳边所指向的儿子
			if(v) ne[v]=ch[ne[u]][i],q.push(v);
			// 如果没有儿子节点,构建u的转移边为回跳边所指向节点的儿子
			else ch[u][i]=ch[ne[u]][i]; 
		}
	}
}

// 查找单词出现次数,传入字符串
int query(char s[]) {
	int ans=0;
	for(int k=0,i=0;s[k];k++) {
		i=ch[i][s[k]-'a']; // i指针指向s[k]这个字符对应的节点
		for(int j=i;j&&~cnt[j];j=ne[j]) // j指针从当前指针开始,沿沿着回跳边跑
			ans+=cnt[j],cnt[j]=-1; // 如果有标记,则累加答案,无论有无标记,都把标记清空,视情况嗷
	}
	return ans;
}

int main() {
	cin>>n; // 模式串个数
	for(int i=0;i<n;i++) {
		cin>>str;	
		insert(str);
	}
	build();
	cin>>str; // 输入主串
	cout<<query(str)<<endl;
	return 0;
}
```
