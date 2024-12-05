#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 这个谈判不就是哈夫曼树嘛
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	cin>>n;
	// 小根堆的写法哦
	priority_queue<int,vector<int>,greater<>> q;
	for(int i=1;i<=n;i++) {
		int tmp;
		cin>>tmp;
		q.push(tmp);
	}
	int ans=0;
	// 最后合成为一个
	while(q.size()!=1) {
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
//		cout<<x<<' '<<y<<'\n';
		int sum=x+y;
		ans+=sum;
		q.push(sum);
	}
	cout<<ans;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
