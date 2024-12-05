#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 找x=a^2-b^2 一看就要逆枚举
  x=2021, 最接近的a和b是 1011²-1010²(当b有最大值时 可找到a最大时整体结果的最小值)
  所以 a和b 最大值为1011
  
 */

const int N=1011;

bool vis[N*N]; 

int main() {
	// 遍历a²-b²(b最小为0 最大为i-1)
	for(int i=1;i<=N;i++) {
		for(int j=0;j<i;j++) {
			int idx=i*i-j*j;
			vis[idx]=1;
		}
	}	
	int cnt=0;
	for(int i=1;i<=2021;i++) if(vis[i]) cnt++;
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
