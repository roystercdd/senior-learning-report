#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 模拟日期类,实现加一天的操作
  
 */

const int N=1e5+5;
// 题目说了保证不出现闰年下标1~12表示1~12月
const int months[] = {
	0,31,28,31,30,31,30,31,31,30,31,30,31
};

int n;

int main() {
	cin>>n;
	while(n--) {
		int year,month,date;
		cin>>year>>month>>date; // 年月日
		date++; // 加一天
		// 说明需要进一个月
		if(date>months[month]) {
			date=1;
			month++;
			if(month>12) {
				month=1;
				year++;
			}
		}
		// 年份范围1000~3000,管他的,还是补个前导0先
		printf("%04d-%02d-%02d\n",year,month,date);
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
