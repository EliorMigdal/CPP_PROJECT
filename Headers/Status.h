#ifndef CPP_PROJECT_STATUS_H
#define CPP_PROJECT_STATUS_H
#include "GlobalVariables.h"

class Status {
private:
    Date statusDate = {0,0,0};
    Time statusTime = {0,0,0};
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    char* statusContent = nullptr;
    char* getStatusContent() const {return this->statusContent;}
    Date getStatusDate() const {return this->statusDate;}
    Time getStatusTime() const {return this->statusTime;}

public:
    Status() {}

    Status(Status& obj) //Copy constructor
    {
        statusDate = obj.statusDate;
        statusTime = obj.statusTime;
        statusType = obj.statusType;
        statusContent = strdup(obj.statusContent);
    }

    Status(const Date& _date)
    {
        statusDate = _date;
    }

    Status(const Date& _date, const Time& _time)
    {
        statusDate = _date;
        statusTime = _time;
    }

    Status(const Date& _date, const Time& _time, const Byte& _status)
    {
        statusDate = _date;
        statusTime = _time;
        statusType = (STATUS_TYPE)_status;
    }

    Status(const Date& _date,const Time& _time, const Byte& _status, const char*& _content)
    {
        statusDate = _date;
        statusTime = _time;
        statusType = (STATUS_TYPE)_status;
        statusContent = new char[strlen(_content) + 1];
        strcpy(statusContent, _content);
    }

    inline char* getStatus() const {return getStatusContent();}
    inline Date getDate() const {return getStatusDate();}
    inline Time getTime() const {return getStatusTime();}
    inline void printDate(Date date, Time time) const;
};

#endif