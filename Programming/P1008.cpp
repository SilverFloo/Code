#include<bits/stdc++.h>
using namespace std;
int x[3001];
main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int l,h,r;
scanf("%d %d %d",&l,&h,&r);
while(r>l){
r--;
x[r]=x[r]>h?x[r]:h;
}
}
for(int i=1;i<3001;i++){//printf("%d ",x[i]);

if(x[i]!=x[i-1])printf("%d %d ",i,x[i]);
}

}
