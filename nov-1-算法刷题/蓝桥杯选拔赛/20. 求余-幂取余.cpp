#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 幂取余板子题, 但是也可以这样想, 答案最终要对1000取余, 那么计算一个乘法
  在做乘法的过程中不断对1000取余即可
  因为每一次乘法都会引入一些数位, 而我们只关心末3位, 而任何比末3位大的数位都不会影响
  最后三位的结果, 所以每次取最后三位并不影响结果
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	int n=1; // 2^0
	for(int i=1;i<=2023;i++) {
		n=n*2%1000;
	}
	cout<<n;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
