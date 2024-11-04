#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<vector<int>> VVI; // 二维数组

/*
  解题思路: 矩阵变换
  顺时针旋转90° 手写代码很难写,用一张正方形卡纸很容易观察得到
  先沿对角线对称一遍,再沿纵轴对称一遍,就等价于矩阵旋转了90°
  那么我们顺时针旋转4次,检验哪次可以得到原矩阵
  
 */

const int N=1e5+5;

int n;
VVI a,b;

// 对c旋转90°
void rotate(VVI &c) {
	// 先沿对角线交换(遍历下三角)
	for(int i=0;i<n;i++) {
		for(int j=0;j<i;j++) {
			swap(c[i][j],c[j][i]);
		}
	}
	// 再沿纵轴交换
	// 枚举每一列
	for(int j=0;j<n;j++) {
		// 分别从首尾枚举这一列上的元素,两两交换
		for(int i=0,k=n-1;i<k;i++,k--) {
			swap(c[i][j],c[k][j]);
		}
	}
}

int main() {
	cin>>n;
	a=b=VVI(n,vector<int>(n)); // 两个二维矩阵
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	// 旋转4次
	for(int i=0;i<4;i++) {
		if(a==b) {
			cout<<i*90<<endl; // 0~270
			return 0;
		}
		rotate(b);
	}
	cout<<-1<<endl; // 没有角度
	return 0;
}

/*
  输入样例:
  3
  1 2 3
  4 5 6
  7 8 9
  7 4 1
  8 5 2
  9 6 3
  输出样例:
  90
 */
