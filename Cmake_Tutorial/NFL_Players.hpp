#include <iostream>
#include <string>
#include <set>

using namespace std;

// List of Divisions
// used extern because these are defined in NFL_Players.cpp
extern vector<string> AFC_East;
extern vector<string> AFC_West;
extern vector<string> AFC_North;
extern vector<string> AFC_South;

extern vector<string> NFC_East;
extern vector<string> NFC_West;
extern vector<string> NFC_North;
extern vector<string> NFC_South;

// List of Positions (Sides of the Ball)
extern vector<string> Defense;
extern vector<string> Offense;

// List of Position Groups
extern vector<string> Offensive_Line;
extern vector<string> Receivers;
extern vector<string> Running_Backs;

extern vector<string> Defensive_Line;
extern vector<string> Secondary;
extern vector<string> Linebackers;

class NFL_Players{


string Name;
string Team;
string Division;
string Position;
string College;
string Position_Group;
string Broader_Position_Group;
int Draft_Year;
// string Phase (to be added)
public:
NFL_Players(string Name, string Team, string Division, string Position, string College, string Position_Group, string Broader_Position_Group, int Draft_Year):Name(Name), Team(Team), Division(Division), 
Position(Position), College(College), Position_Group(Position_Group), Broader_Position_Group(Broader_Position_Group), Draft_Year(Draft_Year){
    std::cout << "PLAYER BIO " << "\n";
    std::cout << "NAME: " << Name << "\n";
    std::cout << "TEAM: " << Team << "\n";
    std::cout << "TEAM DIVISION: " << Division << "\n";
    std::cout << "POSITION: " << Position << "\n";
    std::cout << "POSITION GROUP: " << Position_Group << "\n";
    std::cout << "SIDE OF THE BALL: " << Broader_Position_Group << "\n";
    std::cout << "COLLEGE: " << College << "\n";
    std::cout << "DRAFT YEAR: " << Draft_Year << "\n\n";
};

~NFL_Players(){};

static int Calculate_Player_Relationship_Score (NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes);
static void Relationship_Remarks(NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes);

// void Print_Player_Bio(NFL_Players&Player_Details){
//}

};

string Search_Division(string Team_Name);

NFL_Players Generate_Player();

string Search_PositionGroup(string Position);

string Search_Broader_Position_Group (string Position_Group);

