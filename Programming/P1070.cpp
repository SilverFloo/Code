#include<bits/stdc++.h>
using namespace std;
main(){
int n;
int min1=100000,min2=100000,max=0;scanf("%d",&n);
for(int i=0;i<n;i++){
int x;
scanf("%d",&x);
if(x<=min2){min2=min1;min1=x;if(min2<min1)swap(min2,min1);}
if(x>max)max=x;
}
if(min1+min2>max)printf("no");
else printf("yes");
}
