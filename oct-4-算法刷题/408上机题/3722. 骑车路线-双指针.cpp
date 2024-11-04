#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 枚举一遍双指针找到最大高度差即可
  
 */

const int N=1e3+5;
//int mmax=INT_MIN; // 答案
int n,a[N];

int main() {
	while(cin>>n && n!=-1) {
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);	
		}
		int ans=0;
		for(int i=1;i<=n;) {
			int j=i+1; // 上坡一定包含两个元素 
			while(j<=n && a[j]>=a[j-1]) j++; // 找不严格上升元素的最后一个
			ans=max(ans,a[j-1]-a[i]);
			i=j; // 此处不用+1,因为此时j已经是新序列的开头了
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
