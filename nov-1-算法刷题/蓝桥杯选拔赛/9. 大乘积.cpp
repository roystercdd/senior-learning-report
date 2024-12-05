#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;
const int a[]={99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77};;

int cnt;

int main() {
	int len=sizeof(a)/sizeof(a[1]);
	for(int i=0;i<len-1;i++) {
		for(int j=i+1;j<len;j++) {
			int res=a[i]*a[j];
			if(res>=2022) cnt++;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
