//#include "header.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Student1 {

    private:
        string vardas;
        string pavarde;
        int egzaminas;
        vector<int> mark;
    public:

    // konstruktorius
    Student1(string v ="Default", string p = "Default", int e = 0, vector<int> m = {}) : vardas(v), pavarde(p), egzaminas(e), mark(m) {}
    
    // destruktorius
    ~Student1() {
        //cout << "Destructor for student "<<vardas<<" was called"<<endl;
        mark.clear();
    }

    //setteriai

    void setVardas(string vardas_);

    void setPavarde(string pavarde_);

    void setEgzaminas(int egzaminas_);

    void setMark(vector<int> mark_);

    // getteriai

    string getVardas() const {
        return vardas;
    }

    string getPavarde() const {
        return pavarde;
    }

    int getEgzaminas() const {
        return egzaminas;
    }

    vector<int> getMark() const {
        return mark;
    }

    float getMedian() const;

    float getResult() const;

    void GenerateNames();

};

void print(vector<Student1> &stud);

void import_file (vector<Student1> &stud, string filename);

void sort_students (vector<Student1>& stud);

void print_marks (vector<Student1> stud);

void write_marks (vector<Student1> stud, string name);

void divide_file1 (vector<Student1>& stud,vector<Student1>& kietiakai,vector<Student1>& nuskriaustukai, string filename);

void divide_file2 (vector<Student1>& stud,vector<Student1>& nuskriaustukai, string filename);

void divide_file3 (vector<Student1>& stud,vector<Student1>& nuskriaustukai, string filename);

void pagrindinis_divide (vector<Student1>& stud,vector<Student1>& kietiakai,vector<Student1>& nuskriaustukai, int num);

void sort_file (vector<Student1>& stud, string name);
