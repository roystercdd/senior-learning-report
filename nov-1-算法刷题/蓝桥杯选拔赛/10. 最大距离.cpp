#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 遍历即可 并不难, 10^6
  
 */

const int N=1e3+5;

int n,a[N];

int get_dis(int i,int j) {
	return abs(i-j)+abs(a[i]-a[j]);
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	// 求元素距离
	int mmax=INT_MIN;
	for(int i=1;i<=n-1;i++) {
		for(int j=i+1;j<=n;j++) {
			if(get_dis(i,j)>mmax) mmax=get_dis(i,j);
		}	
	}
	cout<<mmax<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
