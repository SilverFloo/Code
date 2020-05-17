#include<bits/stdc++.h>
using namespace std;
int c(int n,int r){
double x=1;
for(int i=n;i>r;i--){x*=i;}
for(int i=n-r;i>0;i--){x/=i;}
return (int)x;

}
int main(){
int n;
scanf("%d",&n);
printf("%d",n%2==0?c(n,n/2):2*c(n,n/2));

}
