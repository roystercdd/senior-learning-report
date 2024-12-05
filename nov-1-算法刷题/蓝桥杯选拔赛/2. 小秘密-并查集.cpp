#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 没有理解题目中的这样不断重复n次是什么意思, 那就按照我自己的理解
  根据样例来看, 其实这道题就是一个并查集, 最开始每个元素都是一个集合
  随后这个人根据自己卡片上的数字把对应编号的人加入自己的集合中
  
 */

const int N=1e5+5;

int n,a[N];
int fa[N]; // fa[i]: 第i个集合的父结点

// 查找元素所在集合的根
int find(int x) {
	// 自己就是根节点
	if(x==fa[x]) return x;
	// 否则递归查找父节点, 路径压缩
	return fa[x]=find(fa[x]);
}

// 连接两个集合
void join(int a,int b) {
	// b的根作为a的根
	fa[find(a)]=find(b);
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
		fa[i]=i;
	}
	// 再遍历一遍
	for(int i=1;i<=n;i++) {
		// 取出a[i] 这个是要传递的小朋友, 如果a[i]不在集合则加入到自己的集合中去
		// 如果a[i]==i则一定在本集合中 不用管
		if(find(a[i])!=find(i)) join(i,a[i]);
	}
	// 有多少个集合即是看有多少个结点的x==fa[x](多少个根节点)
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(i==fa[i]) cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
