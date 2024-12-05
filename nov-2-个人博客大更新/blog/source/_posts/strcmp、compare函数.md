---
title: strcmp、compare函数
date: 2024-10-03 12:47:35
categories: 学习
tags:
    - 算法竞赛
    - 函数速查
---

<meta name="referrer" content="no-referrer" />

# 函数速查-strcmp、compare

<!-- toc -->

<!-- more -->



## 1. strcmp

* 用于字符数组之间的大小比较
* 比较原则：两个字符数组逐位比较$ASCII$码，首位$ASCII$码的更大的字符数组更大；当一个字符数组是另一个字符数组的前缀时，长度更长的字符数组更大
* $strcmp(str1,str2)$，若前者比后者大，返回$1$，若相等，返回$0$，若后者比前者大，返回$-1$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;

char str_1[20],str_2[20];

int main() {
	// 1)逐位比较ASCII码,首位ASCII码更大的字符串更大
	// 前者比后者大,返回1 
	strcpy(str_1,"CDEF");
	strcpy(str_2,"BCDE");
	cout<<strcmp(str_1,str_2)<<endl;
	// 两者相等,返回0
	strcpy(str_1,"abcde");
	strcpy(str_2,"abcde");
	cout<<strcmp(str_1,str_2)<<endl;
	// 前者比后者小,返回-1
	strcpy(str_1,"abcde");
	strcpy(str_2,"bbcde");
	cout<<strcmp(str_1,str_2)<<endl;
	// 2)其中一个字符串是另一个字符串的前缀,长度更长的字符串更大
	strcpy(str_1,"abcd");
	strcpy(str_2,"abcde");
	cout<<strcmp(str_1,str_2)<<endl;
	return 0;
}
```



## 2. compare

* 用于字符串之间的大小比较
* 比较原则：两个字符串逐位比较$ASCII$码，首位$ASCII$码的更大的字符串更大；当一个字符串是另一个字符串的前缀时，长度更长的字符串更大
* $strcmp(str1,str2)$，若前者比后者大，返回$1$，若相等，返回$0$，若后者比前者大，返回$-1$

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;

string str_1,str_2;

int main() {
	// 前者比后者大,返回1
	str_1="CDEF";
	str_2="BCDE";
	cout<<str_1.compare(str_2)<<endl;
	// 两者相等,返回0
	str_1="abcde";
	str_2="abcde";
	cout<<str_1.compare(str_2)<<endl;
	// 前者比后者小,返回-1
	str_1="abcde";
	str_2="bbcde";
	cout<<str_1.compare(str_2)<<endl;
	// 2)其中一个字符串是另一个字符串的前缀,长度更长的字符串更大
	str_1="abcd";
	str_2="abcde";
	cout<<str_1.compare(str_2)<<endl;
	
	// 3)比较特定位置开始的字符串
	int res_1=str_1.compare(1,3,str_2); // str_1从下标1开始的3个字符与str_2比较大小
	int res_2=str_1.compare(1,3,str_2,1,4); // str_1从下标1开始的3个字符与str_2从下标0开始的2个字符比较大小
	cout<<res_1<<endl;
	cout<<res_2<<endl;
	return 0;
}
```



## 3. 直接比较字符串

* 在$C++$中直接使用 $>, <, ==, >=, <= $这样的关系运算符也能比较字符串的大小，并且同样基于字符串中字符的字典顺序逐位字符比较，直到遇到不相同的字符或者一个字符串结束为止

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;

void str_compare(string a,string b) {
	if(a>b) cout<<"前者比后者大"<<endl;
	else if(a==b) cout<<"二者一样大"<<endl;
	else cout<<"前者比后者小"<<endl;
}

string str_1,str_2;

int main() {
	str_1="CDEF";
	str_2="BCDE";
	str_compare(str_1,str_2);
	// 两者相等,返回0
	str_1="abcde";
	str_2="abcde";
	str_compare(str_1,str_2);
	// 前者比后者小,返回-1
	str_1="abcde";
	str_2="bbcde";
	str_compare(str_1,str_2);
	// 2)其中一个字符串是另一个字符串的前缀,长度更长的字符串更大
	str_1="abcd";
	str_2="abcde";
	str_compare(str_1,str_2);
	return 0;
}
```



## 4. 字符数组/字符串按数值比较

* 比如现在有两个数字， $123456$ 和 $23456$ ，并且是以字符形式存储到字符数组/字符串中，现在要比较这两个字符数组/字符串的大小关系如果直接使用前文的比较方法(按$ASCII$码逐位比较就会出问题)，因为$1$的$ASCII$码小于$2$，但很明显$123456>23456$

* 如果在字符数组/字符串中按下标对其的话又略嫌麻烦，显然是想让$123456$和$23456$都从下标$0$开始存储，这个时候我们可以(在没有前导$0$的情况下)返回长度更长的那个数字，当长度相等的时候直接用$strcmp$或者$compare$比较两个字符串即可

``` c
#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

// 解题思路: 

const int N=1e5+5;

char str1[20],str2[20];
string str11,str22;

bool chars_compare(char str1[],char str2[]) {
	int len1=strlen(str1);
	int len2=strlen(str2);
	if(len1!=len2) return len1>len2;
	else return strcmp(str1,str2)>0;
}

bool str_compare(string str11,string str22) {
	int len1=str11.length();
	int len2=str22.length();
	if(len1!=len2) return len1>len2;
	else return str11.compare(str22)>0;
}
 
int main() {
	// 字符数组
	strcpy(str1,"123");
	strcpy(str2,"1234");
	cout<<chars_compare(str1,str2)<<endl;
	strcpy(str1,"34");
	strcpy(str2,"23");
	cout<<chars_compare(str1,str2)<<endl;
	// 字符串
	str11="123";
	str22="1234";
	cout<<str_compare(str11,str22)<<endl;
	str11="34";
	str22="23";
	cout<<str_compare(str11,str22)<<endl;
	return 0;
}
```
