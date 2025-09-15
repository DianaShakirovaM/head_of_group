#include <gtest/gtest.h>
#include "functions.h"
#include <iostream>
#include <sstream>

using namespace std;

// Тест создания кандидата
TEST(CandidateTest, Creation){
    Candidate candidate("Kevin Costner");

    // Проверяем данные кандидата
    EXPECT_EQ(candidate.name, "Kevin Costner");
    EXPECT_EQ(candidate.votes, 0);
    EXPECT_EQ(candidate.description.interests, "");
    EXPECT_EQ(candidate.description.achievements, "");
    EXPECT_EQ(candidate.description.plans, "");
}

// Тест проведения выборов
TEST(ElectionTest, ConductElection){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    // Сохраняем оригинальный cin
    std::streambuf* orig_cin = std::cin.rdbuf();
    
    // Создаем input stream с тестовыми данными
    std::istringstream input_stream("1\n2\n0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Восстанавливаем оригинальный cin
    std::cin.rdbuf(orig_cin);

    // Проверяем общее количество голосов
    EXPECT_EQ(candidates[0].votes + candidates[1].votes, 2);
}

// Тест голосования за одного кандидата несколько раз
TEST(ElectionTest, VoteForCandidate){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    // Сохраняем оригинальный cin
    std::streambuf* orig_cin = std::cin.rdbuf();
    
    // Создаем input stream с тестовыми данными
    std::istringstream input_stream("1\n1\n1\n0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Восстанавливаем оригинальный cin
    std::cin.rdbuf(orig_cin);

    EXPECT_EQ(candidates[0].votes, 3);
}

// Тест для нуля кандидатов
TEST(ElectionTest, ZeroCandidates){
    vector<Candidate> candidates;

    // Сохраняем оригинальный cin
    std::streambuf* orig_cin = std::cin.rdbuf();
    
    // Создаем input stream с тестовыми данными
    std::istringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Восстанавливаем оригинальный cin
    std::cin.rdbuf(orig_cin);

    // Проверяем что кандидатов нет
    EXPECT_TRUE(candidates.empty());
}

// Тест для нуля голосов
TEST(ElectionTest, ZeroVotes){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    // Сохраняем оригинальный cin
    std::streambuf* orig_cin = std::cin.rdbuf();
    
    // Создаем input stream с тестовыми данными
    std::istringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Восстанавливаем оригинальный cin
    std::cin.rdbuf(orig_cin);

    // Проверяем что кандидаты есть
    EXPECT_FALSE(candidates.empty());
    // Проверяем что голосов нет
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