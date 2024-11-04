#include <iostream>
using namespace std;
int ans=0;
int a[10];
void dfs(int x,int t){
	if(t==5){
		ans++;
		for(int i=1;i<=5;i++) cout<<a[i]<<' ';
		puts("");
		return ;
	}
	for(int i=x;i<=10;i++){
		t++;
		a[x]=i;
		dfs(i,t);
		t--;
	}
}
int main()
{
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
