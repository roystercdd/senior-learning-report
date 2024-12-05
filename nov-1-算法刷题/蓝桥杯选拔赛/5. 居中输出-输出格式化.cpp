#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 用printf只能补前导0, 那就用setfill
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	string s;
	cin>>s;
//	cout<<setfill('=')<<setw(10)<<s;
	// 如果s.size()是偶数, 说明可以补在最中间, 左右两边各 (10-len)/2 个等号
	int len=s.size();
	if(len%2==0) {
		// 先右对齐, 再左对齐
		int all=len+(10-len)/2;
		cout<<right<<setfill('=')<<setw(all)<<s;
		// 再输出(10-len)/2个, 因为输出了一个空字符, 所以要+1
		cout<<setfill('=')<<setw((10-len)/2+1)<<' ';
	} else {
		// 左边比右边多一个
		// 先右对齐输出左边
		int all=len+(10-(len+1))/2+1;
		cout<<right<<setfill('=')<<setw(all)<<s;
		cout<<setw((10-len)/2+1)<<' ';
	}
	
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
