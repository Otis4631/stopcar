#ifndef __STACK_H__
#define __STACK_H__
#include<iostream>
template<class T>
class CStack{  // LIFO 对象
public :
    CStack(int MaxStackSize = 10);
    ~CStack () {delete [] stack;}
    bool IsEmpty() const {return top == -1;}
    bool IsFull() const {return top == MaxTop ; }
T Top() const;   //test
void Push(const T x);
T Pop();
//int GetCarPos(int &x,int carNum

private :
    int top; // 栈顶
    int MaxTop; // 最大的栈顶值
    T *stack; // 堆栈元素数组
};
#endif
