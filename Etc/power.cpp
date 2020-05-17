#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
while(t--){
int x,y,n;
scanf("%d %d %d",&x,&y,&n);
if(y==0){printf("1\n");}
else{
int i=y;int c=0;
while(i!=0){c++;i=i>>1;}
int tab[c];
tab[0]=x%n;
for(int i=1;i<c;i++){tab[i]=(tab[i-1]*tab[i-1])%n;}
//for(int i=0;i<c;i++){printf("%d ",tab[i]);}
int ans=1;c=0;
i=y;
while(i!=0){
int a=i%2;
//printf("%d ",ans);
if(a)ans*=tab[c];
ans%=n;
i>>=1;c++;
}
printf("%d\n",ans);}
}
}
