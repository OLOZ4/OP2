#include <iostream>
#include <ostream>

#include "vector.hpp"
int main() {
    vector<int> test {4};
    vector<int> test1;
    test.push_back(1);
    test.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    vector<int>test3;
    //int* it = test1.begin();
    //std::cout<<*it<<std::endl;

    std::cout<<test3.max_size()<<std::endl;
    //std::cout<<test.get_capacity()<<std::endl;
    //test.reserve(1000000000);
    //std::cout<<test.get_capacity()<<std::endl;
    //test.clear();
    //test.shrink_to_fit();
    //std::cout<<test.get_capacity()<<std::endl;
    //while (test.empty()!= true) {
        //std::cout<<test.get_size()<<std::endl;
        //test.pop_back();
    //}

    //std::cout << test.front() << std::endl;
    //std::cout << test.back() << std::endl;
    //if (test1.empty()) std::cout <<"Vektorius tuscias"<<std::endl;
    //else std::cout <<"Vektorius NEtuscias"<<std::endl;
    
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
}