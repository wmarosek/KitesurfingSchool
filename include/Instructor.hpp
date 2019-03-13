#ifndef Instructor_hpp
#define Instructor_hpp
#include <string>
#include <iostream>
#include "Person.hpp"

using std::string;

class Instructor : public Person{
private:
    int salary;
    int workedHours;
    int numberOfClient;

    
    
public:
    //Constructor and destructor
    Instructor(int  id, string name, string surname, int age, int weight, string sex, int salary, int workedHours = 0);
    ~Instructor();
    Instructor();
    Instructor(const Instructor& in);
    //Getters and setters
    void setWorkedHours(int workedHours);
    void setSalary(int salary);
    int getWorkedHours();
    int getSalary();
    int getNumberOfClient();
    void setNumberOfClient(int numberOfClient);

    Instructor& operator=(const Instructor& in);

    friend std::ostream& operator<<(std::ostream &os, const Instructor &in);

};

#endif