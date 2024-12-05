#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 填空题, 计算2020和3030的公约数的个数是吧
  我的思路是, 找二者的最大公约数, 然后遍历嘛
  
 */

const int N=1e5+5;

int n;
int a,b;
int cnt;

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b) {
	return a*b/gcd(a,b);
}

int main() {
	a=2020;
	b=3030;
//	cout<<gcd(a,b)<<'\n'; // 最大公约数1010
	// 遍历, 找公约数
	for(int i=1;i<=gcd(a,b);i++) {
		if(a%i==0 && b%i==0) {
			cnt++;
		}
	} 
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
