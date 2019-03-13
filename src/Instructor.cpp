#include "../include/Instructor.hpp"

using namespace std;

Instructor::Instructor(int id, string name, string surname, int age, int weight, string sex, int salary, int workedHours) : Person(id, name, surname, age, weight, sex)
{
    this->workedHours = workedHours;
    this->salary = salary;
    this->numberOfClient =0;
}
Instructor::Instructor() : Person(){ 

}
Instructor::~Instructor()
{
    cout << "\nInstructor deleted!" << endl;
}

Instructor::Instructor(const Instructor &in) : Person(in)
{
    this->id = in.id;
    this->name = in.name;
    this->surname = in.surname;
    this->age = in.age;
    this->weight = in.weight;
    this->sex = in.sex;
    this->workedHours = in.workedHours;
    this->salary = in.salary;
    this->numberOfClient = in.numberOfClient;
}
ostream &operator<<(ostream &os, const Instructor &in)
{
    os << "\n"
       << in.id << ". " << in.name << " " << in.surname << endl;
    os << "Age: " << in.age << " Weight: " << in.weight << " Sex: " << in.sex << endl;
    os << "Salary: " << in.salary << " Worked hours: " << in.workedHours << endl;
    os << "Number of Clients: " << in.numberOfClient << endl;
    return os;
}

Instructor &Instructor::operator=(const Instructor &in)
{
    if (&in != this)
    {
        this->id = in.id;
        this->name = in.name;
        this->surname = in.surname;
        this->age = in.age;
        this->weight = in.weight;
        this->sex = in.sex;
        this->workedHours = in.workedHours;
        this->salary = in.salary;
        this->numberOfClient = in.numberOfClient;
    }
    return *this;
}



void Instructor::setWorkedHours(int workedHours)
{
    this->workedHours = workedHours;
}

void Instructor::setSalary(int salary)
{
    this->salary = salary;
}

int Instructor::getWorkedHours()
{
    return workedHours;
}

int Instructor::getSalary()
{
    return salary;
}
int Instructor::getNumberOfClient()
{
    return this->numberOfClient;
}
void Instructor::setNumberOfClient(int numberOfClient)
{
    this->numberOfClient = numberOfClient;
}
