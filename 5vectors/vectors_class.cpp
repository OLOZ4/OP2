#include "header.h"
#include "student.hpp"

int main() {
    vector<string> name;
    vector<string> txtFiles;
    vector<Student1> stud;
    char choice;
    readFile(name);
    while (true) {
        cout <<endl;
        cout << R"(Select:
1) to add a new student
2) to add a new student (generated marks)
3) to add a new student (generated marks and names)
4) to read from file
5) to process and print all students
6) to generate files
7) to quit
--> )";
        cin >> choice;
        switch (choice) {
            case '1': {
                Student1 temp_student;
                temp_student.setVardas("Ben");
                temp_student.setPavarde("Juo");
                temp_student.setEgzaminas(10);

                break;
            }
        }
    }
}