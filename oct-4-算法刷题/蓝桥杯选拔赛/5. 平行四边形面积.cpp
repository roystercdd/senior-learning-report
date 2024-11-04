#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 四舍五入用fixed setprecision
  
 */

const int N=1e5+5;

double l,h;

int main() {
	cin>>l>>h;
	// 如果结果是整数
	if(l*h==int(l*h)) cout<<l*h;
	else cout<<fixed<<setprecision(1)<<l*h;
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
