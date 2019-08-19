#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100002
#define maxv 1002
bool cmp(int a,int b){
    return a < b;
}
int BFind(vector<int> w,int data){
    int head=0,tail=w.size()-1;
    int mid;
    while(tail>=head){
        mid=(head+tail)/2;
        if(w[mid]>data){
            tail=mid-1;
        }
        else if(w[mid]<data)
        {
            head = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main(){
    int N,M,tmp;
    cin>>N>>M;
    vector<int> w;
    for(int i=1;i<=N;i++){
        scanf("%d",&tmp);
        w.push_back(tmp);
    }
    sort(w.begin(),w.end(),cmp);
    int i,j,index,flag=-1;
    //使用二分法查找余数
    for(i=0;w[i] < (M-w[0]);i++){
        if(i+1 < N && w[i]==w[i+1]) continue;
        if(flag == 1) break;
        index = BFind(w,M-w[i]);
        if( index != -1 && index != i){
            cout<<w[i]<<' '<<w[index];
            flag = 1;
            break;
        }
    }
    if(flag == -1) cout<<"No Solution";
    return 0;
}

//输入时就将b[a[i]]标记为1， 若发现有b[m-a[i]]为1，取其最小值。这种解法使用了用空间换取时间。
// #include<stdio.h>
// const int NUM=100005;
// int a[NUM];
// int b[NUM];
// int main()
// {
// 	int n,i,m;
// 	int temp,min=NUM;
// 	//freopen("C:\\Documents and Settings\\Administrator\\桌面\\input.txt","r",stdin);
// 	scanf("%d%d",&n,&m);
// 	for(i=0;i<n;i++){
// 		scanf("%d",&a[i]);
// 		if(a[i]<=m){
// 			temp=(a[i]<m-a[i])?a[i]:(m-a[i]);
// 			if(b[m-a[i]]==1&&min>temp){
// 				min=temp;
// 			}
// 			b[a[i]]=1;
// 		}
// 	}
// 	if(min!=NUM)
// 		printf("%d %d",min,m-min);
// 	else 
// 		printf("No Solution");
// 	return 0;
// }
