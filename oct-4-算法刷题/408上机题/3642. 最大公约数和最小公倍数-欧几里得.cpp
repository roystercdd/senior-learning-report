#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 非常熟悉了,GCD和LCM
  
 */

const int N=1e5+5;

int n,m;

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}


int main() {
	cin>>n>>m;
	cout<<gcd(n,m)<<' '<<n*m/gcd(n,m);
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
