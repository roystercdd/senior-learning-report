#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 先输入星期几 再问过了几天是星期几
  样例中w=6, n=10, 10天过后星期六变成星期几?
  7天一循环, 关键是对n要模7
  
 */

const int N=1e5+5;

int w,n;

int main() {
	cin>>w>>n;
	// %7等于0 则输出星期天, 否则正常星期日
	cout<< ((w+n)%7==0?7:(w+n)%7) <<endl;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
