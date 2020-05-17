#include<bits/stdc++.h>
using namespace std;
int gcd(int u, int v) {
return (v != 0)?gcd(v, u%v):u;
}
int x[100001];
main(){
int n,t;
scanf("%d %d",&n,&t);
for(int i=0;i<n;i++)scanf("%d",&x[i]);
for(int i=0;i<t;i++){
int c,a,b;
scanf("%d %d %d",&c,&a,&b);
if(c==1){x[a-1]=b;}
if(c==2){a--;b--;int coun=0;
for(int j=a;j<=b;j++){
for(int k=j;k<=b;k++){
if(k==j&&x[k]!=1)coun++;
else {int gc=gcd(x[j],x[j+1]);
for(int l=j+1;l<k;l++){
gc=gcd(gc,x[l+1]);
}
if(gc!=1)coun++;
}

}
}
printf("%d\n",coun);
}
}

}
