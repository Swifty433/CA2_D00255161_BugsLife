#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"

using namespace std;

enum class Direction{
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

int main() {
    while(true)
    {
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
                    bug = new hopper(type, id, x, y, dir, size);
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
                break;
            case 2:
                break;
            case 3:
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
                return 0;
            default:
                cerr << "Invalid Option" << endl;
                break;
        }
        return 0;
    }
}

