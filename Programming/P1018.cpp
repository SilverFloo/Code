#include<bits/stdc++.h>
int x=0,y=0;
char d='E';
void walk(int l){
if(d=='N')y+=l;
if(d=='S')y-=l;
if(d=='E')x+=l;
if(d=='W')x-=l;
}
using namespace std;
main(){

int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
char s[5];int l;
scanf("%s %d",s,&l);
if(s[0]=='F'){
walk(l);
}
if(s[0]=='B'){
    if(d=='E')d='W';
     else if(d=='W')d='E';
     else if(d=='N')d='S';
     else if(d=='S')d='N';
walk(l);
}
if(s[0]=='L'){
    if(d=='E')d='N';
    else if(d=='W')d='S';
    else if(d=='N')d='W';
    else if(d=='S')d='E';
walk(l);
}
if(s[0]=='R'){
    if(d=='E')d='S';
   else  if(d=='W')d='N';
    else if(d=='N')d='E';
    else if(d=='S')d='W';
walk(l);
}
if(x>=50000||x<=-50000||y>=50000||y<=-50000){printf("DEAD");return 0;}

}
printf("%d %d \n%c",x,y,d);
}
