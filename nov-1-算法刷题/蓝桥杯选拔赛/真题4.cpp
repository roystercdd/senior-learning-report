#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 用字符串枚举年月日
  
 */

const int N=1e5+5;
int Months[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; // 平年
const string Weekday[]={"星期一","星期二","星期三","星期四","星期五","星期六","星期天"};
string s;

int cnt; // 好日期

int main() {
	int diff=0; // 计算相差多少天
	// 年
	for(int year=1901;year<=2024;year++) {
		s+=to_string(year);
		// 如果是闰年, 把Months[2]改成29
		if(year%4==0 && year%100!=0 || year%400==0) Months[2]=29;
		// 月
		for(int i=1;i<=12;i++) {
			if(!(i/10)) s+="0"; // 不足10
			s+=to_string(i);
			// 日
			for(int j=1;j<=Months[i];j++) {
				if(!(j/10)) s+="0";
				s+=to_string(j);
//				cout<<s<<' ';
				
				// 计算差日
				diff=0;
				int sum=0;
				// 年
				for(int x=1;x<=12;x++) sum+=Months[x]; 
				diff+=(year-1901)*sum;
				// 月
				for(int x=1;x<=i-1;x++) diff+=Months[x];
				// 日
				diff+=j;
				// 计算星期几
//				cout<<diff<<' ';
//				cout<<Weekday[diff%7]<<'\n';
				
				if(Weekday[diff%7]=="星期一" && s.back()=='1') {
					cout<<s<<' '<<diff<<' '<<Weekday[diff%7]<<'\n';
					cnt++;
				}
				
				s.pop_back();
				s.pop_back();
				
			}
			s.pop_back();
			s.pop_back();
		}
		for(int i=1;i<=4;i++) {
			s.pop_back();
		}
		Months[2]=28; // 置回来
		s.clear();
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
