#pragma once

#include<iostream>

// 声明一个函数指针类型
typedef int (*TestFunc)(int argc, char* argv[]);

#include"class_test.h"

// 定义函数数组
TestFunc testFunctions[] = {
    class_test_main,
};

const int numFunctions = sizeof(testFunctions) / sizeof(testFunctions[0]);

