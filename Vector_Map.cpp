#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
vector<int> Vector1 = {11, 45, 34, 90, 75, 55, 29};

//size of vector
int length = Vector1.size();

// initialize map
map<int, string> Map1;

for(int i = 0; i < length; i++){
    getline(cin, Map1[i+1]); 
}

map<int, string>::iterator Iter;
int count = 0;
for(Iter = Map1.begin(); Iter != Map1.end(); Iter++){
    cout << "The " << Iter->second << " element is " << Vector1[count] << "\n";
    count++;
}

return 0;
}