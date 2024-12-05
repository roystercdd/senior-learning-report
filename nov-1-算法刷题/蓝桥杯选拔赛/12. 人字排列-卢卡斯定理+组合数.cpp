#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: n为奇数 1~n先递增再递减排列, 那么n只能在最中间
  所以n-1中有一半在n之前, 一半在n之后, 只需要在n-1中选择(n-1)/2即可
  所以变成了求组合数的问题, 直接计算 C(n-1)((n-1)/2)
  对公式化简, 可以先累乘再累除, 但是答案要取模, 所以需要用乘法逆元
  但是乘法逆元我忘了, 所以直接用卢卡斯定理求解
  
 */

const int N=1e5+5;
const int MOD=1000000007;

int n;

int qmi(int a,int k,int p) {
	int res=1;
	while(k) {
		if(k&1) res=(LL)res*a%p;
		a=(LL)a*a%p;
		k>>=1;
	}
	return res;
}

// 计算Cab mod p
int C(int a,int b,int p) {
	if(b>a) return 0;
	int res=1;
	// a!(b!(a-b)!)=(a-b+1)*...*a/b! 
	// 每次除以i, 乘以j, 对i求逆元做乘法
	for(int i=1,j=a;i<=b;i++,j--) {
		res=(LL)res*j%p; 
		res=(LL)res*qmi(i,p-2,p)%p; // 乘法逆元
	}
	return res;
}

// 对公式敲卢卡斯
int lucas(LL a,LL b,int p) {
	if(a<p && b<p) return C(a,b,p); // lucas递归终点是C_{bk}^{ak}
	// a%p后肯定<p, 所以可以用C(), 但a/p后不一定<p 所以用lucas继续递归
	return (LL)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}

int main() {
	cin>>n;
	
	// 求解C(n-1)((n-1)/2), 使用卢卡斯定理
	cout<<lucas(n-1,(n-1)/2,MOD)<<endl;
	
	return 0;
}

/*
  输入样例:
  5
  输出样例:
  6
 */
