#include <iostream>
#include <string>

class Player {
private:
    int jersey_number;
    int num_goals; // You might want to use this later
    std::string club;
    std::string name;
    std::string nationality;

public:
    void SetPlayerBio() {
        std::cout << "\nEnter player name, club, number and nationality in order: " << "\n";
        //std::cin.ignore(); // ignore any previous newline characters
        std::getline(std::cin, name);
        std::getline(std::cin, club);
        std::cin >> jersey_number;
        std::cin.ignore(); // ignore newline character after reading integer
        std::getline(std::cin, nationality);
    }

    void ChemistryCheck(Player PlayerA, Player PlayerB) {
        if (PlayerA.club == PlayerB.club && PlayerA.nationality == PlayerB.nationality) {
            std::cout << "Max (3 star) Chemistry";
        } else if (PlayerA.nationality == PlayerB.nationality || PlayerA.club == PlayerB.club) {
            std::cout << "2 star Chemistry";
        } else {
            std::cout << "0 Star Chemistry";
        }
    }
};

int main() {
    Player Player1;
    Player1.SetPlayerBio();

    Player Player2;
    Player2.SetPlayerBio();

    Player PlayerComparisonTool;
    PlayerComparisonTool.ChemistryCheck(Player1, Player2);

    return 0;
}
