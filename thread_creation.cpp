#include <iostream>
#include <thread>
//Multiple methods of thread creation


// //1 FUNCTION POINTER

// void fun(int x){
//     while (x-- > 0){
//         std::cout << x << std::endl;
//     }
// }

// int main(){
//     std::thread t1 (fun, 11); //Thread created
//     std::thread t2 (fun, 10);
//     t1.join();
//     t2.join(); //No guarantee that t1 is created before t2
// }

// 2 LAMBDA FUNCTION

// int main(){
//     //we can directly inject lambda at threat creation time
//     auto fun = [](int x){
//         while (x-- > 0){
//             std::cout << x << std::endl;
//         }
//     };

//     // OR

//     std::thread t([](int x){
//         while (x-- > 0){
//             std::cout << x << std::endl;
//         }
//     }, 10);

//     std::thread t (fun, 10);
//     t.join();
//     return 0;
// }

// 3 FUNCTORS (Function Object)

// class Base{
//     public:
//     void operator ()(int x){        //Functors overload the function call operator (), allowing the class instance to be called just like a function e.g Base(15)
//         while (x -- > 0){
//             std::cout << x << std::endl;
//         }
//     }
// };

// int main(){
//     std::thread t (Base(), 10); //example 2
//     t.join();
//     return 0;
// }

// 4 NON_STATIC MEMBER FUNCTION (Revisit)(Instances are needed to call function)

// class Base{
//     public:
//     void run(int x){
//         while (x-- > 0){
//             std::cout << x << std::endl;
//         }
//     }
// };

// int main(){
//     Base b;
//     std::thread t(&Base::run, &b, 10);
//     t.join();
//     return 0;
// }


// 5 STATIC MEMBER FUNCTION (Instances are not needed to call the functions)

class Base{
    public:
    static void run(int x){
        while (x-- > 0){
            std::cout << x << std::endl;
        }
    }
};

int main(){
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}
