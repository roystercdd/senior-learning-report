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
int cnt;

int main() {
	n=2024;
	while(n!=1) {
		cnt++;
		n=floor(sqrt(n));
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
