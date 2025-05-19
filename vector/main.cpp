#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <chrono>
#include <string>

#include "vector.hpp"
int main() {
    //vector<int> test {4};
    Vector<int> test1;
    std::vector<int> test2;
    std::cout<<test1.end()<<std::endl;
    std::cout<<std::to_string(test2.end())<<std::endl;
    //test.push_back(1);
    //test.push_back(2);
    //test1.push_back(3);
    //test1.push_back(4);
    //vector<int>test3;
    //int* it = test1.begin();
    //std::cout<<*it<<std::endl;

    //std::cout<<test3.max_size()<<std::endl;
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
    
    //std::cout << "" << std::endl;
    //std::cout << "" << std::endl;
    //std::cout << "" << std::endl;
    //std::cout << "" << std::endl;

    /*
    unsigned int sz = 1000000;
    std::vector<int> v1;

    auto start = std::chrono::steady_clock::now();

    for (int i = 1; i <= sz; ++i) {
       v1.push_back(i);
       if (v1.size() == v1.capacity()) {
        std::cout<<v1.size()<<std::endl;
       } 
    }

    
    auto end = std::chrono::steady_clock::now();

    // Calculate elapsed time in milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;

    Vector<int> v2;

    auto start1 = std::chrono::steady_clock::now();

    for (int i = 1; i <= sz; ++i) {
        v2.push_back(i);
        if (v2.get_size() == v2.get_capacity()) {
         std::cout<<v2.get_size()<<std::endl;
        } 
     }

    
    auto end1 = std::chrono::steady_clock::now();

    // Calculate elapsed time in milliseconds

    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

    std::cout << "Elapsed time (custom): " << duration1.count() << " ms" << std::endl;

    */
}
