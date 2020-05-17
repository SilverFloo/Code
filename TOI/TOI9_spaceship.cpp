#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
using namespace std;

typedef struct p{
int x,y,z;
//p(int x,int y,int z):x(x),y(y),z(z){}
}pos;

p plu(p a,p b){
p xx;
xx.x=a.x+b.x;
xx.y=a.y+b.y;
xx.z=a.z+b.z;
return xx;
}

int len(p a,p b){
return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int com,n;
bool ch(p a){
//printf(">%d %d %d %d %d<",a.x,a.y,a.z,com,(a.x>=com)&&(a.y>=com)&&(a.z>=com));
return (a.x>=com)&&(a.y>=com)&&(a.z>=com);
}

int main(){

p s;
p shop[10];
p c[10];


int state[10];

cin>>com;
scanf("%d %d %d",&s.x,&s.y,&s.z);
cin>>n;
FOR(i,n){
scanf("%d %d %d",&shop[i].x,&shop[i].y,&shop[i].z);
scanf("%d %d %d",&c[i].x,&c[i].y,&c[i].z);
state[i]=i;
}
int ans=2e9;
do{
p now;
now.x=0;
now.y=0;
now.z=0;
int cost=0;

cost+=len(s,shop[state[0]]);
now=plu(now,c[state[0]]);
FOR1(i,n-1){
if(ch(now)){break;}//printf("%d %d %d/",now.x,now.y,now.z);
cost+=len(shop[state[i-1]],shop[state[i]]);
now=plu(now,c[state[i]]);
}
//printf("%d %d %d/",now.x,now.y,now.z);
//FOR(j,n)printf("%d",state[j]);
//printf("->%d\n",cost);
if(ch(now))ans=min(ans,cost);

}while(next_permutation(state,state+n));

printf("%d",ans);

}
