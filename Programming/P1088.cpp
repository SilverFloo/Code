#include<bits/stdc++.h>
using namespace std;
main(){
int n,m;
scanf("%d %d",&m,&n);
int s[n],e[n];
for(int i=0;i<n;i++){
int sx,ex;
scanf("%d %d ",&sx,&ex);
s[i]=sx-1;
e[i]=ex;
}
sort(s,s+n);int cs=0,ce=0;
sort(e,e+n);
char a;
scanf(" %c",&a);
int ans=0;int c=0;
//for(int i=0;i<n;i++){printf("%d %d\n",e[i],s[i]);}
for(int i=0;i<m;i++){
    while(s[cs]==i&&cs<n){c++;cs++;}
    while(e[ce]==i&&ce<n){c--;ce++;}
//printf("%d %d %d\n",c,cs,ce);
if(a=='R'){ans+=(3-c%3)%3;}
if(a=='G'){ans+=(3-c%3+1)%3;}
if(a=='B'){ans+=(3-c%3+2)%3;}
}
printf("%d",ans);
}
