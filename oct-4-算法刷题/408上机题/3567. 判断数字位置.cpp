#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 太简单了哥们
  
 */

const int N=1e5+5;
int T;

int main() {
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++) {
			if(s[i]>='0' && s[i]<='9') cout<<i+1<<' ';
		}
		puts("");
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
