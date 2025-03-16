#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "NFL_Players.hpp"

using namespace std;

vector<string> AFC_East = {"AFC East","Buffalo Bills", "New York Jets", "New England Patriots", "Miami Dolphins"};
vector<string> AFC_West = {"AFC West","Kansas City Chiefs", "Las Vegas Raiders", "Denver Broncos", "Los Angeles Chargers"};
vector<string> AFC_North = {"AFC North","Baltimore Ravens", "Pittsburgh Steelers", "Cincinnati Bengals", "Cleveland Browns"};
vector<string> AFC_South = {"AFC South","Jacksonville Jaguars", "Tennessee Titans", "Indianapolis Colts", "Houston Texans"};

vector<string> NFC_East = {"NFC East","Washington Commanders", "Dallas Cowboys", "Philadelphia Eagles", "New York Giants"};
vector<string> NFC_West = {"NFC West","Seattle Seahwaks", "San Francisco 49ers", "Arizona Cardinals", "Los Angeles Rams"};
vector<string> NFC_North = {"NFC North","Green Bay Packers", "Minnesota Vikings", "Chicago Bears", "Detroit Lions"};
vector<string> NFC_South = {"NFC South","Tampa Bay Buccaneers", "New Orleans Saints", "Carolina Panthers", "Atlanta Falcons"};

// List of Positions (Sides of the Ball)
vector<string> Defense = {"Defensive Linemen", "Defensive Backs", "Linebackers"};
vector<string> Offense = {"Offensive Linemen", "Receivers", "Running Backs", "Quarterback"};

// Position Groups
vector<string> Offensive_Line = {"LT", "C", "RT", "LG", "RG", "Offensive Linemen"};
vector<string> Receivers = {"WR", "TE", "Receivers"};
vector<string> Running_Backs = {"FB", "RB", "Running Backs"}; 
vector<string> Quarterback = {"QB", "Quarterback"};

vector<string> Defensive_Line = {"DT", "DE", "Defensive Linemen"};
vector<string> Defensive_Backs = {"CB", "FS", "SS", "Defensive Backs"};
vector<string> Linebackers = {"MLB", "OLB", "Linebackers"};

vector<vector<string>> All_Divisions;
vector<vector<string>> Offensive_Position_Groups;
vector<vector<string>> Defensive_Position_Groups;


int NFL_Players::Calculate_Player_Relationship_Score (NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes){
    int Score = 0;
    
    // TEAM-FOCUSED: MAXIMUM 100
    if(PlayerA_Attributes.Team == PlayerB_Attributes.Team){
        Score += 80;

        if (PlayerA_Attributes.Broader_Position_Group == PlayerB_Attributes.Broader_Position_Group){
            Score += 10;
            if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group) {
                Score+= 7;
            }
        }

        if (PlayerA_Attributes.College == PlayerB_Attributes.College){
            Score += 3;
        }
        else if (abs(PlayerA_Attributes.Draft_Year - PlayerB_Attributes.Draft_Year) < 2){
            Score += 3;
        }
    }

    // DIVISION_FOCUSED: MAXIMUM 90
    else if (PlayerA_Attributes.Division == PlayerB_Attributes.Division){
        Score += 60;

        if (PlayerA_Attributes.Broader_Position_Group == PlayerB_Attributes.Broader_Position_Group){
            Score += 10;
            if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
                Score+= 5;
                if (PlayerA_Attributes.Position == PlayerB_Attributes.Position){
                    Score+= 7;
                }
            }
        }

        if (PlayerA_Attributes.College == PlayerB_Attributes.College){
            Score += 3;
            if(abs(PlayerA_Attributes.Draft_Year - PlayerB_Attributes.Draft_Year) < 2){
                Score += 5;
            }
        }

        else if(abs(PlayerA_Attributes.Draft_Year - PlayerB_Attributes.Draft_Year) < 2){
                Score += 3;
        }
    }

    // COLLEGE-FOCUSED: MAXIMUM 80
    else if(PlayerA_Attributes.College == PlayerB_Attributes.College){
        Score+= 50;

        if ((PlayerA_Attributes.Broader_Position_Group == PlayerB_Attributes.Broader_Position_Group)){
            Score += 5;
            if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
                Score+= 8;
                if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
                    Score += 12;
                }
            }
        }

        if (abs(PlayerA_Attributes.Draft_Year - PlayerB_Attributes.Draft_Year) < 2){
                Score += 5;
        }
        
    }

    //POSITION-GROUP FOCUSED: MAXIMUM 55
    else if(PlayerA_Attributes.Broader_Position_Group == PlayerB_Attributes.Broader_Position_Group){
        Score += 35;
        if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
                Score += 10;
                if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
                    Score += 15;
                }
            }

        if (abs(PlayerA_Attributes.Draft_Year - PlayerB_Attributes.Draft_Year) < 2){
                Score += 5;
            }
    }

    return Score;


}

