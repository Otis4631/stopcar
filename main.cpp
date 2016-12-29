#include "stack.h"
#include "queue.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


typedef double Time;
typedef struct{
    char Cmd;
    int CarNum;
    Time time;
}InputData;    //输入数据

typedef struct{
    int CarNum;
    Time reach;
    Time leave;
   // struct StackNode *next;
}CarNode;  //每个汽车的信息


void CarEntrance(CStack<CarNode> *Garage , CQueue<CarNode> *carQueue , int carNum , Time time){
    CarNode *car= new CarNode;
    if(!car){
        cout << "动态内存分配失败！\n";
        exit(0);
    }
    car->reach = time;
    car->CarNum = carNum;
    if(!Garage->IsFull()){
        Garage->Push(*car);
        cout << "车已入库！\n";
    }
     else{
        carQueue->Push(*car);
        cout << "车库已满，车进入便道。\n";
    }
}

void PrintCarInfo(CarNode car){
	double cost = (car.leave - car.reach)*2.0;
	cout << "车辆的号码\t进库时间\t离开时间\t车费（元）";
	cout << car.CarNum << '\t' << car.reach << '\t' << car.leave << '\t' << cost << endl;
}

void PrintAmount(CStack<CarNode> *Garage,CStack<CarNode> *Temp,CQueue<CarNode> *carQueue){
    cout << "当前车库中车的数量：" << Garage->GetCarAmount  << '\t' << "当前便道中车的数量:" << carQueue->GetCarAmount << '\t' <<  "当前临时车道中的数量：" << Temp->GetCarAmount << endl;
}

void CarLeave(CStack<CarNode> *Garage,CStack<CarNode> *Temp,CQueue<CarNode> *carQueue,int carNum,Time time ){
    CarNode *car = new CarNode;
    if(!car){
        cout << "动态内存分配失败！\n";
        exit(0);
    }
    car->CarNum = carNum;
    car->leave = time;
    while(!Garage->IsEmpty()){
        if(Garage->Top().CarNum != car -> CarNum){
            Temp->Push(Garage->Pop());    //车进入临时车道
            if(Garage->IsEmpty())
                cout << "没有该车牌的车！";
        }
        else{      // 获得车辆信息，并回归临时车道的车。
             *car = Garage->Pop();
             PrintCarInfo(*car); // 打印车辆消费单
             while(!Temp->IsEmpty()){   //回归临时车道的车。
                Garage->Push(Temp->Pop());
             }
			 if(!carQueue->IsEmpty()){     //便道中一辆车进入车站。
				Garage->Push(carQueue->Pop());
				cout << "车场有空位，便道第一辆车进入。\n";
				break;                  // 车已经找到，退出循环。
			 }     
        }
    }
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
            if(inputData->Cmd!='A' && inputData->Cmd!='a' && inputData->Cmd!='D' && inputData->Cmd!='d' && inputData->Cmd!='E' && inputData->Cmd!='e'){
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
int main(){
    InputData inputData;
    Input(&inputData);
    return 0;
}
