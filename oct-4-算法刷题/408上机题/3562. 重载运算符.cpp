#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 两角相减求出正弦值即可,注意角度先化成弧度,再转换成sin值
  
 */

const int N=1e5+5;

int T;

int main() {
	cin>>T;
	while(T--) {
		int x,y;
		cin>>x>>y;
		// 30→6/PI
		cout<<fixed<<setprecision(2)<<sin((x-y)/180.0*acos(-1))<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
