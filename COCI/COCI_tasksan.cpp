#include<bits/stdc++.h>
using namespace std;
int h[41],v[41];
int n;
double ans;
int c=0;
void go(int i,double value){
if(value>=ans)c++;
for(int j=i+1;j<n;j++){
if(h[i]<=h[j])go(j,value+v[j]);
}
}
main(){

scanf("%d %lf",&n,&ans);
for(int i=0;i<n;i++)scanf("%d %d",&h[i],&v[i]);
for(int i=0;i<n;i++){go(i,(double)v[i]);}
printf("%d",c);
}
