#include<bits/stdc++.h>
using namespace std;
int main(){
int n,sum=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
int a;
scanf("%d",&a);
sum+=fabs(a);
}
printf("%d",sum);}
