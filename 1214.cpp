#include <iostream>
#include <string>
#include <thread>


int main(){
    //std::cout << "1, 2" << std::endl;
    //goto SECOND_LOOP;
    goto FIRST_LOOP;

    FIRST_LOOP:
    for (int i = 0; i < 7; i++){
        std::cout << i << "\n" << std::endl;
    }

    SECOND_LOOP:
    for (int i = 7; i >= 0; i--){
        std::cout << i << "\n" << std::endl;
    }
}
