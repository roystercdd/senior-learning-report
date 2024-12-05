#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 同理, 枚举3个数字即可
  
 */

const int N=1e5+5;

int a,b,c;
set<int> s;

int main() {
	int cnt=0;
	// 三个数之间都不超过2
	for(a=1;a<=99;a++) {
		for(b=a;b<=a+2;b++) {
			for(c=b;c<=a+2;c++) {
				cnt++;
				if(cnt==23) {
					cout<<a*b*c<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
