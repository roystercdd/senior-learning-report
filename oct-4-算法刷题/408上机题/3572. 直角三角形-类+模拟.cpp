#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 又是一道类的感受题嗷,类这个概念我真不咋用,但是可能也怕考到吧
  哥们要用就直接用结构体去了
  
 */

const int N=1e5+5;
const double eps=1e-8;

class CPoint {
	double x,y;
public:
	CPoint(double _x,double _y): x(_x),y(_y) {}
	double operator- (const CPoint& t) const {
		double dx=x-t.x,dy=y-t.y;
		return sqrt(dx*dx+dy*dy);
	}
};

class CTriangle {
	CPoint a,b,c;
public:
	// 三角形需要存储三个点在平面中的坐标
	CTriangle(CPoint _a,CPoint _b,CPoint _c): a(_a),b(_b),c(_c) {}
	bool check() {
		double s[]={a-b,b-c,c-a}; // 计算三条边的长度
		sort(s,s+3);
		// 判断是否是直角三角形
		return abs(s[0]*s[0]+s[1]*s[1]-s[2]*s[2])<eps;
	}
	double get_len() {
		return (a-b)+(b-c)+(c-a); // 周长,a,b,c都是点哈
	}
};

int main() {
	int T;
	cin>>T;
	while(T--) {
		double x0,y0,x1,y1,x2,y2;
		cin>>x0>>y0>>x1>>y1>>x2>>y2;
		CTriangle t({x0,y0},{x1,y1},{x2,y2});
		if(t.check()) puts("Yes");
		else puts("No");
		printf("%.2lf\n",t.get_len());
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
