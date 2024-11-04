#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 16进制不进位加法, 用hex即可, 但是如何不进位!
  2进制下的不进位加法其实就是异或运算啊!!!
  高精度加法, 不处理进位即可, 同时对高精度做16进制的处理
  
 */

const int N=1e5+5;

int n,a[N];

int get_int(char c) {
	if(c<='9') return c-'0';
	return c-'A'+10;
}

char get_char(int x) {
	if(x<10) return x+'0';
	return x-10+'A';
}

int main() {
	string a,b;
	while(cin>>a>>b) {
		vector<int> A,B;
		// 读入A(以数值形式读入方便计算)
		for(int i=a.size()-1;i>=0;i--) A.push_back(get_int(a[i]));
		// 读入B
		for(int i=b.size()-1;i>=0;i--) B.push_back(get_int(b[i]));
	
		vector<int> C; // 计算加和
		
		for(int i=0;i<A.size() || i<B.size();i++) {
			int t=0;
			if(i<A.size()) t+=A[i];
			if(i<B.size()) t+=B[i];
			C.push_back(t%16); // 不处理进位
		}
		
		// 倒序输出(16进制输出)
		for(int i=C.size()-1;i>=0;i--) cout<<get_char(C[i]);
		cout<<'\n';
	}
	return 0;
}

/*
  输入样例:
  123 456
  6 A
  输出样例:
  579
  0
 */
