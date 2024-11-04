#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 这道题有点东西嘿 一般看到这么复杂的题目我直接懵了哦
  给定A,B 若A+i+(任意三位数)=(B+i)²则输出这样的数对
  其中A最大为10^6, i最大为99 所以数位最大可能为10^9, 若枚举A肯定TLE
  A最小为1+(i=0)+(任意三位数), 所以最小为1000
  所以选择去枚举B, B为根号A, 所以 sqrt(1000)<=B<=sqrt(10^9) 枚举次数是10^6级别的
  
 */

const int N=1e5+5;

int f(int b) {
	return b*b/1000; // b²求到a, /1000 丢掉末三位
} 

int main() {
	int n,ma;
	cin>>n>>ma; // ma是maxA
	
	int mb=sqrt((ma+n-1)*1000+999); // 任意三位最大值为999, *1000是提权
	// sqrt(1000)=31
	
	int cnt=0;
	// 每一个b→对应一个b²→对应一个a→如果a去掉后三位部分是由n+i构成的
	// b从32开始, 相当于a从1000开始的, f(b)从1开始
	for(int b=32;b<=mb;b++) {
		int a=f(b); // 丢掉b*b的末三位, 即A+i的值
		bool success=true;
		// 计算a+i是否与f(b+i)相等
		// 题目要求对于任意的 a+i 都等于 f(b+i)
		for(int i=1;i<n;i++) {
			if(a+i != f(b+i)) {
				success=false;
				break;
			}
		}
		// 输出一组平方朋友对
		if(success) {
			printf("%d %d\n",a,b);
			cnt++;
		}
	}
 	if(!cnt) puts("No Solution.");
	return 0;
}

/*
输入样例:
3 85
输出样例:
73 272
78 281
82 288
85 293
 */
