#include "header.h"
//#include "student.hpp"
bool isValid ( string number ) {
    try {
        int mark = stoi(number);
        if (mark >= 0 && mark <= 10) return true;
        else {
            cout <<"Klaida, iveskite teisinga pazymi! "<<endl;       
            return false;
        } 
    }
    catch (const std::invalid_argument&) {
        cout <<"Klaida, iveskite teisinga pazymi! "<<endl;
        return false;
    }    
}

bool isValid ( int number ) {
    int mark = number;
    if (mark >= 0 && mark <= 10) return true;
    else return false;
}

int randomNumber (int a, int b) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> num(a,b);
    return num(rng);
}

void readFile(vector<string>& name) {
    std::ifstream in("../vardai.txt");
    if (!in.is_open()) {
        cerr << "Failed to open file." << std::endl;
        return;
    }

    while (!in.eof()) {
        string line;
        in >> line;
        name.push_back(line);
    }
}
string get_name(vector <string> name) { 
    return name[randomNumber(1, name.size())];
}

int lineCount (string filename) {
    ifstream in (filename);
    string temp;
    int count = 0;
    while (getline(in, temp)) {
        count++;
    }
    return count;

}
/*
void count_marks (vector<Student>& stud) {
    for (int i = 0; i < stud.size(); i++) {
        double sum = 0;
        for (int j = 0; j < stud[i].mark.size(); j++) {
        sum += stud[i].mark[j];
        }
        double med{};
        std::sort(stud[i].mark.begin(), stud[i].mark.end());
        if ((stud[i].mark.size()-1) % 2 != 0) {
            med = stud[i].mark[stud[i].mark.size()/2.0];
        }
        else {
        med = (stud[i].mark[(stud[i].mark.size()-1)/2.0] + stud[i].mark[stud[i].mark.size()/2.0]) / 2.0;
        }
        stud[i].median = 0.4*med+0.6*stud[i].exam;
        stud[i].result = 0.4*(sum/stud[i].mark.size())+0.6*stud[i].exam;
    }
}

*/


vector<string> listTxtFiles() {
  std::vector<std::string> txtFiles;
  for (const auto& entry : std::filesystem::directory_iterator("../studentai/")) {
    if (entry.is_regular_file() && entry.path().extension() == ".txt") {
      txtFiles.push_back(entry.path().filename().string());
    }
  }
  return txtFiles;
}



void generate_file (int number) {

    int g = 15;
    int counter = 0;
    int mark_count = randomNumber(2, 10);

    auto start = std::chrono::high_resolution_clock::now(); // Paleisti

    string namefile = "studentai" + std::to_string(number) + ".txt";
    std::ofstream out (namefile );
    out  << setw(g) << left<< "Vardas"<< setw(g) << right<< "Pavardė";
    for (int i = 1; i < mark_count+1; i++) {
        out << setw(g) << right<< "ND";
        out <<i;  
    }
    out << setw(g) << right<< "Egz."<<endl;

    for (int j = 0; j < number; j++) {
        out <<"Vardas";
        out <<  setw(g) <<left << j;
        out << "Pavarde";
        out  <<  setw(g) <<left << j;
        for (int z = 0; z < mark_count+1; z++) {
            out << setw(g) << left << randomNumber(0,10);
        }
        out << endl;
    }
    out.close();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Generating file "<<namefile<<" was successful. Took: "<< diff.count() << " s"<<endl;
    std::ofstream outt;
    outt.open("data.txt", std::fstream::app);
    outt << namefile << " "<<diff.count()<<endl;
    outt.close();
}

/*
// tikrai galima geriau, bet kaip? kazakda reikes pasidometi.
void divide_file (vector<Student>& stud,vector<Student>& nuskriaustukai, string filename) {
    string name = "studentai" + std::to_string(stud.size()) + ".txt";
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    nuskriaustukai.reserve(stud.size());
    
    while (stud.back().result < 5.00) {
        nuskriaustukai.push_back(stud.back());
        stud.pop_back();
    }
    
    //while (stud.size() != 0) {
    //    nuskriaustukai.push_back(stud.back());
    //   stud.pop_back();
    //}
    
    nuskriaustukai.shrink_to_fit();
    stud.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Dividing file "<<filename<<" was successful. Took: "<< diff.count() << " s"<<endl;
    print_metrics(filename, diff.count(), 0);
}
*/





void print_metrics (string filename, float data, int num, int strategija) {
    string const type = "vector";
    std::ofstream out;
    
    std::string command = "mkdir -p data";
    system(command.c_str());
    string name = "data/"+std::to_string(strategija)+"."+extractNumbers(filename)+"."+type+".txt";
    
    out.open(name, std::fstream::app);
    //out<<"container type: "<<type<<endl;
    out <<"|" <<data;
    if (num == 1) out <<"|"<< endl;
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

