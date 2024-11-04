#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 怎么北京✌的复试题全是简单模拟啊?
  
 */

const int N=1e5+5;

int T;

int main() {
	cin>>T;
	while(T--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x,y;
		x=a+c;
		y=b+d;
		char z;
		if(y==0) {
			printf("%d\n",x);
			continue;
		}
		else if(y>0) {
			printf("%d+%di\n",x,y);
			continue;
		}
		else {
			printf("%d%di\n",x,y); // 自带负号
			continue;
		}
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
