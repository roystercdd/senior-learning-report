#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 并集好搞定,开一个set,交集的话遍历并集中的元素然后去另外一个集合中找
  
 */

const int N=1e5+5;

int n,m;
set<int> a,b,c; // a→集合n,b→集合m,c→维护并集

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a.insert(x),c.insert(x);
	}
	for(int i=1;i<=m;i++) {
		int x;
		cin>>x;
		b.insert(x),c.insert(x);
	}
	// 找交集个数
	int cnt=0;
	for(auto x:a) {
		// 如果b中有a
		if(b.count(x)) {
			cnt++;
		}
	}
	cout<<cnt<<' '<<c.size()<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
