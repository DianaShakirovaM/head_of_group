#include <gtest/gtest.h>
#include "functions.h"
#include <iostream>

using namespace std;

std::istringstream autoUserInput(const std::string& input){
    return std::istringstream(input);
}
// �������� ������� ��������� � ��������
TEST(CandidateTest, Creation){
    Candidate candidate("Kevin Costner");

    // �������� ������ ���������
    EXPECT_EQ(candidate.name, "Kevin Costner");
    EXPECT_EQ(candidate.votes, 0);
}
// �������� ������������ ���������� �������
TEST(ElectionTest, ConductElection){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    // �������� ����� ������������ � �������� � �����
    std::istringstream input_stream("1\n2\n0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // �������� ������������ �������� �������
    EXPECT_EQ(candidates[0].votes + candidates[1].votes, 2);
}
// �������� ������������ �������� �������, ��������������� ��������������
TEST(ElectionTest, VoteForCandidate){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    std::istringstream input_stream("1\n1\n1\n0\n");

    conductElection(candidates);

    EXPECT_EQ(candidates[0].votes, 3);
}
// ������ ��� ���������� - ������ �� �����
TEST(ElectionTest, ZeroCandidates){
    vector<Candidate> candidates;

    std::istringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // ������ �� ������ ���������� 
    EXPECT_TRUE(candidates.empty());
}
TEST(ElectionTest, ZeroVotes){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    std::istringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // ��������� ����
    EXPECT_FALSE(candidates.empty());
    // ������� � ���������� ���
    EXPECT_EQ(candidates[0].votes + candidates[1].votes, 0);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}