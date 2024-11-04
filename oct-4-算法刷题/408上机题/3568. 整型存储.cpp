#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 未免有点...
  
 */

const int N=1e5+5;

string s;
int cnt=0;

int main() {
	while((cin>>s && s!="0")) {
		cout<<s<<' ';
		// 翻转之前就去掉末尾的0,然后就不存在前导0了
		while(s.size()>1 && s.back()=='0') s.pop_back();
		reverse(s.begin(),s.end());
		cout<<s<<'\n';
		cnt++;
		if(cnt==10) break;
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
