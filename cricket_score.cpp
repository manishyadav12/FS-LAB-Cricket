#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void addPlayerScore()
{
    ofstream file("scores.txt", ios::app);
    if (!file)
    {
        cout << "\033[1;31mError opening file!\033[0m" << endl;
        return;
    }

    string playerName;
    int jerseyNumber;
    int score;

    cout << "\033[1;36m\n----------------------------------------------\033[0m" << endl;
    cout << "\033[1;36m               ADD PLAYER'S SCORE              \033[0m" << endl;
    cout << "\033[1;36m----------------------------------------------\033[0m" << endl;

    cout << "\033[1;33mEnter player name: \033[0m";
    getline(cin >> ws, playerName);
    cout << "\033[1;33mEnter jersey number: \033[0m";
    cin >> jerseyNumber;
    cout << "\033[1;33mEnter score: \033[0m";
    cin >> score;

    string line;
    bool playerExists = false;

    // Check if player with same jersey number already exists
    ifstream existingFile("scores.txt");
    while (getline(existingFile, line))
    {
        string existingPlayerName, existingScore;
        int existingJerseyNumber;

        stringstream ss(line);
        getline(ss, existingPlayerName, ',');
        getline(ss, existingScore, ',');
        existingJerseyNumber = stoi(existingScore);

        if (existingJerseyNumber == jerseyNumber)
        {
            cout << "\033[1;31mPlayer with the same jersey number already exists: " << existingPlayerName << "\033[0m" << endl;
            playerExists = true;
            break;
        }
    }

    existingFile.close();

    if (!playerExists)
    {
        file << playerName << "," << jerseyNumber << "," << score << endl;
        file.close();
        cout << "\033[1;32m\nPlayer score added successfully!\033[0m" << endl;
    }
}

// Function to add a player's score
// void addPlayerScore()
// {
//     ofstream file("scores.txt", ios::app);
//     if (!file)
//     {
//         cout << "\033[1;31mError opening file!\033[0m" << endl;
//         return;
//     }

//     string playerName;
//     int jerseyNumber;
//     int score;

//     cout << "\033[1;36m\n----------------------------------------------\033[0m" << endl;
//     cout << "\033[1;36m               ADD PLAYER'S SCORE              \033[0m" << endl;
//     cout << "\033[1;36m----------------------------------------------\033[0m" << endl;

//     cout << "\033[1;33mEnter player name: \033[0m";
//     getline(cin >> ws, playerName);
//     cout << "\033[1;33mEnter jersey number: \033[0m";
//     cin >> jerseyNumber;
//     cout << "\033[1;33mEnter score: \033[0m";
//     cin >> score;

//     file << playerName << "," << jerseyNumber << "," << score << endl;
//     file.close();

//     cout << "\033[1;32m\nPlayer score added successfully!\033[0m" << endl;
// }

// Function to search for a player's score
void searchPlayerScore()
{
    ifstream file("scores.txt");
    if (!file)
    {
        cout << "\033[1;31mError opening file!\033[0m" << endl;
        return;
    }

    int jerseyNumber;
    cout << "\033[1;36m\n----------------------------------------------\033[0m" << endl;
    cout << "\033[1;36m             SEARCH PLAYER'S SCORE             \033[0m" << endl;
    cout << "\033[1;36m----------------------------------------------\033[0m" << endl;

    cout << "\033[1;33mEnter jersey number to search: \033[0m";
    cin >> jerseyNumber;

    string line;
    bool playerFound = false;

    while (getline(file, line))
    {
        string playerName, score;
        int currentJerseyNumber;

        stringstream ss(line);
        getline(ss, playerName, ',');
        getline(ss, score, ',');
        currentJerseyNumber = stoi(score);

        if (currentJerseyNumber == jerseyNumber)
        {
            cout << "\033[1;32m\nPlayer Name: " << playerName << endl;
            cout << "Jersey Number: " << currentJerseyNumber << endl;
            cout << "Score: " << score << "\033[0m" << endl;
            playerFound = true;
            break;
        }
    }

    if (!playerFound)
    {
        cout << "\033[1;31m\nPlayer not found!\033[0m" << endl;
    }

    file.close();
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\033[1;36m\n----------------------------------------------\033[0m" << endl;
        cout << "\033[1;36m        CRICKET SCORE SHEET MANAGEMENT         \033[0m" << endl;
        cout << "\033[1;36m----------------------------------------------\033[0m" << endl;
        cout << "\033[1;33m1. Add Player's Score\033[0m" << endl;
        cout << "\033[1;33m2. Search Player's Score\033[0m" << endl;
        cout << "\033[1;33m3. Exit\033[0m" << endl;
        cout << "\033[1;33mEnter your choice: \033[0m";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPlayerScore();
            break;
        case 2:
            searchPlayerScore();
            break;
        case 3:
            cout << "\033[1;32m\nExiting program...\033[0m" << endl;
            break;
        default:
            cout << "\033[1;31m\nInvalid choice! Please try again.\033[0m" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
