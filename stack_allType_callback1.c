#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_INITIAL_CAPACITY 10
#define STACK_REALLOC_FACTOR 2

typedef void (*FreeElementFunc)(void*);

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
    FreeElementFunc freeElement; // 释放元素的回调函数
} Stack;

// 初始化栈
bool initializeStack(Stack* stack, FreeElementFunc freeElement) {
    stack->data = malloc(STACK_INITIAL_CAPACITY * sizeof(void*));
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return false;
    }
    stack->size = 0;
    stack->capacity = STACK_INITIAL_CAPACITY;
    stack->freeElement = freeElement;
    return true;
}

// 推入元素
bool push(Stack* stack, void* element) {
    if (stack->size == stack->capacity) {
        // 保存原有数据
        void** originalData = stack->data;
        size_t originalSize = stack->size;
        size_t originalCapacity = stack->capacity;

        // 尝试使用 realloc 分配新的内存
        stack->capacity *= STACK_REALLOC_FACTOR;
        stack->data = realloc(stack->data, stack->capacity * sizeof(void*));

        if (stack->data == NULL) {
            // 如果 realloc 失败，还原原有数据并返回错误码
            fprintf(stderr, "Memory reallocation failed\n");

            // 还原原有数据
            stack->data = originalData;
            stack->size = originalSize;
            stack->capacity = originalCapacity;

            return false;
        }
    }

    stack->data[stack->size++] = element;
    return true;
}

// 弹出元素
void pop(Stack* stack) {
    if (stack->size > 0) {
        stack->size--;

        // 调用回调函数释放元素内存
        if (stack->freeElement != NULL) {
            stack->freeElement(stack->data[stack->size]);
        }
    } else {
        fprintf(stderr, "Error: Stack is empty. Cannot pop element.\n");
    }
}

// 获取栈顶元素
void* top(const Stack* stack) {
    if (stack->size > 0) {
        return stack->data[stack->size - 1];
    } else {
        fprintf(stderr, "Error: Stack is empty. Cannot get top element.\n");
        return NULL;
    }
}

// 检查栈是否为空
bool isEmpty(const Stack* stack) {
    return stack->size == 0;
}

// 释放栈内存
void freeStack(Stack* stack) {
    // 释放每个元素的内存
    if (stack->freeElement != NULL) {
        for (size_t i = 0; i < stack->size; i++) {
            stack->freeElement(stack->data[i]);
        }
    }

    free(stack->data);
    stack->size = 0;
    stack->capacity = 0;
}

// 示例：释放整型元素内存的回调函数
void freeIntElement(void* element) {
  // printf("Debug in freeIntElement\n");
    if (element != NULL) {
      //下面这句话会导致crash, 需要进一步研究
      //crash原因是不能free一个void *,需要用更复杂的数据结构来完成
        // free(element);
    }
}

int main() {
    Stack myStack;

    // 提供释放元素内存的回调函数
    if (!initializeStack(&myStack, freeIntElement)) {
        fprintf(stderr, "Error: Stack initialization failed.\n");
        return EXIT_FAILURE;
    }

    // 在堆上分配整型元素
    int* num1 = malloc(sizeof(int));
    *num1 = 42;
    double num2 = 3.14;
    char ch = 'A';

    if (!push(&myStack, num1) || !push(&myStack, &num2) || !push(&myStack, &ch)) {
        fprintf(stderr, "Error: Push operation failed.\n");
    } else {
        printf("Top element: %c\n", *(char *)top(&myStack));
    }

    pop(&myStack);

    if (!isEmpty(&myStack)) {
        printf("Top element after pop: %f\n", *(double*)top(&myStack));
    }

    freeStack(&myStack);

    return 0;
}
