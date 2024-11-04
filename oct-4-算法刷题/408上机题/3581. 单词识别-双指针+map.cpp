#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 首先每个单词由空格,逗号和句号分隔,则可以用双指针提取每个单词
  输出单词的顺序及其词频从小到大,说明单词有序,可以用map
  统计单词时不区分大小写,则每次把s[i]的小写形式加入到字符串中即可
  
 */

const int N=1e5+5;

string s;
map<string,int> cnt; // 统计单词及其词频

int main() {
	getline(cin,s);
	
	for(int i=0;i<s.size();i++) {
		// 遇到非字母跳过(空格,逗号,句号)
		if(!isalpha(s[i])) continue;
		string tmp;
		// 双指针跳过来,提取这个单词
		int j=i;
		while(j<s.size() && isalpha(s[j])) {
			tmp+=tolower(s[j]); // 不区分大小写
			j++;
		}
		cnt[tmp]++;
		i=j;
	}
	
	for(auto item:cnt) {
		cout<<item.first<<":"<<item.second<<'\n';
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
