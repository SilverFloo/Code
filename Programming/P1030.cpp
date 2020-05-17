#include<bits/stdc++.h>
#define _1 first
#define _2 second
using namespace std;
pair<double,int> rice[100000];
int idx[100000];
bool cmp(int i,int j){return rice[i]._1<rice[j]._1;}
main(){
int nr,b;
scanf("%d",&nr);

for(int i=0;i<nr;i++){
int p,q;
scanf("%d %d",&p,&q);
rice[i]._1=(double)p/q;
rice[i]._2=q;
idx[i]=i;
}


sort(idx,idx+nr,cmp);

int nb;
scanf("%d",&nb);
int n=0;
for(int i=0;i<nb;i++){
int w;double ans=0;
scanf("%d",&w);

while(w!=0){
if(rice[idx[n]]._2>w){rice[idx[n]]._2-=w;ans+=(double)rice[idx[n]]._1*w;w=0;}
else{ans+=(double)rice[idx[n]]._1*rice[idx[n]]._2;w-=rice[idx[n]]._2;n++;}
}
printf("%.3lf\n",ans);
}}
