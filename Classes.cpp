#include <iostream>
#include <string>

class Player {
private:
    //int jersey_number;
    //int num_goals; // You might want to use this later
    std::string club;
    std::string name;
    std::string nationality;
    std::string league;

public:

    Player(){}
    ~Player(){}
    void SetPlayerBio() {
        std::cout << "\n\nName: " << "\n\n";
        std::getline(std::cin, name);

        std::cout << "\nClub: " << "\n\n";
        std::getline(std::cin, club);

        std::cout << "\nNationality: " << "\n\n";
        //std::cin.ignore(); // ignore newline character after reading integer
        std::getline(std::cin, nationality);

        std::cout << "\nLeague: " << "\n\n";
        std::getline(std::cin, league);
    }

    static void ChemistryCheck(Player* PlayerA, Player* PlayerB) {
        if (PlayerA->club == PlayerB->club && PlayerA->nationality == PlayerB->nationality) 
        {
            std::cout << "\nMax (3 star) Chemistry!\n\n";
        } 
        else if (PlayerA->nationality == PlayerB->nationality || PlayerA->club == PlayerB->club) 
        {
            std::cout << "\n2 star Chemistry!\n\n";
        } 
        else if (PlayerA->league == PlayerB->league)
        {
            std::cout << "\n1 Star Chemistry!\n\n";
        }
        else
        {
            std::cout << "0 star Chemistry!\n\n";
        }
    }
};

int main() {
    Player* Player1 = new Player;
    Player* Player2 = new Player;

    Player1->SetPlayerBio();
    Player2->SetPlayerBio();

    Player::ChemistryCheck(Player1, Player2);

    return 0;
}
