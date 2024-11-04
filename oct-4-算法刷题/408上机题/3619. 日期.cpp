#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 首先年份定死了,也不用考虑闰年啥的(4月后)
  然后计算天数差再模7就可以咯
  
 */

const int N=1e5+5;
// 从5月份开始存,5~12月,下标从0到6
const int mounth[]={31,30,31,31,30,31,30,31};
const string week[]={" ","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int n,a[N];


int main() {
	int m,d; // m月d天
	cin>>m>>d;
	int cnt=0;
	if(m==4) {
		cnt=d-12;
	}
	else {
		int i=4;
		// 4月剩余的天数肯定为30-12+1=19了
		cnt=18;
//		i=5; // 变成5月
		// 中间几个月,加整的天数
		while(m-i>1) {
//			cout<<"现在是第"<<i<<"月,离"<<m<<"月还有"<<m-i<<"个月,"<<"加"<<mounth[i+1-5]<<"天\n";	
			cnt+=mounth[i+1-5]; // 从下标0开始
			i++;
		}
		// 加上最后一个月剩的零头天数
		cnt+=d;
	}
	// week[0]表示星期天
//	cout<<cnt<<'\n';
//	cout<<(cnt+4-1)%7+1<<'\n';
	cout<<week[(cnt+4-1)%7+1]<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
