#include<stdio.h>
main(){
int n;
scanf("%d",&n);
int i=0,v=0,x=0,l=0,c=0,j;
for(j=1;j<=n;j++){
    switch(j%10){
    case 1:i++;break;
    case 2:i+=2;break;
    case 3:i+=3;break;
    case 6:
    case 4:i++;v++;break;
    case 5:v++;break;
    case 7:v++;i+=2;break;
    case 8:v++;i+=3;break;
    case 9:x++;i++;break;
    }
    switch((j/10)%10){
    case 1:x++;break;
    case 2:x+=2;break;
    case 3:x+=3;break;
    case 4:
    case 6:x++;l++;break;
    case 5:l++;break;
    case 7:x+=2;l++;break;
    case 8:x+=3;l++;break;
    case 9:c++;x++;break;
    }






    c+=j/100;
}
printf("%d %d %d %d %d",i,v,x,l,c);

}
