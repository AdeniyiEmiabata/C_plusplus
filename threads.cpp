#include <iostream>
#include <thread>
#include <string>
using namespace std;
static bool s_Finished = false;
//function that contains instructions for what we want the worker thread to do
void DoWork()
{
    using namespace std::literals::chrono_literals;
    //std::cout << "started thread id=" << &std::this_thread::get_id << std::endl;
    //int timer = 0;
    while (!s_Finished)
    {
    std::cout << "Waiting for info...\n";
    std::this_thread::sleep_for(30s); //wait 30 seconds after printing Working before printing it again. "this_thread" accesses the existing thread
    s_Finished = true;
    }
    std::cout << "TIME ELAPSED! Session over\n";

}

class Citizen
{
    public:
    string Name;
    int Age;
    string Occupation;
    string City_of_Residence;
    string Current_Company;

    void DisplayInfo() const{
        std::cout << "Name: " << Name << "\n";
        std::cout << "Age: " << Age << "\n";
        std::cout << "Job: " << Occupation << "\n";
        //std::cout << "Location: " << City_of_Residence << "\n";
        std::cout << "Company: " << Current_Company << "\n"; 
    }
    //constructor
    Citizen(){}
    //destructor
    ~Citizen(){}
};
int main()
{   
    Citizen James;
    std::cout << "Hey! What's your name?\n";
    std::thread worker(DoWork);
    std::getline(cin,James.Name);
    s_Finished = true;
    s_Finished = false;
    //std::cin.get(); //once we hit "Enter" which is the exit conditon for this line of code, since it's taking user input,
                    // it executes the next line and subsequently stops the DoWork() function from running.
    
    //s_Finished = true;

    

    //std::cout << "Finished" << std::endl;
    std::cout << "Hi! Nice to meet you " << James.Name << "\n"; //this will have a different thread id from the one used in the DoWork() function.
    s_Finished = true;
    s_Finished = false;
    std::cout << "So what do you do for work?\n";
    std::getline(cin, James.Occupation);
    std::cout << "That's fun! I wanted to do " << James.Occupation << " when I was younger\n" ;
    s_Finished = true;
    s_Finished = false;

    std::cout << "And how old are you?\n";
    std::cin >> James.Age;
    s_Finished = true;
    s_Finished = false;

    std::cout << "A couple of more questions...where do you currently work?\n";
    std::getline(cin, James.Current_Company);
    s_Finished = true;
    //s_Finished = false;
    worker.join(); //waits for the thread "worker" to finish all execution before main thread executes its next instructions
                   //Block the current thread
    
    James.DisplayInfo();
    //std::cin.get();
}

