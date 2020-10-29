cmake_minimum_required(VERSION 3.17)
project(MySQL Example)

set(CMAKE_CXX_STANDARD 11)

add_executable(Test main.cc)

target_link_libraries(Test mysqlcppconn)
