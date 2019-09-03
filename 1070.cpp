#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 1100
#define inf 10000
int graph[maxn][maxn];
int n,m,k,ds;
int conv(char a[]){
	int id = 0,len = strlen(a),i=0;
	while(i<len){
		if(a[i] != 'G'){
			id = id*10 + (a[i] -'0');
		}
		i++;
	}
	if(a[0] = 'G') id += n;
	return id;
}
int main(){
	cin>>n>>m>>k>>ds;
	//fill(graph,graph+maxn*maxn,inf);
	char a[5],b[5];
	int len,ia,ib;
	for(int i=0;i<k;i++){
		scanf("%s %s %d",&a,&b,&len);
		ia = conv(a);
		ib = conv(b);
		graph[ia][ib] = graph[ib][ia] = len;
		cout<<ia<<' '<<ib<<endl;
	}
	return 0;
}
