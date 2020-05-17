#include<bits/stdc++.h>
using namespace std;
int areax[6000],areay[6000];

main(){
int m,n,c;
scanf("%d %d %d",&m,&n,&c);
while(c--){
int x,y,r;
scanf("%d %d %d",&x,&y,&r);
x+=105;y+=105;
areax[x-r]++;
areax[x+r+1]--;
areay[y-r]++;
areay[y+r+1]--;
}
int ans=0,sum=0;
for(int i=0;i<6000;i++){
sum+=areax[i];
if(sum>ans)ans=sum;
}
sum=0;
for(int i=0;i<6000;i++){
sum+=areay[i];
if(sum>ans)ans=sum;
}
printf("%d",ans);
}
