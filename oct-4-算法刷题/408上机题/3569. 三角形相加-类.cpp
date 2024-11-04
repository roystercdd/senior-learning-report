#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 仿yxc,直接写一个类来操作
  
 */

const int N=1e5+5;

int n,a[N];

class CTriangle {
	int y,x;
public:
	CTriangle(int _y,int _x): y(_y),x(_x) {}
	CTriangle operator+ (const CTriangle& t) const {
		return CTriangle(y+t.y,x+t.x);
	}
	string to_string() {
		char s[30];
		sprintf(s,"A(0,%d),B(0,0),C(%d,0)",y,x);
		return s;
	}
};

int main() {
	CTriangle t(0,0); // 初始化一个类,注意方法必须是public
	int y,x;
	while(cin>>y, y) {
		cin>>x;
		CTriangle r(y,x);
		t=t+r;
	}
	cout<<t.to_string()<<endl;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
