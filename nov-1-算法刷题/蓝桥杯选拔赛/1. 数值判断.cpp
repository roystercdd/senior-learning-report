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

bool check(string s) {
	// 下标从0到s.size-1
	int last=s[0]-'0';
//	cout<<last<<' ';
	for(int i=1;i<s.size();i++) {
		if(s[i]-'0'>last) {
			last=s[i]-'0';
//			cout<<last<<' ';
		} else {
			// 如果s[i]<=last 则false
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	cin>>s;
	if(check(s)) cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
