#include<bits/stdc++.h>
using namespace std;
int ch[4];
main(){
char s[105];
scanf("%s",s);
int k;
scanf("%d",&k);
int x=0,y=0;
for(int i=0;i<strlen(s);i++){
switch(s[i]){
case 'N':x++;ch[0]++;break;
case 'S':x--;ch[1]++;break;
case 'E':y++;ch[2]++;break;
case 'W':y--;ch[3]++;break;
}
}
if(x<0&&k>0){
    x-=min(ch[0],k);
    k-=ch[0];
}
if(x>0&&k>0){
    x+=min(ch[1],k);
    k-=ch[1];
}
if(y<0&&k>0){
    y-=min(ch[2],k);
    k-=ch[2];
}
if(y>0&&k>0){
    y+=min(ch[3],k);
    k-=ch[3];
}
int kk=abs(x)+abs(y);
if(k>0)kk-=k;
printf("%d",(kk)*2);

}
