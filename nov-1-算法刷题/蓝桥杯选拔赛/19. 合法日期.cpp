#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 定义一个日期数组即可, 然后2021是平年哈
  
 */

const int N=1e5+5;
const int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int n,a[N];
int m,d;

int main() {
	cin>>m>>d;
	if(m>12) {
		cout<<"no";	
		return 0;
	}
	if(d>months[m]) {
		cout<<"no";
		return 0;
	}
	cout<<"yes";
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
