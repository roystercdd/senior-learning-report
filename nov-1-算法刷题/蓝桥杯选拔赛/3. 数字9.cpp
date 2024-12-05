#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 填空, 统计1~2019中有多少个数包含9
  
 */

const int N=1e5+5;

int n,a[N];

// 拆位并check有没有数位为9
bool check(int x) {
	while(x) {
		if(x%10==9) return true;
		x/=10;
	}
	return false;
}

int cnt;

int main() {
	for(int i=1;i<=2019;i++) {
		int tmp=i;
		if(check(tmp)) cnt++;
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
