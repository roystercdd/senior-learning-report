#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 非常简单的字符串处理嗷
  如果是大写字母距离'A'和'Z'相同,则 'Z'-(s[i]-'A') 就是反码
  因为 A的反码就是Z,A距离A为0,Z距离Z为0
  
 */

const int N=1e5+5;

int n,a[N];

string solve(string str) {
	string ans;
	for(int i=0;i<str.size();i++) {
		// 如果小写字母
		if(str[i]>='a' && str[i]<='z') {
			ans+= ('z'-(str[i]-'a'));
		} else if(str[i]>='A' && str[i]<='Z') {
			ans+= ('Z'-(str[i]-'A'));
		} else {
			ans+=str[i];
		}
	}
	return ans;
}

int main() {
	string s;
	while(cin>>s && s!="!") {
		cout<<solve(s)<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
