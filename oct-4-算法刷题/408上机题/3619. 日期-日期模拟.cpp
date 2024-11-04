#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 今天12年4月12星期四,输入到12月31日之前的日期(月和日)
  通过一个(day+1)%7直接与星期做计算即可
  
 */

const int N=1e5+5;
// 2012年是闰年
const int months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int n,a[N];

int main() {
	int month,date;
	cin>>month>>date; // 输入月和日
	
	int m=4,d=12,day=4; // 4月12日起,今天是星期四
	// O(n)做法,每次增加一天
	// 蔡乐公式→O(1)时间计算星期
	while(m<month || d<date) {
		d++;
		if(d>months[m]) {
			d=1;
			m++;
		}
		day=(day+1)%7; // 直接计算是星期几
	}
	
	// 星期下标,下标0~6,表示星期天~星期一
	string names[]= {
		"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
	};
	
	cout<<names[day]<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
