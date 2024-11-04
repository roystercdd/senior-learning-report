#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 数学推导,详见md
  
 */

const int N=1e5+5;

int n;

int main() {
	cin>>n;
	n*=2; // 变成2n
	
	bool flag=false; // 是否有解
	// 先枚举2n的所有约数,最少有两项,所以x>1
	for(int x=sqrt(n);x>1;x--) {
		// 如果是约数,则令为x,xy=2n,则y=2n/x
		if(n%x==0) {
			int y=n/x; // y是首项,这里n已*=2
			int k=x; // 表明从y开始向后k项
			int t=y-(x-1); // 公式推导y-(x-1)必须为偶数
			if(t%2==0) {
				int a=t/2; // 首项a=(y-(x-1))/2
				for(int j=a;j<a+k;j++) {
					printf("%d ",j);
				}
				puts("");
				flag=true;
			}
		}
	}
	if(!flag) puts("NONE");
	return 0;
}

/*
输入样例:
25
输出样例:
3 4 5 6 7
12 13
*/
