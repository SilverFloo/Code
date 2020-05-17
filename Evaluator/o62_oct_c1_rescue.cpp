#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stdio.h>

using namespace std;

class Point {
public:
    int r,c;
};

int cave_r,cave_c;    // row, col
int position_r,position_c;  // Eettan's position
int drop_count;
vector<pair<Point,Point>> walls;

vector<vector<int>> room,dist;  //-1 = wall, 0 = free, 1 = robot

void print(vector<vector<int>> &m) {
    int R = m.size();
    int C = m[0].size();
    for (int r = 0; r < R;r++) {
        for (int c = 0;c < C;c++) {
            printf("%3d",m[r][c]);
        }
        printf("\n");
    }
}

void get_size(int &uR, int &uC) {
    int n;
    cin >> cave_r >> cave_c;
    uR = cave_r;
    uC = cave_c;
    cin >> position_r >> position_c;
    cin >> n;
    walls.resize(n);
    for (int i = 0;i < n;i++) {
      cin >> walls[i].first.r >> walls[i].first.c;
      cin >> walls[i].second.r >> walls[i].second.c;
    }

    //build room
    room = vector<vector<int>>(cave_r+2, vector<int>(cave_c+2,0));
    dist = vector<vector<int>>(cave_r+2, vector<int>(cave_c+2,-1));
    for (int i = 0;i < cave_c+2;i++) {
      room[0][i] = -1;
      room[cave_r+1][i] = -1;
    }
    for (int i = 0;i < cave_r+2;i++) {
      room[i][0] = -1;
      room[i][cave_c+1] = -1;
    }
    for (int i = 0;i < n;i++) {
      int dr = walls[i].second.r - walls[i].first.r; dr = (dr == 0) ? 0 : dr / abs(dr);
      int dc = walls[i].second.c - walls[i].first.c; dc = (dc == 0) ? 0 : dc / abs(dc);
      int cr = walls[i].first.r;
      int cc = walls[i].first.c;
      while (cr != walls[i].second.r || cc != walls[i].second.c) {
        room[cr][cc] = -1;
        cr += dr;
        cc += dc;
      }
      room[cr][cc] = -1;

    }

    if (room[position_r][position_c] == -1) {
        cout << "INPUT ERROR: HUMAN IN WALL" << endl;
        exit(1);
    }
    room[position_r][position_c] = 1;

    //build distance
    dist[position_r][position_c] = 0;
    queue<Point> q;
    q.push( {position_r,position_c});
    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {1,0,-1,0};
    while (q.empty() == false) {
        auto p = q.front();q.pop();
        int d = dist[p.r][p.c]+1;
        for (int j = 0;j < 4;j++) {
            int nr = p.r + dr[j];
            int nc = p.c + dc[j];
            if (room[nr][nc] == 0 && dist[nr][nc] == -1) {
                dist[nr][nc] = d;
                q.push({nr,nc});
            }
        }
    }
    //print(room);
    //print(dist);



    //reset drop count
    drop_count = 0;
}
int drop_robot(int r, int c) {
    if (r < 1 || r > cave_r || c < 1 || c > cave_c) {
        cout << "WRONG CALL TO drop_robot: r = " << r << " c = " << c << endl;
        exit(1);
    }
    drop_count++;
    return dist[r][c];
    return 0;
}

void answer(int r, int c) {
    if (r == position_r && c == position_c) {
        cout << "CORRECT" << endl;
        cout << "drop count = " << drop_count << endl;
    } else {
        cout << "WRONG ANSWER!!" << endl;
        cout << "drop count = " << drop_count << endl;
    }
    exit(0);
}


int R,C;

int main(){
  freopen("input.txt","r",stdin);
    get_size(R,C);

    int d1 = drop_robot(1,1);
    int d3 = drop_robot(R,C);
    int d2 = drop_robot(1,C);
    int d4 = drop_robot(R,1);
//no wall
    if(d1!=-1&&d2!=-1&&d3!=-1&&d4!=-1){
        int a = (d1+d2-C+1)/2;
        int b = d1-a;
        answer(a+1,b+1);
    }
// 1 wall
    if(d1==-1&&d2==-1&&d3!=-1&&d4!=-1){
        int a = (d3+d4-C+1)/2;
        int b = d4-a;
        answer(R-a,b+1);
    }

    if(d3==-1&&d4==-1&&d1!=-1&&d2!=-1){
        int a = (d1+d2-C+1)/2;
        int b = d1-a;
        answer(a+1,b+1);
    }

    if(d1==-1&&d4==-1&&d2!=-1&&d3!=-1){
        int a = (d2+d3-R+1)/2;
        int b = d2-a;
        answer(b+1,C-a);
    }

    if(d2==-1&&d3==-1&&d1!=-1&&d4!=-1){
        int a = (d1+d4-R+1)/2;
        int b = d1-a;
        answer(b+1,a+1);
    }
// 2 wall outside
    if(d2!=-1&&d3!=-1&&d4!=-1){
         int a = (d3+d4-C+1)/2;
        int b = d4-a;
        answer(R-a,b+1);
    }
    if(d1!=-1&&d3!=-1&&d4!=-1){
        int a = (d3+d4-C+1)/2;
        int b = d4-a;
        answer(R-a,b+1);
    }

    if(d1!=-1&&d2!=-1&&d4!=-1){
        int a = (d1+d2-C+1)/2;
        int b = d1-a;
        answer(a+1,b+1);
    }
    if(d1!=-1&&d2!=-1&&d3!=-1){
        int a = (d1+d2-C+1)/2;
        int b = d1-a;
        answer(a+1,b+1);
    }

// find
    int l=1,r=C;
    int ans=0;
    while(l<=r){
        int m=(l+r)/2;
        int x;
        if(d4!=-1||d3!=-1){
            x=R;
        }else{
            x=1;
        }
        if(drop_robot(x,m)==-1){
            if(d4!=-1||d1!=-1)r=m-1;
            if(d3!=-1||d2!=-1)l=m+1;
        }
        else{
            if(d4!=-1||d1!=-1)l=m+1;
            if(d3!=-1||d2!=-1)r=m-1;
            ans=m;
        }
    }
// 2 wallinside
int x;
    if(d1!=-1){
        x=drop_robot(1,ans);
        int a = (d1+x-ans+1)/2;
        int b = d1-a;
        answer(a+1,b+1);
    }
    if(d2!=-1){
        x=drop_robot(1,ans);
        int a = (d2+x-(R-ans+1)+1)/2;
        int b = x-a;
        answer(a+1,ans+b);
    }
      if(d3!=-1){
        x=drop_robot(R,ans);
        int a = (d3+x-(R-ans+1)+1)/2;
        int b = x-a;
        answer(R-a,ans+b);
    }
      if(d4!=-1){
        x=drop_robot(R,ans);
        int a = (d4+x-ans+1)/2;
        int b = d4-a;
        answer(R-a,b+1);
    }

    return 0;
}
/*
10 10
8 8
2
5 5
10 5
5 5
5 10
*/
