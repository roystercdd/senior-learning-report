#include<bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 对1~10^9的数字进行排列(位数为1~9),所以首先想到全排列
  
 */

const int N=9+5; // 最大9位

int n;
char a[N];
string ans; // 排列过后的结果
bool used[N]; // 判断每位是否被用过了
int mmax=INT_MIN; // 找最大值

// 在放第u位的数字
void dfs(int u) {
	// 1) 边界u>n
	if(u>n) {
//		cout<<ans<<'\n';
		// 维护一下最大值
		if(stoll(ans)%30==0) mmax=max(mmax,stoll(ans));
		return;
	}
	// 2) 枚举方案,即a[i]中每一位
	for(int i=1;i<=n;i++) {
		// 如果这一位未被使用,拼接
		if(!used[i]) {
			ans+=a[i];
			used[i]=true;
			dfs(u+1); // 去找下一位
			used[i]=false;
			// 没有字符串减法哈
//			ans-=a[i];
			ans.pop_back();  
		}
	}
}

signed main() {
	cin>>a+1;
	n=strlen(a+1); // 获取长度
//	cout<<n<<'\n';
	dfs(1);
	if(mmax==INT_MIN) mmax=-1; // 说明没找到
	cout<<mmax;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
