#include<stdio.h>
int gcd(int a,int b){
int t;
while(b){
t=a;
a=b;
b=t%b;
}
return a;
}
main(){
int a,b,i;
scanf("%d %d",&a,&b);
int n = gcd(a>b?a:b,a<b?a:b);
for(i=1;i<=n;i++){
        if(n%i==0){printf("%d %d %d\n",i,a/i,b/i);}


}


}

