#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 稍微需要绕一下, 用一个标志位表示下一个遇到元音/辅音时段数+1, 最后枚举
  并且第一次必须是str[i]为辅音, 且flag=0 才会进入cnt++, 也就是说第一段一定是辅音节
  
 */

const int N=1e5+5;

int n,a[N];
int cnt; // 记录段数

bool check_yuanyin(char ch) {
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
	return false;
}

int main() {
	string str;
	cin>>str;
	bool flag=0; // flag=0时找辅音; flag=1时找元音
	// 遍历字符串
	for(int i=0;i<str.size();i++) {
		// 如果是元音并且flag为1, cnt++
		if(check_yuanyin(str[i]) && flag) {
			cnt++;
			flag=0;
		}
		// 如果是辅音并且flag为0, cnt++
		if(!check_yuanyin(str[i]) && !flag) {
			cnt++;
			flag=1; // 遇到元音时段数+1
		}
		// 其他情况说明属于上一个元音/辅音节,无需处理
	}	
	// 统计完后看cnt是否为4段
	if(cnt==4) cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}

/*
  输入样例:
  lanqiao
  输出样例:
  yes
 */
