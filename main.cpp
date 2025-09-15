#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    int numCandidates;
    cout << "Enter the amount of candidates: ";
    cin >> numCandidates;
    cin.ignore();  // Очищаем буфер

    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Enter the name of candidate #" << i + 1 << ": ";
        getline(cin, name);
        
        Description desc;
        cout << "Enter interests for " << name << ": ";
        getline(cin, desc.interests);
        cout << "Enter achievements for " << name << ": ";
        getline(cin, desc.achievements);
        cout << "Enter plans for " << name << ": ";
        getline(cin, desc.plans);
        cout << endl;

        candidates.push_back(Candidate(name, desc));
    }

    conductElection(candidates);
    return 0;
}