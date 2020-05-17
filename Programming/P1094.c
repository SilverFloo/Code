#include<stdio.h>
main(){
int i,j,k;
int a[5];
for(i=0;i<5;i++)scanf("%d",&a[i]);
for(i=5-1;i>=0;i--){
for(j=0;j<i;j++){
if(a[j]>a[j+1]){
int tmp=a[j];
a[j]=a[j+1];
a[j+1]=tmp;
for(k=0;k<5;k++){printf("%d ",a[k]);}printf("\n");
}

}

}

}
