#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=20+5;

bool check(int a,int b,int c) {
	// 所以除法变乘法,a==b*c,避免整除带来的判断影响
	// 10^9×10^9可能爆int
	if(a+b==c || a-b==c || (ll)a*b==c || (ll)b*c==a) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int a,b,c;
	while(cin>>a>>b>>c)
	if(check(a,b,c) || check(b,a,c)) {
		cout<<"YES"<<'\n';
	} else {
		cout<<"NO"<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
