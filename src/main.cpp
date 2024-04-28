#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"
#include "jewelBug.h"
#include <SFML/Graphics.hpp>
#include <thread>

using namespace std;

//enum class
enum class Direction{
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

//Direction to string method
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

//Headings method
void headings(){
    //Headings
    printf("********************************************************\n");
    printf("%-5s %-6s %s %12s %10s %7s\n",
           "Type", "ID", "Position", "Direction", "Size", "Alive");
    printf("********************************************************\n");
}

// Function to display Bug information
void display(const bug& bug) {
    // Print bug information
    printf("%-5c %-6d (%-2d,%-2d)     %-15s %-7d %-7s\n",
           bug.getType(), bug.getId(), bug.getPosition().first, bug.getPosition().second,
           dirString(static_cast<Direction>(static_cast<int>(bug.getDir()))).c_str(), bug.getSize(), bug.isAlive() ? "true" : "false");
}

//method to find a bug by specific ID
bug* board::findBugByID(const vector<bug*> & vect) {
    int findID;

    //prompt user for an id
    cout << "Input an ID of bug to find" << endl;
    cin >> findID;
    //loops throught he vector of bugs to find the bug with ID
    for (const bug* bug : vect)
    {
        //checks if they match
        if(bug->getId() == findID)
        {
            //if found prints a message and displays details
            cout << "Bug Found" << endl;
            headings();
            display(*bug);
            break;
        }
    }
    // If bug is not found, print a message
    if(!findID)
    {
        cout << "No Bug Found!" << endl;
    }
    return nullptr;
}

//Shows the path that the bug travelled over its life.
void showLifeHistory(const vector<bug*> & vect){

    //iterate through bug vector
    for (const auto &bug: vect) {
        //then print bugs id and start of path
        cout << "Bug ID: " << bug->getId() << " - Path: ";
        //checking if bug is alive
        if (bug->isAlive()) {
            //gets bugs path
            const auto &path = bug->getPath();
            //check if the bug has made any moves
            if (!path.empty()) {
                auto it = path.begin();
                cout << "(" << it->first << "," << it->second << ")";
                ++it;
                //prints intial position
                for (; it != path.end(); ++it) {
                    cout << " -> (" << it->first << "," << it->second << ")";
                }
            } else {
                //and if no moves are made yet print mesage
                cout << "No moves made yet.";
            }
        } else {
            //bug dead message
            cout << "Bug is Dead";
        }
        cout << endl;
    }
}

//method to write the path bugs took to a file called "bugs_life_history_date_time.out"
void writeBugHistoryToFile(const vector<bug*> vect, const string& filename){
    //setting up file name
    ofstream outputFile(filename);

    //if file fails to open
    if (!outputFile.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    // Write bug history to the file
    for (const auto& bug : vect) {
        outputFile << "Bug ID: " << bug->getId() << " Path: ";

        //getting the path of the bug
        const auto& path = bug->getPath();
        //boolean for if the bug hasnt moved yet
        bool isStart = true;

        // writing the moves made by the bug
        for (const auto& point : path) {
            //if the bug haas moved then it will show the location with a forward arrow to its next position
            if (!isStart) {
                outputFile << " -> ";
            }
            outputFile << "(" << point.first << "," << point.second << ")";
            isStart = false;
        }

        // shows if the bug is dead in the file and when it died
        if (!bug->isAlive()) {
            outputFile << " - Bug is Dead";
        }

        outputFile << endl;
    }

    //closes the file
    outputFile.close();
}

//Method to set up the sfml window to play the game in a pop out window
void sfmlWindow(board& board,vector<bug*>& vect){

    //rendering a window that is 480x480
    sf::RenderWindow window(sf::VideoMode(480, 480), "CA2 BugsLife Project");
    // Load images for bugs
    sf::Texture hopperTexture;
    if (!hopperTexture.loadFromFile("Hopper.png")) {
        cout << "No image found" << endl;
    }
    sf::Texture crawlerTexture;
    if (!crawlerTexture.loadFromFile("Crawler.png")) {
        cout << "No image found" << endl;
    }
    sf::Texture jewelTexture;
    if (!jewelTexture.loadFromFile("Jewel.png")) {
        cout << "No image found" << endl;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //ability to close popup window
            if (event.type == sf::Event::Closed)
                window.close();

            //setting up the button press events
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
            {
                //checking if button is pressed
                if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Mouse::Left)
                {
                    if(!board.gameOver(vect))
                    {
                        // Move all bugs
                        board.tap(vect);
                        board.fightPhase(vect);
                    }
                    else if (board.gameOver(vect))
                    {
                        //when all bugs dead game over and closes window
                        window.close();
                        cout << "Game over! Play Again?" << endl;
                        //then write to a file with statistics
                        writeBugHistoryToFile(vect, "bugs_life_history_date_time.out");
                    }
                }
            }
        }
        //clearing the window
        window.clear();
        //drawing the window
        board.draw(window, vect,hopperTexture,crawlerTexture,jewelTexture);
        //displaying window
        window.display();
    }
}

