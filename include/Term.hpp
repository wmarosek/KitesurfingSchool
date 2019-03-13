#ifndef Term_hpp
#define Term_hpp
#include <string>
#include <iostream>

using std::ostream;

class Term {
private:
    int start;
    int end;
    int day;
    int month;   

public:
    Term(int start, int end,  int day , int month);
    ~Term();
    int getMonth() const;
    int getDay() const;
    int getEnd() const;
    int getStart() const;
    friend ostream& operator<<(ostream &os, const Term &t);
    bool operator== (const Term& t2) const;
    

};

#endif