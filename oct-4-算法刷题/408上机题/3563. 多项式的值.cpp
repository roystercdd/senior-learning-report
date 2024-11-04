#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 非常简单的模拟题啊啊啊
  
 */

const int N=1e5+5;

int T;

int main() {
	cin>>T;
	while(T--) {
		int n; // 最高次项,项数则为n+1
		cin>>n;
		int ans=0;
		// 项数n+1,用vector保存每一项的
		vector<int> v;
		for(int i=1;i<=n+1;i++) {
			int tmp;
			cin>>tmp;
			v.push_back(tmp); // 尾插
		}
		int x;
		cin>>x;
		for(int i=0;i<n+1;i++) {
			ans+=v[i]*pow(x,i);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
