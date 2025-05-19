#include <iomanip>
#include <ios>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include "../program/human.hpp"
#include "vector.hpp"

using std::string;
using std::vector;


class Student1 : private Human {

    private:
        //string vardas;
        //string pavarde;
        int egzaminas;
        vector<int> mark;
    public:

    // konstruktorius
    Student1(string v = "Default", string p = "Default", int e = 0, vector<int> m = {0}) :  egzaminas(e), mark(m) {
        //std::cout << "Iskviestas Konstruktorius studentui " << v <<std::endl;
        vardas = v;
        pavarde = p;
    }
    
    // destruktorius
    ~Student1() {
        //std::cout << "Iskviestas Destruktorius studentui "<<vardas<<std::endl;
        mark.clear();
    }

    // copy konstruktorius
    //Student1 (const Student1 &other) : Student1(other.vardas, other.pavarde, other.egzaminas, other.mark) { // kodel jei cia parasau : Student1 vardas = other.vardas....
    Student1 (const Student1 &other) { // kodel jei cia parasau : Student1 vardas = other.vardas....
        vardas = other.vardas;
        pavarde = other.pavarde;
        egzaminas = other.egzaminas;
        mark = other.mark;
        //std::cout<<"Iskviestas Copy Konstruktorius studentui "<<vardas<<std::endl;
    }

    // copy assignment
    Student1& operator=(const Student1 &other) {
        if (this != &other) { // Patikrinti ar ne self-asigninama
            //std::cout << "Assigning vardas, this: " << this << ", other: " << &other << std::endl;
            vardas = other.vardas;
            //std::cout << "Assigning pavarde" << std::endl;
            pavarde = other.pavarde;
            //std::cout << "Assigning egzaminas" << std::endl;
            egzaminas = other.egzaminas;
            //std::cout << "Assigning mark" << std::endl;
            mark = other.mark;
        }
        else std::cout << "Self-assignment, skipping" <<std::endl;
        //std::cout << "Iskviestas Copy Assignmentas studentui " << vardas <<std::endl;
        return *this;
    }

    //move konstruktorius
    //Student1(Student1&& other) noexcept : Student1(other.vardas ,other.pavarde, other.egzaminas, other.mark) {
        //other = Student1();
        //std::cout << "Iskviestas Move Konstruktorius studentui " << vardas << std::endl;
    //}

    Student1(Student1&& other) noexcept : 
    Human(std::move(other.vardas), std::move(other.pavarde)), // Move base class members
      egzaminas(other.egzaminas),
      mark(std::move(other.mark)) {
    // Reset the moved-from object
    other.vardas = "Default";
    other.pavarde = "Default";
    other.egzaminas = 0;
    other.mark = {0};
    //std::cout << "Iskviestas Move Konstruktorius studentui " << vardas << std::endl;
}

    // move assignment
    /*
    Student1& operator=(Student1&& other) noexcept {
        if (this != &other) { // Patikrinti ar ne self-moving
            vardas = other.vardas;
            pavarde = other.pavarde;
            egzaminas = other.egzaminas;
            mark = other.mark;

            other = Student1();
        }
        else std::cout <<"Self-moving, skipping"<<std::endl;
        //std::cout<<"Iskviestas Move Assignmentas studentui "<<vardas<<std::endl;
        return *this;
    }
    */

    Student1& operator=(Student1&& other) noexcept {
        if (this != &other) { // Avoid self-move
            // Move base class members
            Human::operator=(std::move(other));
    
            // Move member variables
            egzaminas = other.egzaminas;
            mark = std::move(other.mark);
    
            // Reset the moved-from object
            other.vardas = "Default";
            other.pavarde = "Default";
            other.egzaminas = 0;
            other.mark = {0};
            
        }
        //std::cout<<"Iskviestas Move Assignmentas studentui "<<vardas<<std::endl;
        return *this;
    }

    // Equality operator
    bool operator==(const Student1& other) const {
        return (vardas == other.vardas &&
                pavarde == other.pavarde &&
                egzaminas == other.egzaminas &&
                mark == other.mark);
    }
    
    // setteriai

    void setVardas (string vardas_) override;

