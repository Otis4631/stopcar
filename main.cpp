#include "stack.h"
#include "queue.h"
#include <iostream>

using namespace std;
typedef int Time;
typedef struct{
    char Cmd;
    int CarNum;
    Time time;
}InputData;    //输入数据

typedef struct StackNode{
    int CarNum;
    Time reach;
    Time leave;
    struct StackNode *next;
}CarNode;  //每个汽车的信息


void CarEntrance(CStack<CarNode> *Garage , CQueue<CarNode> *carQueue , int carNum , int time){
    CarNode *car= new CarNode;
    if(!car){
        cout << "动态内存分配失败！\n";
        exit(0);
    }
    car->reach = time;
    car->CarNum = carNum;
    if(!Garage->IsFull()){
        Garage->push(car);
        cout << "车已入库！\n";
    }
     else{
        carQueue->push(car);
        cout << "车库已满，车进入便道。\n";
    }
}

void CarLeave(CStack<CarNode> *Garage,CStack<CarNode> *Temp,CQueue<CarNode> *carQueue,int carNum,int time ){
    CarNode *car = new CarNode;
    if(!car){
        cout << "动态内存分配失败！\n";
        exit(0);
    }
    Time leave = time;

}



void Input (InputData *inputData){
    int max_size;
    cout << "请输入停车场容量 max_size （最多为100）：";
    do
     {
        cin >> max_size;
        if(!(max_size<=100 && max_size>0))
            cout << "输入有误，请重新输入：";
     }
    while(!(max_size<=100 && max_size>0));
    CStack <CarNode> Garage(max_size);
    CStack <CarNode> Temp(max_size);
    CQueue <CarNode>  CarQueue(max_size);
    bool end_flag=0;
    while(!end_flag){
        bool input_end_flag=0;
        while(!input_end_flag){
            cout << "请输入车库命令，格式如下（命令，车牌号，入库或出库时间）" << endl;
            cout << "A(a)-入库\tD(d)-离开\t"<< endl;
            cin >> inputData->Cmd >> inputData->CarNum >> inputData->time;
            if(inputData->Cmd!='A' && inputData->Cmd!='a' && inputData->Cmd!='D' && inputData->Cmd!='d' && inputData->Cmd!='E' && inputData!='e'){
                cout << "命令不正确，请重新输入！" << endl;
                input_end_flag=0;
            }
            else input_end_flag=1;
            switch(inputData->Cmd){
                case 'A':
                case 'a':
                    CarEntrance(&Garage,&CarQueue,inputData->CarNum,inputData->time);
                    break;                                                              //车入库函数
                case 'D':
                case 'd':
                     CarLeave(&Garage,&Temp,&CarQueue,inputData->CarNum,inputData->time);  //车出库函数
                     break;
                case 'E':
                case 'e':
                    end_flag=1; 
            }
        }
    }
}
