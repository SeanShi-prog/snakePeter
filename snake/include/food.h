#pragma once
#include "wall.h"
#include<windows.h>//food.cpp中没有包含#include<windows.h>，所以说明#include内容可以递归展开

//多重定义
/* void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与二维数组是相反的
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}//光标定位函数
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); */
//int a;multiple definition of `a'

void gotoxy(HANDLE hOut, int x, int y);
extern HANDLE hOut;//类比函数,这里声明了一次，具体的实现交给编译器

class Food {
public:
    Food(Wall &tempWall);
    void setFood();
private:
    //食物的坐标
    int foodX;
    int foodY;
    Wall &wall;
};