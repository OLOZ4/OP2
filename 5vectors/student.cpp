#include "student.hpp"
#include "functions.cpp"
#include <algorithm>


float Student1::getMedian() const {
    vector<int> marks = mark;
    double med{};
    std::sort(marks.begin(), marks.end());
    if ((marks.size()-1) % 2 != 0) med = marks[marks.size()/2.0];
    else med = (marks[(marks.size()-1)/2.0] + marks[marks.size()/2.0])/2;
    return 0.4*med+0.6*egzaminas;
}

float Student1::getResult() const {
    double sum = 0;
    for (const auto& mark: mark) sum += mark;
    return 0.4*(sum/mark.size())+0.6*egzaminas;
}

void Student1::setVardas(string vardas_) {
    vardas = vardas_;
}

void Student1::setPavarde(string pavarde_) {
    pavarde = pavarde_;
}

void Student1::setEgzaminas (int egzaminas_) {
    egzaminas = egzaminas_;
}

void Student1::setMark(vector<int> mark_) {
    mark = mark_;
}
/*
void Student1::GenerateNames() {
    vardas = get_name(name);
    pavarde = get_name(name)
}
*/

void print(vector<Student1> &stud) {
    for (auto &student : stud) {
      cout << "Student: " << student.getVardas() << " " << student.getPavarde()
           << endl;
      cout << "Egzaminas: " << student.getEgzaminas() << endl;
      cout << "Marks: ";
      for (int mark : student.getMark()) {
        cout << mark << " ";
      }
      cout << endl;
  
      cout << "Median: " << student.getMedian() << endl;
  
      cout << "Vid: " << student.getResult();
  
      cout << endl << endl;
    }
  }

void import_file (vector<Student1> &stud, string filename) {

    string temp;
    string vardas, pavarde;
    vector<int> mark;
    ifstream in("../studentai/"+filename);
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    int lineNum = lineCount(filename);
    getline(in, temp);
    stud.reserve(lineNum);                    
    string word;
    Student1 temp_student;
    while (getline(in, temp)) {   
        std::istringstream stream (temp);
        while (stream) {
            stream >> vardas >> pavarde;
            temp_student.setVardas(vardas);
            temp_student.setPavarde(pavarde);
            while (stream) {
                stream >> word;
                mark.push_back(std::stoi(word));
            }
            temp_student.setEgzaminas(mark.back());
            mark.pop_back();

            temp_student.setMark(mark);
            //stud.push_back(std::move(temp_student));
            
            stud.push_back(temp_student);
            mark.clear();
        }
    }
        //count_marks(stud);
        auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> diff = end-start;
        cout << "Importing file " <<filename<<" was successful. Took: "<< diff.count() << " s"<<endl;
        //print_metrics(filename, diff.count(), 0);
        in.close();
        
}

void sort_students (vector<Student1>& stud) {
    cout <<"There are: "<<stud.size()<<" Students"<<endl;
    cout << R"(Sort by:
1) student name
2) student surname
3) student mark (average)
4) student mark (median)
--> )";
    char choice1;
    while (true) {
    cin >> choice1;
    switch (choice1) {
            case '1': {
                std::sort(stud.begin(), stud.end(), [](const Student1& a, const Student1& b) {
                
                return (a.getVardas()) < (b.getVardas());});
                //print_marks(stud);            
                return;
            }
            case '2': {
                std::sort(stud.begin(), stud.end(), [](const Student1& a, const Student1& b) {

                return a.getPavarde() < b.getPavarde();});
                //print_marks(stud);            
                return;
            }
            case '3': {
                std::sort(stud.begin(), stud.end(), [](const Student1& a, const Student1& b) {

                return a.getResult() < b.getResult();});
                //print_marks(stud);            
                return;
            }
            case '4': {
                std::sort(stud.begin(), stud.end(), [](const Student1& a, const Student1& b) {

                return a.getMedian() < b.getMedian();
                });
                //print_marks(stud);            
                return;
            }
            default: {
                cout << "\n\nInvalid choice. Please try again.\n--> ";
                continue;
            }
            break;   
        }
        
    }
}

