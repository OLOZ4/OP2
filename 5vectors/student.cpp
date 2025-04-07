#include "student.hpp"
#include "functions.cpp"
#include <algorithm>
#include <vector>

float Student1::getMedian()  {
    double med{};
    std::sort(mark.begin(), mark.end());
    if ((mark.size()-1) % 2 != 0) med = mark[mark.size()/2.0];
    else med = (mark[(mark.size()-1)/2.0] + mark[mark.size()/2.0])/2;
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
    //mark.push_back(mark_);
}
/*
void Student1::GenerateNames() {
    vardas = get_name(name);
    pavarde = get_name(name)
}
*/