# QUANTITATIVE_SYSTEM

[TOC]

### SOME RECORD

---

#### 关于CmakeLists.txt的静态库导入

测试发现在使用add_subdirectory并且在子CmakeLists.txt中使用link_directories来指定库目录不生效，在target_link_libraries的时候还会报错，提示找不到（无法打开）库文件。

针对以上问题，暂时不深究导致它的原因，我这里通过find_library实现了一种通用的解决方案

```cmake
function(find_and_print_library lib_name lib_path_var search_path)
	message(STATUS "search_path: ${search_path}")
	find_library(${lib_path_var} NAMES ${lib_name} PATHS ${search_path})
	if (${lib_path_var})
		message(STATUS "${lib_name} found at: ${${lib_path_var}}")
	else()
	    message(FATAL_ERROR "${lib_name} not found at ${search_path}")
	endif()
endfunction()
```

使用示例

```CMAKE
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
find_and_print_library(lib_a lib_a_PATH ${TRADEAPI_PATH})
target_link_libraries(target 
	${lib_a_PATH}
)
```

---

