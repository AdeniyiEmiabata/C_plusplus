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

class NFL_Players{


string Name;
string Team;
string Division;
string Position;
string College;
int Years_of_Exp;
// string Phase (to be added)
public:
NFL_Players(string Name, string Team, string Division, string Position, string College, int Years_of_Exp):Name(Name), Team(Team), Division(Division), 
Position(Position), College(College), Years_of_Exp(Years_of_Exp){};

~NFL_Players(){};

int Calculate_Player_Relationship_Score (NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes);
void Relationship_Remarks(NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes);
};

string Search_Division(string Team_Name);

NFL_Players Generate_Player();



