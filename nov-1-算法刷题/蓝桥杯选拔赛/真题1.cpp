#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int n=2024;

bool is_prime(int x) {
	for(int i=2;i<=x/i;i++) {
		if(x%i==0) return false;
	}
	return true; // 质数
}

int cnt;

int main() {
	// 1不是质数
	for(int i=2;i<=n;i++) {
		if(is_prime(i) && n%i==0) {
			cout<<i<<'\n';
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
