#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
C 实现 C++ 类

C 实现 C++ 的面向对象特性（封装、继承、多态）

封装：使用函数指针把属性与方法封装到结构体中
继承：结构体嵌套
多态：父类与子类方法的函数指针不同
*/

//其他几个版本的解释： 
//https://www.cnblogs.com/skynet/archive/2010/09/23/1833217.html
//https://www.codeproject.com/Articles/108830/Inheritance-and-Polymorphism-in-C
//https://stackoverflow.com/questions/351733/how-would-one-write-object-oriented-code-in-c/351745#351745


// "类"的定义
typedef struct {
    int age;
    char name[50];
} Person;

// "构造函数"
Person* createPerson(int age, const char* name) {
    Person* person = (Person*)malloc(sizeof(Person));
    if (person != NULL) {
        person->age = age;
        strncpy(person->name, name, sizeof(person->name) - 1);
        person->name[sizeof(person->name) - 1] = '\0'; // 确保字符串以null结尾
    }
    return person;
}

// "成员函数"
void printPerson(const Person* person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

// "析构函数"
void destroyPerson(Person* person) {
    free(person);
}

//===========================================

/*
// 基类
typedef struct {
    int age;
    char name[50];
} Person;
*/

// 派生类
typedef struct {
    Person base; // 基类对象嵌入派生类
    char profession[50];
} Employee;

// 构造函数
Employee* createEmployee(int age, const char* name, const char* profession) {
    Employee* employee = (Employee*)malloc(sizeof(Employee));
    if (employee != NULL) {
        employee->base.age = age;
        strncpy(employee->base.name, name, sizeof(employee->base.name) - 1);
        employee->base.name[sizeof(employee->base.name) - 1] = '\0';
        strncpy(employee->profession, profession, sizeof(employee->profession) - 1);
        employee->profession[sizeof(employee->profession) - 1] = '\0';
    }
    return employee;
}

// 成员函数
void printEmployee(const Employee* employee) {
    printf("Name: %s, Age: %d, Profession: %s\n",
           employee->base.name, employee->base.age, employee->profession);
}

// 析构函数
void destroyEmployee(Employee* employee) {
    free(employee);
}


//===========================================

// 基类
typedef struct {
    void (*printInfo)(const void*); // 成员函数指针
} Shape;

// 派生类1
typedef struct {
    Shape base; // 基类对象嵌入派生类
    double radius;
} Circle;

// 派生类2
typedef struct {
    Shape base; // 基类对象嵌入派生类
    double width;
    double height;
} Rectangle;

// 成员函数
void printCircle(const void* shape) {
    const Circle* circle = (const Circle*)shape;
    printf("Circle with radius %.2f\n", circle->radius);
}

void printRectangle(const void* shape) {
    const Rectangle* rectangle = (const Rectangle*)shape;
    printf("Rectangle with width %.2f and height %.2f\n", rectangle->width, rectangle->height);
}



int main() {
    // 使用封装
    Person* person = createPerson(25, "John Doe");
    printPerson(person);

    // 销毁对象
    destroyPerson(person);


//===========================================


    // 使用继承
    Employee* employee = createEmployee(30, "Jane Doe", "Software Engineer");
    printEmployee(employee);

    // 销毁对象
    destroyEmployee(employee);


//===========================================


    // 使用多态
    Circle circle = {{printCircle}, 5.0};
    Rectangle rectangle = {{printRectangle}, 4.0, 6.0};

    // 调用成员函数
    circle.base.printInfo(&circle);
    rectangle.base.printInfo(&rectangle);

    return 0;
}
