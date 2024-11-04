#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int n,m,a[N];


int main() {
	cin>>n>>m; 
	int res=0;
	while(n&&m) {
		// 假设n<m
		if(n>m) swap(n,m);
		res+=m/n; // 切除m/n个n×n的正方形
		// 剩余长宽为 m%n 和 n
		m=m%n;
	}
	cout<<res;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
