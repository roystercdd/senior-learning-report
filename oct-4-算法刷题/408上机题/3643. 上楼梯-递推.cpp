#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=25;

int n,f[N];


int main() {
	f[1]=1;
	f[2]=2;
	f[3]=4;
	for(int i=4;i<=N;i++) {
		f[i]=f[i-1]+f[i-2]+f[i-3];
	}
	cin>>n;
	cout<<f[n];
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
