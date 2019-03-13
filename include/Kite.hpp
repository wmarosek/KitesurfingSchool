#ifndef Kite_hpp
#define Kite_hpp
#include <string>

using std::string;

class Kite
{
  private:
    int id;
    string brand;
    int size;

  public:
    //Constructor and destructor
    Kite(int id, string brand, int size);
    ~Kite();

    //Getters and setters
    int getId() const;
    void setSize(int size);
    int getSize();
    void setBrand(string brand);
    string getBrand();
    
    friend std::ostream& operator<<(std::ostream &os, const Kite &k);
    bool operator==(const Kite &k) const;
    bool operator<(const Kite &a) const;
};

#endif