#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getComputerChoice() {
    int choice = rand() % 3; // 0 = rock, 1 = paper, 2 = scissors
    if (choice == 0) return "rock";
    else if (choice == 1) return "paper";
    else return "scissors";
}

string determineWinner(string user, string computer) {
    if (user == computer)
        return "It's a tie!";
    else if ((user == "rock" && computer == "scissors") ||
             (user == "paper" && computer == "rock") ||
             (user == "scissors" && computer == "paper"))
        return "You win!";
    else
        return "Computer wins!";
}

int main() {
    srand(time(0)); // Seed for randomness

    string userChoice;
    while (true) {
        cout << "\nEnter rock, paper, or scissors (or 'quit' to stop): ";
        cin >> userChoice;

        if (userChoice == "quit") {
            cout << "Thanks for playing!\n";
            break;
        }

        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;
        cout << determineWinner(userChoice, computerChoice) << endl;
    }

    return 0;
}