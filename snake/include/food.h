#pragma once
#include "wall.h"
#include<windows.h>//food.cpp中没有包含#include<windows.h>，所以说明#include内容可以递归展开

void gotoxy(HANDLE hOut, int x, int y);
extern HANDLE hOut;//类比函数,这里声明了一次，具体的定义交给链接器去找

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
