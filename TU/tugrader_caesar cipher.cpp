#include<bits/stdc++.h>
using namespace std;
int main(){
int s,k;
cin>>s>>k;
char st[s+5];
scanf("%s",st);
for(int i=0;i<s;i++){
if(isupper(st[i])){
st[i]=((st[i]-'A'+k)%26+26)%26+'A';
}
else{
st[i]=((st[i]-'a'+k)%26+26)%26+'a';
}
}
printf("%s",st);
}
