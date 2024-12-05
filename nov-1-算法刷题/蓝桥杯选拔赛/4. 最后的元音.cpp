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

bool yuanyin(char ch) {
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
	return false;
} 

int main() {
	string s;
	cin>>s;
	char ch;
	for(int i=0;i<s.size();i++) {
		if(yuanyin(s[i])) ch=s[i];
	}
	cout<<ch;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
