#include "header.h"
#include "student.hpp"
//#include "vector.hpp"

int main() {
    //std::locale::global(std::locale("en_US.UTF-8")); 
    vector<string> name;
    //vector<string> txtFiles;
    Vector<Student1> stud;
    char choice;
    readFile(name);
    while (true) {
        cout << endl;
        cout << R"(Select:
1) to add a new student
2) to add a new student (generated marks)
3) to add a new student (generated marks and names)
4) to read from file
5) to process and print all students
6) to generate files
7) to test Rule of Five
8) to quit
9) to compare std::vector and custom vector 
--> )";
        cin >> choice;
        switch (choice) {
            case '1': {
                
                Student1 temp_student;
                cin >> temp_student;
            
                stud.push_back(temp_student);
                //print(stud);
                //cout << stud[0];
                break;
            }

            case '2': {
                Student1 temp_student;
                string vardas, pavarde, mark_temp;
                vector<int> mark {};

                cout << "Enter name: ";
                cin >> vardas;
                temp_student.setVardas(vardas);

                cout << "Enter surname: ";
                cin >> pavarde;
                temp_student.setPavarde(pavarde);

                temp_student.setEgzaminas(randomNumber(0, 10));
                cout << "Generated exam mark was: "<< temp_student.getEgzaminas()<<endl;

                for (int i = 0; i < randomNumber(3, 10); i++) {
                    mark.push_back(randomNumber(0, 10));
                    cout << "Generated mark was: "<< mark.back() << endl;
                }
                temp_student.setMark(mark);

                stud.push_back(temp_student);
                mark.clear();
                //print(stud);
                break;
            }

            case '3': {
                //stud.reserve(stud.get_size()+1);
                Student1 temp_student;
                vector<int> mark {};

                temp_student.setVardas(get_name(name));
                cout << "Generated name is: "<< temp_student.getVardas() <<endl;

                temp_student.setPavarde(get_name(name));
                cout << "Generated surname is: "<< temp_student.getPavarde() <<endl;

                temp_student.setEgzaminas(randomNumber(0, 10));
                cout << "Generated exam mark was: "<< temp_student.getEgzaminas()<<endl;

                for (int i = 0; i < randomNumber(3, 10); i++) {
                    mark.push_back(randomNumber(0, 10));
                    cout << "Generated mark was: "<< mark.back() << endl;
                }
                temp_student.setMark(mark);

                stud.push_back(temp_student);
                //print(stud);
                break;
            }

            case '4': {
                vector<string> txtFiles = listTxtFiles();
                string filename;

                if (!txtFiles.empty()) {
                    system("clear");
                    cout << "Choose a .txt file to open:\n";
                    for (size_t i = 1; i < txtFiles.size()+1; ++i) {
                    cout << i << ") " << txtFiles[i-1] << "\n";
                        }
                    cout <<"--> ";
                    int choice2;
                    while (true) {
                        cin >> choice2;
                        system("clear");

                        if (choice2 >=1 && choice2 <=  static_cast<int>(txtFiles.size())) {
                            filename = txtFiles[choice2-1];
                            break; 
                        } else {
                            cout << "Invalid choice, try again:\n";
                        }
                    }
                } 
                else {
                    std::cout << "No .txt files found in this directory.\n";
                }

                try {
                    ifstream in("../studentai/"+filename);
                    in.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
                }
                catch(std::exception const& e){
                cout << "Klaida atidarant faila: " << e.what() << std::endl;
                break;
                }
                cout << "Reading from: " << filename << endl;
                import_file(stud, filename);

                break;
            }

            case '5': {
                system("clear");
                choose_printing_method(stud);
                break;
            }

            case '6': {
                system("clear");
                pagrindinis_divide_choice(stud);
                break;
            }
            
            case '7':{
                system("clear");
                rule_of_five();
                break;
            }

            case '8': {
                cout <<endl<< "quitting... bye" << endl;
                return 0;
            }

            case '9': {
                compare_vectors();
                break;
            }
            
            default: {
                cout << "\n\nInvalid choice. Please try again.\n";
            }
        }
    }
}