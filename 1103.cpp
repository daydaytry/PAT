#include<iostream> 
#include<algorithm>
#include<cmath>
#include <vector>
using namespace std;
int list[401];
int n,k,p,top,submax=0;
vector<int> ans,tmp;
//noek可以用 tmp.size() 代替 
void DFS(int index,int sum,int nowk,int subsum){
	if(sum == n && nowk == k){
		if(subsum > submax){
			submax = subsum;
			ans = tmp;
		}
		//DFS一定会遍历完所有的可能 
		return;
	}
	//对DFS进行剪枝 
	if(sum > n || nowk == k || index == 0){
		return ;
	}
	//路径的记录 
	tmp.push_back(index);
	DFS(index,sum+list[index],nowk+1,subsum+index);
	//将第一种选择弹出 
	tmp.pop_back();
	DFS(index - 1,sum,nowk,subsum);
}
int main(){
	cin>>n>>k>>p;
	top = pow(n,1.0/p);
	int index=1;
	for(int i=1;i<=top;i++){
		list[index++]=pow(i,p);
	}
	//根据题目要求从最大值top开始遍历，使得结果按字典序最大。若要字典序最小可以从1开始遍历 
	DFS(top,0,0,0);
	if(!ans.size()){
		cout<<"Impossible";
	}
	else{
		cout<<n<<" = "<<ans[0]<<'^'<<p;
		for(int i=1;i<ans.size();i++){
			cout<<" + "<<ans[i]<<'^'<<p;
		}
	}
	return 0;
}
