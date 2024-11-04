#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 直接查位运算技巧
  2^31-1刚好是int所能表达的最大范围
  需要注意的是最右边为第0位
  
 */

const int N=1e5+5;

int x,i,j; // 交换x 2进制表示下的第i位和第j位

int main() {
	cin>>x>>i>>j;
	// 提取x二进制表示的第i位 x>>i&1
	int a=x>>i&1,b=x>>j&1;
	// 如果a和b不等则交换一下,相等则不用处理
	// 交换无非是0变1,1变0,所以亦或一下这一位即可
	if(a!=b) {
		x^=(1<<i); // 也可以不加括号
		x^=(1<<j);
	}
	cout<<x<<'\n';
	return 0;
}

/*
输入样例:
38 2 4
输出样例:
50
 */
