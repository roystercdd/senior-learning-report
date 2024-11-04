#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 字符串匹配题,挺多技巧的,值得反复做
  1) 不区分大小写,那就把模式串和匹配串都改为小写来匹配
  2) 其他技巧详见代码
  
 */

const int N=1e3+10;

int n;
string str[N],p;

// 大写字符变小写
string filter(string str) {
	string res;
	for(auto c:str) res+=tolower(c);
	return res;
}

// p是否能与a满足题目中的匹配
// 关键在于遇到 '[' 时将 '['和']'之间的字符提取出来匹配
// 用的是find函数,手写很容易出错
bool match(string a,string p) {
	// j手动自增(匹配时),只要a和p一个串没走完就继续走
	for(int i=0,j=0;i<a.size() || j<p.size();i++) {
		// 如果一个串提前走完,说明没匹配成功
		if(i==a.size() || j==p.size()) return false;
		
		// 遇到'['之前的字符匹配
		if(p[j]!='[') {
			if(a[i]!=p[j]) return false;
			j++;
		}
		else {
			string s; // 提取 ' ' 之间的字符
			j++;
			while(p[j]!=']') s+=p[j++];
			j++; // 此时j指向 ']' 之后的下一个元素
			// 此时逻辑继续回到之前 p[j]!='[' 般比较
			// 找不到
			if(s.find(a[i])==-1) return false;
		}
	}
	return true;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>str[i];
	cin>>p;
	p=filter(p);
	
	for(int i=0;i<n;i++) {
		// 匹配成功
		if(match(filter(str[i]),p)) {
			cout<<i+1<<' '<<str[i]<<'\n';
		}
	}
	
	return 0;
}

/*
输入样例:
4
Aab
a2B
ab
ABB
a[a2b]b
输出样例:
1 Aab
2 a2B
4 ABB
 */
