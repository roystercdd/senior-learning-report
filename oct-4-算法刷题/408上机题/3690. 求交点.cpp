#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const double eps=1e-8; // 误差

/*
  解题思路: 计算几何可以用向量法来求解,这样就不用管斜率不存在的情况来特判
  注意P/Q是点,u和v是向量,所以P表示的直线是P+t×v,Q表示的是Q+t×u
  两个向量的叉积表示这两个向量所围成的三角形的面积
  
 */

const int N=1e5+5;

// 求两个向量之间的叉积
double cross(PDD a,PDD b) {
	return a.x*b.y-a.y*b.x; // define
}

int n,a[N];

int main() {
	PDD p,v,q,u; // p,v第一条直线上两个点,q,u第二条上两个点
//	cin>>p.x>>p.y>>v.x>>v.y;
//	cin>>q.x>>q.y>>u.x>>u.y;
	scanf("%lf%lf%lf%lf",&p.x,&p.y,&v.x,&v.y);
	scanf("%lf%lf%lf%lf",&q.x,&q.y,&u.x,&u.y);
	// 直接利用v和u计算两点做差后的向量值
	v.x-=p.x,v.y-=p.y;
	u.x-=q.x,u.y-=q.y;
	// 1) 如果向量u和v(即两条直线之间的面积小于eps,说明重合或者平行)
	if(abs(cross(u,v))<eps) puts("Parallel or coincident");
	//	cout<<cross(u,v)<<'\n'<<u.x<<' '<<u.y<<' '<<v.x<<' '<<v.y<<'\n';
	// 2) 否则 根据推的公式来计算实际的坐标,根据相似三角形来计算t0/t的比例
	else {
		PDD w(p.x-q.x,p.y-q.y); // 连接PQ二点的向量
		double t=cross(w,u)/cross(u,v); // 比例即为t0
		PDD res(p.x+t*v.x,p.y+t*v.y);
//		cout<<fixed<<setprecision(2)<<res.x<<' '<<res.y<<'\n';
		printf("%.2lf %.2lf",res.x,res.y);
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
