#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 对每个字符都无视大小写
  简单, 输入一个字符串, 然后将其所有字符小写化再与lanqiao比较即可
  交给tolower函数吧!
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	string s;
	cin>>s;
	string tmp="";
	for(char ch:s) {
		tmp+=tolower(ch);
	}
	if(tmp=="lanqiao") cout<<"yes";
	else cout<<"no";
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
