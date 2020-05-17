#include<bits/stdc++.h>
using namespace std;
main(){
int n;int mc=0,mf,ms;
scanf("%d",&n);
int x[n];
for(int i=0;i<n;i++)scanf("%d",&x[i]);
for(int i=0;i<n;i++){
for(int j=i;j<n;j++){
int c=0;
for(int k=0;k<n;k++){if(k<i&&x[k]==k+1)c++;
else if(k>j&&x[k]==k+1)c++;
else if(x[j+i-k]==k+1)c++;
}
if(c>mc){mc=c;mf=x[i];ms=x[j];}
}

}
printf("%d %d",mf,ms);
}
