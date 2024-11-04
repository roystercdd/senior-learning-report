#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 主要是处理偏移量后的循环, 超过z后减个26从a开始
  
 */

const int N=1e5+5;

string str; 

int main() {
	cin>>str;
	for(auto ch:str) {
		cout<<char(ch+3>'z'?ch-26+3:ch+3);
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
