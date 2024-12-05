#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 一眼差分, 每次清理(r1,c1)-(r2,c2)相当于这片地方全部-1
  -1过后再用一次前缀和把所有点加起来, 做一次枚举求哪些点还为1
  
 */

const int N=1e2+5;

int n,m,a[N][N],b[N][N]; // b是差分数组
int s[N][N]; // 做前缀和之后的数组

int main() {
	cin>>n>>m;
	// 原数组全为1, 1表示未清理, 0表示已清理
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			a[i][j]=1;
			// 差分是前缀和的逆运算
			b[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1]; 
		}	
	}
	int t;
	cin>>t;
	while(t--) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		// (x1,y1)-(x2,y2) 全部-1
		b[x1][y1]+=(-1);
		b[x1][y2+1]-=(-1);
		b[x2+1][y1]-=(-1);
		b[x2+1][y2+1]+=(-1);
	}
	int cnt=0;
	// 用一次前缀和求出s数组并输出
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+b[i][j];
//			cout<<s[i][j]<<' ';
			if(s[i][j]==1) cnt++; 
		}	
//		puts("");
	}
	cout<<cnt;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
