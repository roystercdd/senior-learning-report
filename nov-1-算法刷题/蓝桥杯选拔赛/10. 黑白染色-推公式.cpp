#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 不就是一个洪泛吗, 狗屁洪泛, 长宽这么大, 没法用BFS模拟, 直接推公式
  如果列是偶数, 那么每一行上的黑白相同
  如果列是奇数, 那么在一半的基础上再额外加一列, 行是奇则黑多n/2+1, 行是偶则黑多n
  
 */

const int N=1e5+5;

int n,m; // 长宽
int cnt; // 计数

signed main() {
	cin>>n>>m;
	// 列是偶数
	if(m%2==0) {
		cout<<m/2*n<<'\n';
	}	
	// 列是奇数, 则m-1是偶数, 先算这几列
	// 加上多出来的这列, 这一列有几个黑要看行
	else {
		if(n&1) cout<<(m-1)/2*n+(n+1)/2<<'\n';
		else cout<<(m-1)/2*n+n/2<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
