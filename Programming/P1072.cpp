#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[500005];int st=0,status=1;
int get(int no){
int x=(st+status*no)%n;
if(x<0)x+=n;
return x;
}
main(){
scanf("%d %d",&n,&m);
for(int i=0;i<n;i++)scanf("%d",&v[i]);
while(m--){
char c;
scanf(" %c",&c);
if(c=='a'){
int x,y;
scanf("%d %d",&x,&y);x--;y--;
swap(v[get(x)],v[get(y)]);}
if(c=='b'){
int x,y;
scanf("%d %d",&x,&y);x--;
v[get(x)]=y;
}
if(c=='c'){
int x;
scanf("%d",&x);x--;
st=st+status*x;
if(st<0)st+=n;
status*=-1;
}
if(c=='q'){
int x;
scanf("%d",&x);x--;
printf("%d\n",v[get(x)]);
}/*printf(">>");
for(int i=0;i<n;i++){
printf("%d",v[get(i)]);
}printf("<<%d %d<\n",st,status);*/
}

}
