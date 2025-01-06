#include <iostream>
#include <set>



int main(){

std::set<int> Sets = {1,3,2, 5, 6};
std::set<int>::iterator Iter = Sets.end();


std::cout << *(Iter++) ;
}