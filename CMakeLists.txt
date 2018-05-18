cmake_minimum_required (VERSION 3.8)
project(GlobalSwitching)

include_directories ("${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11)
# Add source to this project's executable.
add_executable (GlobalSwitching GlobalSwitching "GlobalSwitching.cpp"; "cpps/CurrentMemoryManagerStrategy.cpp";
"cpps/MemoryManagerSwitcher.cpp"; "cpps/RuntimeHeapStrategy.cpp"; "cpps/StackMemoryManager.cpp"; "cpps/StdMemoryManager.cpp")


