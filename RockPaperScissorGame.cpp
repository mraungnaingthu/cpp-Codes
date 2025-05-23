//
// Created by Aung Naing Thu on 5/21/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class RockPaperScissorGame
{
    private:
        int playerChoice;  // 1: Rock, 2: Paper, 3: Scissor
        int computerChoice;

    public:
        RockPaperScissorGame()
        {
            playerChoice = 0;
            computerChoice = 0;
            srand(time(0)); // Seed for random number generation
        }

        void setPlayerChoice(int choice)
        {
            playerChoice = choice;
        }

        void generateComputerChoice()
        {
            computerChoice = (rand() % 3) + 1; // Random number between 1 and 3
        }

        void determineWinner()
        {
            cout << "Computer chose: " << convertChoiceToString(computerChoice) << endl;

            if (playerChoice == computerChoice)
            {
                cout << "It's a draw!" << endl;
            }
            else if ((playerChoice == 1 && computerChoice == 3) ||
                     (playerChoice == 2 && computerChoice == 1) ||
                     (playerChoice == 3 && computerChoice == 2))
            {
                cout << "You win!" << endl;
            }
            else
            {
                cout << "Computer wins!" << endl;
            }
        }

        string convertChoiceToString(int choice)
        {
            switch (choice)
            {
                case 1: return "Rock";
                case 2: return "Paper";
                case 3: return "Scissors";
                default: return "Invalid";
            }
        }
};

int main()
{
    cout << "Welcome to the Rock Paper Scissors Game!\n";
    cout << "Choose an option:\n1. Rock\n2. Paper\n3. Scissors >>> ";

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 3)
    {
        cout << "Invalid choice! Please choose between 1 and 3.\n";
        return 1;
    }

    RockPaperScissorGame rps;
    rps.setPlayerChoice(choice);
    rps.generateComputerChoice();
    rps.determineWinner();

    return 0;
}
