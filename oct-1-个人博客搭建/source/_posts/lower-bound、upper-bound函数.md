---
title: lower_bound、upper_bound函数
date: 2024-10-03 12:49:57
categories: 学习
tags:
    - 算法竞赛
    - 函数速查
---

<meta name="referrer" content="no-referrer" />

# lower_bound和upper_bound

<!-- toc -->



## 1. 概述

* $lower\_bound()$ 和$upper\_bound()$ 都是基于**二分查找**在一个**排好序**的数组或容器（如 $vector,\ list,\ set$ ）中进行快速查找的函数，位于 $<algorithm>$ 标准库中，由于采用二分查找，所以函数的时间复杂度是 $O(log_2^n)$
* **划重点！基于二分查找！数组或容器必须有序！**



## 2. 函数使用

* $lower\_bound(begin,end,num)$：适用于**从小到大排序**的有序序列，从数组/容器的 $begin$ 位置起，到 $end-1$ 位置结束，查找第一个**大于等于** $num$ 的数字
  * 若找到则返回该数字的地址，通过减去起始地址 $begin$ 的技巧可以求得其在数组/容器中的下标，如 $lower\_bound(arr,arr+n,3)-arr$ 表示在数组 $arr$ 中查找第一个大于等于 $3$ 的元素在数组中的下标
  * 若找不到，则返回 $end$，即数组/容器最后一个元素的下一个元素

* $upper\_bound(begin,end,num)$：适用于**从小到大排序**的有序序列，从数组/容器的 $begin$ 位置起，到 $end-1$ 位置结束，查找第一个**大于** $num$ 的数字

  * 若找到则返回该数字的地址，通过减去起始地址 $begin$ 的技巧可以求得其在数组/容器中的下标，如 $upper\_bound(arr,arr+n,3)-arr$ 表示在数组 $arr$ 中查找第一个大于 $3$ 的元素在数组中的下标

  * 若找不到，则返回 $end$，即数组/容器最后一个元素的下一个元素

* $lower\_bound(begin,end,num,greater<type>())$：适用于**从大到小排序**的有序序列，从数组/容器的 $begin$ 位置起，到 $end-1$ 位置结束，查找第一个**小于等于** $num$ 的数字

  * 若找到则返回该数字的地址，通过减去起始地址 $begin$ 的技巧可以求得其在数组/容器中的下标，如 $lower\_bound(arr,arr+n,3,greater<int>())-arr$ 表示在数组 $arr$ 中查找第一个小于等于 $3$ 的元素在数组中的下标
  * 若找不到，则返回 $end$，即数组/容器最后一个元素的下一个元素

* $upper\_bound(begin,end,num,greater<type>())$：适用于**从大到小排序**的有序序列，从数组/容器的 $begin$ 位置起，到 $end-1$ 位置结束，查找第一个**小于** $num$ 的数字

  * 若找到则返回该数字的地址，通过减去起始地址 $begin$ 的技巧可以求得其在数组/容器中的下标，如 $upper\_bound(arr,arr+n,3,greater<int>())-arr$ 表示在数组 $arr$ 中查找第一个小于 $3$ 的元素在数组中的下标

  * 若找不到，则返回 $end$，即数组/容器最后一个元素的下一个元素



## 3. 案例代码

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;

int main() {
	// 升序
	int arr[]={1,3,2,8,5};
	sort(arr,arr+5);
	cout<<"序列为(从小到大排序):";
	for(auto x:arr) cout<<x<<' ';
	cout<<endl;
	// 1.lower_bound
	cout<<lower_bound(arr,arr+5,5)-arr<<endl; // 第一个大于等于5的是5,下标是3
	// 2.upper_bound
	cout<<upper_bound(arr,arr+5,6)-arr<<endl; // 第一个大于6的是8,下标是4
	
	// 降序
	sort(arr,arr+5,greater<int>()); // greater<int>()表示降序规则
	cout<<"序列为(从大到小排序):";
	for(auto x:arr) cout<<x<<' ';
	cout<<endl;
	// 3.lower_bound
	cout<<lower_bound(arr,arr+5,3,greater<int>())-arr<<endl; // 第一个小于等于3的是3,下标是2
	// 4.upper_bound
	cout<<upper_bound(arr,arr+5,3,greater<int>())-arr<<endl; // 第一个小于等于3的是2,下标是3
	return 0;
}
```
