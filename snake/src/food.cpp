#include<iostream>
using namespace std;
#include "food.h"

void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与二维数组是相反的
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}//光标定位函数
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall &tempWall) :wall(tempWall) {

}
void Food::setFood() {
    //保证食物不出现在蛇上
    while(true) {
       //确定随机位置
        foodX=rand()%(wall.ROW-2)+1;
        foodY=rand()%(wall.COL-2)+1; 
        if(wall.getWall(foodX,foodY)==' ') {
            wall.setWall(foodX,foodY,'#');//在墙上设置
            gotoxy(hOut, 2*foodY, foodX);
            cout<<"#";
            break;
        }
    }
}