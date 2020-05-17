#include<bits/stdc++.h>
using namespace std;
int a[30005];
queue<int> ql,qr;
main(){
int n;
scanf("%d",&n);

for(int i=0;i<n;i++){scanf("%d",&a[i]);}
sort(a,a+n);
ql.push(0);qr.push(n-1);
while(!ql.empty()){

int l=ql.front();
ql.pop();
int r=qr.front();
qr.pop();    if(r-l<3){printf("0");return 0;}
if(a[l]+a[l+1]>a[r]){printf("%d",r-l+1);return 0;}
ql.push(l+1);qr.push(r);
ql.push(l);qr.push(r-1);
}
}
