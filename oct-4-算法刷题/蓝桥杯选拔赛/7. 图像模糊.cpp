#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 哈哈 卷积操作都来啦
  
 */

const int N=1e2+5;
// 我直接逆时针最后加上自己, 下标为0不用
const int dx[]={0,-1,-1,-1,0,1,1,1,0,0};
const int dy[]={0,-1,0,1,1,1,0,-1,-1,0};

int n,m,a[N][N];
int b[N][N]; // 用来记录备份, 最后输出b

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	// 以中心开始卷积
	int sum; // 求平均值
	int cnt; // 求有多少数参与计算
 	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			// 对于每一个新的a[i][j]都重新计算
			sum=0;
			cnt=0;
//			cout<<sum<<' '<<cnt<<'\n';
			// 遍历九个方向
			for(int k=1;k<=9;k++) {
				int xx=i+dx[k];
				int yy=j+dy[k];
				// 越界处理
				if(xx<1 || yy<1 || xx>n || yy>m) continue;
				sum+=a[xx][yy];
				cnt++;
			}
//			cout<<i<<' '<<j<<' '<<sum<<' '<<cnt<<'\n';
			// 更新这个位置的值
			b[i][j]=floor(sum/cnt);
		}	
	}
	// 遍历打印矩阵
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cout<<b[i][j]<<' ';
		}	
		puts("");
	}
	return 0;
}

/*
  输入样例:
  3 4
  0 0 0 255
  0 0 255 0
  0 30 255 255
  输出样例:
  0 42 85 127
  5 60 116 170
  7 90 132 191
 */