void print_marks (vector<Student1> stud) {
    int g = 15;
    cout << endl << setw(g) << left<< "Vardas: "<< setw(g) << left<< "Pavardė: "<< setw(g) << left<< "Pažymys(vid.): "<< setw(g) << left<< "Pažymys(med.): "<< endl;
     cout<<"__________________________________________________________________________________"<<endl;
    for (int i = 0; i < stud.size(); i++) {
        cout <<setw(g)<< left<< stud[i].getVardas() << setw(g)<< left<< stud[i].getPavarde(); 
        cout << setw(g) <<left<<std::setprecision(3)<< stud[i].getResult() << setw(g)<< left << std::setprecision(3) <<  stud[i].getMedian() << endl; // kur mediana vietoj vidurkio imti mediana
    }
    cout<<endl;
    //-----------------------Writing-to-file-----------------------
    write_marks(stud, "output.txt");
    //-------------------------------------------------------------
}

void write_marks (vector<Student1> stud, string name) {

    int g = 15;
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    std::ofstream out (name);
    out << setw(g) << left<< "Vardas: "<< setw(g) << left<< "Pavardė: "<< setw(g) << left<< "Pažymys(vid.): "<< setw(g) << left<< "Pažymys(med.): "<< endl;
    out<<"__________________________________________________________________________________"<<endl;
    for (int i = 0; i < stud.size(); i++) {
        out <<setw(g)<< left<< stud[i].getVardas() << setw(g)<< left<< stud[i].getPavarde(); 
        out << setw(g) <<left<<std::setprecision(3)<< stud[i].getResult() << setw(g)<< left << std::setprecision(3) <<  stud[i].getMedian() << endl; // kur mediana vietoj vidurkio imti mediana
    }
    out.close();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Writing file " <<name<<" was successful. Took: "<< diff.count() << " s"<<endl;
}

void divide_file1 (vector<Student1>& stud, vector<Student1>& kietiakai, vector<Student1>& nuskriaustukai, string filename) {
    string name = "studentai" + std::to_string(stud.size()) + ".txt";
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    nuskriaustukai.reserve(stud.size());
    kietiakai.reserve(stud.size());
    
    for (auto &a: stud) {
        if (a.getResult() >= 5.00) kietiakai.push_back(a);
        else nuskriaustukai.push_back(a);
    }

    nuskriaustukai.shrink_to_fit();
    kietiakai.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Dividing file "<<name<<" was successful. Took: "<< diff.count() << " s"<<endl;
    //print_metrics(filename, diff.count(), 0, 0);
}

void divide_file2 (vector<Student1>& stud, vector<Student1>& nuskriaustukai, string filename) {
    string name = "studentai" + std::to_string(stud.size()) + ".txt";
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    nuskriaustukai.reserve(stud.size());
    
    while (stud.back().getResult() < 5.00) {
        nuskriaustukai.push_back(stud.back());
        stud.pop_back();
    }

    nuskriaustukai.shrink_to_fit();
    stud.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Dividing file "<<filename<<" was successful. Took: "<< diff.count() << " s"<<endl;
    //print_metrics(filename, diff.count(), 0, 0);
}

void divide_file3(vector<Student1>& stud, vector<Student1>& nuskriaustukai, string filename) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Partition the students based on the result
    auto partition_point = std::stable_partition(stud.begin(), stud.end(), [](const Student1& s) { return s.getResult() >= 5.0; });
    //print_marks(stud);
    
    // Move the failing students to nuskriaustukai
    nuskriaustukai = vector<Student1>(std::make_move_iterator(partition_point), std::make_move_iterator(stud.end()));
    stud.erase(partition_point, stud.end());
    
    // Shrink to fit
    nuskriaustukai.shrink_to_fit();
    stud.shrink_to_fit();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Dividing file " << filename << " was successful. Took: " << diff.count() << " s" << std::endl;
    //print_metrics(filename, diff.count(), 0);
}

