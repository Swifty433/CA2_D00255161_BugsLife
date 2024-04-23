#include <iostream>
#include <vector>
#include "bug.cpp"

using namespace std;

enum class Direction{
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

string directionString(int directionInt) {
        if (directionInt = 1) {
            return "North";
        }
        else if(directionInt = 2){
            return "East";
        }
        else if(directionInt = 3){
            return "South";
        }
        else if(directionInt = 4){
            return "West";
        }
        else{
            return "Not a known direction";
        }
    }

int main() {
    vector<bug> bugs;

    int userCommand;

    //main menu goes here
    cout << "Hello" << endl;

}

