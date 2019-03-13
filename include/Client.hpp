#ifndef Client_hpp
#define Client_hpp
#include <string>
#include <iostream>
#include "Person.hpp"
#include "Instructor.hpp"

using std::string;


class Client : public Person{
private:
    int hours;
    int price;
    Instructor *in;    

           
public:
    //Constructor and destructor
    Client();
    Client(int id, string name, string surname , int age, int weight, string sex, int price = 130 , int hours = 0);
    ~Client();
    //Getters and setters
    int getPrice();
    int getHours();
    void setPrice(int price);
    void setHours(int hours);
    void setInstructor(Instructor *in);
    Instructor* getInstructor();
    void getPay(); //Pay by lessons
    
    friend std::ostream& operator<<(std::ostream &os, const Client &c);
    
};

#endif