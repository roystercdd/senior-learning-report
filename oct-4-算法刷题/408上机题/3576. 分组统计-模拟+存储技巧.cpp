#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: n个数分别出现m个数字(m<=n),并将n个数分为k组
  统计每组中每个数值有多少个
  
 */

const int N=1e2+5;

int T;
int n,k;
int a[N]; 

map<int,map<int,int>> m; // m[i][j],第i组中数字为j的频度
set<int> s; // 记录不重复的数字

int main() {
	cin>>T;
	while(T--) {
		cin>>n;
		k=0;
		m.clear(); // 清空映射
		s.clear(); // 清空不重复数字集
		
		// 输入n个数
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			s.insert(a[i]);
		}
		
		// 每个数分别属于哪个组
		for(int i=1;i<=n;i++) {
			int t;
			cin>>t;
			m[t][a[i]]++; // 第t组数字为a[i]的频度+1
			k=max(k,t); // 记录最大的组号
		}
		
		// 打印m中的值
//		for(int i=1;i<=k;i++) {
//			for(auto it:m[i]) {
//				cout<<it.first<<' '<<it.second<<'\n';
//			}
//		}
//		puts("");
		
		// 输出每组统计结果
		// i:组别
		for(int i=1;i<=k;i++) {
			printf("%d={",i);
			bool first=true;
			for(auto item:s) {
				if(!first) cout<<",";
				// 输出数字和频度
				if(m[i].find(item)!=m[i].end()) printf("%d=%d",item,m[i][item]);
				else printf("%d=0",item);
				first=false;
			}
			puts("}");
		}
	}
	
	return 0;
}

/*
  输入样例:
  1
  7
  3 2 3 8 8 2 3
  1 2 3 2 1 3 1
  输出样例:
  1={2=0,3=2,8=1}
  2={2=1,3=0,8=1}
  3={2=1,3=1,8=0}
  
 */
