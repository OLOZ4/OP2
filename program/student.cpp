#include "../program/student.hpp"
#include <vector>

float Student1::getMedian() const {
    vector<int> marks = mark;
    double med{};
    std::sort(marks.begin(), marks.end());
    if ((marks.size()-1) % 2 != 0) med = marks[marks.size()/2.0];
    else med = (marks[(marks.size()-1)/2.0] + marks[marks.size()/2.0])/2;
    marks.clear();
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
      std::cout << "Student: " << student.getVardas() << " " << student.getPavarde() << std::endl;
           std::cout << "Egzaminas: " << student.getEgzaminas() << std::endl;
           std::cout << "Marks: ";
      for (int mark : student.getMark()) {
        std::cout << mark << " ";
      }
      std::cout << std::endl;
  
      std::cout << "Median: " << student.getMedian() << std::endl;
  
      std::cout << "Vid: " << student.getResult();
  
      std::cout << std::endl << std::endl;
    }
  }

void import_file (Vector<Student1> &stud, string filename) {

    string temp;
    
    std::ifstream in("../studentai/"+filename);

    if (!in) {
        std::cerr << "Error: Could not open the file." << std::endl;
    }

    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    int lineNum = lineCount(filename);
    getline(in, temp);
    stud.reserve(lineNum);
                        
    Student1 temp_student;
    while (in>>temp_student) {
        stud.push_back(temp_student);
    }
    //count_marks(stud);y
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    std::cout << "Importing file " <<filename<<" was successful. Took: "<< diff.count() << " s"<<std::endl;
    //print_metrics(filename, diff.count(), 0);
    in.close();
        
}

/*
void import_file (vector<Student1> &stud, string filename) {

    string temp;
    string vardas, pavarde;
    vector<int> mark;
    int egz;
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
            //temp_student.setVardas(vardas);
            //temp_student.setPavarde(pavarde);
            int marks;
            while (stream) {
                stream >> marks;
                mark.push_back(marks);
            }
            egz = mark.back();
            mark.pop_back();

            //temp_student.setMark(mark);
            //stud.push_back(std::move(temp_student));
            //Student1 temp_student (vardas, pavarde, egz, mark);
            //stud.push_back(std::move(temp_student));
            stud.emplace_back(vardas, pavarde, egz, mark);
            mark.clear();
        }
    }
        //count_marks(stud);
        auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> diff = end-start;
        std::cout << "Importing file " <<filename<<" was successful. Took: "<< diff.count() << " s"<<endl;
        //print_metrics(filename, diff.count(), 0);
        in.close();
        
}
*/

void sort_students (Vector<Student1>& stud) {
    std::cout <<"There are: "<<stud.get_size()<<" Students"<<std::endl;
    std::cout << R"(Sort by:
1) student name
2) student surname
3) student mark (average)
4) student mark (median)
--> )";
    char choice1;
    while (true) {
    std::cin >> choice1;
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
                std::cout << "\n\nInvalid choice. Please try again.\n--> ";
                continue;
            }
            break;   
        }
        
    }
}

void choose_printing_method (Vector<Student1>& stud) {
    sort_students(stud);
    char choice;
    string filename;
    std::cout << R"(Print:
1) To terminal
2) To file
3) Both
--> )";
    while (true) {
        std::cin >> choice;
        switch (choice) {
            case '1': {
                print_marks(stud);
                return;
            }

            case '2': {
                std::cout << "Enter file name, press 'd' for default name 'output.txt'"<<std::endl << "-->";
                std::cin >> filename;
                if (filename == "d" ) write_marks(stud, "output.txt");
                else write_marks(stud, filename);
                return;
            }
            
            case '3': {
                std::cout << std::endl <<"Enter file name, press 'd' for default name 'output.txt'"<< std::endl << "-->";
                std::cin >> filename;
                if (filename == "d" ) write_marks(stud, "output.txt");
                else write_marks(stud, filename);
                print_marks(stud);
                return;
            }

            default: {
                std::cout << "\n\nInvalid choice. Please try again.\n--> ";
            }
        }
    }
}

void print_marks (Vector<Student1> stud) {
    int g = 15;
    std::cout << std::endl << std::setw(g) << std::left<< "Vardas: "<< std::setw(g) << std::left<< "Pavardė: "<< std::setw(g) << std::left<< "Pažymys(vid.): "<< std::setw(g) << std::left<< "Pažymys(med.): "<< std::endl;
    std::cout<<"__________________________________________________________________________________"<<std::endl;
    for (int i = 0; i < stud.get_size(); i++) {
        std::cout << stud[i];
    }
    std::cout<<std::endl;
}

