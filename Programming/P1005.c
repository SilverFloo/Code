#include<stdio.h>
main(){
int n,j;
scanf("%d",&n);
int a[n],i,p[n],max=0,posi,posj;
for(i=0;i<n;i++){scanf("%d",&a[i]);if(a[i]>max){max=a[i];posi=i;posj=i;}}
p[0]=a[0];
for(i=1;i<n;i++){p[i]=p[i-1]+a[i];if(p[i]>max){max=p[i];posi=0;posj=i;}}
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(p[j]-p[i]>max){max=p[j]-p[i];posi=i+1;posj=j;}

    }
}
if(max<=0)printf("Empty sequence");
else
{
for(i=posi;i<=posj;i++){printf("%d ",a[i]);}
printf("\n%d",max);}
}
