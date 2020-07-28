#include "grader.h"
#include "cluedo.h"
#include<bits/stdc++.h>
using namespace std;
void Solve(){
   queue<int> a,b,c;
   for(int i=1;i<=6;i++){
      a.push(i);
      c.push(i);
   }
   for(int i=1;i<=10;i++){
      b.push(i);
   }
   while(1){
      int r = Theory(a.front(),b.front(),c.front());
      if(r==1)a.pop();
      if(r==2)b.pop();
      if(r==3)c.pop();
      if(r==0)return;
   }
}