    void setPavarde(string pavarde_) override;

    void setEgzaminas(int egzaminas_);

    void setMark(vector<int> mark_);

    // getteriai

    string getVardas() const override {
        return vardas;
    }

    string getPavarde() const override {
        return pavarde;
    }

    int getEgzaminas() const {
        return egzaminas;
    }

    vector<int> getMark() const {
        return mark;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Student1& stud) {
        int g = 20;
        os << std::setw(g) << std::left << stud.getVardas() 
        << std::setw(g) << std::left << stud.getPavarde() 
        << std::setw(g) << std::left << std::setprecision(3) 
        << stud.getResult() << std::setw(g) << std::left 
        << std::setprecision(3) << stud.getMedian() << std::endl;
        return os;
    }
    
    // ifstreama dar padaryt
    friend std::ifstream& operator>>(std::ifstream& in, Student1& stud) {
        std::string temp;
        std::getline(in, temp); // Read the entire line
        //std::cout << "nuskaitoma eilute \n" << std::endl;

        if (temp.empty()) return in; // Skip empty lines
        
        string random;
        std::istringstream stream(temp); // Convert the line into a string stream
        //std::cout << "konvertuojama i string stream \n" << std::endl;

        stream >> stud.vardas >> stud.pavarde;

        //std::cout << "ivesta vardas ir pavarde" << std::endl;
        //std::cout << stud.getPavarde() << " " << stud.getPavarde() << "\n";
        
        int marks;
        stud.mark.clear(); // Clear marks vector
        while (stream >> marks) {
            stud.mark.push_back(marks);
            //std::cout << "ivestas pazymys \n" << std::endl;

        }
        
        if (!stud.mark.empty()) {
            stud.egzaminas = stud.mark.back();
            stud.mark.pop_back();
        } else {
            stud.egzaminas = 0; // Default value if no marks are provided
        }
        //std::cout << "ivestas egzaminas \n" << std::endl;

        

        return in;
    }

    friend std::istream& operator>>(std::istream& is, Student1& stud) {
        std::string egzaminas, mark_temp;
        vector<int> mark {};

        std::cout << "Enter name: ";
        is >> stud.vardas;

        std::cout << "Enter surname: ";
        is >> stud.pavarde;

        while (true) {
            std::cout << "Enter exam mark (0-10): ";
            std::cin >> egzaminas;
            if (std::stoi(egzaminas) >= 0 && std::stoi(egzaminas) <= 10) {
                stud.egzaminas = std::stoi(egzaminas); 
                break;
            }
        }

        while (true) {
            std::cout << "Enter a mark (or 'q' to quit): ";
            std::cin >> mark_temp;

            if (mark_temp == "q") {
                stud.mark = mark;
                mark.clear();
                system("clear");
                break;
            }

            if (std::stoi(mark_temp) >= 0 && std::stoi(mark_temp) <= 10) {
                mark.push_back(std::stoi(mark_temp));
            }
        }

        return is;
    }

    float getMedian() const;

    float getResult() const;

    void GenerateNames();

};

void print(vector<Student1> &stud);

void import_file (Vector<Student1> &stud, string filename);

void sort_students (Vector<Student1>& stud);

void choose_printing_method (Vector<Student1>& stud);

void print_marks (Vector<Student1> stud);

void write_marks (Vector<Student1> stud, string name);

void divide_file1 (Vector<Student1>& stud,Vector<Student1>& kietiakai,Vector<Student1>& nuskriaustukai, string filename);

void divide_file2 (Vector<Student1>& stud,Vector<Student1>& nuskriaustukai, string filename);

void divide_file3 (Vector<Student1>& stud,Vector<Student1>& nuskriaustukai, string filename);

void pagrindinis_divide (Vector<Student1>& stud,Vector<Student1>& kietiakai,Vector<Student1>& nuskriaustukai, int num);

void pagrindinis_divide_choice(Vector<Student1>& stud);

void sort_file (Vector<Student1>& stud, string name);

void rule_of_five();

void print_metrics (string filename, float data, int num, int strategija);

int lineCount (string filename);

string extractNumbers(const std::string& str);

void compare_vectors();
