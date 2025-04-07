#include "header.h"
#include "student.hpp"


int main() {
  vector<string> name;
  vector<string> txtFiles;
  vector<Student1> stud;
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
7) to quit
--> )";
    cin >> choice;
    switch (choice) {
        case '1': {
            Student1 temp_student;
            string vardas, pavarde, mark_temp;
            string egzaminas;
            vector<int> mark {};

            cout << "Enter name: ";
            cin >> vardas;
            temp_student.setVardas(vardas);

            cout << "Enter surname: ";
            cin >> pavarde;
            temp_student.setPavarde(pavarde);

            while (true) {
                cout << "Enter exam mark (0-10): ";
                cin >> egzaminas;
                if (isValid(std::stoi(egzaminas))) {
                    temp_student.setEgzaminas(std::stoi(egzaminas));
                    break;
                }
            }

            while (true) {
                cout << "Enter a mark (or 'q' to quit): ";
                cin >> mark_temp;

                if (mark_temp == "q") {
                    temp_student.setMark(mark);
                    mark.clear();
                    system("clear");
                    break;
                }
                if (isValid(mark_temp)) {
                mark.push_back(std::stoi(mark_temp));
                }  
            }
        
            stud.push_back(temp_student);
            mark.clear();
            //print(stud);
            break;
        }

        case '2': {
            Student1 temp_student;
            string vardas, pavarde, mark_temp;
            int egzaminas;
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
            txtFiles.clear();
            vector<string> txtFiles = listTxtFiles();
            string filename;

            if (!txtFiles.empty()) {
                system("clear");
                cout << "Choose a .txt file to open:\n";
                for (size_t i = 1; i < txtFiles.size()+1; ++i) {
                cout << i << ") " << txtFiles[i-1] << "\n";
                    }
                cout <<"--> ";
                int choice;
                while (true) {
                    cin >> choice;
                    system("clear");

                    if (choice >= 1 && choice <= txtFiles.size()) {
                        filename = txtFiles[choice-1];
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
            cout << "FILENAME" << filename << endl;
            import_file(stud, filename);

            break;
        }

        case '5': {
            sort_students(stud);
            //count_marks(stud);
            print_marks(stud);
            cout <<endl;
            break;
        }

        case '6': {
            system("clear");
            vector<Student1> nuskriaustukai, kietiakai;
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
}