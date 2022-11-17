#ifndef CPP_ASSIGNMENT1_MEMBERS_H
#define CPP_ASSIGNMENT1_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class Status;
class FanPage;
class Member {
private:
    char* name = nullptr;
    Date birthday = {0,0,0};
    Status* bulletinBoard = nullptr;
    size_t numOfStatuses = 0;
    Member* friends = nullptr;
    size_t numOfFriends = 0;
    FanPage* pages = nullptr;
    size_t numOfPages = 0;

public:
    Member() {};
    Member(Member& obj)
    {
        name = _strdup(obj.name);
        birthday = obj.birthday;
        bulletinBoard = obj.bulletinBoard;
        friends = obj.friends;
        pages = obj.pages;
        numOfFriends = obj.numOfFriends;
        numOfPages = obj.numOfPages;
        numOfStatuses = obj.numOfStatuses;
    }//Copy constructor.
    Member(const char*& _name)
    {
       name = _strdup(_name);
    }
    Member(const char*& _name, const Date& _birthday)
    {
        name = _strdup(_name);
        birthday = _birthday;
    }
    inline void addFriend(Member& member);
  
};

#endif