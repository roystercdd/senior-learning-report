#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 用一个while(1)遍历, 转换为二进制数再看是否有3个1即可
  
 */

const int N=1e5+5;

int n,a[N];
int cnt;

// 将十进制num转换成R进制
string Itoa(int num,int R) {
	string str;
	int rmd;
	char ch;
	if(num==0) str="0";
	while(num>0) {
		rmd=num%R;
		ch=(rmd<10)?(rmd+'0'):(rmd-10+'A');
		str=ch+str; // 拼在前面
		num/=R;
	}
	return str;
}

int ans;

int main() {
	int i=1;
	while(1) {
		string tmp=Itoa(i,2);
		int cnt=0;
		for(int i=0;i<tmp.size();i++) {
			if(tmp[i]=='1') cnt++;
		}
		if(cnt==3) ans++;
		if(ans==23) {
			cout<<i;
			break;
		}
		i++;
	}	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
