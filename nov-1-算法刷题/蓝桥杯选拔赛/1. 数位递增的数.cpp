#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 最开始想过用dfs暴搜倒着枚举, 后来发现分支有点多
  还是老老实实正着枚举, 通过拆位判断从最后一位起往前是否满足数位递增
  唯一一个技巧在于while(x/10) 这样可以判断到只剩第一位时停止, 就不用特判了
  
 */

const int N=1e5+5;

int n,cnt;

// 判断x是否是递增的
bool check(int x) {
	// 拆位, 判断是否>=前一位, 这里用x/10 判断到第一位即可
	while(x/10) {
		int d1=x%10;
		int d2=x/10%10;
		if(d1<d2) return false;
		x/=10;
	}
	return true;
} 

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		if(check(i)) cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  30
  输出样例:
  26
 */
