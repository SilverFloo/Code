#include<bits/stdc++.h>
using namespace std;
bool ch[100];
int sum1[10],sum2[10],s1=0,s2=0;
main(){
int n,ans;
scanf("%d",&n);
int tab[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d",&tab[i][j]);
sum1[i]+=tab[i][j];
sum2[j]+=tab[i][j];
if(i==j)s1+=tab[i][j];
if(i+j==n-1)s2+=tab[i][j];

}
}
ans=n*(n*n+1)/2;
for(int i=0;i<n;i++){
if(sum1[i]!=ans){printf("No");return 0;}
if(sum2[i]!=ans){printf("No");return 0;}
}if(s1!=ans||s2!=ans){printf("No");return 0;}

printf("Yes");
}
