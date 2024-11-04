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


int main() {
	int a,b,c;
	// 输入三条边,如何预处理出最小和次小呢?
	// 优先队列嘛
	while(cin>>a>>b>>c) {
		priority_queue<int,vector<int>,greater<int>> pq;
		pq.push(a),pq.push(b),pq.push(c);
		int cnt=1; // 第三次的时候减
		int ans=0;
		while(!pq.empty()) {
			if(cnt==3) {
				ans+=pq.top()*-1;
			} else {
				ans+=pq.top();
			}
			pq.pop();
			cnt++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
