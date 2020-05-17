#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
scanf("%d",&n);
int x[n];
for(int i=0;i<n;i++){
scanf("%d",&x[i]);if(x[i]<=0){printf("Not Easy");exit(0);}
}
int M=fabs(x[1]-x[0]);
for(int i=1;i<n-1;i++){
if(fabs(x[i+1]-x[i])!=M){printf("Not Easy");exit(0);}
}
printf("Easy");
}
