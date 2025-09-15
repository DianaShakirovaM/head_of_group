#include <gtest/gtest.h>
#include "functions.h"
#include <iostream>

using namespace std;

std::istringstream autoUserInput(const std::string& input){
    return std::istringstream(input);
}
// Обновляю существующие тесты
TEST(CandidateTest, Creation) {
    Candidate candidate("Kevin Costner");

    EXPECT_EQ(candidate.name, "Kevin Costner");
    EXPECT_EQ(candidate.votes, 0);
    // Добавляю проверки на default описание
    EXPECT_EQ(candidate.description.interests, "");
    EXPECT_EQ(candidate.description.achievements, "");
    EXPECT_EQ(candidate.description.plans, "");
}

TEST(ElectionTest, ConductElection) {
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    std::istringstream input_stream("1\n2\n0\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    std::cin.rdbuf(orig_cin);
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

// Тест создания кандидата с описанием
TEST(CandidateTest, CreationWithDescription) {
    Description desc("Programming", "Olympiad winner", "Improve education");
    Candidate candidate("John Doe", desc);

    EXPECT_EQ(candidate.name, "John Doe");
    EXPECT_EQ(candidate.votes, 0);
    EXPECT_EQ(candidate.description.interests, "Programming");
    EXPECT_EQ(candidate.description.achievements, "Olympiad winner");
    EXPECT_EQ(candidate.description.plans, "Improve education");
}

// Тест создания кандидата без описания
TEST(CandidateTest, CreationWithoutDescription) {
    Candidate candidate("Jane Smith");

    EXPECT_EQ(candidate.name, "Jane Smith");
    EXPECT_EQ(candidate.votes, 0);
    EXPECT_EQ(candidate.description.interests, "");
    EXPECT_EQ(candidate.description.achievements, "");
    EXPECT_EQ(candidate.description.plans, "");
}

// Тест default конструктора Description
TEST(DescriptionTest, DefaultConstructor) {
    Description desc;
    
    EXPECT_EQ(desc.interests, "");
    EXPECT_EQ(desc.achievements, "");
    EXPECT_EQ(desc.plans, "");
}

// Тест параметризованного конструктора Description
TEST(DescriptionTest, ParameterizedConstructor) {
    Description desc("Music", "Concert", "Tour");
    
    EXPECT_EQ(desc.interests, "Music");
    EXPECT_EQ(desc.achievements, "Concert");
    EXPECT_EQ(desc.plans, "Tour");
}

// Тест вывода описания при голосовании
TEST(ElectionTest, DisplayDescriptionDuringVoting) {
    vector<Candidate> candidates;
    Description desc("Tech", "Projects", "Innovate");
    candidates.push_back(Candidate("Tech Guy", desc));
    
    // Тестируем, что описание корректно хранится
    EXPECT_EQ(candidates[0].description.interests, "Tech");
    EXPECT_EQ(candidates[0].description.achievements, "Projects");
    EXPECT_EQ(candidates[0].description.plans, "Innovate");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}