#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 数组为L, n个大小为一组, k个位置不能用, 问至多多少组
  直接用不能停车的位置和上一个位置做除法下取整就可以了
  直到长度到达L
  
 */

const int N=1e5+5;

int L,k,n; // 总长度, 一个车位长度, 不能用的区域
vector<int> park;

int main() {
	cin>>L>>k>>n;
	for(int i=1;i<=n;i++) {
		int tmp;
		cin>>tmp;
		park.push_back(tmp);
	}
	int last=1; // 记录上一个使用的车位
//	cout<<last<<'\n';
	int ans=0;
	for(auto item:park) {
		// item-1 是最后一个可用的位置
		// last 是第一个未被使用的位置
		ans+= (item-last)/k; // 有几个车位
		last=item+1;
//		cout<<last<<'\n';
	}
	// 到L, 共L-last+1个
	ans+=(L-last+1)/k;
	cout<<ans;
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