void write_marks (Vector<Student1> stud, string name) {

    int g = 15;
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    std::ofstream out (name);
    out << std::setw(g) << std::left<< "Vardas: "<< std::setw(g) << std::left<< "Pavardė: "<< std::setw(g) << std::left<< "Pažymys(vid.): "<< std::setw(g) << std::left<< "Pažymys(med.): "<< std::endl;
    out<<"__________________________________________________________________________________"<<std::endl;
    for (int i = 0; i < stud.get_size(); i++) {
        out << stud[i];
    }
    out.close();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    std::cout << "Writing file " <<name<<" was successful. Took: "<< diff.count() << " s"<<std::endl;
}

void divide_file1 (Vector<Student1>& stud, Vector<Student1>& kietiakai, Vector<Student1>& nuskriaustukai, string filename) {
    string name = "studentai" + std::to_string(stud.get_size()) + ".txt";
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    nuskriaustukai.reserve(stud.get_size());
    kietiakai.reserve(stud.get_size());
    
    for (auto &a: stud) {
        if (a.getResult() >= 5.00) kietiakai.push_back(a);
        else nuskriaustukai.push_back(a);
    }

    nuskriaustukai.shrink_to_fit();
    kietiakai.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    std::cout << "Dividing file "<<name<<" was successful. Took: "<< diff.count() << " s"<<std::endl;
    //print_metrics(filename, diff.count(), 0, 0);
}

void divide_file2 (Vector<Student1>& stud, Vector<Student1>& nuskriaustukai, string filename) {
    string name = "studentai" + std::to_string(stud.get_size()) + ".txt";
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    nuskriaustukai.reserve(stud.get_size());
    
    while (stud.back().getResult() < 5.00) {
        nuskriaustukai.push_back(stud.back());
        stud.pop_back();
    }

    nuskriaustukai.shrink_to_fit();
    stud.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    std::cout << "Dividing file "<<filename<<" was successful. Took: "<< diff.count() << " s"<<std::endl;
    //print_metrics(filename, diff.count(), 0, 0);
}

void divide_file3(Vector<Student1>& stud, Vector<Student1>& nuskriaustukai, string filename) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Partition the students based on the result
    auto partition_point = std::stable_partition(stud.begin(), stud.end(), [](const Student1& s) { return s.getResult() >= 5.0; });
    //print_marks(stud);
    std::cout<<partition_point<<std::endl;
    std::cout<<stud.end()<<std::endl;
    
    // Move the failing students to nuskriaustukai
    nuskriaustukai = Vector<Student1>(std::make_move_iterator(partition_point), std::make_move_iterator(stud.end()));

    stud.erase(partition_point, stud.end());
    
    // Shrink to fit
    nuskriaustukai.shrink_to_fit();
    stud.shrink_to_fit();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Dividing file " << filename << " was successful. Took: " << diff.count() << " s" << std::endl;
    print_metrics(filename, diff.count(), 0,3);
}

void pagrindinis_divide (Vector<Student1> &stud, Vector<Student1> &kietiakai, Vector<Student1> &nuskriaustukai, int num) {
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
        std::cout<<endl<< "Sorting kietiakai:"<<endl;
        sort_students(kietiakai);
        std::cout<< "Sorting nuskriaustukai:"<<endl;
        sort_students(nuskriaustukai);
        */
        
        if (num == 1) write_marks(kietiakai, "studentai"+std::to_string(file_size[i])+"_kietiakai.txt");
        else {
            //write_marks(stud, "studentai"+std::to_string(file_size[i])+"_kietiakai.txt");
            //write_marks(nuskriaustukai, "studentai"+std::to_string(file_size[i])+"_nuskriaustukai.txt");
        }
        
        stud.clear();
        nuskriaustukai.clear();
        
        std::cout <<"==================================================================="<<std::endl;
        std::cout << "| Processed file "<< std::setw(30)<< std::left<<filename<<" Took: "<< std::setprecision(3)<<std::setw(5) <<std::left<<diff.count() << " s |"<<std::endl;
        std::cout <<"==================================================================="<<std::endl<<std::endl;
        print_metrics(filename, diff.count(), 1, num);
    }
}

void pagrindinis_divide_choice(Vector<Student1> &stud) {
    Vector<Student1> nuskriaustukai, kietiakai;
    std::cout << R"(Select:
1) Pirma strategija
2) Antra strategija
3) Trečia strategija
--> )";
            char pasirinkimas;
            std::cin >> pasirinkimas;
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
                        std::cout << "Klaida. Neteisingas pasirinkimas!";
                    }
                }                 
            } 
}

void sort_file (Vector<Student1>& stud, string name) {
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    std::sort(stud.begin(), stud.end(), [](const Student1& a, const Student1& b) {return a.getResult() > b.getResult();});    
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    std::cout << "Sorting file "<<name<<" was successful. Took: "<< diff.count() << " s"<<std::endl;
    //print_metrics(name, diff.count(), 0);
}

