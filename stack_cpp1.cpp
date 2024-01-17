#include <cstddef>
#include <cstdio>
#include <iostream>
using namespace std;

template<typename T, size_t MaxSize>
class Stack{
private:
  T elements[MaxSize];
  size_t topIndex;

public:
  Stack() : topIndex(0){}

  void push(const T& value){
    if(topIndex<MaxSize)
    {
      elements[topIndex++] = value;
    }
    else
    {
      printf("Stack is Full. Can not push.\n");
      exit(-1);
    }
  }

  void pop(){
    if (topIndex>0)
    {
      --topIndex;
    }
    else
    {
      printf("Stack is empty. Can not pop.\n");
      exit(-1);
    }
  }

  T top() const {
    if (topIndex>0)
    {
      return elements[topIndex-1];
    }
    else {
      printf("Stack is empty. Can not get top element.\n");
      exit(-1);
    }
  }

  bool isEmpty() const {
    return topIndex == 0;
  }

  size_t size() const {
    return topIndex;
  }
};

// To execute C++, please define "int main()"
int main() {

  Stack<int, 5> intStack;
  intStack.push(10);
  intStack.push(20);
  intStack.push(30);

  while (!intStack.isEmpty()) {
    printf("Top element : %d \n", intStack.top());
    intStack.pop();
  }

  Stack<double, 10> doubleStack;
  doubleStack.push(3.14);
  doubleStack.push(6.28);
  doubleStack.push(10.36);

  while (!doubleStack.isEmpty()) {
    printf("Top element : %f \n", doubleStack.top());
    doubleStack.pop();
  }
  
  return 0;
}
