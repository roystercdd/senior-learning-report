#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 这个简单嘛 来, 注意要开long long
  
 */

const int N=1e5+5;

int n,a[N];

// 转换并赋值, 取非0位出来做乘积
void convert(int &x) {
	int res=1;
	int tmp=x;
	while(tmp) {
		if(tmp%10) res*=tmp%10;
		tmp/=10;
	}
	cout<<res<<'\n';
	x=res;
}

signed main() {
	cin>>n;
	while(n>=10) {
		convert(n);
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
