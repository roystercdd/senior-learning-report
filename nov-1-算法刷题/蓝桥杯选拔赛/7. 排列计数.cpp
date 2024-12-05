#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 1~21中求全排列, 然后再check一下是否是奇不动
  啊不对 真打算老老实实写啊 当然是, 既然奇数已经固定了, 对偶数进行排列就是答案了
  2 4 6 8 10 12 14 16 18 20 共10个数字, 10的阶乘嘛
  
 */

const int N=1e5+5;

int n,a[N];

int fact(int x) {
	if(x==0) return 1;
	return x*fact(x-1);
}

int main() {
	cout<<fact(10);
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
