#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 大数据%2023, 相当于每次运算都%2023, 如何找到这个运算?
  只需要用一个字符串存储每位数据×10复原原数据即可
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	string s="12345678901234567890123456789012345678901234567890";
	int ans=0; // 每次都%2023
	for(int i=0;i<s.size();i++) {
		ans=(ans*10+s[i]-'0')%2023;
//		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
