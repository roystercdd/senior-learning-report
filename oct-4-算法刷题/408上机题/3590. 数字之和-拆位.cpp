#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: get_numbers:获取每一位上的数字之和
  
 */

const int N=1e5+5;

LL n;
LL get_numbers(LL n) {
	if(n==0) return 0;
	LL res=0;
	while(n) {
		res+=n%10;
		n/=10;
	}	
	return res;
}

int main() {
	while(cin>>n) {
//		cout<<INT_MAX<<'\n'; // 2×10^9 妥妥够
		cout<<get_numbers(n)<<' '<<get_numbers(n*n)<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
