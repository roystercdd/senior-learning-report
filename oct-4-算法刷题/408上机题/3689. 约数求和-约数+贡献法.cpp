#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int n,a[N];


int main() {
	// 贡献法,看1~n每个数字能做多少次约数,能有多少贡献
	cin>>n;
	ll res=0;
	// 枚举每个数是哪些数的约数
	for(ll i=1;i<=n;i++) {
		// i一定是 floor(n/i) 个数的约数
		// i 2i 3i ... (n/i)×i
		res+=floor(n/i)*i; // 出现这么多次,每个数都是i
	}
	cout<<res;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
