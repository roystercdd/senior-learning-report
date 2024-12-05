#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  
 */

const int N=1e5+5;

int n,a[N];

// 把十进制数转换为其他进制数
string Iota(int num,int R) {
	string str; // 结果
	int rmd; // 余数
	char ch;
	
	if(num==0) str="0"; // 特判任意进制的0
	
	while(num) {
		rmd=num%R;
		ch=(rmd<10)?(rmd+'0'):(rmd-10+'A');
		str=ch+str;
		num/=R;
	}
	// 加前导0操作
	
	return str;
}

int cnt=0;

// 计算字符串str的数位和
int sum(string str) {
	int res=0;
	for(int i=0;i<str.size();i++) {
		res+=str[i]-'0';
	}
	return res;
}

int main() {
	n=1;
	while(1) {
		string num1=Iota(n,2);
		string num2=Iota(n,8);
		if(sum(num1)==sum(num2)) cnt++;
		if(cnt==23) {
			cout<<n;
			break;
		}
		n++;
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
