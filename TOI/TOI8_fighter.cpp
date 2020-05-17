#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
using namespace std;

int main(){
int p;
cin>>p;
int hp[2];
hp[0]=p;hp[1]=p;
int state=-1;
int combo=0;
FOR(i,2*p){
int x;cin>>x;
if(x%2==state){combo++;}
else{state=x%2;combo=1;}
if(combo>=3){hp[!state]-=3;}
else hp[!state]--;

//printf("%d %d\n",hp[0],hp[1]);
if(hp[!state]<=0){cout<<state<<endl<<x;break;}
}

}
