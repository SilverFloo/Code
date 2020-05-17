#include<bits/stdc++.h>
using namespace std;
int tab[256];
main(){
int n,t;
for(int i=1;i<256;i++)tab[i]=2000000000;
scanf("%d %d",&n,&t);int pow=1;for(int i=0;i<t;i++)pow*=2;
for(int i=0;i<n;i++){
int p,s=0;
scanf("%d",&p);
for(int j=0;j<t;j++){int x; scanf("%d",&x);s=s<<1;s=s|x;}

for(int j=0;j<pow;j++){
if(tab[s|j]>p+tab[j]){tab[s|j]=p+tab[j];}}
}
printf("%d",tab[pow-1]);
}
