
#include <iostream>
#include <thread>
#include <chrono>

int Function(int maximum){
    while (maximum > 0){
        std::cout <<  maximum << std::endl;
        maximum --;
    }
    //std::this_thread::sleep_for(std::chrono::seconds(3)); // wait/sleep for three seconds before ending the thread. JOIN ends
    std::cout << "Thread finished" << std::endl;
    return 0;
}
// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)

// int main(){

//     std::thread thread_example (Function, 23);
//     std::cout << "main() start" << std::endl; //This will be printed at the start of the printing output of the function "Function"
//     if (thread_example.joinable()){  //Best practice is to check if the thread is actually joinable before joining. This guards against double joining.
//         thread_example.join();
//     }
    
//     //thread_example.join(); //throws an error if you join the same thread twice: ibc++abi: terminating due to uncaught exception of type std::__1::system_error: thread::join failed: Invalid argument
//     std::cout << "main() done" << std::endl; //This will not be printed until "Function" is done running, due to the .join() performed right before. 
//     // Which means wait till thread is done before continuing execution.
//     return 0;
// }



// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.


int main(){ //The Parent thread in this case is the thread running int main().

    std::thread thread_example (Function, 23);
    std::cout << "main() start" << std::endl; //This will be printed at the start of the printing output of the function "Function"
    
    if (thread_example.joinable())
        thread_example.detach(); //by detaching this thread, we no longer wait for it to finish before proceeding to the next line of execution.

    std::cout << "main() done" << std::endl; 
    std::this_thread::sleep_for(std::chrono::seconds(5)); // waits 5 seconds to for thread_example to finish executing
    
    return 0; //If we have detached thread and main function is returning then the detached thread execution is suspended.
}

// NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will 
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.