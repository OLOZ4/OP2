#include <cstddef>
#include <iostream>
#include <limits>

template <typename T>
class Vector {
    private:
        T* data;
        size_t size;
        size_t capacity;

        void resize(size_t new_size) {
            if (new_size <= size) {
                return; // Tik sumazinti dydi aij bbz kas cia zodziu palikt vietoj
            } 
            else {
                reserve(new_size); // Rezervuoja vieta jeigu reikia
                for (size_t i = size; i < new_size; ++i)
                    data[i] = T(); // Naudoja default konstruktoriu naujiems objektams
                size = new_size;
            }
        }

    public:
        //-------Member-funkcijos----------//
        
        // Konstruktorius
        Vector() : data(nullptr), size(0), capacity(0) {}//std::cout << "Iskviestas konstruktorius"<< std::endl;}

        // Konstruktorius su nustatytu dydziu 
        explicit Vector(size_t initial_capacity) : data(new T[initial_capacity]), size(0), capacity(initial_capacity) {}//std::cout << "Iskviestas konstruktorius"<< std::endl;}

        // Konstruktorius su aibe
        Vector(std::initializer_list<T> list) : size(list.size()) {
            data = new T[size];
            size_t i = 0;
            for (const auto& elem : list) {
                data[i++] = elem;
            }
        }

        // Move konstruktorius
        Vector(Vector&& other) noexcept
         : data(other.data), size(other.size), capacity(other.capacity) {
                other.data = nullptr;
                other.size = 0;
                other.capacity = 0;
            }
        
        // Copy konstruktorius
        Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }

        // Destruktorius
        ~Vector() {
            delete[] data;
            //std::cout<< "Iskviestas destruktorius"<< std::endl;
        }

        // Copy asignment
        // operatorius= pvz b = a
        Vector& operator=(const Vector& other) {
            if (this != &other) { 
                delete[] data;
                size = other.size;
                capacity = other.capacity;
                data = new T[capacity];
                for (size_t i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
                

            }
            return *this;
        }

        // Move asignment
        // operatorius= pvz b = std::move(a)
        Vector& operator=(Vector&& other) {
            if (this != &other) {
                delete[] data;
        
                data = other.data;
                size = other.size;
                capacity = other.capacity;
        
                other.data = nullptr;
                other.size = 0;
                other.capacity = 0;
                
            }
            return *this;
        }

        // Konstruktorius is dvieju operatoriu ar pointeriu
        template<typename input>
        Vector(input first, input last) {
            size = std::distance(first, last);
            capacity = size;
            data = new T[capacity];
            size_t i = 0;
            for (auto it = first; it != last; ++it, ++i) {
                data[i] = *it;
            }
        }

        //--------ELEMENT-ACCESS----------------//

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
        
        //--------ITERATORS-----------//

        // Pradzia
        T* begin() {
            return data;
        }

        // Pabaiga
        T* end() {
            return data+size;
        }

        //  R Pradzia
        T* rbegin() {
            return data+size-1;
        }

        // R Pabaiga
        T* rend() {
            return data-1;
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
            if (new_capacity <= capacity) return;
            // Grow at least double to avoid frequent allocations
            size_t new_cap = (capacity == 0) ? 1 : capacity;
            while (new_cap < new_capacity) new_cap *= 2;
            T* new_data = new T[new_cap];
            for (size_t i = 0; i < size; ++i)
                new_data[i] = data[i];
            delete[] data;
            data = new_data;
            capacity = new_cap;
        }

        // Sushrinkinti capacity
        void shrink_to_fit() {
            if (capacity > size) {
                resize(size);
            }
        }
        
        // Max dydis
        size_t max_size() const {
            return std::numeric_limits<size_t>::max() / sizeof(T);
        }
        
        //---------Modifiers-----------//

        // Isvalyti vektoriu
        void clear() {//?
            //delete[] data;
            //data = nullptr;
            size = 0;
            //capacity = 0;
        }

        // Ideti elementa x i y vieta
        void insert(size_t index, const T& value) {
            if (index > size) {
                throw std::out_of_range("Insert index out of range");
            }
    
            if (size == capacity) {
                reserve(capacity == 0 ? 1 : capacity * 2);
            }

            for (size_t i = size; i > index; --i) {
                data[i] = data[i - 1];
            }
            data[index] = value;
            ++size;
        }

        // Ideti x kopiju y elemento pries z vieta
        void insert(size_t index, size_t count, const T& value) {
            if (index > size) {
                throw std::out_of_range("Insert index out of range");
            }
    
            if (size == capacity) {
                reserve(capacity == 0 ? 1 : capacity * 2);
            }

            // Visus egzistuojancius elementus perkelia i desine
            for (size_t i = size; i > index; --i) {
                data[i + count - 1] = data[i - 1];
            }
            // I senas vietas ideda naujus elementus
            for (size_t i = 0; i < count; ++i) {
                data[index + i] = value;
            }
            size += count;
        }

        // Prideti elementa i gala
        void push_back(const T& value) {
            if (size == capacity) {
                reserve(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = value;
            //size++;
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
        T*erase(T* first, T* last) {
            //
            //
            //std::cout << "Erase from index: " << (first - data) << " to index: " << (last - data) << " (size=" << size << ")" << std::endl;
            //
            // Bounds check (optional, but for debugging it's helpful)
            if (first < data || last > data + size || first > last) {
                throw std::out_of_range("Invalid erase range");
            }
        
            size_t erase_count = last - first;
            if (erase_count == 0) return first;
        
            // Move trailing elements forward
            for (T* it = first; last != data + size; ++it, ++last) {
                *it = std::move(*last);
            }
        
            size -= erase_count;
            return first;
        }

        //--------------------------//

    };