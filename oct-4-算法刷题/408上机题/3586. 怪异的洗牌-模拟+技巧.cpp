#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 对特定位置做一次shift操作和flip操作
  1) shift操作:右边拼到左边,就像字符串的最小表达式
     可以用原地算法,对[1,l]翻转一次,再对[r,n]翻转,再对整个数组翻转就达到了相同的效果
  
  2) flip操作:按照回文对称,对前半部分进行翻转
  
  3) reverse(first,last) 表示翻转 [first,last) 的元素,经典左闭右开
  
 */

const int N=1e3+10;

int n,k;
int w[N]; // 卡牌

int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		w[i]=i; // 1 2 3 ... n	
	}
	while(k--) {
		int x;
		cin>>x;
		
		// 1) shift
		// 先翻转 [1,x]
		reverse(w+1,w+1+x);
		// 再翻转 [x+1,n]
		reverse(w+1+x,w+1+n);
		// 再整体翻转
		reverse(w+1,w+1+n);
		
		// 2) flip 翻转(w+1,w+n/2+1)[n是奇数则恰不操作]
		reverse(w+1,w+n/2+1); // 下标从1开始时中位点是 (n-1)/2+1 
	}
	for(int i=1;i<=n;i++) {
		cout<<w[i]<<' ';
	}
	return 0;
}

/*
输入样例:
6 1
4
输出样例:
1 6 5 2 3 4
 */
