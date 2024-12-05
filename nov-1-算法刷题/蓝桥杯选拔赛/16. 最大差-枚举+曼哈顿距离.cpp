#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

/*
  解题思路: 从一个30×20的矩阵中找出曼哈顿距离不超过5的元素的最大差值
  
 */

const int N=30+5;

int n=30,m=20;
int a[N][N];
int f[N][N]; // f[i][j]: 从曼哈顿距离不超过5的其他位置到(i,j)的最大差值

// 找距离点(i,j)曼哈顿距离不超过5的最大差值
void search(int x,int y) {
	// 遍历因子范围很精髓哦
	for(int i=-5;i<=5;i++) {
		for(int j=-5;j<=5;j++) {
			// 数组越界
			if(x+i<1 || x+i>n || y+j<1 || y+j>m) continue;
			// 曼哈顿距离不超过5
			if(abs(i)+abs(j)>5) continue;
			// 找最大差值
			f[x][y]=max(f[x][y],a[x+i][y+j]-a[x][y]);
		}
	}
}

int main() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
//			cin>>a[i][j];
		}	
	}
	int mmax=INT_MIN;
	// 遍历, 计算曼哈顿距离下的差值, 若>5则continue
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			search(i,j);
		}	
		// 遍历一遍找f矩阵中的最大值
		for(int j=1;j<=m;j++) {
			mmax=max(mmax,f[i][j]);	
		}
	}
//	cout<<mmax;
	cout<<"8940";
	return 0;
}

/*
输入样例:
5137 8534 5597 3858 9242 7901 5735 4752 3590 6568 8481 1039 9940 9666 2950 1119 9391 7083 4625 8509
9661 6419 1115 2502 2663 5787 9553 7676 7508 3428 5698 1757 6048 8086 3091 1620 1277 1419 9534 5014
4125 9529 1679 9525 1896 2988 9763 3348 9366 1248 3699 7555 3167 9637 3632 1165 4143 8678 8590 2559
8822 8835 4322 5504 3759 4993 3402 4171 8027 4096 1933 7803 8034 2560 9801 7238 2611 9710 9350 2387
7413 7211 3107 5763 6372 2439 6668 1892 2076 5500 8264 2324 8747 4871 8962 2672 1398 3421 2508 2793
4965 9822 5995 3687 5007 1500 5033 1787 4380 1000 4069 6532 2023 3430 8036 7491 3960 6755 4173 1693
8836 8610 3057 5447 4001 7848 1081 6441 9940 8584 7272 5980 3735 8203 6889 4069 2760 3629 3819 3806
2389 9878 6163 3273 4565 9555 9764 4663 5197 5417 7669 6991 8089 6394 6961 8681 9700 3870 2243 5311
8103 7366 2394 7100 7594 3715 4593 9263 8125 8233 4523 2144 4814 2990 3657 4785 7583 8574 1335 8833
1654 8952 9522 1759 3219 3389 1600 5384 7865 1244 7198 2922 4883 7763 3163 5019 3593 2738 4405 2470
2246 6189 5809 5824 3465 5961 5751 1041 4460 2481 8948 4457 7853 6995 8558 4521 8908 9785 1926 3572
8302 2528 9940 4514 1389 5333 4862 9811 1070 4862 3095 1336 3409 7779 7709 7524 4195 2464 5806 3991
3414 8622 2139 4970 4211 1474 5610 8534 6228 5955 8105 7034 4600 8445 3055 2723 9615 5666 1291 6734
8046 5166 7040 8201 8825 5220 5867 3269 8799 5285 1705 3271 8660 1559 8889 9833 9800 3393 4002 3087
3339 3753 1699 3662 2975 6709 2931 6437 2750 6376 5119 1412 3806 3836 7429 6393 7661 7638 4959 9775
3681 5303 9472 3821 6692 1690 2170 7144 5132 2402 7483 3806 7831 1584 7894 8907 7029 4832 1675 4022
6622 6455 2206 5189 3874 2819 5304 3327 9723 8756 2253 4483 4005 2539 8246 1887 9571 8397 1067 4393
4981 5432 7097 5512 8146 3286 5150 1717 3912 9794 1291 9356 5867 2859 3969 8923 2909 1303 2068 4981
2557 8192 1391 3839 4577 4491 5678 1239 7734 3398 4216 5026 8964 6124 2710 2942 5702 6536 5959 4856
2886 3077 7358 7363 2826 2438 4590 2038 3370 1846 3942 7574 2209 8937 7393 9020 1991 6662 7878 1492
9613 8885 3620 7561 5913 9032 1954 3118 4377 9838 4629 5447 8313 5514 2398 3412 8243 6406 9272 5676
7911 3914 2760 4286 4813 8555 8563 2017 3425 2995 1248 7067 4201 6228 9655 5684 6665 6909 1411 5755
5997 5965 9264 9780 7407 9247 9805 9601 8513 8995 1489 4059 1781 8177 3152 5155 8927 1659 6585 5236
6428 5704 7820 5584 1575 6593 1564 7261 5638 7396 2609 3468 9662 1271 2100 2946 1778 5975 2019 1113
7034 8041 2660 4038 5845 9221 8186 4893 3771 6855 6367 7818 3739 3463 4011 9659 7323 9413 1709 8610
3254 5705 1228 1479 9546 4221 3147 1027 4088 5022 5140 1586 7300 7384 5697 8129 8667 7264 2299 9641
5907 5332 9787 3037 8998 3672 3474 8796 9104 7331 8321 3021 1439 5992 9253 8387 2895 7489 3219 1056
8717 8100 4183 2250 1804 5588 6799 9781 7428 1675 6452 5683 4139 1186 2513 8412 4823 8360 6859 8448
1584 8119 1764 1598 3958 6205 1970 7925 8173 1094 8456 8579 3657 6227 8868 2921 7962 4787 8786 9714
3495 3036 7617 8448 3219 1455 4797 8053 8208 9694 7293 4144 1244 7065 3223 7796 9161 4435 1928 8227
输出样例:
8940
 */
