#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 我觉得贪心吧, 字典序最小
  肯定越靠前的越小越好, 所以遍历一遍
  如果当前字符比下一个字符大, 就把当前字符删了
  但是总感觉这样做有BUG =-= 是这么贪的吗
  
 */

const int N=1e5+5;

int n,a[N];

int main() {
	string s;
	cin>>s;
	// 操作有t步
	cin>>n;
	while(n--) {
		for(int i=0;i<s.size();i++) {
			if(s[i]>s[i+1]) {
				s.erase(i,1); // 删除i开始向后一个元素
				break;
			}
		}
	}
	cout<<s; // 好吧 想了想应该是对的
	return 0;
}

/*
  输入样例:
  LANQIAO
  3
  输出样例:
  AIAO
 */
