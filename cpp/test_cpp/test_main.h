#pragma once

#include<iostream>

// ����һ������ָ������
typedef int (*TestFunc)(int argc, char* argv[]);

#include "class/class_test.h"
#include "ctp/ctp_test.h"
#include "lib/lib_test.h"

// ���庯������
TestFunc testFunctions[] = {
    class_test_main,
    ctp_test_main,
    lib_test_main,
};

const int numFunctions = sizeof(testFunctions) / sizeof(testFunctions[0]);

