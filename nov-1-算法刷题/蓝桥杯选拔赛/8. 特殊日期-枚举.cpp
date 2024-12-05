#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 直接枚举就好, 对year拆位求和, 枚举月份和日
  月份注意要考虑到闰年的情况, 用数组表示即可
  
 */

const int N=1e5+5;

int n,a[N];
int mounths[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; // 平年

// 对数拆位并计算求和
int fun(int x) {
	int sum=0;
	while(x) {
		sum+=x%10;
		x/=10;
	}
	return sum;
}

int cnt;

int main() {
	// 枚举年份
	for(int year=1900;year<=9999;year++) {
		// 闰年
		if(year%4==0 && year%100!=0 || year%400==0) mounths[2]=29;
		else mounths[2]=28; // 注意这里要把months改回来
		// 枚举月份
		for(int i=1;i<=12;i++) {
			// 枚举天数
			for(int j=1;j<=mounths[i];j++) {
				int m=i;
				int d=j;
				if(fun(year)==fun(m)+fun(d)) {
//					cout<<year<<' '<<m<<' '<<d<<'\n';
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
