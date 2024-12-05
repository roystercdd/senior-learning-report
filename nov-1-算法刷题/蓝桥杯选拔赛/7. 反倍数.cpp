#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 不是a倍数不是b倍数不是c倍数
  我的建议是通过类似于欧拉筛的方法把a,b,c的倍数都渲染一遍
  直接预处理10^6范围内的数据, 最后统计一次即可
  
 */

const int N=1e6+5;

int n;
int a,b,c; 
bool st[N]; // st[i]:0 是反倍数, 1不是反倍数

int main() {
	cin>>n;
	cin>>a>>b>>c;
	for(int i=1;i<=n;i++) {
		if(i%a==0 || i%b==0 || i%c==0) st[i]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(!st[i]) cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  30
  2 3 6
  输出样例:
  10
 */
