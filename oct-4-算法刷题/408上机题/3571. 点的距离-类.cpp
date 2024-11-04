#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 题目要求这个类有构造函数,并且重构"-"这个运算符(非友元重载)
  
 */

const int N=1e5+5;

int T;

class CPoint {
	double x,y;
// 公共方法
public:
	// 构造函数
	CPoint(double _x,double _y): x(_x),y(_y) {}
	// 重载算数运算符
	double operator- (const CPoint& t) const {
		double dx=x-t.x,dy=y-t.y;
		return sqrt(dx*dx+dy*dy);
	}
};

int main() {
	cin>>T;
	while(T--) {
		double x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		CPoint a(x1,y1),b(x2,y2);
		printf("%.2lf\n",a-b); // 重载运算符直接计算两点的距离
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
