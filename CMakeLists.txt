cmake_minimum_required(VERSION 3.12)
project(desafio-3)

# Use C++17 as C++ standard.
set(CMAKE_CXX_STANDARD 17)

# Create an executable named desafio with our files.
add_executable(desafio3 main.cpp source/Msg.cpp source/EmailMsg.cpp source/TextMsg.cpp source/MsgManager.cpp source/User.cpp)
