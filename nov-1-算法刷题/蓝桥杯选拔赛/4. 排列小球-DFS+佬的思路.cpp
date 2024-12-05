#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  R G B 共3个数(可为0), 将RGB分解为 t1, t2, ... ,tn
  是搜索罢 但是怎么搜才能使t1,t2,...,tn严格单调递增呢
  看了个佬的思路, 太强力
  
 */

const int N=1e5+5;

int ans;
int n,a[N],sum;

// 记录每一次放的什么颜色的球, 有多少个
PII s[N];
int idx=1; // 因子

string col[]={"0","红","绿","蓝"};

// sum:当前排放球数量总和, x:上一个排放球的数量, last:上一个球的颜色
void dfs(int sum,int x,int last) {
	// 把球放完了, 是一种方案
	if(sum==0) {
		ans++;
//		cout<<"第"<<ans<<"种方案"<<'\n';
		// 打印一下
		for(int i=1;i<=idx-1;i++) {
//			cout<<col[s[i].x]<<' '<<s[i].y<<'\n';
		}
		return;
	}
	// 遍历三种颜色的球
	for(int i=1;i<=3;i++) {
		if(i==last) continue; // 如果等于上一种颜色就跳过
		// 不同颜色, 但是要递增, 所以j从x+1开始取, 但不能超过自身总数
		for(int j=x+1;j<=a[i];j++) {
			a[i]-=j;
			s[idx].x=i; // 颜色是i
			s[idx].y=j; // 个数是j
			idx++;
			dfs(sum-j,j,i); // 进入下一层, 总数-j, 上次放j个, 上一种颜色是i
			a[i]+=j;
			idx--;
		}
	}
}

int main() {
	// 输入RGB
	for(int i=1;i<=3;i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	// sum: 当前排放球总和, 0: 上一个排放球数量为0, -1: 上一个颜色为-1
	dfs(sum,0,-1);
	cout<<ans;
	return 0;
}

/*
  输入样例:
  3 6 0
  输出样例:
  3
  rrrgggggg
  grrrggggg
  ggrrrgggg
 */
