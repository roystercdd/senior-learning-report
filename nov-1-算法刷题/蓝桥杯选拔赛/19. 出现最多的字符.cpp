#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 考输入输出的, 不定行定长和不定行不定长都可以用while(cin>>s)解决
  
 */

const int N=1e5+5;

string s;
map<char,int> m; // 记录字符出现了多少次

int main() {
//	while(cin>>s) {
//		for(int i=0;i<s.size();i++) {
//			m[s[i]]++;
//		}
//	}
//	int mmax=INT_MIN;
//	char idx;
//	for(auto it:m) {
//		if(it.y>mmax) {
//			mmax=it.y;
//			idx=it.x;
//		}
//	}
//	cout<<idx<<'\n';
//	cout<<mmax<<'\n';
	cout<<78<<'\n';
	return 0;
}

/*
  输入样例:
  FFEEFEAAECFFBDBFBCDA
  DACDEEDCCFFAFADEFBBA
  FDCDDCDBFEFCEDDBFDBE
  EFCAAEECEECDCDECADDC
  DFAEACECFEADCBFECADF
  DFBAAADCFAFFCEADFDDA
  EAFAFFDEFECEDEEEDFBD
  BFDDFFBCFACECEDCAFAF
  EFAFCDBDCCBCCEADADAE
  BAFBACACBFCBABFDAFBE
  FCFDCFBCEDCEAFBCDBDD
  BDEFCAAAACCFFCBBAAEE
  CFEFCFDEEDCACDACECFF
  BAAAFACDBFFAEFFCCCDB
  FADDDBEBCBEEDDECFAFF
  CDEAFBCBBCBAEDFDBEBB
  BBABBFDECBCEFAABCBCF
  FBDBACCFFABEAEBEACBB
  DCBCCFADDCACFDEDECCC
  BFAFCBFECAACAFBCFBAF
  输出样例:
  
 */
