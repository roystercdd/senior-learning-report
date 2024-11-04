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

int teshu(char c) {
	if(c=='J') return 1;
	else if(c=='Q') return 2;
	else if(c=='K') return 3;
	else return 4;
}

int main() {
	cin>>n;
	int cnt=0;
	while(n--) {
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++) {
			if(s[i]>='0' && s[i]<='9') cnt+=0;
			else {
				cnt+=teshu(s[i]);
			}
		}
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
