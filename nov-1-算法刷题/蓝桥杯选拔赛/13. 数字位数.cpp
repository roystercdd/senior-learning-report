#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 填空题, 很简单, 计算有多少个1位数, 多少个2位数, 多少个3位数, 多少个4位数即可
  
 */

const int N=1e5+5;

int n,a[N];


int main() {
	int len=0;
	len+=9; // 9个个位数, 1~9
	len+=2*90; // 99-10+1=90个两位数
	len+=3*900; // 999-100+1=900个三位数
	len+=4*(2020-1000+1);
	cout<<len;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
