#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 合数数量用数的总个数减去素数个数即可
  数据范围10^7, 欧拉筛
  注意1不是质数也不是合数, 最小的合数是4
  
 */

const int N=1e7+5;

int n,a[N];
int primes[N]; // 前缀和求1~i之间数的个数
bool st[N]; // 1~i中的数是否被筛过了
int cnt; // 素数个数
int s[N]; // 前缀和统计合数个数

void get_primes(int n) {
	// 遍历1~n中所有数
	for(int i=2;i<=n;i++) {
		if(!st[i]) primes[cnt++]=i; // 找到质数
		// 标记倍数为合数
		for(int j=0;primes[j]*i<=n;j++) {
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
	
	// 统计合数的个数
	for(int i=2;i<=n;i++) {
		s[i]=s[i-1];
		if(st[i]) s[i]++;
	}
}


int main() {
	get_primes(N); 
	int a,b;
	while(cin>>a>>b) {
		cout<<s[b]-s[a-1]<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
