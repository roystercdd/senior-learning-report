#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 先输入这几个信号塔, 再遍历二维矩阵, 看哪些点在里面
  无非就是计算 点与点之间的距离是否小于等于R²
  
 */

const int N=1e5+5;

int n,m,t,r; // 长宽, 数量, 半径
int cnt;

int main() {
	cin>>n>>m>>t>>r;
	vector<PII> v; // 存放信号塔的坐标
	while(t--) {
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	// 遍历二维数组每一个点, 共 W+1 × H+1
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			// 遍历每一个信号塔看是否冲突
			for(auto it:v) {
				if( (it.x-i)*(it.x-i)+(it.y-j)*(it.y-j)<=r*r ) {
					cnt++; 
					break; // 被一个覆盖到了就行 所以break掉
				}
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}

/*
  输入样例:
  10 10 2 5
  0 0
  7 0
  输出样例:
  57
 */
