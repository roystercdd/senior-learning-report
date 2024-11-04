#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 枚举优化+试除法
  1) 在数据范围内枚举末尾是1的数字,然后试除法判质数,本题规模是1e4,能过
  复杂度: 最后一位固定的四位数,相当于枚举前3位,1e3×试除法(根号n)
  2) 如果规模大,方法就应该是欧拉筛先筛出质数,改为哈希表存,枚举后比对是不是质数
  
 */

const int N=1e4+5;

int n,cnt,p[N]; // p[cnt]:第cnt个质数

// 数据范围不大,试除法拿质数
bool is_prime(int x) {
	if(x<2) return false;
	// 1) i<=sqrt(x), sqrt函数速度太慢了
	// 2) i×i<=x, 容易溢出
	// 3) i<=x/i 速度快且不溢出,最佳写法
	for(int i=2;i<=x/i;i++) {
		if(x%i==0) return false; // 不是质数 
	}
	return true;
}
	
int main() {
	// 枚举数据范围内末尾尾1的所有数,用于判质数
	int n;
	while(cin>>n) {
		bool flag=false; // 若不存在质数则输出-1
		// 1~n 中所有末尾为1
		// 手写模拟一下,首先i=1
		// (1/10+1)*10+1 = 11
		// (11/10+1)*10+1 = 21 ...
		// (91/10+1)*10+1 = 101 tiancai!
		for(int i=1;i<n;i=(i/10+1)*10+1) {
			if(is_prime(i)) {
				flag=true;
				cout<<i<<' ';
			}
		}
		if(!flag) cout<<"-1";
		puts("");
	}
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
