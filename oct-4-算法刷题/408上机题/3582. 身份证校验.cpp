#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 第一次写写错了,直接看yxc的了,最近手感不佳
  
 */

const int N=1e5+5;

// w每一位权重,r:余数为0~9时校验位对应的值
int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char r[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool check(string s) {
	if(s.size()!=18) return false;
	
	int sum=0;
	// 前17位不可能出现x撒
	for(int i=0;i<17;i++) {
		if(!isdigit(s[i])) return false;
		else sum+=w[i]*(s[i]-'0');
	}
	return s.back()==r[sum%11]; // s.back直接取校验位
}

int main() {
	string s;
	while(cin>>s) {
		if(check(s)) puts("ID Correct");
		else puts("ID Wrong");
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
