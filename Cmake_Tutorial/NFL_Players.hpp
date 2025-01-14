#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> AFC_East = {"AFC_East","Buffalo Bills", "New York Jets", "New England Patriots", "Miami Dolphins"};
set<string> AFC_West = {"AFC_West","Kansas City Chiefs", "Las Vegas Raiders", "Denver Broncos", "Los Angeles Chargers"};
set<string> AFC_North = {"AFC_North","Baltimore Ravens", "Pittsburgh Steelers", "Cincinnati Bengals", "Cleveland Browns"};
set<string> AFC_South = {"AFC_South","Jacksonville Jaguars", "Tennessee Titans", "Indianapolis Colts", "Houston Texans"};

set<string> NFC_East = {"NFC_East","Washington Commanders", "Dallas Cowboys", "Philadelphia Eagles", "New York Giants"};
set<string> NFC_West = {"NFC_West","Seattle Seahwaks", "San Francisco 49ers", "Arizona Cardinals", "Los Angeles Rams"};
set<string> NFC_North = {"NFC_North","Green Bay Packers", "Minnesota Vikings", "Chicago Bears", "Detroit Lions"};
set<string> NFC_South = {"NFC_South","Tampa Bay Buccaneers", "New Orleans Saints", "Carolina Panthers", "Atlanta Falcons"};


class NFL_Players{


string Name;
string Team;
string Division;
string Position;
string College;
int Years_of_Exp;

public:
NFL_Players(string Name, string Team, string Division, string Position, string College, int Years_of_Exp):Name(Name), Team(Team), Division(Division), 
Position(Position), College(College), Years_of_Exp(Years_of_Exp){};

~NFL_Players(){}

int Calculate_Player_Relationship_Score (NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes){
    int Score = 0;
    
    if(PlayerA_Attributes.Team == PlayerB_Attributes.Team){
        Score += 80;
        if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
            Score += 10;
            if (PlayerA_Attributes.Years_of_Exp == PlayerB_Attributes.Years_of_Exp){
                Score += 5;
            }
        }
        if (PlayerA_Attributes.College == PlayerB_Attributes.College){
            Score += 5;
        }
    }

    if (PlayerA_Attributes.Division == PlayerB_Attributes.Division){
        Score += 50;
        if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
            Score += 10;
            if (PlayerA_Attributes.Years_of_Exp == PlayerB_Attributes.Years_of_Exp){
                Score += 5;
            }
        }
        if (PlayerA_Attributes.College == PlayerB_Attributes.College){
            Score += 5;
        }
    }

    if(PlayerA_Attributes.College == PlayerB_Attributes.College){
        Score+= 40;
        if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
            Score += 10;
            if (PlayerA_Attributes.Years_of_Exp == PlayerB_Attributes.Years_of_Exp){
                Score += 10;
            }
        }
    }

    if(PlayerA_Attributes.Position == PlayerB_Attributes.Position){
        Score += 30;
        if (PlayerA_Attributes.Years_of_Exp == PlayerB_Attributes.Years_of_Exp){
                Score += 10;
            }
    }

    if(PlayerA_Attributes.Years_of_Exp == PlayerB_Attributes.Years_of_Exp){
        Score += 20;
    }

    return Score;


};

void Relationship_Remarks(NFL_Players& PlayerA_Attributes, NFL_Players& PlayerB_Attributes){

    int Relationship_Score = Calculate_Player_Relationship_Score(PlayerA_Attributes, PlayerB_Attributes);

    if (Relationship_Score > 20 && Relationship_Score < 45){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a low chemistry score of " << Relationship_Score << "\n";
        cout << "We do not recommend having these players in the same team. Refresh the pool for better options!" << "\n";
        cout << "Low relationship scores affect player performance!" << "\n";
    }

    else if (Relationship_Score > 45 && Relationship_Score < 65){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a below average chemistry score of " << Relationship_Score << "\n";
        cout << "These players are compatible. Reinforce your team with other players with higher relationship scores" << "\n";
        cout << "Low relationship scores affect player performance!" << "\n";
    }

    else if (Relationship_Score > 65 && Relationship_Score < 75){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an average chemistry score of " << Relationship_Score << "\n";
        cout << "These players are mildly compatible. Reinforce your team with other players with higher relationship scores" << "\n";
    }

    else if (Relationship_Score > 75 && Relationship_Score < 85){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a good chemistry score of " << Relationship_Score << "\n";
        cout << "These players are very compatible. Reinforce your team with other players with higher relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
    }

    else if (Relationship_Score > 85 && Relationship_Score < 100){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have a great chemistry score of " << Relationship_Score << "\n";
        cout << "These players will gel very well. Search the player pool for more players with similar relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
    }

    else if(Relationship_Score == 100){
        cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an excellent chemistry score of " << Relationship_Score << "\n";
        cout << "Excellent selections! Search the player pool for more players with similar relationship scores" << "\n";
        cout << "High relationship scores improve player performance" << "\n";
    }

    cout << PlayerA_Attributes.Name << " and " << PlayerB_Attributes.Name << " have an extremely low chemistry score of " << Relationship_Score << "\n";
        cout << "Avoid putting these players in the same lineup!" << "\n";
        cout << "Low relationship scores improve player performance" << "\n";

    return;
}
};

string Search_Division(string Team_Name){
    string Division;
    if(AFC_East.contains(Team_Name)){
        set<string>::iterator Iter = AFC_East.begin();
        Division = *Iter;
        return Division;
    }

    if(AFC_West.contains(Team_Name)){
        set<string>::iterator Iter = AFC_West.begin();
        Division = *Iter;
        return Division;
    }

    if(AFC_North.contains(Team_Name)){
        set<string>::iterator Iter = AFC_North.begin();
        Division = *Iter;
        return Division;
    }

    if(AFC_South.contains(Team_Name)){
        set<string>::iterator Iter = AFC_South.begin();
        Division = *Iter;
        return Division;
    }

    if(NFC_East.contains(Team_Name)){
        set<string>::iterator Iter = NFC_East.begin();
        Division = *Iter;
        return Division;
    }

    if(NFC_West.contains(Team_Name)){
        set<string>::iterator Iter = NFC_West.begin();
        Division = *Iter;
        return Division;
    }

    if(NFC_North.contains(Team_Name)){
        set<string>::iterator Iter = NFC_North.begin();
        Division = *Iter;
        return Division;
    }

    if(NFC_South.contains(Team_Name)){
        set<string>::iterator Iter = NFC_South.begin();
        Division = *Iter;
        return Division;
    }

    Division = "Team Not Found! Check your spelling and/or letter casing";
    return Division;

}

NFL_Players Generate_Player(){
    string Name;
    string Team;
    string Division;
    string Position;
    string College;
    int Years_of_Exp;

    cout << "Be mindful of letter casing when entering details!" << "\n";

   
    cout << "Input Player Name: " << "\n";
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    getline(cin, Name);

    cout << "Input Player Team: " << "\n";
    getline(cin, Team);

    cout << "Input Player Position: " << "\n";
    getline(cin, Position);

    cout << "Input Player College: " << "\n";
    getline(cin, College);

    cout << "Input Player's Years of Experience: " << "\n";
    cin >> Years_of_Exp;

    Division = Search_Division(Team);
    NFL_Players Player_Details(Name, Team, Division, Position, College, Years_of_Exp);
    return Player_Details;

}



