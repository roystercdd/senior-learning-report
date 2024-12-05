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

int n,a[N];

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b) {
	return a*b/gcd(a,b);
}

int cnt;

int main() {
	for(int i=1;i<=2021;i++) {
		if(lcm(i,2021)==4042) cnt++;
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
