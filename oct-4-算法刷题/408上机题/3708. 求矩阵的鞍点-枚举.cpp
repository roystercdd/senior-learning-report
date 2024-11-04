#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 有点像计挑赛做过的一道真题
  1) 要找矩阵中在行上最大且列上最小的值,可能不存在,可能有多个
  2) 最简单的做法 2*O(n^2) 毕竟数据范围最小
  3) 尤其注意for循环结束后i和j的位置!!!
  
 */

const int N=1e2+5;

int n,m,a[N][N];


int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	int i,j;
	int tmp_i,tmp_j;
	// 枚举求每一行的最大值
	vector<int> vmax;
	vector<PII> vmax_index;
	for(i=1;i<=n;i++) {
		int mmax=INT_MIN;
		for(j=1;j<=m;j++) {
			if(a[i][j]>mmax) {
				mmax=a[i][j];
				tmp_i=i;
				tmp_j=j;
			}
		}
		vmax.push_back(mmax);
		vmax_index.push_back({tmp_i,tmp_j});
	} 
	// 枚举每一列的最小值
	vector<int> vmin;
	vector<PII> vmin_index;
	// 枚举每一列
	for(i=1;i<=m;i++) {
		int mmin=INT_MAX;
		// 每一行上的元素a[j][i]
		for(j=1;j<=n;j++) {
			if(a[j][i]<mmin) {
				mmin=a[j][i];
				tmp_i=i;
				tmp_j=j;
			} // 爱你
		}
		vmin.push_back(mmin);
		vmin_index.push_back({tmp_i,tmp_j});
	} 
	
	// 输出艾尼测试
	// 每一行的最大值
	for(auto mmax:vmax) cout<<mmax<<' ';
	puts("");
	for(auto item:vmax_index) cout<<item.first<<' '<<item.second<<' ';
	puts("");
	for(auto mmin:vmin) cout<<mmin<<' ';
	puts("");
	for(auto item:vmin_index) cout<<item.first<<' '<<item.second<<' ';
	puts("");
	
	// 如果这一行的最大值的坐标恰为这一列的最小值的坐标
	for(i=0;i<min(vmax.size(),vmin.size());i++) {
		if(vmax_index[i].first==vmin_index[i].first && vmax_index[i].second==vmin_index[i].second) {
			cout<<vmax_index[i].first<<' '<<vmax_index[i].second<<' '<<vmax[i]<<'\n';
		}
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
