#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int n;
int ans,idx=INT_MAX; // ans 最大次数,idx 值

unordered_map<int,int> cnt;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		cnt[x]++;
	}
	// 遍历找出现次数最多且最小的值
	int res=0; // 假设0是这个数
	for(auto& [k,v]:cnt) {
		if(cnt[res]<v || cnt[res]==v && k<res) {
			res=k;
		}
	}
	cout<<res;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
