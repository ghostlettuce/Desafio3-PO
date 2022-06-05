cmake_minimum_required(VERSION 3.12)
project(desafio-3)

# Use C++17 as C++ standard.
set(CMAKE_CXX_STANDARD 17)

# Create an executable named desafio with our files.
add_executable(desafio3 main.cpp Msg.cpp EmailMsg.cpp TextMsg.cpp MsgManager.cpp User.cpp)
