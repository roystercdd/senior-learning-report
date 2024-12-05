#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 太简单了哥子, 其实就是星期几问题
  
 */

const int N=1e5+5;

int n,a[N];
string dang[]={"low","mid","high"};

int main() {
	cin>>n;
	cout<<dang[n%3];
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
