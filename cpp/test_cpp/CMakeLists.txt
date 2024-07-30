# CMakeList.txt: QUANTITATIVE_SYSTEM 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("test_cpp")

# 将源代码添加到此项目的可执行文件。
add_executable(test_cpp "test_main.cpp" "test_main.h" "class/class_test.cpp" "class/class_test.h" "ctp/ctp_test.cpp" "ctp/ctp_test.h" "lib/lib_test.cpp" "lib/lib_test.h")

# 打印 CMAKE_CURRENT_SOURCE_DIR
message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

function(find_and_print_library lib_name lib_path_var search_path)
	message(STATUS "search_path: ${search_path}")
	find_library(${lib_path_var} NAMES ${lib_name} PATHS ${search_path})
	if (${lib_path_var})
		message(STATUS "${lib_name} found at: ${${lib_path_var}}")
	else()
	    message(FATAL_ERROR "${lib_name} not found at ${search_path}")
	endif()
endfunction()

set(TRADEAPI_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../include/ctp/traderapi/win64)
find_and_print_library(thostmduserapi_se thostmduserapi_se_LIB_PATH ${TRADEAPI_PATH})
find_and_print_library(thosttraderapi_se thosttraderapi_se_LIB_PATH ${TRADEAPI_PATH})
find_and_print_library(lib_a lib_a_PATH ${TRADEAPI_PATH})

target_link_libraries(test_cpp 
	${thostmduserapi_se_LIB_PATH}
	${thosttraderapi_se_LIB_PATH}
	${lib_a_PATH}
)




if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET test_cpp PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
