#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 任意两位相邻差值都为1, 数据范围大, 反着枚举
  枚举范围内的数字 判断其是否满足条件, 不如
  枚举满足条件的数字, 判断其是否在范围内
  最高位有9种取法, 后面的每一位要么比上一位+1, 要么-1, 都只有2种
  深搜最合适!!!
  
 */

const int N=1e5+5;

int n,a[N];
int l,r; // 左右端点
int ans; // 答案

// dfs(i): 第1位为i
// 非常细节的地方, 这里的x开成LL, 是因为x*10过后可能会爆int
void dfs(LL x) {
	if(x>r) return; // 超出范围,剪枝
	if(x>=l && x>=10) ans++;
	
	int d=x%10; // 最后一位
	// 如果d>=1 说明这一位是可以-1的
	if(d) dfs(x*10+d-1);
	// 如果d<9 说明这一位是可以+1的
	if(d<9) dfs(x*10+d+1);
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		scanf("%d%d",&l,&r);
		ans=0;
		// 枚举第一位, 9种情况
		for(int i=1;i<=9;i++) {
			dfs(i);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
