#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "NFL_Players.hpp"

using namespace std;

int main(){
    // CMake:
    // (1) Create new directory
    // (2) Switch Explorer to that new directory
    // (3) > CMake:Quick Start
    // (4) Set project name
    // (5) Set whether C/C++ Project
    // (6) Set whether executable/library
    // (7) Add tools - CTest & CPack
    // (8) Add new presets - "Create from Compilers" etc.
    // (9) set (CMAKE_CXX_STANDARD 23) in CMakeLists.txt to set c++ version to c++23
    // (10) make sure add_executable(CMake_Testing main.cpp) is last line of CMakeLists.txt
    // (11) add set(CMAKE_CXX_STANDARD_REQUIRED ON)
            //  set(CMAKE_CXX_EXTENSIONS OFF) to support (9)
    NFL_Players Player_1 = Generate_Player();
    string empty;
    getline(cin, empty);
    std::cout << "ENTER DETAILS FOR THE SECOND PLAYER" << "\n";
    NFL_Players Player_2 = Generate_Player();

    Player_1.Calculate_Player_Relationship_Score(Player_1, Player_2);
    Player_1.Relationship_Remarks(Player_1, Player_2);
    return 0;
}
