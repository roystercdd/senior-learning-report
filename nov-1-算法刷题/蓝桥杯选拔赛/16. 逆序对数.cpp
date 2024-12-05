#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 求逆序对的个数嘛, 归并排序板子直接掏出来
  
 */

const int N=1e5+5;

int n;
int a[]={0,87,39,35,1,99,10,54,1,46,24,74,62,49,13,2,80,24,58,8,14,83,23,97,85,3,2,86,10,71,15};
int tmp[N];
int res; // 计算逆序对个数

// 从数组长度l,r中进行
void merge_sort(int l,int r) {
	if(l>=r) return; // 边界条件, 不可再分
	int mid=l+r>>1; // 分治
	// 先分
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	// 合并
	int k=0,i=l,j=mid+1; // 两部分数组装入tmp中
	while(i<=mid && j<=r) {
		// a[i]<=a[j] 优先装入tmp, 从小到大
		if(a[i]<=a[j]) tmp[k++]=a[i++];
		else {
			// 否则发现a[i]>a[j] 则是一个逆序对
			// 那a[i]右侧的也比a[j]大, 共mid-i+1个
			tmp[k++]=a[j++];
			res+=(mid-i+1);
		}
	}
	// 如果左半没装完
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	
	// 把tmp赋值给a
	for(int i=l,j=0;i<=r;i++,j++) a[i]=tmp[j];
}

int main() {
	// 先求个长度吧
	int len=sizeof(a)/sizeof(a[0])-1; // 下标从1~len
//	cout<<len<<'\n';
//	for(int i=1;i<=len;i++) {
//		cout<<a[i]<<' ';
//	}
//	puts("");
	merge_sort(1,len);
	cout<<res<<'\n';
	return 0;
}

/*
  输入样例:
  
  输出样例:
  
 */
