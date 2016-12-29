#include "stack.h"
template<class T>
CStack<T>::CStack(int MaxStackSize){  //类的构造函数
    MaxTop = MaxStackSize - 1;
    stack = new T[MaxStackSize];
    top = -1;
}

template<class T>
T CStack<T>::Top() const{    // 返回栈顶元素
    if (!IsEmpty())
        return stack[top];
}

template<class T>
void CStack<T>::Push(const T x){ //添加元素x
    if (!IsFull())
    {
        stack[++top] = x;
    }
}

template<class T>
T CStack<T>::Pop(){// 删除栈顶元素，并返回其值。
    if (!IsEmpty())
        return stack[top--];
}
template <class T>
int CStack<T>:: GetCarAmount(){
    return top+1;
}

/*template<class T>
bool CStack<T>::GetCarPos(int &x,int carNum){
    int temp=top;
    while(temp){
        if(carNum == stack[top].CarNum){
            x=temp;
            return true;
        }
        temp--;
    }
    if(stack[temp]!=carNum)
        return false;
}*/
