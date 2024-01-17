#include <cstddef>
#include <cstdio>
#include <iostream>
using namespace std;

template<typename T>

class Stack{
private:
  T * elements;
  size_t capacity;
  size_t topIndex;

public:
  Stack(size_t initCapacity = 10) : capacity(initCapacity), topIndex(0){
    elements = new T[capacity];
  }

  ~Stack(){
    delete [] elements;
  }

  void push(const T& value){
    if (topIndex == capacity){
      capacity *= 2;
      T * newElements = new T[capacity];
      for (size_t i = 0; i<topIndex; ++i)
      {
        newElements[i] = elements[i];
      }
      delete [] elements;
      elements = newElements;
    }
    elements[topIndex++] = value;
  }

  void pop(){
    if (topIndex>0)
    {
      --topIndex;
    }
    else {
      printf("Stack is empty. Can not pop.\n");
    }
  }

  T top() const {
    if (topIndex>0)
    {
      return elements[topIndex-1];
    }
    else
    {
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

  Stack<int> intStack;
  intStack.push(10);
  intStack.push(20);
  intStack.push(30);

  while (!intStack.isEmpty()) {
    printf("Top element : %d \n", intStack.top());
    intStack.pop();
  }

  Stack<double> doubleStack;
  doubleStack.push(3.14);
  doubleStack.push(6.28);
  doubleStack.push(10.36);

  while (!doubleStack.isEmpty()) {
    printf("Top element : %f \n", doubleStack.top());
    doubleStack.pop();
  }

  return 0;
}
