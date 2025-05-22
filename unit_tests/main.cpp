#include "catch.hpp"
#include "../program/student.hpp"
//#include "../program/vector.hpp"

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

TEST_CASE("Student1 objects are stored correctly in a container", "[container]") {
    Student1 student1("Jonas", "Ponas", 8, {9, 8, 7});
    Student1 student2("Donatas", "Mykolas", 5, {8, 7, 0});
    Student1 student3("Austeja", "Aiste", 9, {10, 9, 9});

    std::vector<Student1> students;

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);

    REQUIRE(students.size() == 3);

    REQUIRE(students[0].getResult() == student1.getResult());
    REQUIRE(students[1].getResult() == student2.getResult());
    REQUIRE(students[2].getResult() == student3.getResult());

    REQUIRE(students[0].getMedian() == student1.getMedian());
    REQUIRE(students[1].getMedian() == student2.getMedian());
    REQUIRE(students[2].getMedian() == student3.getMedian());

    REQUIRE(students[0].getVardas() == student1.getVardas());
    REQUIRE(students[1].getVardas() == student2.getVardas());
    REQUIRE(students[2].getVardas() == student3.getVardas());
}

// TEST FOR VECTOR CLASS

TEST_CASE("Vector default constructor and get_size/capacity") {
    Vector<int> v;
    REQUIRE(v.get_size() == 0);
    REQUIRE(v.get_capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("Vector default constructor as array") {
    Vector<int> v {1,2,3};
    REQUIRE(v.get_size() == 3);
    REQUIRE(!v.empty());
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
}

TEST_CASE("Vector(size_t) creates vector with reserved capacity") {
    Vector<int> v(10);
    REQUIRE(v.get_size() == 0);
    REQUIRE(v.get_capacity() >= 10);
    v.push_back(5);
    REQUIRE(v.get_size() == 1);
}

TEST_CASE("push_back and operator[]") {
    Vector<std::string> v;
    v.push_back("a");
    v.push_back("b");
    v.push_back("c");
    REQUIRE(v.get_size() == 3);
    REQUIRE(v[0] == "a");
    REQUIRE(v[2] == "c");
}

TEST_CASE("front and back") {
    Vector<int> v;
    v.push_back(10);
    v.push_back(42);
    v.push_back(7);
    REQUIRE(v.front() == 10);
    REQUIRE(v.back() == 7);
}

TEST_CASE("at throws when out of range") {
    Vector<int> v;
    v.push_back(1);
    REQUIRE_NOTHROW(v.at(0));
    REQUIRE_THROWS_AS(v.at(1), std::out_of_range);
}

TEST_CASE("copy constructor") {
    Vector<int> v;
    for(int i=0; i<5; ++i) v.push_back(i * 2);
    Vector<int> v2(v);
    REQUIRE(v2.get_size() == v.get_size());
    for(int i=0; i<v.get_size(); ++i)
        REQUIRE(v2[i] == v[i]);
}

TEST_CASE("move constructor") {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    Vector<int> v2(std::move(v));
    REQUIRE(v2.get_size() == 2);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("copy assignment") {
    Vector<int> v1, v2;
    for (int i = 0; i < 3; i++) v1.push_back(i);
    v2 = v1;
    REQUIRE(v2.get_size() == v1.get_size());
    for(int i=0; i<v1.get_size(); ++i)
        REQUIRE(v2[i] == v1[i]);
}

TEST_CASE("move assignment") {
    Vector<int> v1;
    v1.push_back(100);
    v1.push_back(200);
    Vector<int> v2;
    v2 = std::move(v1);
    REQUIRE(v2.get_size() == 2);
    REQUIRE(v2[1] == 200);
}

TEST_CASE("clear empties the vector") {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.clear();
    REQUIRE(v.get_size() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("insert single element") {
    Vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.insert(1, 2); // insert 2 at index 1
    REQUIRE(v.get_size() == 3);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
}

TEST_CASE("insert multiple copies") {
    Vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.insert(1, 2, 2); // insert two 2s at index 1
    REQUIRE(v.get_size() == 4);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 2);
    REQUIRE(v[3] == 4);
}

TEST_CASE("pop_back removes last element") {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    REQUIRE(v.get_size() == 1);
    REQUIRE(v.back() == 1);
    v.pop_back();
    REQUIRE(v.empty());
    REQUIRE_THROWS_AS(v.pop_back(), std::out_of_range);
}

TEST_CASE("erase by index") {
    Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4);
    v.erase(1); // remove 2
    REQUIRE(v.get_size() == 3);
    REQUIRE(v[1] == 3);
    v.erase(0); // remove 1
    REQUIRE(v[0] == 3);
}

TEST_CASE("erase by iterator range") {
    Vector<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i);
    int* first = v.begin() + 1;
    int* last = v.begin() + 4;
    v.erase(first, last); // should erase 1,2,3
    REQUIRE(v.get_size() == 2);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 4);
}

TEST_CASE("reserve and capacity") {
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.get_capacity() >= 100);
    // Should not affect size
    REQUIRE(v.get_size() == 0);
}

TEST_CASE("shrink_to_fit reduces capacity") {
    Vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    v.reserve(100);
    size_t before = v.get_capacity();
    v.shrink_to_fit();
    REQUIRE(v.get_capacity() <= before);
    REQUIRE(v.get_capacity() >= v.get_size());
}

TEST_CASE("max_size returns a large value") {
    Vector<int> v;
    REQUIRE(v.max_size() > 10000);
}

TEST_CASE("range constructor") {
    std::vector<int> src = {1,2,3,4,5};
    Vector<int> v(src.begin(), src.end());
    REQUIRE(v.get_size() == src.size());
    for (size_t i = 0; i < src.size(); ++i)
        REQUIRE(v[i] == src[i]);
}

TEST_CASE("begin/end/rbegin/rend") {
    Vector<int> v;
    v.push_back(5); v.push_back(10); v.push_back(15);
    REQUIRE(*v.begin() == 5);
    REQUIRE(*(v.end()-1) == 15);
    REQUIRE(*v.rbegin() == 15);
    REQUIRE(*(v.rend()+1) == 5);
}
