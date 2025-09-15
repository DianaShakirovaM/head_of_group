#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    //�����
    // testInvalidCandidateCount();
    // testCandidateNameWithSpaces();
    // ���� ���������� ����������
    int numCandidates;
    cout << "Enter the amount of candidates: ";
    cin >> numCandidates;
    // while(!testInvalidCandidateCount(numCandidates)){
    //     cin >> numCandidates;
    // }
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
