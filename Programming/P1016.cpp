#include<bits/stdc++.h>
using namespace std;
main(){
char s[10];double i=0,j=0;
while(1){
scanf("%s",s);
if(s[0]=='*')break;
int d=0;int x=0;
while(s[x]<='9'&&s[x]>='0'){d*=10;d+=s[x]-'0';x++;}
if(s[x]=='N'){
    if(s[x+1]=='W'){j-=d/sqrt(2);i+=d/sqrt(2);}
    else if(s[x+1]=='E'){j+=d/sqrt(2);i+=d/sqrt(2);}
    else i+=d;
    }
if(s[x]=='S'){
    if(s[x+1]=='W'){j-=d/sqrt(2);i-=d/sqrt(2);}
    else if(s[x+1]=='E'){j+=d/sqrt(2);i-=d/sqrt(2);}
    else i-=d;
}
if(s[x]=='E')j+=d;
if(s[x]=='W')j-=d;
}
printf("%.3lf %.3lf\n",(double)j,(double)i);
printf("%.3lf",sqrt(i*i+j*j));
}
