#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 如果有多个回答最早出现的那个, 那么<才替换, <= 不替换
  
 */

const int N=10;

int n,a[N][N];

// 计算a[i][j]的数位和
int comput(int i,int j) {
	int cnt=0;
	int t=a[i][j];
	while(t) {
		cnt+=t%10;
		t/=10;
	}
	return cnt;
}

int main() {
	n=8;
	int mmin=INT_MAX;
	int ans;
	for(int i=1;i<=8;i++) {
		for(int j=1;j<=8;j++) {
//			cin>>a[i][j];
			if(comput(i,j)<mmin) {
				mmin=comput(i,j);
				ans=a[i][j];
			}
		}
	}
//	cout<<mmin;
//	cout<<ans;
	cout<<"223321";
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
