#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для описания кандидата
struct Description {
    string interests;
    string achievements;
    string plans;

    Description(string i = "", string a = "", string p = "") {
        interests = i;
        achievements = a;
        plans = p;
    }
};

// обновила структура Candidate
struct Candidate {
    string name;
    int votes;
    Description description;  // Добавила описание

    Candidate(string n, Description desc = Description()) {
        name = n;
        votes = 0;
        description = desc;
    }
};

// Searching for the length of the longest name of candidate
int canditatesLongestName(vector<Candidate>& candidates){
    int candidates_longest_name_length = 0;
    for(int i = 0; i < candidates.size(); i++){
        if (candidates[i].name.length() > candidates_longest_name_length){
            candidates_longest_name_length = candidates[i].name.length();
        }
    }
    return candidates_longest_name_length;
}
void outputElection(vector<Candidate>& candidates){
    // ����� ������ �������� ����� ���������
    int candidates_longest_name_length = canditatesLongestName(candidates);
    cout << "\nLongest name is " << candidates_longest_name_length << " symbols" << endl;

    cout << "\nElection results:" << endl;
    // ������� ���������������� ������
    for (int i = 0; i < 16+candidates_longest_name_length; i++) {
        cout << "@";
    }
    cout << endl;
    // ����� �����������
    for (int i = 0; i < candidates.size(); i++) {
        cout << "@ " << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " votes";
        int needed_spaces_amount = 0;
        needed_spaces_amount = candidates_longest_name_length - candidates[i].name.length();
        for (int j = 0; j < needed_spaces_amount + 1; j++){
            cout << " ";
        }
        cout << "@" << endl;
    }
    // ������ ���������������� ������
    for (int i = 0; i < 16+candidates_longest_name_length; i++) {
        cout << "@";
    }
}
// ������� ��� ���������� �����������
void conductElection(vector<Candidate>& candidates) {
    cout << "Voting for the choice of the headman!" << endl;

    // ����� ������ ����������
    cout << "Candidates:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // ���� �����������
    while (true) {
        cout << "Enter the number of the candidate you want to vote for (0 - end voting):";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Invalid choice!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // ���������� ���������� ������� ���������
        candidates[choice - 1].votes++;
    }

    // ���������� ���������� �� �������� �������
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // ����� ����������� �����������
    // cout << "���������� �����������:" << endl;
    outputElection(candidates);
}
// // test 1
// void testInvalidCandidateCount() { 
//     int numCandidates = -10;

//     if (numCandidates > 0) {
//         cout << "Test 1 Passed: Valid input." << endl;
//         // return true;
//     }
//     else {
//         cout << "Test 1 Failed: Invalid input. Try again." << endl;
//         // return false;
//     }
// }
// void testCandidateNameWithSpaces() {
//     int numCandidates = 1;

//     string name = "Haruki Murakami";

//     if (name.find(' ') == string::npos) {
//         cout << "Test 2 Passed: Valid input." << endl;
//     } else {
//         cout << "Test 2 Failed: Invalid input." << endl;
//     }
// }