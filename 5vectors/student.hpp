//#include "header.h"
#include <string>
#include <vector>

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
    ~Student1(){}

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

    float getMedian();

    float getResult() const;

    void GenerateNames();

};