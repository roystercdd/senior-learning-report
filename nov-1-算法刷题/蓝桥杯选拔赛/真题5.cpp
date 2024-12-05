#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 贪心思想, 
  
 */

const int N=1e5+5;
const int Num[]={0, 9226, 4690, 4873, 1285, 4624, 1596, 6982, 590,
	8806, 121, 8399, 8526, 5426, 64, 9655, 7705, 3929, 3588, 7397,
	8020, 1311, 5676, 3469, 2325, 1226, 8203, 9524, 3648, 5278, 8647};

int n,a[N];

signed main() {
//	cout<<(3^5)<<endl; // 测试一下
	int ans=INT_MAX; // 找最小平方和
	int sum=0;
	int idx;
	// 枚举一个数嘛, 就硬枚举, 单调性不推了, 从1~1e6
	for(int i=1;i<=1e7;i++) {
		sum=0;
		for(int j=1;j<=30;j++) {
			sum+= (i^Num[j])*(i^Num[j]);
		}
		if(sum<ans) {
			ans=sum;
			idx=i;
			cout<<idx<<' '<<sum<<'\n';
		}
	}
	cout<<idx<<' '<<ans;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
