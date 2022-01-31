#include "snake.h"
#include "wall.h"
#include "food.h"
#include<windows.h>

Snake::Snake(Wall &tempWall,Food &tempFood) : wall(tempWall),food(tempFood){//引用必须初始化
    pHead=NULL;
}
void Snake::destroySnake() {
    Point *temp=pHead;
    while(pHead!=NULL) {
        temp=pHead->next;
        delete pHead;
        pHead=temp;
    }
}
//此处设计非常巧妙，多加研究，面向对象的思想
//添加节点的方式为添加的新的位置为@，原来@的位置为=
void Snake::addPoint(int x,int y) {
    Point *newPoint=new Point;
    newPoint->x=x;
    newPoint->y=y;
    //newPoint->next=NULL;//应该等于pHead吧，否则导致删除节点无效
    newPoint->next=pHead;
    
    if(pHead!=NULL) {
        wall.setWall(pHead->x,pHead->y,'=');//@换成=
        gotoxy(hOut, 2*pHead->y, pHead->x);
        cout<<"=";
    }
        
    pHead=newPoint;//如果头为空，新节点为头，否则新节点也为头，原头换成等号
    wall.setWall(pHead->x,pHead->y,'@');//添加的新结点是头
    gotoxy(hOut, 2*pHead->y, pHead->x);
    cout<<"@";
}
void Snake::initSnake() {
    destroySnake();

    addPoint(5,3);
    addPoint(5,4);
    addPoint(5,5);

}
//链表删除尾节点的算法
void Snake::dePoint() {
    //蛇的节点小于2不执行删除操作，感觉不需要，因为不删尾的情况好像没有，只要调用了删尾操作，就需要执行
    //if(pHead->next==NULL) return;
    Point *pre=pHead;
    Point *cur=pHead->next;

    while(cur->next!=NULL) {
        //pre=pHead->next;
        pre=pre->next;
        cur=cur->next;
    }
    //删除尾结点  
    wall.setWall(cur->x,cur->y,' ');
    gotoxy(hOut, 2*cur->y, cur->x);
    cout<<" ";
    delete cur;
    pre->next=NULL;
}
bool Snake::move(char key) {
    //获取头的坐标，因为增加节点是将原来的头换成=，新的位置换成@，所以先抓住头这个主要影响因素
    int x=pHead->x;
    int y=pHead->y;
    switch(key) {
        case Up:
            x--;
            break;
        case Down:
            x++;
            break;
        case Left:
            y--;
            break;
        case Right:
            y++;
            break;
        default:
            break;
    }
    Point *cur=pHead;

    while(cur->next!=NULL) {
        //pre=pHead->next;
        cur=cur->next;
    }
    //如果移动后撞到墙或者碰到身子，碰到尾巴不结束
    if(wall.getWall(x,y)=='*'||wall.getWall(x,y)=='=') {
        if(cur->x==x&&cur->y==y) {
            addPoint(x,y);//别忘了加这些
            dePoint();
            return true;
        }
        cout<<"Game Over!"<<endl;
        return false;
    } else {//分两种情况
        if(wall.getWall(x,y)=='#') {//吃到食物
            addPoint(x,y);
            //别忘记重新设置食物
            food.setFood();
            return true;
        } else {
            addPoint(x,y);
            dePoint();
            return true;
        }
    }

}
int  Snake::getScore() {
    Point *cur=pHead;//这里的cur应该属于局部变量，应该和dePoint里的cur不冲突S
    numNode=0;
    while(cur!=NULL) {
        numNode++;
        cur=cur->next;
    }
    score=(numNode-3)*5;
    return score;
}
//void Snake::getNum() {}
//先输出分数再输出速度
int Snake::getSpeed() {
    if(numNode<5) moveSpeed=200;
    else if(numNode<10) moveSpeed=150;
    else if(numNode<15) moveSpeed=140;
    else if(numNode<20) moveSpeed=120;
    else moveSpeed=100;
    return moveSpeed;
}
