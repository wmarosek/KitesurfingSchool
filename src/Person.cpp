#include "../include/Person.hpp"
#include <string>
#include <iostream>


using namespace std;

//CONSTRUCTOR AND DESTRUCTOR

Person::Person(int id, string name, string surname , int age , int weight , string sex){
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->weight = weight;
    this->sex = sex;
}

Person::Person(){
    
}

Person::~Person(){
    cout << "\nPerson deleted!" << endl;
}

//SETTERS AND GETTERS
void Person::setSex(string sex){
    this->sex = sex;
}

string Person::getSex(){
    return sex;
}

void Person::setWeight(int weight){
    this->weight = weight;
}

int Person::getWeight(){
    return weight;
}

void Person::setAge(int age){
    this->age = age;
}

int Person::getAge(){
    return age;
}

void Person::setSurname(string surname){
    this->surname = surname;
}

string Person::getSurname(){
    return surname;
}

void Person::setName(string name){
    this->name = name;
}

string Person::getName(){
    return name;
}

int Person::getId() const{
    return id;
}

ostream& operator<<(std::ostream &os, const Person &p){
    os << p.id << ". " << p.name << " " << p.surname << endl;
    os << "Age: " << p.age << "Weight: " << p.weight << "Sex: " << p.sex << endl;
    return os;
}

bool Person::operator==(const Person &in) const
{
    return (this->getId() == in.getId());
}

bool Person::operator!=(const Person &in) const
{
    return (this->getId() != in.getId());
}
bool Person::operator<(const Person &a) const
{
	return surname < a.surname;
}

