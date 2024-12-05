#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 这道三元组很简单不要想复杂了
  直接枚举中心点, 然后再枚举两侧i和k, 保证a[j]<a[i] && a[k]>a[i]
  三重循环
  
 */

const int N=1e5+5;

int n,a[N];
int cnt;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	
	}
	// 枚举中心
	for(int i=2;i<=n-1;i++) {
		bool flag=false;
		// 枚举左端点
		for(int j=1;j<=i-1;j++) {
			// 枚举右端点
			for(int k=i+1;k<=n;k++) {
				if(a[j]<a[i] && a[i]<a[k]) {
					cnt++;
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  5
  1 2 5 3 5
  输出样例:
  2
 */
