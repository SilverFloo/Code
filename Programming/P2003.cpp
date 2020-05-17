#include<bits/stdc++.h>
using namespace std;
int s[100005];
int dp[2][4][4][4];
int v(int a,int b,int c){
int x=0;
if(a==1||b==1||c==1)x++;
if(a==2||b==2||c==2)x++;
if(a==3||b==3||c==3)x++;
return x;
}
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
char a;
scanf(" %c",&a);
if(a=='M')s[i]=1;
if(a=='B')s[i]=2;
if(a=='F')s[i]=3;
}
int now=0,prev=1;
for(int i=n-1;i>=0;i--){
for(int a=0;a<4;a++){
for(int b=0;b<4;b++){
for(int c=0;c<4;c++){
if(i==0)dp[now][a][b][c]=max(v(a,0,s[i])+dp[prev][0][b][c],v(b,c,s[i])+dp[prev][c][a][0]);
else dp[now][a][b][c]=max(v(a,s[i-1],s[i])+dp[prev][s[i-1]][b][c],v(b,c,s[i])+dp[prev][c][a][s[i-1]]);
}
}
}
swap(now,prev);
}
printf("%d",dp[prev][0][0][0]);

}
