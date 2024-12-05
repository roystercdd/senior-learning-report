#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 无向图无自环和重边, 那就是最大完全图, 所以[n×(n-1)]/2
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	n=2020;
	cout<<n*(n-1)/2<<'\n';	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
