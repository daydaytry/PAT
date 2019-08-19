#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 10002
#define maxv 102
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int N,M;
    cin>>N>>M;
    int w[maxn],dp[maxv]={0};
    bool choice[maxn][maxv]={false};
    for(int i=1;i<=N;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+1+N,cmp);
    for(int i=1;i<=N;i++){
        for(int v=M;v>=w[i];v--){
            if(dp[v] <= (dp[v-w[i]]+w[i]))
            {
                dp[v] = dp[v-w[i]] + w[i];
                choice[i][v] = true;
            }
            else choice[i][v] = false;
        }
    }
    
    if(dp[M] != M) cout<<"No Solution"<<endl;
    else{
        int v=M,i=N;
        vector<int> ans;
        while(i > 0){
            if(choice[i][v]){
                ans.push_back(w[i]);
                v -= w[i];
            }
            i--;
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)
        {
            cout<<" "<<ans[i];
        }
    }
    return 0;
}
