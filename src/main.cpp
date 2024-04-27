#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"
#include "jewelBug.h"

using namespace std;

enum class Direction{
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

string dirString(Direction dir) {
    switch (dir) {
        case Direction::North:
            return "North";
        case Direction::East:
            return "East";
        case Direction::South:
            return "South";
        case Direction::West:
            return "West";
        default:
            return "Unknown";
    }
}

void headings(){
    //Headings
    printf("%-5s %-6s %s %12s %10s %7s\n",
           "Type", "ID", "Position", "Direction", "Size", "Alive");
}

// Function to display Bug information
void display(const bug& bug) {
    // Print bug information
    printf("%-5c %-6d (%-2d,%-2d)     %-15s %-7d %-7s\n",
           bug.getType(), bug.getId(), bug.getPosition().first, bug.getPosition().second,
           dirString(static_cast<Direction>(static_cast<int>(bug.getDir()))).c_str(), bug.getSize(), bug.isAlive() ? "true" : "false");
}

bug* board::findBugByID(const vector<bug*> & vect) {
    int findID;
    bool ifBugFound = false;

    cout << "Input an ID of bug to find" << endl;
    cin >> findID;
    for (const bug* bug : vect)
    {
        if(bug->getId() == findID)
        {
            cout << "Bug Found" << endl;
            headings();
            display(*bug);

            ifBugFound = true;
            break;
        }
        else
        {
            cout << "No Bug Found!" << endl;
        }
    }
}

int main() {

    std::cout << R"(
______                   _     _  __       _____   ___   _____
| ___ \                 | |   (_)/ _|     /  __ \ / _ \ / __  \
| |_/ /_   _  __ _ ___  | |    _| |_ ___  | /  \// /_\ \`' / /'
| ___ \ | | |/ _` / __| | |   | |  _/ _ \ | |    |  _  |  / /
| |_/ / |_| | (_| \__ \ | |___| | ||  __/ | \__/\| | | |./ /___
\____/ \__,_|\__, |___/ \_____/_|_| \___|  \____/\_| |_/\_____/
              __/ |
             |___/
)" << '\n';

        vector<bug*> vect;
        board bugBoard;

        ifstream file("bugs.txt");

        if(!file.is_open()){
            cout << "Cant Open File" << endl;
            return 1;
        }

        string line;
        while(getline(file, line)){
            stringstream ss(line);
            vector<string> tokens;
            string token;
            while(getline(ss, token, ';')){
                tokens.push_back(token);
            }

            try{
                char type = tokens[0][0];
                int id = stoi(tokens[1]);
                int x = stoi(tokens[2]);
                int y = stoi(tokens[3]);
                int dir = stoi(tokens[4]);
                int size = stoi(tokens[5]);

                bug* bug = nullptr;
                if(type == 'C'){
                    bug = new crawler(type, id, x, y, dir, size);
                }
                else if (type == 'H'){
                    int hopLength = stoi(tokens[6]);
                    bug = new hopper(type, id, x, y, dir, size, hopLength);
                }
                else if(type == 'J'){
                    int hopLength = stoi(tokens[6]);
                    bug = new jewelBug(type, id, x, y, dir, size, hopLength);
                }
                else{
                    cout << "Error reading types" << endl;
                }

                if(bug){
                    vect.push_back(bug);
                    bugBoard.addBugToBoard(*bug); // create this method
                }
            }
            catch (const invalid_argument& e){
                cerr << "invalid input: " << e.what() << endl;
            }
        }
        file.close();

        //User display Menu

        int userCommand;
        bool runProgramme = true;
    while(runProgramme)
    {
        cout << "*******Menu********" << endl;
        cout << "Choose a command you want!" << endl;
        cout << "1. Initialize Bug Board" << endl;
        cout << "2. Display All Bugs" << endl;
        cout << "3. Find a Bug" << endl;
        cout << "4. Tap the Bug Board" << endl;
        cout << "5. Display Life History of All Bugs" << endl;
        cout << "6. Display All Cells Listing Their Bugs" << endl;
        cout << "7. Run Simulation" << endl;
        cout << "8. Exit" << endl;
        cin >> userCommand; // Get user's choice

        for(const auto& bug: vect){
            bugBoard.addBugToBoard(*bug); //create method
        }

        switch (userCommand) {
            case 1:
                cout << "Bug Board Initialized!\n" << endl;
                bugBoard.displayBoard();
                break;
            case 2:
                headings();
                for (bug* bug : vect) {
                    display(*bug);
                }
                cout << "\n" << endl;
                break;
            case 3:
                bugBoard.findBugByID(vect);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                runProgramme = false;
                break;
            default:
                cerr << "Invalid Option" << endl;
                break;
        }
    }
    return 0;
}