void rule_of_five() {
    char choice2;
std::cout << R"(Select:
1) Copy Constructor
2) Copy Assignment Operator
3) Move Constructor
4) Move Assignment Operator
--> )"; 

        std::cin >> choice2;
            switch (choice2) {
                while (true) {
                      
                    case '1': {
                        std::cout <<"Creating student a"<<std::endl;
                        Student1 a ("Tomas", "Tomaitis",10,vector<int>{1,2,3});
                        std::cout <<"a: "<<a<<std::endl;
                        std::cout <<"Creating student b, so that b = a"<<std::endl;
                        Student1 b (a);
                        std::cout <<"b: "<<b<<std::endl;
                        break;
                    }

                    case '2': {
                        std::cout <<"Creating student a"<<std::endl;
                        Student1 a ("Kostas", "Kostaitis",9,vector<int>{10,10,10});
                        std::cout <<"a: "<<a<<std::endl;
                        std::cout <<"Creating student b"<<std::endl;
                        Student1 b;
                        std::cout <<"b: "<<b<<std::endl;
                        std::cout <<"Now let's use operator '=' to make b = a "<<std::endl<<std::endl;
                        b = a;
                        std::cout << "b: " <<b<<std::endl;
                        std::cout << "let's try b = b:" << std::endl;  
                        b = b;
                        break;
                    }

                    // konstruktorius nepatinkrintas blogai padaryta
                    case '3': {
                        std::cout <<"Creating student a"<<std::endl;
                        Student1 a ("Genute", "Genutaite",2,vector<int>{1});
                        std::cout <<"a: "<<a<<std::endl;
                        std::cout <<"Creating student b with move constructor:"<<std::endl<<std::endl;
                        Student1 b (std::move(a));
                        std::cout <<"b: "<<b<<std::endl;
                        std::cout <<"Now let's check a"<<std::endl<<std::endl;
                        std::cout <<"a: "<<a<<std::endl;
                        break;
                    }

                    case '4': {
                        std::cout <<"Creating student a"<<std::endl;
                        Student1 a ("Mykolas", "Mykolaitis",2,vector<int>{3,3});
                        std::cout <<"a: "<<a<<std::endl;
                        std::cout <<"Creating student b"<<std::endl;
                        Student1 b;
                        std::cout <<"b: "<<b<<std::endl;
                        std::cout <<"Now let's use operator '=' to move from a to b "<<std::endl<<std::endl;
                        b = std::move(a);
                        std::cout <<"b: "<<b<<std::endl;
                        std::cout <<"Now let's check a"<<std::endl<<std::endl;
                        std::cout <<"a: "<<a<<std::endl<<std::endl;
                        break;
                    }

                    default: {
                        std::cout << "\n\nInvalid choice. Please try again.\n";
                        continue;
                    }
                }
            }
        
}

void print_metrics (string filename, float data, int num, int strategija) {
    string const type = "vector";
    std::ofstream out;
    
    std::string command = "mkdir -p data";
    system(command.c_str());
    string name = "data/"+std::to_string(strategija)+"."+extractNumbers(filename)+"."+type+".txt";
    
    out.open(name, std::fstream::app);
    //out<<"container type: "<<type<<endl;
    out <<"|" <<data;
    if (num == 1) out <<"|"<< std::endl;
}

int lineCount (string filename) {
    std::ifstream in (filename);
    string temp;
    int count = 0;
    while (getline(in, temp)) {
        count++;
    }
    return count;

}

string extractNumbers(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (std::isdigit(ch)) {
            result += ch;
        }
    }
    return result;
}

void compare_vectors() {
    std::vector<int> size {10000,100000,1000000,10000000,100000000};

    std::vector<int> v1;
    Vector<int> v2;

    for (int i = 0; i <size.size(); i++) {
        std::cout<< std::setw(10) << std::left<<"<<---------Size: "<<size[i]<<"--------->>"<<std::endl;

        auto start = std::chrono::steady_clock::now();
        for (int j = 1; j <= size[i]; ++j) {
            v1.push_back(j);
            //if (v1.size() == v1.capacity()) std::cout<<v1.capacity()<<std::endl;
        }
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
        v1.clear();

        auto start1 = std::chrono::steady_clock::now();
        for (int j = 1; j <= size[i]; ++j) {
            v2.push_back(j);
            //if (v2.get_size() == v2.get_capacity()) std::cout<<v2.get_capacity()<<std::endl;   
        }
        auto end1 = std::chrono::steady_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
        std::cout << "Elapsed time (custom): " << duration1.count() << " ms" << std::endl;
        std::cout << "Difference: " << duration.count()-duration1.count() << " ms" << std::endl << std::endl;

       
        v2.clear();
    }
}
