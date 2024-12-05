#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 全排列嘛, 高中数学题, 但是有两个A, 法一直接当数学题算
  A77 / C21(两个A无法交换)
  
 */

const int N=1e5+5;

int n,a[N];

// 计算x!
int fact(int x) {
	if(x==0) return 1;
	return x*fact(x-1);
}

// 法2, 直接全排列
void solve() {
	char s[]="LANQIAO";
	sort(s,s+7);
	int ans=1;
	// 直接计算全排列 并且按照实际含义, 非常好用
	while(next_permutation(s,s+7)) ans++;
	cout<<ans<<'\n';
}

int main() {
	cout<<fact(7)/2<<endl;
	solve();
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
