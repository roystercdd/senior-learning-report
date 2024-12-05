#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 每个非零位都-1, 操作次数无非就是看整数里面最高位是多少
  10^10 用字符串来存即可
  
 */

const int N=1e5+5;

string s;

int main() {
	cin>>s;
	char mmax=CHAR_MIN;
	for(int i=0;i<s.size();i++) {
		if(s[i]>mmax) {
			mmax=s[i];
		}
	}
	cout<<mmax;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
