#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 循环位移, 字符串问题嘛
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	string s;
	cin>>s;
	char ch=s[0];
	for(int i=0;i<=4;i++) {
		s[i]=s[i+1];
	}
	s[5]=ch; // 最后赋值
	cout<<s;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
