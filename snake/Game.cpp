#include<iostream>
using namespace std;
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<windows.h>

int main()
{
    //添加随机种子
    srand((unsigned) time(NULL));

    Wall w1;
    w1.initWall();
    w1.drawWall();

    Food f1(w1);
    f1.setFood();

    Snake s1(w1,f1);
    s1.initSnake();

    gotoxy(hOut, 0, Wall::ROW);//光标定位
    cout<<"Score:"<<s1.getScore()<<" "<<"points."<<endl;

    bool isDead=false;
    //char arr[4]={'w','a','d','s'};
    //接收用户输入
    char key;
    char a='y';//y or n
    //char preMove=arr[2];
    char preMove;
    while(!isDead) {
        key=_getch();
        //进入移动的状态的输入是有条件的，不能180度转弯
        if((key=='w'||key=='s'||key=='a'||key=='d')&&(
        (key=='w'&&preMove!='s')||(key=='s'&&preMove!='w')||
        (key=='a'&&preMove!='d')||(key=='d'&&preMove!='a'))) {
            preMove=key;
            do {//用户没有输入就一直移动
                if(s1.move(key)==true) {
                    //移动成功
                    //system("cls");
                    //w1.drawWall();
                    gotoxy(hOut, 0, Wall::ROW);//光标定位
                    cout<<"Score:"<<s1.getScore()<<" "<<"points."<<endl;
                    Sleep(s1.getSpeed());
                } else {
                    isDead=true;
                    gotoxy(hOut, 0, Wall::ROW+2);//光标定位
                    cout<<"Do you want to continue, y or n? Enter to confirm."<<endl;
                    cin>>a;
                    switch(a) {
                        case 'y':
                            isDead=false;
                            break;
                        case 'n':
                            break;
                        default:
                            break;
                    }
                    //清屏
                    system("cls");
                    w1.initWall();
                    w1.drawWall();
                    f1.setFood();
                    s1.initSnake();
                    gotoxy(hOut, 0, Wall::ROW);//光标定位
                    cout<<"Score:"<<s1.getScore()<<" "<<"points."<<endl;
                    break;
                }
            }while(!_kbhit());//_kbhit()没有键盘输入返回0
        }   
    }

    system("pause");
    return 0; 
}
