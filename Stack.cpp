#include <iostream>
#include <stack>
#include <vector>
int main(){

    // stack declaration: LIFO - Last In First Out
    std::stack<int> Stack_Example;

    //insert elements
    // Elements are inserted in reverse order
    Stack_Example.push(1);
    Stack_Example.push(2);
    Stack_Example.push(3);
    Stack_Example.push(4);
    Stack_Example.push(5);
    Stack_Example.push(6);
    Stack_Example.push(7);
    Stack_Example.push(8);

    //Insert elements using an underlying container: insert in bulk
    // use a vector as the underlying container
    std::vector <int> Vector_Example = {13, 23, 55};
    std::stack <int, std::vector<int>> StackExample_2(Vector_Example);


    //length of stack
    int length = Stack_Example.size();
    std::cout << "Initial Length is " << length << "\n";

    //remove elements
    Stack_Example.pop(); // will remove the element added last (8)
    Stack_Example.pop(); // then removes next

    //length of stack
    int length_pop = Stack_Example.size();
    std::cout << "New Length is " << length_pop << "\n";

    // Get most recently added element in stack
    std::cout << "Most recent element is " << Stack_Example.top() << "\n";
    std::cout << "Most recent element is " << StackExample_2.top() << "\n";
    
    // check if empty: 1 (yes) or 0 (no)
    std::cout << "Empty or not " << Stack_Example.empty() << "\n";

    std::cout << "\n\n\n\n";
    // iterate over elements (at an instance, can only check top element)
    while(!Stack_Example.empty()){
        std::cout << Stack_Example.top() << "\n";
        Stack_Example.pop();
    }    
}