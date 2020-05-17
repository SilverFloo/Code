#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
scanf("%d",&n);
int c=0;
c+=3000*(n/15);
n%=15;
if(n>=10){c+=3000;n=0;}
else{c+=1500*(n/5);n%=5;}
if(n==1)c+=500;
else if(n==2)c+=800;
else if(n==3)c+=1300;
else if(n==4)c+=1500;
printf("%d",c);
}
