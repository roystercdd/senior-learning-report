#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 输入多个字符串,但是最多展示4个,后插入的先打印,直接借助数据结构vector使用push_front
  
 */

const int N=1e5+5;

int T;
string s;

int main() {
	deque<string> dq;
	cin>>T;
	while(T--) {
		cin>>s;
		dq.push_front(s);
		if(dq.size()>4) dq.pop_back(); // 去尾
		for(int i=0;i<dq.size();i++) {
			cout<<i+1<<"="<<dq[i]<<' ';
		}
		puts("");
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
