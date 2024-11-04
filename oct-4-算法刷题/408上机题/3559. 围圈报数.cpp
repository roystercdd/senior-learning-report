#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 就是约瑟夫环,用数组模拟固然简单,题目说用环形链表模拟
  即是把数组最后一位的值置为第一个元素即可
  而且本体固定报3退出,所以直接ne[ne[st]]即可表示第三个人
  
 */

const int N=1e5+5;

int n,T,ne[N];

int main() {
	cin>>T;
	while(T--) {
		memset(ne,0,sizeof ne); // ne数组清空
		cin>>n;
		for(int i=1;i<=n;i++) ne[i]=i+1; // 第i个指向第i+1个元素
		ne[n]=1; // 指回第一个
		
		int st=n; // ne[i]表示实际编号,ne[n]才是第一个
		// 输出n个人的退出顺序(进行n次操作)
		while(n--) {
			st=ne[ne[st]]; // st报1,ne[st]报2,ne[ne[st]]报3,而ne[st]是实际编号
			cout<<ne[st]<<' '; // 输出这个人的实际编号
			ne[st]=ne[ne[st]]; // 则st是ne[st]的上一个人,st的下一个直接指向ne[ne[st]]
		}
		puts("");
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
