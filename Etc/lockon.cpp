#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int path[MAX];
main(){
int n,p;
scanf("%d %d",&n,&p);
for(int i=0;i<n;i++){
int a,b;
scanf("%d %d",&a,&b);
path[a]++;
path[b+1]--;
}
int x=0;int ch=0;
int m=9999999;
for(int i=0;i<1000000;i++){
x+=path[i];
if(x==n){ch=1;
if(fabs(p-i)<m)m=fabs(p-i);
}
if(ch==1&&x!=n)break;
}
printf("%d",m==9999999?-1:m);
}
