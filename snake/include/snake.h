#pragma once
#include<iostream>
using namespace std;
#include "wall.h"
#include "food.h"

class Snake {
public:
    Snake(Wall &tempWall,Food &tempFood);
    //初始化蛇
    void initSnake();
    //每次运行前销毁蛇
    void destroySnake();
    //增加节点
    void addPoint(int x,int y);
    //删除尾结点
    void dePoint();
    //移动操作
    bool move(char key);
    //获取节点数量
    //void getNum();
    //获得得分
    int getScore();
    //获得移动速度
    int getSpeed();
    //感觉可以设置为公有的数据，公有私有原则？
    int moveSpeed;
    int score;
private:
    //节点数据
    struct Point {
        //x,y指向所对应墙区域的位置
        int x;
        int y;
        Point *next;
    };
    //用一个指针指向头结点
    Point *pHead;
    Wall &wall;
    //移动数据
    enum {Up='w',Down='s',Left='a',Right='d'};
    Food &food;
    int numNode=0;
};