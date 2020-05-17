#include<bits/stdc++.h>
using namespace std;
int main(){
char s[100005];
scanf("%s",s);
char now='a';
for(int i=0;i<strlen(s);i++){

if(s[i]<=now){s[i]=now;now++;}
if(now=='z'+1)break;
}
if(now=='z'+1)printf("%s",s);
else printf("-1");

}
