#include <string>

class Human {
    protected:

    std::string vardas;
    std::string pavarde;

    public:

    // Default constructor
    Human() : vardas(""), pavarde("") {}

    // Parameterized constructor
    Human(const std::string& v, const std::string& p) : vardas(v), pavarde(p) {}

    
    // virtualus destruktorius
    virtual ~Human() {
        //std::cout << "Virtual destructor Human was called"<<std::endl;
    }

    // Copy assignment operator
    Human& operator=(const Human& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
        }
        return *this;
    }

    //virtualus setteriai
    virtual void setVardas(std::string vardas_) = 0;

    virtual void setPavarde(std::string pavarde_) = 0;

    //virtualus getteriai
    virtual std::string getVardas() const = 0;
 
    virtual std::string getPavarde() const = 0;
};