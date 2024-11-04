#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 求连续区间和等于某数,我首先想到的是前缀和
  但是下面的做法是二维的,铁定会TLE
  
 */

const int N=1e7+5;

int n;
int a[N]; // a[i]=i 
int s[N]; // 维护a的前缀和

int main() {
	cin>>n;
	// 预处理到n之前的前缀和
	for(int i=1;i<=n;i++) {
		a[i]=i;
		s[i]=s[i-1]+a[i];
	}
	bool flag=false; // 是否有解
	// 枚举起点
	for(int i=1;i<n;i++) {
		// 枚举终点
		for(int j=1+1;j<n;j++) {
			if(s[j]-s[i-1]==n) {
				flag=true;
				// 找到解则输出这个连续的区间
				for(int k=i;k<=j;k++) {
					cout<<k<<' ';
				}
				puts("");
			}
		}
	}
	if(!flag) cout<<"NONE";
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
