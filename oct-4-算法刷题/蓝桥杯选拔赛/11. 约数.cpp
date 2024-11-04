#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 填空题, 从小于2022的所有数中去找约数就可以了
  
 */

const int N=1e5+5;

int n,a[N];
int cnt;

int main() {
	int n=2020;
	// 1和本身算约数吗?其实一直不知道
	for(int i=1;i<=n;i++) {
		if(n%i==0) {
//			cout<<i<<'\n';
			cnt++;
		}
	}
 	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
