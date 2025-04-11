//#include "header.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

using std::string;
using std::vector;



class Student1 {

    private:
        string vardas;
        string pavarde;
        int egzaminas;
        vector<int> mark;
    public:

    // konstruktorius
    Student1(string v ="Default", string p = "Default", int e = 0, vector<int> m = {0}) : vardas(v), pavarde(p), egzaminas(e), mark(m) {std::cout << "Iskviestas Konstruktorius studentui " << v <<std::endl;}
    
    // destruktorius
    ~Student1() {
        std::cout << "Iskviestas Destruktorius studentui "<<vardas<<std::endl;
        mark.clear();
    }

    // copy konstruktorius
    //Student1 (const Student1 &other) : Student1(other.vardas, other.pavarde, other.egzaminas, other.mark) { // kodel jei cia parasau : Student1 vardas = other.vardas....
    Student1 (const Student1 &other) { // kodel jei cia parasau : Student1 vardas = other.vardas....
        vardas = other.vardas;
        pavarde = other.pavarde;
        egzaminas = other.egzaminas;
        mark = other.mark;
        std::cout<<"Iskviestas Copy Konstruktorius studentui "<<vardas<<std::endl;
    }

    // copy assignment
    Student1& operator=(const Student1 &other) {
        if (this != &other) { // Patikrinti ar ne self-asigninama
            vardas = other.vardas;
            pavarde = other.pavarde;
            egzaminas = other.egzaminas;
            mark = other.mark;
        }
        else std::cout <<"Self-assignment, skipping"<<std::endl;
        std::cout<<"Iskviestas Copy Assignmentas studentui "<<vardas<<std::endl;
        return *this;
    }

    //move konstruktorius
    Student1(Student1&& other) noexcept : Student1(other.vardas ,other.pavarde, other.egzaminas, other.mark) {
        other = Student1();
        std::cout<<"Iskviestas Move Konstruktorius studentui "<<vardas<<std::endl;
    }

    // move assignment
    Student1& operator=(Student1&& other) noexcept {
        if (this != &other) { // Patikrinti ar ne self-moving
            vardas = other.vardas;
            pavarde = other.pavarde;
            egzaminas = other.egzaminas;
            mark = other.mark;
            
            other.vardas = "Default";
            other.pavarde = "Default";
            other.egzaminas = 0;
            other.mark = {0};
        }
        else std::cout <<"Self-moving, skipping"<<std::endl;
        std::cout<<"Iskviestas Move Assignmentas studentui "<<vardas<<std::endl;
        return *this;
    }

    // setteriai

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

    friend std::ostream& operator<<(std::ostream& os, const Student1& stud) {
    os << "Vardas: " << stud.getVardas() << " || Pavarde: "<< stud.pavarde<<" || Rezultatas: "<< stud.getResult()<<std::endl;
    return os;
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
