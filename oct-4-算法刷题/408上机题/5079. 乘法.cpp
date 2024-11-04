#include<bits/stdc++.h>
#define x first
#define y second
#define int long long 

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 求n×m个数中排名k的元素
  
 */

const int N=1e5+5;

int n,m,k;
int a[N],b[N];

signed main() {
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>b[i];
	}
	priority_queue<int> pq; // 默认大根堆
	vector<int> v;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int tmp=a[i]*b[j];
//			pq.push(tmp);
			v.push_back(tmp);
		}	
	}
//	 弹出k次?
	sort(v.begin(),v.end(),greater());
//	for(auto item:v) {
//		cout<<item<<' ';
//	}
//	puts("");
	cout<<v[k-1]; // 排名k的元素
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
