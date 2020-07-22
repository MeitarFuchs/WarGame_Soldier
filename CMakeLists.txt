cmake_minimum_required(VERSION 3.15)
project(Wargame)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wargame Demo.cpp Soldier.hpp FootCommander.cpp FootSoldier.cpp Board.cpp  DemoGame.hpp SniperCommander.cpp Sniper.cpp Paramedic.cpp ParamedicCommander.cpp)