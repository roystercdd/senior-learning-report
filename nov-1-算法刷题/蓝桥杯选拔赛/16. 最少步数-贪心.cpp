#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 看错了不好意思, 第一次做看成求方案数了, 那肯定递推嘛
  一交 错了嘿, 原来是找零钱, 原来是贪心嗷
  
 */

const int N=1e5+5;
const int step[]={0,3,2,1}; // 大步数在前, 步数最少

int n,a[N];

int main() {
	cin>>n;
	int ans=0;
	for(int i=1;i<=3;i++) {
		ans+=n/step[i];
		n%=step[i];
	}
	cout<<ans;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
