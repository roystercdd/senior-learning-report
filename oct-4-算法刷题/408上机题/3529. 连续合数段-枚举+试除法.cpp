#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 没必要专门开一个vector存储具体有哪些元素,维护很麻烦
  只要知道末尾位置和长度,就可以打印出所有值(因为是连续的嘛)
  数据范围小,可以不用欧拉筛
  
 */

const int N=1e5+5;

int a,b;

// 试除法
bool is_prime(int n) {
	if(n<2) return false;
	for(int i=2;i<=n/i;i++) {
		if(n%i==0) return false;
	}
	return true;
}

int main() {
	cin>>a>>b;
	int s=0; // 连续合数段的长度
	int ans_len=0; // 长度
	int ans_end=0; // 末尾位置
	for(int i=a;i<=b;i++) {
		// 如果不是质数,即合数嘛
		if(!is_prime(i)) {
			s++;
			if(s>ans_len) {
				ans_len=s;
				ans_end=i; // 更新结束位置和长度,可回溯出合数段
			} 
		}
		// 遇到质数,清零
		else {
			s=0;
		}
	}
	// 打印
	for(int i=ans_end-ans_len+1;i<=ans_end;i++) {
		cout<<i<<' ';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
