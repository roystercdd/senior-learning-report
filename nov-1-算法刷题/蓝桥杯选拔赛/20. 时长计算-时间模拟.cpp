#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 这道题十分明显的时间模拟题, 计算两个时间的差值
  对两个时间的差值, 分别求取总秒数相减, 最终将其转换成HH:MM:SS即可
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	int h1,m1,s1;
	int h2,m2,s2;
	// 格式化输入用scanf
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	// 化总秒数
	int sum1=0,sum2=0;
	sum1=s1+m1*60+h1*3600;
//	cout<<sum1<<'\n';
	sum2=s2+m2*60+h2*3600;
//	cout<<sum2<<'\n';
	// 计算差值
	int diff=sum2-sum1;
//	cout<<diff<<'\n';
	// 将差值化为HH:MM:SS
	int h=diff/3600;
	int m=diff%3600/60;
	int d=diff%3600%60;
	printf("%02d:%02d:%02d",h,m,d);
	return 0;
}

/*
  输入样例:
  08:58:10
  17:20:31
  输出样例:
  08:22:21
 */
