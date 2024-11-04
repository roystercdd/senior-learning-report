#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 一个简单的日期模拟
  
 */

const int N=1e5+5;

int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};;

// 计算是否为闰年,四年一闰,百年不闰,四百年又闰
int is_leap(int y) {
	if(y%4==0 && y%100 || y%400==0) return 1;
	return 0;
}

int T;

int main() {
	cin>>T;
	while(T--) {
		int y,m,d,s; // 在y-m-s的基础上加上s天
		cin>>y>>m>>d>>s;
		if(is_leap(y)) months[2]=29;
		else months[2]=28;
		
		while(d+s>months[m]) {
			// 先计算到下个月的1号
			s-=months[m]-d+1;
			d=1;
			m++;
			// 计算到下一年
			if(m>12) {
				m=1;
				y++;
				// 是否是闰年
				if(is_leap(y)) months[2]=29;
				else months[2]=28;
			}
		}
		d+=s; // 加上剩下的天数
		printf("%d-%02d-%02d\n",y,m,d); // 打印年月日
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
