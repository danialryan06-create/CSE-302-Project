#include <iostream>
#include <fstream>
#include <sstream>
#include "ASListR.h"
using namespace std;

int main() {
    ASListR list;
    ifstream file("mlb_2015_modified.csv");

    if (!file.is_open()) {
        cout << "Error opening CSV file.\n";
        return 1;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string teamID, Wstr, AStr;

        getline(ss, teamID, ',');
        getline(ss, Wstr, ',');
        getline(ss, AStr, ',');

        Team t;
        t.teamID = teamID;
        t.W = stoi(Wstr);
        t.attendance = stoi(AStr);

        list.insert(t);
    }

    cout << "Sorted MLB Team Data (by Wins, descending):\n\n";
    list.printAll();

    cout << "\nEnter minimum wins: ";
    int inputWins;
    cin >> inputWins;

    cout << "Teams with wins >= " << inputWins << ":\n";
    list.printGreaterThan(inputWins);

    return 0;
}
