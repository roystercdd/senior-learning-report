#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 题目开先没读懂,判断一个数是否有不为1的完全平方因子→是否存在k>1使得k²整除n
  12的因子有2,3,4,6,6×6÷12=3能整除
  15的因子有:1,3,5,没有哪个因子的
  没读懂题目
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	while(cin>>n) {
		bool res=false;
		// 枚举所有因子,
		for(int i=2;i<=n/i;i++) {
//			cout<<i<<'\n';
			if(n%(i*i)==0) {
//				cout<<"Y"<<' '<<i<<'\n';
				res=true;
				break;
			}
		}
		if(res) puts("Yes");
		else puts("No");
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
