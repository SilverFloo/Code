#include<bits/stdc++.h>
main(){

int n;
scanf("%d",&n);
while(n!=-1){
int a=1,b=1,c=0;
for(int i=0;i<n;i++){
    int t=b;
    b+=c+1;
    c=t;
}
printf("%d %d\n",b,a+b+c);
scanf("%d",&n);
}

}
