#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 达到回文数,做过很多次了,能通过库函数实现就尽量通过库函数实现
  题目说了操作次数一定不超过1000并且计算和不超过INT_MAX
  
 */

int n; // 转为数字
string s; // 字符串存储

bool huiwen(string s) {
	string ss=s;
	reverse(s.begin(),s.end()); // 不会影响外部哈,没有引用
	if(s==ss) return true;
	return false;
}

int main() {
	cin>>s;
	int cnt=0; // 操作步数
	while(!huiwen(s)) {
		string ss=s;
		reverse(s.begin(),s.end());
		s=to_string(stoi(ss)+stoi(s)); // 新的字符串
		cnt++;
	}
	cout<<cnt<<' '<<s<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
