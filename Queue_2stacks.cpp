#include <cstddef>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class MyQueue{
private:
  std::stack<T> inputStack;
  std::stack<T> outputStack;

public:
  //add an element to the end of myqueue
  void enqueue(const T& element){
    inputStack.push(element);
  }

  //remove an element from the head of myqueue
  T dequeue(){
    if (outputStack.empty())
    {
      while (!inputStack.empty()) {
        outputStack.push(inputStack.top());
        inputStack.pop();
      }
    }

    if (outputStack.empty())
    {
      printf("Queue is empty.\n");
      return T();
    }

    T frontElement = outputStack.top();
    outputStack.pop();

    return frontElement;
  }

  bool isEmpty() const {
    return inputStack.empty() && outputStack.empty();
  }

  size_t size() const {
    return inputStack.size() + outputStack.size();
  }
};



// To execute C++, please define "int main()"
int main() {

  MyQueue<int> myQueue;
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  
  printf("dequeue : %d \n", myQueue.dequeue());
  printf("dequeue : %d \n", myQueue.dequeue());

  myQueue.enqueue(4);
  myQueue.enqueue(5);

  printf("size of queue : %zu \n", myQueue.size());
  printf("dequeue : %d \n", myQueue.dequeue());
  printf("dequeue : %d \n", myQueue.dequeue());

  myQueue.enqueue(6);
  myQueue.enqueue(7);

  printf("dequeue : %d \n", myQueue.dequeue());
  printf("dequeue : %d \n", myQueue.dequeue());

  printf("size of queue : %zu \n", myQueue.size());

  return 0;
}
