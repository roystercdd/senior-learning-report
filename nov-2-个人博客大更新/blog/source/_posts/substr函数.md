---
title: substr函数
date: 2024-10-03 12:46:05
categories: 学习
tags:
    - 算法竞赛
    - 函数速查
---

<meta name="referrer" content="no-referrer" />

# 函数速查-substr

<!-- more -->



* $substr$ 函数用于截取字符串，$substr(pos,\ n)$ 指从指定字符串的 $pos$ 索引起向后截取 $n$ 个字符，具体使用方法见代码

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
	string s="01234567"; // 索引从0开始
	
	string s1=s.substr(); // 1)不传参等价于复制字符串
	cout<<s1<<endl; // 01234567
	
	string s2=s.substr(0,2); // 2)传递2个参数,截取从字符串s下标0开始往后的2个字符
	cout<<s2<<endl; // 01
	
	string s3=s.substr(4); // 3)传递1个参数,截取s索引为4到字符串尾部
	cout<<s3<<endl; // 4567
	
	string s4=s.substr(8); // 4)若pos超过了string的大小,不抛出异常但没有输出
	cout<<s4<<endl; // 不输出
	
	string s5=s.substr(2,10); // 5)若pos+n超过了string的大小,则自动调整n的值,最多只截取到s的末尾
	cout<<s5<<endl; // 234567
	
	string s6=s.substr(-1); // 6)pos传入负值,抛出out_of_range异常(RE运行时错误)
	cout<<s6<<endl; // 报错,RE
	
	string s7=s.substr(3,-2); // 7)n传入负值,则默认截取到字符串末尾
	cout<<s7<<endl; // 34567
	return 0;
}
```
