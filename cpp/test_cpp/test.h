#pragma once

#include<iostream>

// ����һ������ָ������
typedef int (*TestFunc)(int argc, char* argv[]);

#include"class_test.h"

// ���庯������
TestFunc testFunctions[] = {
    class_test_main,
};

const int numFunctions = sizeof(testFunctions) / sizeof(testFunctions[0]);

