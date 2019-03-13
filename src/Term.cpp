#include "../include/Term.hpp"

using namespace std;

Term::Term(int start, int end,  int day , int month) {
    if(end>start){
        this->start = start;
        this->end = end;
        this->day = day;
        this->month = month;   
    }
    else{
        cout << "\nEnd time has to be later than start!";
    }
}

Term::~Term()
{
    cout << "\nTerm deleted!" << endl;
}
int Term::getMonth() const
{
    return month;
}

int Term::getDay() const
{
    return day;
}

int Term::getEnd() const
{
    return end;
}

int Term::getStart() const
{
    return start;
}

ostream &operator<<(ostream &os, const Term &t)
{
    os << "\nDay | Month | Start/End Hours: " << t.day << " | " << t.month << " | " << t.start << "/" << t.end;
    return os;
}

bool Term::operator==(const Term& t2) const{
    return (((this->getDay() == t2.getDay()) &&  (this->getMonth() == t2.getMonth())) 
    && ((t2.getStart()<=this->getStart() && this->getStart() < t2.getEnd()) || (t2.getStart()>=this->getStart() && this->getEnd() >= t2.getEnd()) || (t2.getStart()<this->getEnd() && this->getEnd() < t2.getEnd())));

}