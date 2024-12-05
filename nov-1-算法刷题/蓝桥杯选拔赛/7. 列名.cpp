#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 1~26 是A~Z, 27~702(702-27+1=676) 是AA~ZZ
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	int cnt=702;
	// 第一位
	for(int i=65;i<=90;i++) {
		for(int j=65;j<=90;j++) {
			for(int k=65;k<=90;k++) {
				cnt++;
				if(cnt==2022) printf("%c%c%c",i,j,k);
			}
		}
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
