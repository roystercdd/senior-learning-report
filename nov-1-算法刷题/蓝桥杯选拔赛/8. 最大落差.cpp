#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 落差, a[i]>a[i+1]
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	int mmax=INT_MIN;
	bool flag=false;
	for(int i=1;i<=n-1;i++) {
		if(a[i]>a[i+1]) {
			flag=true;
			int tmp=a[i]-a[i+1];
			mmax=max(mmax,tmp);
		}
	}
	if(!flag) {
		cout<<"0";
	} else {
		cout<<mmax;	
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
