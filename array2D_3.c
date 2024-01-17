#include <stdio.h>
#include <stdlib.h>

//要求改进2d数组的实现方式使得全部数据在一块连续的空间上
// 结构体：用于存储二维数组信息
typedef struct {
    int rows;
    int cols;
    int* data; // 一维数组模拟二维数组
} Array2D;

// 函数：分配二维整数数组的空间
Array2D allocate2DArray(int rows, int cols) {
    Array2D array2D;
    array2D.rows = rows;
    array2D.cols = cols;

    // 分配一维数组作为二维数组的模拟
    array2D.data = (int*)malloc(rows * cols * sizeof(int));

    if (array2D.data == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    return array2D;
}

// 函数：释放二维整数数组的空间
void free2DArray(Array2D array2D) {
    free(array2D.data);
}

// 函数：通过索引访问二维数组元素
int getElement(Array2D array2D, int row, int col) {
    return array2D.data[row * array2D.cols + col];
}

// 函数：通过索引设置二维数组元素值
void setElement(Array2D array2D, int row, int col, int value) {
    array2D.data[row * array2D.cols + col] = value;
}

int main() {
    int rows = 3;
    int cols = 4;

    // 分配二维整数数组的空间
    Array2D myArray = allocate2DArray(rows, cols);

    // 初始化二维数组（示例：将所有元素设为 0）
    for (int i = 0; i < myArray.rows; i++) {
        for (int j = 0; j < myArray.cols; j++) {
            setElement(myArray, i, j, 0);
        }
    }

    // 使用二维数组

    // 释放二维整数数组的空间，无需提供数组大小
    free2DArray(myArray);

    return 0;
}
