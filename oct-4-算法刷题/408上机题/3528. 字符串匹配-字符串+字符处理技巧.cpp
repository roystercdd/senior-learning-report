#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 不区分大小写的比对,感觉难点也在字符串的划分上面
  1) 不区分大小写比对 大写→小写,小写→大小都要考虑到,那就+32,-32,或者本身就相等吧
  
 */

const int N=1e3+5;

int n;

vector<string> str; // 字符串集

// 不区分大小写
bool equal(char a,char b) {
	if(a==b || a+32==b || a-32==b) return true;
	return false;
}

int main() {
	cin>>n;
	string tmp;
	while(n--) {
		cin>>tmp;
		str.push_back(tmp);
	}
	string p; //原串
	cin>>p;
	// 遍历每个字符串
	// i→字符串集
	// j→字符串集中的字符串
	// k→原串
	int i,j,k;
	for(i=0;i<str.size();i++) {
		// 匹配串
		k=0;
		int ans_idx; // 答案下标
		string ans_str; // 答案字符串
		bool flag=false; // 初始找不到
		for(j=0;j<str[i].size();) {
			// 原串k
			if(equal(str[i][j],p[k])) {
				j++,k++; // 这一位能匹配上
			}
			// 如果遇到左括号,则要特殊处理了,到右括号之前寻找是否有字符能相等
			else if(p[k]=='[') {
				for(;p[k]!=']';k++) {
					// 找得到
					if(equal(str[i][j],p[k])) {
//						cout<<i+1<<' '<<str[i]<<'\n'; // 输出这个字符串
						ans_idx=i+1;
						ans_str=str[i];
						flag=true;
					}
					// 如果找到最后一位了都找不到,说明不存在至少一个匹配,此时退出找下一个字符串
					if(p[k]==']') break;
				}
				// 结束的时候k指向的是']'的下一位,k不用走了,j还要++
				j++;
			}
			// 如果压根匹配不上,可以break去找下一个字符串了
			else {
				break;
			}
		}
		// 循环结束后如果有答案
		if(flag) {
			// 还有一种情况, ab 和 a[a2b]b ab中的b和括号中的b匹配,剩下的b无东西可匹配
			// 即k没匹配完,如果没匹配完,不输出
			if(k!=p.size()) {
				cout<<ans_idx<<' '<<ans_str<<'\n';
			}
		}
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
