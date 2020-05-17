#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
using namespace std;
int val(int a,int b,int c){
int co=0;
if(a==1||b==1||c==1)co++;
if(a==2||b==2||c==2)co++;
if(a==3||b==3||c==3)co++;
return co;
}
int dp[2][4][4][4];
int s[100005];
int main(){
int n;
cin>>n;

s[0]=0;
FOR1(i,n+1){
char a;
scanf(" %c",&a);
if(a=='W')s[i]=3;
if(a=='D')s[i]=1;
if(a=='F')s[i]=2;
}
int now=0,prev=1;

for(int k=n;k>0;k--){
for(int a=0;a<4;a++){
for(int b=0;b<4;b++){
for(int c=0;c<4;c++){
if(k>0){
int l=dp[prev][s[k-1]][b][c]+val(a,s[k-1],s[k]);
int r=dp[prev][c][a][s[k-1]]+val(b,c,s[k]);
dp[now][a][b][c]=max(l,r);
//printf("%d-",dp[now][a][b][c]);
}
}
}
}
swap(now,prev);
}
printf("%d",dp[prev][0][0][0]);
}
