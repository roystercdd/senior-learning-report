#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 太简单力
  
 */

const int N=1e5+5;

int n,a[N];
int cnt; // 统计洁净数

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		string str=to_string(i);
		for(int j=0;j<str.size();j++) {
			if(str[j]=='2') {
				cnt++;
//				cout<<i<<'\n';
				break;
			}
		}
	}
	cout<<n-cnt<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