//Main Menu for app containing reading from a file as well as the cases.
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

        //vector of bugs
        vector<bug*> vect;
        board bugBoard;

        ifstream file("bugs.txt");

        //checking if the file can be opened
        if(!file.is_open()){
            //if it cant be opened print message
            cout << "Cant Open File" << endl;
            return 1;
        }

        //string to store each line read from file
        string line;
        //reading each file
        while(getline(file, line)){
            //string stram to parse the line into tokens
            stringstream ss(line);
            //vecter to store the tokens from each line
            vector<string> tokens;
            //strimg to store each token
            string token;

            //extract token form stringstream
            while(getline(ss, token, ';')){
                tokens.push_back(token);
            }

            try{
                // get bug properties
                char type = tokens[0][0];
                int id = stoi(tokens[1]);
                int x = stoi(tokens[2]);
                int y = stoi(tokens[3]);
                int dir = stoi(tokens[4]);
                int size = stoi(tokens[5]);

                //pointer to a bug object
                bug* bug = nullptr;
                //check the type of bug and create an objedct for it
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

                //if bug object is created succesfully
                if(bug){
                    //add the bug object to the vector of bugs
                    vect.push_back(bug);
                    //add the bug to the board
                    bugBoard.addBugToBoard(*bug); // create this method
                }
            }
            catch (const invalid_argument& e){
                cerr << "invalid input: " << e.what() << endl;
            }
        }
        //close file after reading from it
        file.close();

        //display Menu
        int userCommand;
        bool runProgramme = true;
        bool bugBoardInitialized = false;
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
        cout << "8. RUN SFML POP UP WINDOW!" << endl;
        cout << "9. Exit" << endl;
        cin >> userCommand; // Get user's choice

        for(const auto& bug: vect){
            bugBoard.addBugToBoard(*bug); //create method
        }

        //ensure board is initialized before any other commands are ran
        if (!bugBoardInitialized && userCommand != 1) {
            cout << "Must initialize the bug board first!" << endl;
            continue;
        }

        //switch cases for commands
        switch (userCommand) {
            case 1:
                cout << "Bug Board Initialized!\n" << endl;
                bugBoard.displayBoard();
                bugBoardInitialized = true;
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
                for(bug* bug : vect){
                    if(bug->isAlive()){
                        bug->move();
                    }
                }
                bugBoard.fightPhase(vect);
                break;
            case 5:
                showLifeHistory(vect);
                break;
            case 6:
                bugBoard.showAllCells(vect);
                break;
            case 7:
                //link to resource used for case 7: https://stackoverflow.com/questions/50136540/calling-a-function-every-1-second-precisely
                while (!bugBoard.gameOver(vect)) {
                    // Move all bugs
                    bugBoard.tap(vect);
                    bugBoard.fightPhase(vect);

                    // Sleep for 1 second before the next iteration
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                // Game over: Write bug history to file
                writeBugHistoryToFile(vect, "bugs_life_history_date_time.out");
                break;
            case 8:
                cout<<"Opening SFML Window! Enjoy!" << endl;
                sfmlWindow(bugBoard, vect);
                break;
            case 9:
                writeBugHistoryToFile(vect,"bugs_life_history_date_time.out");
                runProgramme = false;
                break;
            default:
                cerr << "Invalid Option" << endl;
                break;
        }
    }
    return 0;
}

