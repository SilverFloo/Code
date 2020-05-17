#include<bits/stdc++.h>
using namespace std;
int main(){
char s[205];
scanf("%s",s);
int x=0;
int c=0;
for(int i=0;i<strlen(s);i++){
if(s[i]=='(')x++;
if(s[i]==')')x--;
if(x==-1){x++;c++;}
}
if(x>0)c+=x;
printf("%d",c);
}
