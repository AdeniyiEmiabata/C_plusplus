#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "NFL_Players.hpp"

using namespace std;

set<string> AFC_East = {"AFC_East","Buffalo Bills", "New York Jets", "New England Patriots", "Miami Dolphins"};
set<string> AFC_West = {"AFC_West","Kansas City Chiefs", "Las Vegas Raiders", "Denver Broncos", "Los Angeles Chargers"};
set<string> AFC_North = {"AFC_North","Baltimore Ravens", "Pittsburgh Steelers", "Cincinnati Bengals", "Cleveland Browns"};
set<string> AFC_South = {"AFC_South","Jacksonville Jaguars", "Tennessee Titans", "Indianapolis Colts", "Houston Texans"};

set<string> NFC_East = {"NFC_East","Washington Commanders", "Dallas Cowboys", "Philadelphia Eagles", "New York Giants"};
set<string> NFC_West = {"NFC_West","Seattle Seahwaks", "San Francisco 49ers", "Arizona Cardinals", "Los Angeles Rams"};
set<string> NFC_North = {"NFC_North","Green Bay Packers", "Minnesota Vikings", "Chicago Bears", "Detroit Lions"};
set<string> NFC_South = {"NFC_South","Tampa Bay Buccaneers", "New Orleans Saints", "Carolina Panthers", "Atlanta Falcons"};

// List of Positions (Sides of the Ball)
set<string> Defense = {"DT", "DE", "CB", "OLB", "MLB", "FS", "SS", "Defense"};
set<string> Offense = {"QB", "LT", "C", "RT", "LG", "RG", "TE", "FB", "WR", "RB", "Offense"};

// Position Groups
set<string> Offensive_Line = {"LT", "C", "RT", "LG", "RG", "Offensive Line"};
set<string> Receivers = {"WR", "TE", "Receiver"};
set<string> Running_Backs = {"FB", "RB", "Running Back"}; 

set<string> Defensive_Line = {"DT", "DE", "Defensive Line"};
set<string> Secondary = {"CB", "FS", "SS", "Secondary"};
set<string> Linebackers = {"MLB", "OLB", "Linebacker"};

vector<set<string>> All_Divisions;
vector<set<string>> Offensive_Position_Groups;
vector<set<string>> Defensive_Position_Groups;


int NFL_Players::Calculate_Player_Relationship_Score (NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes){
    int Score = 0;
    
    if(PlayerA_Attributes.Team == PlayerB_Attributes.Team){
        Score += 80;
        if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
            Score += 10;
            if (PlayerA_Attributes.Draft_Year == PlayerB_Attributes.Draft_Year){
                Score += 5;
            }
        }
        if (PlayerA_Attributes.College == PlayerB_Attributes.College){
            Score += 5;
        }
    }

    else if (PlayerA_Attributes.Division == PlayerB_Attributes.Division){
        Score += 50;
        if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
            Score += 10;
            if (PlayerA_Attributes.Draft_Year == PlayerB_Attributes.Draft_Year){
                Score += 5;
            }
        }
        if (PlayerA_Attributes.College == PlayerB_Attributes.College){
            Score += 5;
        }
    }

    else if(PlayerA_Attributes.College == PlayerB_Attributes.College){
        Score+= 40;
        if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
            Score += 10;
            if (abs(PlayerA_Attributes.Draft_Year - PlayerB_Attributes.Draft_Year) < 2){
                Score += 10;
            }
        }
    }

    else if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
        Score += 30;
        if (PlayerA_Attributes.Draft_Year == PlayerB_Attributes.Draft_Year){
                Score += 10;
            }
    }

    else if(PlayerA_Attributes.Draft_Year == PlayerB_Attributes.Draft_Year){
        Score += 20;
    }

    return Score;


}

void NFL_Players::Relationship_Remarks(NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes){

    int Relationship_Score = Calculate_Player_Relationship_Score(PlayerA_Attributes, PlayerB_Attributes);

    if (Relationship_Score >= 20 && Relationship_Score < 45){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a low chemistry score of " << Relationship_Score << "\n";
        cout << "We do not recommend having these players in the same team. Refresh the pool for better options!" << "\n";
        cout << "Low relationship scores affect player performance!" << "\n";
        return;
    }

    else if (Relationship_Score >= 45 && Relationship_Score < 65){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a below average chemistry score of " << Relationship_Score << "\n";
        cout << "These players are compatible. Reinforce your team with other players with higher relationship scores" << "\n";
        cout << "Low relationship scores affect player performance!" << "\n";
        return;
    }

    else if (Relationship_Score >= 65 && Relationship_Score < 75){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an average chemistry score of " << Relationship_Score << "\n";
        cout << "These players are mildly compatible. Reinforce your team with other players with higher relationship scores" << "\n";
        return;
    }

    else if (Relationship_Score >= 75 && Relationship_Score < 85){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a good chemistry score of " << Relationship_Score << "\n";
        cout << "These players are very compatible. Reinforce your team with more players with good relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
        return;
    }

    else if (Relationship_Score >= 85 && Relationship_Score < 100){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a great chemistry score of " << Relationship_Score << "\n";
        cout << "These players will gel very well. Search the player pool for more players with similar relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
        return;
    }

    else if(Relationship_Score == 100){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an excellent chemistry score of " << Relationship_Score << "\n";
        cout << "Excellent selections! Search the player pool for more players with similar relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
        return;
    }

    cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an extremely low chemistry score of " << Relationship_Score << "\n";
    cout << "Avoid putting these players in the same lineup!" << "\n";
    cout << "Low relationship scores improve player performance" << "\n";
    return;
}

NFL_Players Generate_Player(){
    string Name;
    string Team;
    string Division;
    string Position;
    string College;
    int Draft_Year;

    cout << "\n\n------Hit Enter to Start!-------";

    //to ensure the last cin>> for Draft_Year does not affect the first getline for the 2nd player getline(cin, Name): Needs Fixing
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "\nNOTE: Be mindful of letter casing when entering details!" << "\n";

    cout << "\n\nInput Player Name: " << "\n";
    getline(cin, Name);

    cout << "\n\nInput Player Team: " << "\n";
    getline(cin, Team);

    cout << "\n\nInput Player Position: " << "\n";
    getline(cin, Position);

    cout << "\n\nInput Player College: " << "\n";
    getline(cin, College);

    cout << "\n\nInput Player's Draft Year: " << "\n";
    cin >> Draft_Year;

    cout << "\n\n";
    Division = Search_Division(Team);
    NFL_Players Player_Details(Name, Team, Division, Position, College, Draft_Year);
    return Player_Details;

}

string Search_Division(string Team_Name){

    All_Divisions.push_back(AFC_East);
    All_Divisions.push_back(AFC_West);
    All_Divisions.push_back(AFC_North);
    All_Divisions.push_back(AFC_South);
    All_Divisions.push_back(NFC_East);
    All_Divisions.push_back(NFC_West);
    All_Divisions.push_back(NFC_North);
    All_Divisions.push_back(NFC_South);
    
    string Division;

    for(vector<set<string>>::iterator Iter = All_Divisions.begin(); Iter != All_Divisions.end(); Iter++){
        if((*Iter).contains(Team_Name)){
            Division = *((*Iter).begin());
            return Division;
        }       
    }

    Division = "Team Not Found! Restart and Check your spelling and/or letter casing\n\n";
    return Division;

}