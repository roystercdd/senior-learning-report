#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 双重遍历即可
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	int mmax=INT_MIN;
	for(int i=1;i<=n-1;i++) {
		if(a[i+1]-a[i]>mmax) mmax=a[i+1]-a[i];
	}
	cout<<mmax;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
