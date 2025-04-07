#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <filesystem>
#include <ios>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::vector;
using std::ifstream;
using std::cerr;
using std::left;
using std::right;

struct Student {
    string name{};
    string surname{};
    int exam{};
    vector<int> mark{};
    double result;
    double median;
};

bool isValid ( string number );

bool isValid ( int number );

int randomNumber (int a, int b);

void readFile(vector<string>& name);

string get_name(vector <string> name);

int lineCount (string filename);

void count_marks (vector<Student>& stud);

void print_marks (vector<Student> stud);

void write_marks (vector<Student> stud, string name);

vector<string> listTxtFiles();

void import_file (vector<Student>& stud, string filename);

void generate_file (int number);

void sort_file (vector<Student>& stud, string name);

void divide_file1 (vector<Student>& stud,vector<Student>& kietiakai,vector<Student>& nuskriaustukai, string filename);

void divide_file2 (vector<Student>& stud,vector<Student>& nuskriaustukai, string filename);

void divide_file3 (vector<Student>& stud,vector<Student>& nuskriaustukai, string filename);

void pagrindinis_divide (vector<Student>& stud,vector<Student>& kietiakai,vector<Student>& nuskriaustukai, int num);

void sort_students (vector<Student>& stud);

void print_metrics (string filename, float data, int num, int strategija);

string extractNumbers(const std::string& str);