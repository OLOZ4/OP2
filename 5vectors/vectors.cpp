#include "header.h"

int main() {
    vector<string> name;
    vector<string> txtFiles;
    vector<Student> stud;
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
                string mark;
                int exam_mark;
                Student temp_student;
                cout << "Enter name: ";
                cin >> temp_student.name;
                cout << "Enter surname: ";
                cin >> temp_student.surname;
                while (true) {
                    cout << "Enter exam mark (0-10): ";
                    cin >> mark;
                    if (isValid(mark)) {
                       temp_student.exam = std::stoi(mark) ;
                       break;
                    }  
                }
                while (true) {
                    cout << "Enter a mark (or 'q' to quit): ";
                    cin >> mark;

                    if (mark == "q") {
                        stud.push_back(temp_student);
                        temp_student.mark.clear();
                        system("clear");
                        break;
                    }
                    if (isValid(mark)) {
                       temp_student.mark.push_back(std::stoi(mark)) ;
                    }  
                    
                } 
                break;
            }
            
            case '2': {
                Student temp_student{};
                cout << "Enter name: ";
                cin >> temp_student.name;
                cout << "Enter surname: ";
                cin >> temp_student.surname;
                temp_student.exam = randomNumber(0, 10);
                cout << "Generated exam mark was: "<< temp_student.exam<<endl;
                for (int i = 0; i < randomNumber(3, 10); i++) {
                    temp_student.mark.push_back(randomNumber(0, 10));
                    cout << "Generated mark was: "<< temp_student.mark.back() << endl;
                }
                stud.push_back(temp_student);
                temp_student.mark.clear();
                break;
            }

            case '3': {
                Student temp_student{};
                temp_student.name = get_name(name);
                cout << "Generated name is: "<< temp_student.name <<endl;
                temp_student.surname = get_name(name);
                cout << "Generated surame name is: "<< temp_student.surname<<endl;
                temp_student.exam = randomNumber(0, 10);
                cout << "Generated exam mark was: "<< temp_student.exam<<endl;
                for (int i = 0; i < randomNumber(3, 10); i++) {
                    temp_student.mark.push_back(randomNumber(0, 10));
                    cout << "Generated mark was: "<< temp_student.mark.back() << endl;
                }
                stud.push_back(temp_student);
                temp_student.mark.clear();
                break;
            }
            case '4': {
                txtFiles.clear();
                vector<string> txtFiles = listTxtFiles();
                string filename;
                
                if (!txtFiles.empty()) {
                    system("clear");
                    cout << "Choose a .txt file to open:\n";
                    for (size_t i = 0; i < txtFiles.size(); ++i) {
                    cout << i << ") " << txtFiles[i] << "\n";
                        }
                    cout <<"--> ";
                    int choice;
                    while (true) {
                        cin >> choice;
                        system("clear");

                        if (choice >= 1 && choice <= txtFiles.size()) {
                            filename = txtFiles[choice];
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
                    ifstream in(filename);
                    in.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
                }catch(std::exception const& e){
                cout << "Klaida atidarant faila: " << e.what() << std::endl;
                break;
                }

                import_file(stud, filename);

                break;
            }
            case '5': {
                system("clear");
                /*
                for (int i = 0; i < stud.size(); i++) {
                    cout <<"Name: "<< stud[i].name << endl;
                    cout <<"Surname: "<< stud[i].surname << endl;
                    cout <<"Exam mark: "<< stud[i].exam << endl;
                    for (int j = 0; j < stud[i].mark.size(); j++) {
                        cout << stud[i].mark[j] << " ";
                    }
                    cout << endl;
                    
                }
               */ 

                sort_students(stud);
                count_marks(stud);
                print_marks(stud);
                cout <<endl;
                break;
            }
            
            case '6': {
                // kokios funkcijos turetu buti igyvendintos:
                // failu sukurimas
                // nuskaityti faila 
                // isrusiuoti faila
                // padalainti faila i dvi kategorijas
                // israsyti i du atskirus failus
                // islcearinti stud vectoriu
                //-----------------------------
                //ka reiketu matuoti v1.0 versijoje:
                // 1. duomenų nuskaitymą iš failų į atitinkamą konteinerį
                // 2. studentų rūšiavimą didėjimo tvarką konteineryje (funkcija sort);
                // 3. studentų skirstymo  į dvi grupes/kategorijas (naujų konteinerių su skirtingais studentais kūrimas);

                system("clear");
                vector<Student> nuskriaustukai, kietiakai;
                cout << R"(Select:
1) Pirma strategija
2) Antra strategija
3) Trečia strategija
--> )";
                char pasirinkimas;
                cin >> pasirinkimas;
                switch (pasirinkimas) {
                    while (true) {
                        case '1': {
                            pagrindinis_divide(stud, kietiakai, nuskriaustukai, 1);
                            break;
                        }
                        case '2': {
                            pagrindinis_divide(stud, kietiakai, nuskriaustukai, 2);
                            break;
                        }
                        case '3': {
                            pagrindinis_divide(stud, kietiakai, nuskriaustukai, 3);
                            break;
                        }
                        default: {
                            cout << "Klaida. Neteisingas pasirinkimas!";
                        }
                    }                 
                }
                
                  
                break;
            }

            case '7': {
                cout <<endl<< "quitting... bye" << endl;
                return 0;
            }

            default: {
                cout << "\n\nInvalid choice. Please try again.\n";
            }   
        }
    }
    return 0;
}