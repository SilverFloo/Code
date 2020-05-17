#include<bits/stdc++.h>
using namespace std;
int magnet[100000000], ma[100000000];
main(){
int n,m,q;
scanf("%d %d %d",&n,&m,&q);
int s[m],e[m];
for(int i=0;i<m;i++){
scanf("%d %d",&s[i],&e[i]);
s[i]--;e[i]+=s[i];
}
sort(s,s+m);
sort(e,e+m);

int c=0,sx=0,ex=0;
for(int i=0;i<n;i++){
while(sx<m&&s[sx]==i){c++;sx++;}
while(ex<m&&e[ex]==i){c--;ex++;}
magnet[i]=c%2;
if(i==0)ma[i]=1;
else if(magnet[i]==magnet[i-1]){ma[i]=ma[i-1]+1;}
else ma[i]=1;

}
for(int i=0;i<q;i++){
int qu=1;
scanf("%d",&qu);
qu--;
while(qu<n-1){
if(ma[qu]>=ma[qu+1]){
    printf("%d\n",ma[qu]); break;
}qu++;}
if(qu==n-1){printf("%d\n",ma[n-1]);}
}
}
