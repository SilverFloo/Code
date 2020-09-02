#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
int dp[505][505];
char tab[505][505];
bool st[505][505];
int main(){
    int n,m;
    cin>>n>>m;
    if((n+m)%2!=0){
        printf("NO SOLUTION");
        exit(0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tab[i][j];
            if((i+j)%2==0&&tab[i][j]=='/'){
                st[i][j]=1;
            }
            else if((i+j)%2==1&&tab[i][j]=='\\'){
                st[i][j]=1;
            }
            dp[i][j]=1e9;
        }
    }
    dp[n][m]=st[n][m];
    queue<ii> q;
    q.emplace(n,m);
    while(!q.empty()){
        int i=q.front().f;
        int j=q.front().s;
        q.pop();
        if(i==0||i>n||j==0||j>m)continue;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                if((i+j)%2==0&&k==-l)continue;
                if((i+j)%2==1&&k==l)continue;
                if(dp[i+k][j+l]>dp[i][j]+st[i+k][j+l]){
                    dp[i+k][j+l]=dp[i][j]+st[i+k][j+l];
                    q.emplace(i+k,j+l);
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++)printf("%d ",dp[i][j]);
    //     cout<<endl;
    // }
    printf("%d",dp[1][1]);
}