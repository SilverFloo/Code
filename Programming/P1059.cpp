#include<bits/stdc++.h>
using namespace std;
char str[10000];
int pos=0;
void press(int num,int t){
switch(num){
case 1:pos-=(t+1);if(pos<0)pos=0;break;
case 2:str[pos]='A'+t%3;pos++;break;
case 3:str[pos]='D'+t%3;pos++;break;
case 4:str[pos]='G'+t%3;pos++;break;
case 5:str[pos]='J'+t%3;pos++;break;
case 6:str[pos]='M'+t%3;pos++;break;
case 7:str[pos]='P'+t%4;pos++;break;
case 8:str[pos]='T'+t%3;pos++;break;
case 9:str[pos]='W'+t%4;pos++;break;
}

}
main(){
int plate[3][3]={1,2,3,4,5,6,7,8,9};
int n,i,j,p,t;
scanf("%d %d %d",&n,&p,&t);
switch(p){
case 1:i=0;j=0;break;
case 2:i=0;j=1;break;
case 3:i=0;j=2;break;
case 4:i=1;j=0;break;
case 5:i=1;j=1;break;
case 6:i=1;j=2;break;
case 7:i=2;j=0;break;
case 8:i=2;j=1;break;
case 9:i=2;j=2;break;
}
press(plate[i][j],t-1);
while(--n){
int x,y;
scanf("%d %d %d",&x,&y,&t);
i+=y;
j+=x;

press(plate[i][j],t-1);
}
if(pos==0)printf("null");
else{
str[pos]='\0';
printf("%s",str);
}
}
