#include "catch.hpp"
#include "student.hpp"
#include <fstream>

TEST_CASE("Setters") {
    Student1 studentas;

    studentas.setVardas("Adomas");
    studentas.setPavarde("Kestas");
    studentas.setEgzaminas(10);
    studentas.setMark(vector<int> {10,10,10});

    REQUIRE(studentas.getVardas() == "Adomas");
    REQUIRE(studentas.getPavarde() == "Kestas");
    REQUIRE(studentas.getEgzaminas() == 10);
    REQUIRE(studentas.getMark() == vector<int> {10,10,10});
}

TEST_CASE("Default constructor") {
    Student1 studentas;

    REQUIRE(studentas.getVardas() == "Default");
    REQUIRE(studentas.getPavarde() == "Default");
    REQUIRE(studentas.getResult() == 0);
    REQUIRE(studentas.getMedian() == 0);
}

TEST_CASE("Copy constructor") {
    Student1 a ("Tomas", "Tomaitis",10,vector<int>{1,2,3});
    Student1 b (a);

    REQUIRE(b == a);
}

TEST_CASE("Copy Assignment Operator") {
    Student1 a ("Kostas", "Kostaitis",9,vector<int>{10,10,10});
    Student1 b;
    b = a;

    REQUIRE(b == a);
}

TEST_CASE("Move Constructor") {
    Student1 a ("Genute", "Genutaite",2,vector<int>{1});
    Student1 b (std::move(a));
    Student1 Default;

    REQUIRE(b.getVardas() == "Genute");
    REQUIRE(b.getPavarde() == "Genutaite");
    REQUIRE(b.getEgzaminas() == 2);
    REQUIRE(b.getMark() == vector<int>{1});
    REQUIRE(a == Default);

}

TEST_CASE("Move Assignment Operator") {
    Student1 a ("Mykolas", "Mykolaitis",2,vector<int>{3,3});
    Student1 b;
    Student1 Default;

    b = std::move(a);

    REQUIRE(b.getVardas() == "Mykolas");
    REQUIRE(b.getPavarde() == "Mykolaitis");
    REQUIRE(b.getEgzaminas() == 2);
    REQUIRE(b.getMark() == vector<int>{3,3});
    REQUIRE(a == Default);

}

TEST_CASE("Reading from file") {
    Student1 studentas;

    std::ifstream in ("../studentai/studentai1.txt");
    in >> studentas;

    REQUIRE(studentas.getVardas() == "Vardas0");
    REQUIRE(studentas.getPavarde() == "Pavarde0");
    REQUIRE(studentas.getEgzaminas() == 3);
    REQUIRE(studentas.getMark() == vector<int>{6,0,10,0,2,8,4,6,6,8});
}