void NFL_Players::Relationship_Remarks(NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes){

    int Relationship_Score = Calculate_Player_Relationship_Score(PlayerA_Attributes, PlayerB_Attributes);

    if (Relationship_Score >= 20 && Relationship_Score < 45){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a low chemistry score of " << Relationship_Score << "\n";
        if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
            std::cout << "These players may weaken your " << PlayerA_Attributes.Position_Group << " group and your overall " << PlayerA_Attributes.Broader_Position_Group << "\n";
        }
        cout << "We do not recommend having these players in the same team. Refresh the pool for better options!" << "\n";
        cout << "Low relationship scores affect player performance!" << "\n";

        if((PlayerA_Attributes.Position_Group == "Receivers" && PlayerB_Attributes.Position == "QB") || (PlayerB_Attributes.Position_Group == "Receivers" && PlayerA_Attributes.Position == "QB")){
            cout << "Your QB will struggle to be on the same page with your receiver! QB-Receiver chemistry is critical to a good offense\n";
        }

        if((PlayerA_Attributes.Position_Group == "Receivers" && PlayerB_Attributes.Position == "QB") || (PlayerB_Attributes.Position_Group == "Receivers" && PlayerA_Attributes.Position == "QB")){
            cout << "Your QB will struggle to be on the same page with your receiver! QB-Receiver chemistry is critical to a good offense\n";
        }

        return;
    }

    else if (Relationship_Score >= 45 && Relationship_Score < 65){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a below average chemistry score of " << Relationship_Score << "\n";
        if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
            std::cout << "These players may weaken your " << PlayerA_Attributes.Position_Group << " group and your overall " << PlayerA_Attributes.Broader_Position_Group << "\n";
        }
        cout << "These players are compatible. Reinforce your team with other players with higher relationship scores" << "\n";
        cout << "Low relationship scores affect player performance!" << "\n";

        if((PlayerA_Attributes.Position_Group == "Receivers" && PlayerB_Attributes.Position == "QB") || (PlayerB_Attributes.Position_Group == "Receivers" && PlayerA_Attributes.Position == "QB")){
            cout << "Your QB may struggle to be on the same page with your receiver! QB-Receiver chemistry is critical to a good offense\n";
        }

        return;
    }

    else if (Relationship_Score >= 65 && Relationship_Score < 75){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an average chemistry score of " << Relationship_Score << "\n";
        cout << "These players are mildly compatible. Reinforce your team with other players with higher relationship scores" << "\n";
        return;
    }

    else if (Relationship_Score >= 75 && Relationship_Score < 85){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a good chemistry score of " << Relationship_Score << "\n";
        if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
            std::cout << "These players will strengthen your " << PlayerA_Attributes.Position_Group << " room and your overall " << PlayerA_Attributes.Broader_Position_Group << "\n";
        }
        cout << "These players are very compatible. Reinforce your team with more players with good relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
        if((PlayerA_Attributes.Position_Group == "Receivers" && PlayerB_Attributes.Position == "QB") || (PlayerB_Attributes.Position_Group == "Receivers" && PlayerA_Attributes.Position == "QB")){
            cout << "Your QB will have no trouble building a good relationship with your receiver!\n";
        }
        return;
    }

    else if (Relationship_Score >= 85 && Relationship_Score < 100){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a great chemistry score of " << Relationship_Score << "\n";
        if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
            std::cout << "These players will strengthen your " << PlayerA_Attributes.Position_Group << " room and your overall " << PlayerA_Attributes.Broader_Position_Group << "\n";;
        }
        cout << "These players will gel very well. Search the player pool for more players with similar relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";

        if((PlayerA_Attributes.Position_Group == "Receivers" && PlayerB_Attributes.Position == "QB") || (PlayerB_Attributes.Position_Group == "Receivers" && PlayerA_Attributes.Position == "QB")){
            cout << "This QB-Receiver duo can be the foundation of your offense!\n";
        }
        return;
    }

    else if(Relationship_Score == 100){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an excellent chemistry score of " << Relationship_Score << "\n";
        if (PlayerA_Attributes.Position_Group == PlayerB_Attributes.Position_Group){
            std::cout << "These players will strengthen your " << PlayerA_Attributes.Position_Group << " room and your overall " << PlayerA_Attributes.Broader_Position_Group << "\n";;
        }
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
    string Position_Group;
    string Broader_Position_Group;
    int Draft_Year;

    cout << "\nWelcome to the NFL Player Comparison Tool: Compare players to help your team-building process\n\n" << "------Hit Enter to Start!-------";

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
    Position_Group = Search_PositionGroup(Position);
    Broader_Position_Group = Search_Broader_Position_Group (Position_Group);
    NFL_Players Player_Details(Name, Team, Division, Position, College, Position_Group, Broader_Position_Group, Draft_Year);
    //Print_Player_Bio(Player_Details);
    return Player_Details;

}

