#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int T;
int l,r;
int cnt;

void dfs(int x) {
	if(x>r) return;
	if(x>=l && x>=10) cnt++;
	
	int d=x%10; // 末位
	// 1~8 还可以++
	if(d<9) dfs(x*10+d+1);
	// 1~9 还可以--
	if(d>=1) dfs(x*10+d-1);
}

signed main() {
	cin>>T;
	while(T--) {
		cin>>l>>r;
		cnt=0;
		for(int i=1;i<=9;i++) {
			dfs(i);
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
