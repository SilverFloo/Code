#include<stdio.h>
main(){
int n,x=1;
scanf("%d",&n);
char c[n];
for(int i=0;i<n;i++){
scanf(" %c",&c[i]);
if(i!=0){if(c[i]!=c[i-1])x++;}
}
printf("%d",x+1);

}
