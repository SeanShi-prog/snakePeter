#include<iostream>
using namespace std;
#include "wall.h"

void Wall::initWall() {
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++) {
            if(i==0||j==0||i==ROW-1||j==COL-1) gameArr[i][j]='*';
            else gameArr[i][j]=' ';
        }
}

void Wall::drawWall() {
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++)
            cout<<gameArr[i][j]<<' ';
        if(i==0) cout<<"The snake Peter prefers eating '#'."<<endl;
        else if(i==1) cout<<"Author:little Hao"<<endl;
        else if(i==3) cout<<"How to move it?"<<endl;
        else if(i==4) cout<<"Up:w"<<endl;
        else if(i==5) cout<<"Down:s"<<endl;
        else if(i==6) cout<<"Left:d"<<endl;
        else if(i==7) cout<<"Right:a"<<endl;
        else if(i==9) cout<<"Can you get 100 points? Have a try."<<endl;
        //else if(i==10) cout<<""<<endl;
        else cout<<endl;
    }       
}
void Wall::setWall(int x,int y,char c) {
    gameArr[x][y]=c;
}

char Wall::getWall(int x,int y) {
    return gameArr[x][y];
}