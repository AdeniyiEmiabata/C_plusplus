#include <iostream>
#include <set>
#include <string>
#include <ranges>
#include <functional>
#include <map>
#include <numeric>
#include <algorithm>

class StringTimer{
    private:
    int max_entries;
    std::map<time_t, std::string> Times_Values;


    public:
    // Constructor
    StringTimer():max_entries{1'000'000}{} 


    void Add_Elements(time_t& time, std::string& func_string){           
        if(Times_Values.size() < max_entries){
            Times_Values[time] = func_string;
        }
    }

    time_t Average_Time()const          
    {
        if (Times_Values.empty()){
            return 0;
        }

        time_t Total_Time = std::accumulate(
            Times_Values.begin(), Times_Values.end(), time_t{},
            [](time_t sum, const auto& key_value) { return sum + key_value.first; }
        );

        return Total_Time / Times_Values.size();
    }

    int Number_of_Eligible_Times(time_t& Minimum_Time)const     
    {
        return std::count_if(Times_Values.begin(), Times_Values.end(), [Minimum_Time](const auto& key_value) {
        return key_value.first >= Minimum_Time;
    });
    }

    int Number_of_Eligible_Strings(int Minimum_Character_Count) const
    {
        return std::count_if(Times_Values.begin(), Times_Values.end(), [Minimum_Character_Count](const auto& key_value) {
        return key_value.second.size() >= Minimum_Character_Count;
    });
    }

    std::string Find_Longest_String()const
    {

        if (Times_Values.empty()) {
            return "";
        }

        auto longest_string = std::max_element(Times_Values.begin(), Times_Values.end(),
        [](const auto& key_value, const auto& key_value_2) { 
            return key_value.second.size() < key_value_2.second.size(); }
        );

        return longest_string-> second;

    }

     int Total_Number_of_Strings()const 
    {
        return Times_Values.size();
    }

    bool Check_for_Time(time_t& time)const 
    {
        return Times_Values.count(time);
    }

    bool Check_for_String(const std::string& func_string) const
    {
    return std::any_of(Times_Values.begin(), Times_Values.end(), [&func_string](const auto& key_value) {
        return key_value.second == func_string;
    });
    }
    

};






