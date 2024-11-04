#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 首先单词长度是非常长的,重新排列能否构成不能用dfs
  看了一眼算法标签是前缀和,突然想到是否区间和相等能说明组成部分是相同的
  
 */

const int N=5e4+5;

string str;
string s1,s2;
int s[N]; // 计算前缀和

int main() {
	cin>>str;
	for(int i=0;i<str.size();i++) {
		if(i==0) s[i]=str[i];
		else s[i]=str[i]-str[i-1];
		cout<<s[i]<<' ';
	}
	puts("");
	int T;
	cin>>T;
	while(T--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a-=1,b-=1,c-=1,d-=1;		
		// 下标从0开始
		s1=str.substr(a,b-a+1);
		s2=str.substr(c,d-c+1);
		cout<<s1<<' '<<s2<<'\n';
		// 计算这部分前缀和是否相等即可
		if(s[b]-s[a-1]==s[d]-s[c-1]) cout<<"DA"<<'\n';
		else cout<<"NE"<<'\n';
	}
	
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
