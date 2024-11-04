#include<bits/stdc++.h>
#define x first
#define y second
#define PI acos(-1) // 定义PI
#define int long long 

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 只要半径从大到小排,可视化表面积的公式就是最大的
  要让选出的蛋糕的侧面表面积最大,即选半径最长的,所以这道题就是个贪心
  因为答案要除以PI,所以所有计算都可以不考虑PI
  
 */

const int N=1e5+5;

int n,m; // 半径和高度

struct Yuanzhu {
	int r,h;
}yuanzhu[N];

bool cmp(Yuanzhu a,Yuanzhu b) {
	// 表面积不同,大的在前
	if(a.h*a.r!=b.h*b.r) {
		return a.r*a.h>b.r*b.h;
	}
	return a.r>b.r;
}

signed main() {
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++) {
		cin>>yuanzhu[i].r>>yuanzhu[i].h;
	}
	sort(yuanzhu+1,yuanzhu+1+n,cmp);
	int tmp=0;
	for(int i=1;i<=m;i++) {
		tmp=max(tmp,yuanzhu[i].r*yuanzhu[i].r);
		ans+=yuanzhu[i].r*yuanzhu[i].h*2;
	}
	cout<<ans+tmp<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
