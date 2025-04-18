#include <string>
class Human {
    protected:

    std::string vardas;
    std::string pavarde;

    public:

    // virtualus destruktorius
    virtual ~Human() {
        //std::cout << "Virtual destructor Human was called"<<std::endl;
    }

    //virtualus setteriai
    virtual void setVardas(std::string vardas_) = 0;

    virtual void setPavarde(std::string pavarde_) = 0;

    //virtualus getteriai
    virtual std::string getVardas() const = 0;
 
    virtual std::string getPavarde() const = 0;
};