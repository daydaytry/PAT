#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;
int mid[MAX];
int mergesort(int a[],int n){
	int sign = 0,flag = 0;
	for(int step = 2;step<n;step*=2){
		for(int i=0;i<n;i+=step){
			sort(a+i,a+i+step+1);
		}
		for(int j=0;j<n;j++){
			if(a[j] != mid[j]){
				flag = 1;
				break;
			}
		}
		if(sign){
			printf("%d",a[0]);
			for(int j=1;j<n;j++){
				printf(" %d",a[j]);
			}
			return 1;
		}
		if(flag == 0){
			cout<<"Merge Sort"<<endl;
			sign = 1;
		}
	}
	return 0;
}
int insertionsort(int a[],int n){
	int tmp[MAX],flag,sign=0;
	for(int i=0;i<n;i++){
		tmp[i] = a[i];
		flag = 0;
		sort(tmp,tmp+i+1);
		for(int j=0;j<n;j++){
			if(j<=i){
				if(tmp[j] != mid[j]){
					flag = 1;
					break;
				}
			}
			else{
				if(a[j] != mid[j]){
					flag = 1;
					break;
				}
			}
		}
		if(sign){
			printf("%d",tmp[0]);
			for(int j=1;j<n;j++){
				if(j<=i){
					printf(" %d",tmp[j]);
				}
				else{
					printf(" %d",a[j]);
				}
			}
			return 1;
		}
		if(flag == 0){
			cout<<"Insertion Sort"<<endl;
			sign = 1;
		}
	}
	return 0;
}
int main(){
	int a[MAX],tmp[MAX];
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>mid[i];
		tmp[i]=a[i];
	}
	insertionsort(tmp,n);
	mergesort(a,n);
	return 0;
}