// void NFL_Players::Print_Player_Bio(NFL_Players&Player_Details){
//     std::cout << "PLAYER BIO " << "\n";
//     std::cout << "NAME: " << Player_Details.Name << "\n";
//     std::cout << "TEAM: " << Player_Details.Team << "\n";
//     std::cout << "TEAM DIVISION: " << Player_Details.Division << "\n";
//     std::cout << "POSITION: " << Player_Details.Position << "\n";
//     std::cout << "POSITION GROUP: " << Player_Details.Position_Group << "\n";
//     std::cout << "SIDE OF THE BALL: " << Player_Details.Broader_Position_Group << "\n";
//     std::cout << "COLLEGE: " << Player_Details.College << "\n";
//     std::cout << "DRAFT YEAR: " << Player_Details.Draft_Year << "\n\n";
// }

string Search_Division(string Team_Name){

    string Division;
    Division = "Team Not Found! Restart and Check your spelling and/or letter casing\n\n";
    All_Divisions.push_back(AFC_East);
    All_Divisions.push_back(NFC_East);
    All_Divisions.push_back(AFC_West);
    All_Divisions.push_back(NFC_West);
    All_Divisions.push_back(AFC_North);
    All_Divisions.push_back(NFC_North);
    All_Divisions.push_back(AFC_South);
    All_Divisions.push_back(NFC_South);

    for(vector<vector<string>>::iterator Iter = All_Divisions.begin(); Iter != All_Divisions.end(); Iter++){

       std::vector<string>::iterator Iter_Division =  std::find((*Iter).begin(), (*Iter).end(), Team_Name);

       if (Iter_Division != (*Iter).end()){
            Division = *((*Iter).begin());
            break;
       }

       //else{
            
        
       //}
        // if((*Iter).contains(Team_Name)){
        //     Division = *((*Iter).begin());
        //     return Division;
        // }       
    }

    return Division;
    

}

string Search_PositionGroup(string Position){

    string Position_Group = "Position group not found! Check spelling of position!";
    Offensive_Position_Groups.push_back(Offensive_Line);
    Offensive_Position_Groups.push_back(Receivers);
    Offensive_Position_Groups.push_back(Running_Backs);
    Offensive_Position_Groups.push_back(Quarterback);

    Defensive_Position_Groups.push_back(Defensive_Line);
    Defensive_Position_Groups.push_back(Defensive_Backs);
    Defensive_Position_Groups.push_back(Linebackers);

    for(vector<vector<string>>::iterator Iter = Offensive_Position_Groups.begin(); Iter != Offensive_Position_Groups.end(); Iter++){
        std::vector<string>::iterator Iter_Position_Group =  std::find((*Iter).begin(), (*Iter).end(), Position);
        if(Iter_Position_Group != (*Iter).end()){
            Position_Group = *((*Iter).end() - 1);
            break;
        }
        
        // if((*Iter).contains(Position)){
        //     Position_Group = *(prev((*Iter).end(), 1));
        //     std::cout << Position_Group << "\n";
        // }
    }

    for(vector<vector<string>>::iterator Iter = Defensive_Position_Groups.begin(); Iter != Defensive_Position_Groups.end(); Iter++){
        std::vector<string>::iterator Iter_Position_Group =  std::find((*Iter).begin(), (*Iter).end(), Position);
        if (Iter_Position_Group != (*Iter).end()){
            Position_Group = *((*Iter).end() - 1);
            break;
        }
        
        // if((*Iter).contains(Position)){
        //     Position_Group = *(std::prev((*Iter).end(),1));
        //     std::cout << Position_Group << "\n";
        // }
    }


    return Position_Group;
}

string Search_Broader_Position_Group (string Position_Group){
    
    string Broader_Position_Group = "Broader Position group not found! Please check spelling of Position!";
    vector<string>::iterator Offensive_Iter = std::find(Offense.begin(), Offense.end(), Position_Group);
    if (Offensive_Iter != Offense.end()){
        Broader_Position_Group = "Offense";
    }

    vector<string>::iterator Defensive_Iter = std::find(Defense.begin(), Defense.end(), Position_Group);
    if (Defensive_Iter != Defense.end()){
        Broader_Position_Group = "Defense";
    }

    return Broader_Position_Group;
}