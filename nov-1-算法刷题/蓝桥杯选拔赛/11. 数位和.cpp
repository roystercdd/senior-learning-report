#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 枚举咯
  
 */

const int N=1e5+5;

int n,a[N];

// 判断x是否为质数
bool is_prime(int x) {
	for(int i=2;i<x/i;i++) {
		if(x%i==0) return false;
	}
	return true;
}

int cnt;

// 拆位计算是否为23
bool check(int x) {
	int res=0;
	while(x) {
		res+=x%10;
		x/=10;
	}
	if(res==23) return true;
	return false;
}

int main() {
	// 虽然从1开始哈, 但是我们知道1肯定不是质数
	for(int i=2;i<=1000000;i++) {
		if(is_prime(i) && check(i)) cnt++;
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
