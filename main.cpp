#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��������� ��� �������� ���������� � ���������
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};
// Searching for the length of the longest name of candidate
int canditatesLongestName(vector<Candidate>& candidates){
    int candidates_longest_name = 0;
    for(int i = 0; i < candidates.size(); i++){
        if (candidates[i].name.length() > candidates_longest_name){
            candidates_longest_name = candidates[i].name.length();
        }
    }
    return candidates_longest_name;
}
void outputElection(vector<Candidate>& candidates){
    cout << "\nElection results:" << endl;
    cout << endl;
    // ����� �����������
    for (int i = 0; i < candidates.size(); i++) {
        cout << "@ " << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " votes";
        cout << "@" << endl;
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

int main() {
    // ���� ���������� ����������
    int numCandidates;
    cout << "Enter the amount of candidates: ";
    cin >> numCandidates;

    // ���� ��� ����������
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Enter the name of candidate #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // ���������� �����������
    conductElection(candidates);

    return 0;
}
