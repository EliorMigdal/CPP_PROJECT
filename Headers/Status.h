#ifndef CPP_PROJECT_STATUS_H
#define CPP_PROJECT_STATUS_H
#include "GlobalVariables.h"

class Status {
private:
    Date statusDate = {0,0,0};
    Time statusTime = {0,0,0};
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    char* statusContent = nullptr;

public:
    //Constructors:
    Status() = default; //Default constructor.
    Status(const Status& obj); //Copy constructor
    explicit Status(const Date& _date);
    Status(const Date& _date, const Time& _time, const Byte& _status, const char* _content);
    ~Status();
    //end of constructors
    
    //Methods
    char* getStatus() const { return this->statusContent; }
    Date getStatusDate() const { return this->statusDate; }
    Time getStatusTime() const { return this->statusTime; }
    void printDate(const Date& date, const Time& time) const;
    void createStatus();
 
};

#endif