void pagrindinis_divide (vector<Student1> &stud, vector<Student1> &kietiakai, vector<Student1> &nuskriaustukai, int num) {
    const vector<int> file_size = {1000, 10000, 100000, 1000000, 10000000};

    for (int i = 0; i < file_size.size(); i++) {
        string filename = "../studentai/studentai" + std::to_string(file_size[i])+ ".txt";
        //generate_file(file_size[i]);
        
        auto start = std::chrono::high_resolution_clock::now(); // Paleisti
        import_file(stud,filename);
        sort_file(stud, filename);
        if (num == 1) divide_file1(stud, kietiakai, nuskriaustukai, filename);
        if (num == 2) divide_file2(stud, nuskriaustukai, filename);
        if (num == 3) divide_file3(stud, nuskriaustukai, filename);
        
        
        auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> diff = end-start;
        /*
        cout<<endl<< "Sorting kietiakai:"<<endl;
        sort_students(kietiakai);
        cout<< "Sorting nuskriaustukai:"<<endl;
        sort_students(nuskriaustukai);
        */
        
        //if (num == 1) write_marks(kietiakai, "studentai"+std::to_string(file_size[i])+"_kietiakai.txt");
        //else write_marks(stud, "studentai"+std::to_string(file_size[i])+"_kietiakai.txt");
        //write_marks(nuskriaustukai, "studentai"+std::to_string(file_size[i])+"_nuskriaustukai.txt");
        stud.clear();
        nuskriaustukai.clear();
        
        cout <<"==================================================================="<<endl;
        cout << "| Processed file "<< setw(30)<< left<<filename<<" Took: "<< std::setprecision(3)<<setw(5) <<left<<diff.count() << " s |"<<endl;
        cout <<"==================================================================="<<endl<<endl;
        print_metrics(filename, diff.count(), 1, num);
    }
}

void pagrindinis_divide_choice(vector<Student1> &stud) {
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
}

void sort_file (vector<Student1>& stud, string name) {
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    std::sort(stud.begin(), stud.end(), [](const Student1& a, const Student1& b) {return a.getResult() > b.getResult();});    
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Sorting file "<<name<<" was successful. Took: "<< diff.count() << " s"<<endl;
    //print_metrics(name, diff.count(), 0);
}

void rule_of_five() {
    char choice2;
cout << R"(Select:
1) Copy constructor
2) Copy Assignment Operator
3) Move Constructor
4) Move Assignment Operator
--> )"; 

            cin >> choice2;
            switch (choice2) {
                while (true) {
                      
                    case '1': {
                        cout <<"Creating student a"<<endl;
                        Student1 a ("Tomas", "Tomaitis",10,vector<int>{1,2,3});
                        cout <<"a: "<<a<<endl;
                        cout <<"Creating student b, so that b = a"<<endl;
                        Student1 b = a;
                        cout <<"b: "<<b<<endl;
                        break;
                    }

                    case '2': {
                        cout <<"Creating student a"<<endl;
                        Student1 a ("Kostas", "Kostaitis",9,vector<int>{10,10,10});
                        cout <<"a: "<<a<<endl;
                        cout <<"Creating student b"<<endl;
                        Student1 b;
                        cout <<"b: "<<b<<endl;
                        cout <<"Now let's use operator '=' to make b = a "<<endl<<endl;
                        b = a;
                        cout <<"b: "<<b<<endl;
                        b = b;
                        break;
                    }

                    case '3': {
                        cout <<"Creating student a"<<endl;
                        Student1 a ("Genute", "Genutaite",2,vector<int>{1});
                        cout <<"a: "<<a<<endl;
                        cout <<"Creating student b with move constructor:"<<endl<<endl;
                        Student1 b = std::move(a);
                        cout <<"b: "<<b<<endl;
                        cout <<"Now let's check a"<<endl<<endl;
                        cout <<"a: "<<a<<endl;
                        break;
                    }

                    case '4': {
                        cout <<"Creating student a"<<endl;
                        Student1 a ("Mykolas", "Mykolaitis",2,vector<int>{3,3});
                        cout <<"a: "<<a<<endl;
                        cout <<"Creating student b"<<endl;
                        Student1 b;
                        cout <<"b: "<<b<<endl;
                        cout <<"Now let's use operator '=' to move from a to b "<<endl<<endl;
                        b = std::move(a);
                        cout <<"b: "<<b<<endl;
                        cout <<"Now let's check a"<<endl<<endl;
                        cout <<"a: "<<a<<endl<<endl;
                        break;
                    }

                    default: {
                        cout << "\n\nInvalid choice. Please try again.\n";
                        continue;
                    }
                }
            }
        
}