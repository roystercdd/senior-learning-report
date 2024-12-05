#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int n,a[N];
map<char,int> m; // m[i]=j, i出现了j次

int main() {
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) m[s[i]]++;
//	for(auto it:m) {
//		cout<<it.x<<' '<<it.y<<'\n';
//	}
	for(char i='0';i<='9';i++) {
		if(m.find(i)!=m.end()) cout<<m[i]<<' ';
		else cout<<"0"<<' ';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
