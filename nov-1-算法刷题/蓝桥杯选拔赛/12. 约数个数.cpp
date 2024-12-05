#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 枚举法计算约数个数
  
 */

const int N=1e5+5;

int n,a[N];

int cnt(int x) {
	int ans=0;
	for(int i=1;i<=x/i;i++) {
		if(x%i==0) {
			ans++;
			if(x/i!=i) ans++;
		}
	}
	return ans;
}

int main() {
	cout<<cnt(2023);
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
