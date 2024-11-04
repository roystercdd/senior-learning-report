#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 
  把每个数字定义为结构体,存储位数和本身的值,再用自定义cmp排序
  对于负数,临时变量存储其绝对值进行拆位
  
 */

const int N=1e6+5;

int n,a[N];

struct Num{
	int len; // 长度
	int x; // 大小
}num[N];

bool cmp(Num a,Num b) {
	if(a.len!=b.len) return a.len>b.len;
	return a.x<b.x;
}

// 考点就在这儿了,对0进行特判
int count(int n) {
	if(n==0) return 1;
	int cnt=0;
	while(n) {
		cnt++;
		n/=10;
	}
	return cnt;
}

int main() {
	int tot=1; // 数字存储因子
	int tmp;
	while(scanf("%d",&tmp)!=EOF) {
		num[tot].len=count(abs(tmp)); // 数位
		num[tot].x=tmp;
		tot++;
	}
	sort(num+1,num+tot,cmp);
	for(int i=1;i<=tot-1;i++) cout<<num[i].x<<' ';
	return 0;
}

/*
输入样例:
10 -3 1 23 89 100 9 -123
输出样例:
-123 100 10 23 89 -3 1 9
 */
