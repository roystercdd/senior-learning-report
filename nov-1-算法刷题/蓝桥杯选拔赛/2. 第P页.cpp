#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 不就是推一个分页查询的标准公式吗
  
 */

const int N=1e5+5;

int t,a,p; // t个商品, 每页显示a个, 求第p页最小与最大编号

int main() {
	cin>>t>>a>>p;
	// 1~a, a+1~2a, 输出最小和最大的时候都判断一下是否超过最大值
	cout<< min((p-1)*a+1,t) <<' '<< min(p*a,t);
	return 0;
}

/*
  输入样例:
  31 10 4
  输出样例:
  31 31
 */
