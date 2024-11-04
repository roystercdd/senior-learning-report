#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 最长公共子串板子题
  
 */

const int N=1e2+10;

int n,a[N];
char sa[N],sb[N];
int f[N][N]; // f[i][j]:当sa下标为i,sb下标为j时的最长公共子序列长度
int st=0,len=0; // 开始位置和长度
int ans=0; // 最长连续子串长度

// 最长公共子序列
void LCS(int n,int m) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			// 如果相同,则长度+1
			if(sa[i]==sb[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=0;
		
			// 记录最长的结果(输出最后一个)
			if(f[i][j]>=len) {
				len=f[i][j];
				st=i-len+1; // 起始位置
			}
			
			ans=max(ans,f[i][j]);
		}	
	}
}

int main() {
	cin>>sa+1>>sb+1;
	int n=strlen(sa+1);
	int m=strlen(sb+1);
	LCS(n,m);
	cout<<ans<<'\n';
	// 还要输出这个最长子序列
	// 当n==0 && m==0时跳出循环
	for(int i=st;i<=st+len-1;i++) {
		cout<<sa[i];
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
