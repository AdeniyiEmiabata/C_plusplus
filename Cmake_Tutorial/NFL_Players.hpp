#include <iostream>
#include <string>
#include <set>

using namespace std;

// List of Divisions
// used extern because these are defined in NFL_Players.cpp
extern set<string> AFC_East;
extern set<string> AFC_West;
extern set<string> AFC_North;
extern set<string> AFC_South;

extern set<string> NFC_East;
extern set<string> NFC_West;
extern set<string> NFC_North;
extern set<string> NFC_South;

// List of Positions (Sides of the Ball)
extern set<string> Defense;
extern set<string> Offense;

// List of Position Groups
extern set<string> Offensive_Line;
extern set<string> Receivers;
extern set<string> Running_Backs;

extern set<string> Defensive_Line;
extern set<string> Secondary;
extern set<string> Linebackers;

class NFL_Players{


string Name;
string Team;
string Division;
string Position;
string College;
int Draft_Year;
// string Phase (to be added)
public:
NFL_Players(string Name, string Team, string Division, string Position, string College, int Draft_Year):Name(Name), Team(Team), Division(Division), 
Position(Position), College(College), Draft_Year(Draft_Year){};

~NFL_Players(){};

int Calculate_Player_Relationship_Score (NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes);
void Relationship_Remarks(NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes);
};

string Search_Division(string Team_Name);

NFL_Players Generate_Player();

string Search_PositionGroup(string Position);



