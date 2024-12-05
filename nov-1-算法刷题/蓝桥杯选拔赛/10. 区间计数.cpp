#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 枚举咯
  
 */

const int N=1e5+5;

int n,a[N];
int cnt;

int main() {
	for(int l=0;l<=100;l++) {
		for(int r=0;r<=100;r++) {
			if(r-l>=10) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
