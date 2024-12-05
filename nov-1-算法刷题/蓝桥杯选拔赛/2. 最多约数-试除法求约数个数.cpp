#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 来一把边读边输出
  
 */

const int N=1e5+5;

int n;

// 计算x的约数个数, 用试除法即可
// i<sqrt(x) 即 i*i<x 即 i<x/i
int cnt(int x) {
	int ans=0;
	for(int i=1;i<=x/i;i++) {
		if(x%i==0) {
			ans++;
			if(i!=x/i) ans++;
		}
	}
	return ans;
}

int main() {
//	n=36;
//	int t;
//	int mmax=INT_MIN;
//	int idx;
//	while(n--) {
//		cin>>t;
//		cout<<cnt(t)<<'\n';
//		if(cnt(t)>mmax) {
//			mmax=cnt(t);
//			idx=t;
//		}
//	}
//	cout<<idx;
	cout<<901440;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
