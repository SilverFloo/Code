#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=b-1;i>=a;i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
int main(){
char s[45];
scanf("%s",s);
for(int i=0;i<strlen(s);i++){
if(isupper(s[i])){
printf("%c",(s[i]-'A'+2)%26+'A');
}
else if(!islower(s[i]))printf("%c",s[i]);
}
}
