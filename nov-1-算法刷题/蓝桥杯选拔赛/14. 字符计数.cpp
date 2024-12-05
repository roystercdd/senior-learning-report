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
bool check_yuanyin(char ch) {
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
	return false;
}

string s;

int main() {
	cin>>s;
	int cnt1=0,cnt2=0;
	for(auto ch:s) {
		if(check_yuanyin(ch)) cnt1++;
		else cnt2++;
	}
	cout<<cnt1<<'\n'<<cnt2;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
