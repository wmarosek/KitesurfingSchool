#ifndef Person_hpp
#define Person_hpp
#include <string>
#include <iostream>

using std::string;


class Person {
protected:
    int id;
    string name;
    string surname;
    int age;
    int weight;
    string sex;

    
public:
    //CONSTRUCTORS
    Person(int id, string name, string surname , int age , int weight , string sex);
    Person();
    ~Person();
    //SETTERS AND GETTERS
    int getId() const;
    string getSex() ;
    void setSex(string sex);
    void setWeight(int weight);
    int getWeight() ;    
    void setAge(int age);    
    int getAge();     
    void setSurname(string surname);
    string getSurname();
    void setName(string name);
    string getName();
    
    friend std::ostream& operator<<(std::ostream &os, const Person &p);
    bool operator==(const Person &in) const;
    bool operator!=(const Person &in) const;
    bool operator <(const Person &a) const;
};

#endif