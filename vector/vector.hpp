#include <cstddef>
#include <iostream>
#include <ostream>

template <typename T>
class vector {
    private:
        T* data;
        size_t size;
        size_t capacity;

        void resize (size_t new_capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }

    public:
        // Konstruktorius
        vector() : data(nullptr), size(0), capacity(0) {std::cout << "Iskviestas konstruktorius"<< std::endl;}

        // Konstruktorius su nustatytu dydziu 
        explicit vector(size_t initial_capacity) : data(new T[initial_capacity]), size(0), capacity(initial_capacity) {std::cout << "Iskviestas konstruktorius"<< std::endl;}

        // Destrukorius
        ~vector() {
            delete[] data;
            std::cout<< "Iskviestas destruktorius"<< std::endl;
        }

        //--------ELEMENT ACCESS----------------//

        // Pasiekti elementa su patikrinimu 
        T& at(size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // Pasiekti elementa per indeksa
        T& operator[](size_t index) {
            return data[index];
        }

        // Paimti pirma elementa
        T& front() {
            return data[0];
        }
        
        // Pasiekti paskutini elementa
        T& back() {
            return data[size-1];
        }
        
        //--------CAPACITY-----------//
        
        // Gauti size
        size_t get_size() const {
            return size;
        }

        // Gauti capacity
        size_t get_capacity() const {
            return capacity;
        }

        // Patikrinti ar vektorius tuscias
        bool empty() const {
            if (size == 0) return true;
            else return false;
        }

        // Rezervuoti vieta atmintyje
        void reserve(size_t new_capacity) {
            if (new_capacity > capacity) resize(new_capacity);
        }

        // Sushrinkinti capacity
        void shrink_to_fit() {
            resize(size);
        }
        
        //---------Modifiers-----------//

        // Isvalyti vektoriu
        void clear() {
            for (size_t i = 0; i < size; ++i) {
                data[i].~T(); // Iskvieciamas destruktorius kiekvienam vektoriui
            }
            size = 0;
        }

        // Prideti elementa i gala
        void push_back(const T& value) {
            if (size == capacity) {
                resize(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = value;
        }

        // Istrinti elementa is galo
        void pop_back() {
            if (size == 0) {
                throw std::out_of_range("Index out of range");
            }
            data[size-1].~T(); // Iskviesti destruktoriu paskutiniam elementui(?)
            --size;

        }

        // Istrinti elementa is pasirinktos vietos
        void erase(size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = data[i+1];
            }

            --size;
        }

        // Istrinti elementu aibe is pasirinktos vietos 
        void erase(size_t first, size_t last) {
            if (first >= size || last > size || first >= last) {
                throw std::out_of_range("Invalid range for erase");
            }
            size_t count = last - first;

            for (size_t i = first; i < size - count; ++i) {
                data[i] = data[i + count];
            }

            size -= count;
        }

        //--------------------------//

    };