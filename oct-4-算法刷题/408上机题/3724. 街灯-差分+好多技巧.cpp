#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: N个位置用多少盏街灯点亮(可以照亮前后K个位置)
  遍历每个灯的位置,对[x-k,x+k]这个区间内上快速加上1(差分思想)
  然后对差分数组b[i]做前缀和,枚举b[i]为0(没有灯)的位置,用ceil(c/(2*k+1))求最少灯数
  最后累计起来即可,技巧如下:
  1) 因为灯的范围是[x-k,x+k]共2k+1个位置,所以不管灯放的位置,直接用无灯区/(2k+1)即可
  2) 最后一个位置可能有灯,但是前面有一段无灯区,此时要对结尾进行特判
  可以直接对b[n+1](相当于额外开一个一定进入if的空间)位置置为1,这样一定会进入if
  3) (x-k) 或 (x+k) 可能越界,用1和n进行限界一下
  
 */

const int N=1e3+5;

int b[N];
int n,m,k; // 位置,灯数,范围


int main() {
	while(cin>>n>>m>>k) {
		memset(b,0,sizeof b); // 重置差分数组
		while(m--) {
			int x;
			cin>>x;
			// [x-k,x+k]差分++
			// 当然x-k或者x+k可能越界,所以边界处理
			int l=max(1,x-k),r=min(n,x+k);
			b[l]++,b[r+1]--;
		}
		// 对b做前缀和
		for(int i=1;i<=n;i++) {
			b[i]+=b[i-1];
		}
		// 渲染n+1位为1,这样一定会进入if,避免了无法结算灯盏的情况
		// for循环也要开到n+1
		b[n+1]=1;
		int res=0,len=2*k+1; 
		for(int i=1,c=0;i<=n+1;i++) {
			// 遇到有灯的了,对前面的无灯区进行结算
			if(b[i]) {
				res+=(c+len-1)/len; // 额外需要开的灯的数量,或者ceil(c/len)
				c=0;
			} else {
				c++;
			}
		}
		cout<<res<<'\n';
	}

	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
