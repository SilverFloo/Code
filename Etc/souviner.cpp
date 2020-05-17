#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
while(t--){
int x,n;
scanf("%d %d",&x,&n);
vector<int> price[n];
for(int i=0;i<n;i++){
int a;scanf("%d",&a);
while(a--){int b;scanf("%d",&b);price[i].push_back(b);}
}
bool dp[n][x+1];
for(int i=0;i<n;i++){
for(int j=0;j<=x;j++)dp[i][j]=0;
}for(int i=0;i<price[0].size();i++){if(price[0][i]<=x)dp[0][price[0][i]]=1;}
for(int i=1;i<n;i++){
for(int k=0;k<=x;k++){
if(dp[i-1][k]){
for(int j=0;j<price[i].size();j++){
if(k+price[i][j]<=x)dp[i][k+price[i][j]]=1;
}
}
}
}
//for(int i=0;i<n;i++){for(int j=0;j<=x;j++)printf("%d ",dp[i][j]);printf("\n");}
for(x;x>=0;x--){if(dp[n-1][x]){printf("%d\n",x);break;
}}
if(x==-1)printf("no solution\n");
}
}
