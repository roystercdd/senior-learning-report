#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 栈模拟题,STL秒了
  题目非常贴心的告诉你如果栈中没有元素要忽略stk.pop()操作 呜呜 什么好人 避免你RE
  
 */

const int N=1e5+5;

int n,a[N],T;

int main() {
	while(cin>>T && T!=0) {
		stack<int> stk; // 新开一栈
		while(T--) {
			char op;
			int x; 
			cin>>op;
			if(op=='P') {
				cin>>x;
				stk.push(x);
			} else if(op=='O') {
				// 小知识 !stk.empty()比stk.size()更快
				if(!stk.empty()) {
					stk.pop();
				}
			} else if(op=='A') {
				if(stk.empty()) cout<<'E'<<'\n'; // '\n'比endl快
				else cout<<stk.top()<<'\n';
			}
		}
		puts("");
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
