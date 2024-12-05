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

int main() {
	n=2024;
	for(int i=1;i<=10000;i++) {
		if(i*i*i>=2024) {
			cout<<i-2024;
			break;
		}
	}	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
