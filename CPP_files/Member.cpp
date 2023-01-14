#include "../Headers/Member.h"
#include "../Headers/FanPage.h"

//Constructors
//----------------------------------------------------------
Member::Member(string& _name): Entity(_name){}
//----------------------------------------------------------
Member::Member(std::string &_name, Date &_date): Entity(_name), birthday(_date){}
//----------------------------------------------------------

//Member-to-FanPage Methods
//----------------------------------------------------------
void Member::addFanPage(FanPage &fanPage) noexcept(false) //Adds a fan page.
{
    if (this->isFan(fanPage))
        throw addAFanException();

    else
        this->pages[fanPage.Entity::getName()] = &fanPage;
}
//----------------------------------------------------------
void Member::removeFanPage(FanPage &fanPage) noexcept(false) //Removes a fan page.
{
    if (!this->isFan(fanPage))
        throw removeAFanException();

    else
        this->pages.erase(fanPage.Entity::getName());
}
//----------------------------------------------------------
bool Member::isFan(FanPage & _fanPage) //Searches for fan page in member's pages.
{
    return this->pages.find(_fanPage.FanPage::getName()) == this->pages.end();
}
//----------------------------------------------------------

//Printer Methods
//----------------------------------------------------------
void Member::printTenLastStatuses() noexcept(false) //Prints all of member's friends' 10 last statuses.
{
    if (this->bulletinBoard.empty())
        throw memberPrintStatusesException();

    else
    {
        size_t _numOfStatuses = this->bulletinBoard.size();
        size_t logicPrintSize = 0;
        if (_numOfStatuses < PRINT_STATUS)
        {
            logicPrintSize = _numOfStatuses;
            cout << this->Member::getName() << " has only posted " << _numOfStatuses << " statuses:" << endl;
        }

        else
            cout << this->Member::getName() << "'s last " << PRINT_STATUS << " statuses:" << endl;

        size_t to_Run = _numOfStatuses - logicPrintSize;
        {
            using reverseStatusIter = vector<Status*>::const_reverse_iterator;
            reverseStatusIter begin = this->bulletinBoard.crbegin();
            reverseStatusIter end = this->bulletinBoard.crend();
            for (reverseStatusIter rit = begin; rit != end && (to_Run < _numOfStatuses); ++rit)
            {
                cout << "------------------------------------\n\tStatus #"
                     << _numOfStatuses-- << "\n------------------------------------" << endl << *rit << endl;
            }
        }
    }
}
//----------------------------------------------------------
void Member::printPages() noexcept(false) //Prints member's pages (Implementation only).
{
    if (this->pages.empty())
        throw printPagesException();

    else
    {
        for (const auto& kv : this->pages)
            cout << kv.first << endl;
    }
}
//----------------------------------------------------------

//Operators
//----------------------------------------------------------
const Member &Member::operator+=(Member& _member) //Member += Member operator.
{
    try{this->Entity::addMember(_member);}
    catch (addAFriendException& error) { throw addAFriendException(error); }
    catch (...) { throw memberExceptions(); }
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator-=(Member& _member) //Member -= Member operator.
{
    try {this->Member::removeMember(_member);}
    catch (removeAFriendException& error) {throw removeAFriendException(error);}
    catch(...) {throw memberExceptions();}
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator+=(FanPage &fanPage) noexcept(false) //Member += FanPage operator.
{
    try {this->Member::addFanPage(fanPage);}
    catch (addAFanException& error) { throw error; }
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator-=(FanPage &fanPage) noexcept(false) //Member -= FanPage operator.
{
    try {this->Member::removeFanPage(fanPage);}
    catch (removeAFanException& error) {throw error;}
    catch(...) {throw memberExceptions();}

    return *this;
}
//----------------------------------------------------------

//Commented Methods
//----------------------------------------------------------
//void Member::addFriend(Member* memberToAdd) //Adds a new friends to the friends array.
//{
//    if (!this->Member::isFriend(memberToAdd->getName()))
//        this->friends[memberToAdd->Member::getName()] = memberToAdd;
//
//    else
//        throw addAFriendException();
//}
//----------------------------------------------------------
//void Member::removeFriend(const string& memberToRemove) //Removes a friend from the friends array.
//{
//    if (this->Member::isFriend(memberToRemove))
//        this->friends.erase(memberToRemove);
//
//    else
//        throw removeAFriendException();
//}
//----------------------------------------------------------
//bool Member::isFriend(const string& member_name) //Searches for a member in other member's friends array.
//{
//    return this->friends.find(member_name) != this->friends.end();
//}
//----------------------------------------------------------
//void Member::printFriendsArr() const //Prints friends' names.
//{
//    if (this->friends.empty())
//        throw printFriendsException();
//
//    else
//    {
//        cout << "----------------------------------\n" << this->Member::getName() <<
//        "'s friends are:\n----------------------------------" << endl;
//        for (const auto& kv : this->friends)
//            cout <<"\t" << kv.first << endl;
//    }
//}
//----------------------------------------------------------
//Member-to-Status Methods
//----------------------------------------------------------
//void Member::printStatuses(const size_t& numToPrint) const //Prints member's statuses.
//{
//    if (this->bulletinBoard.empty())
//        throw memberPrintStatusesException();
//
//    else
//    {
//        size_t _numOfStatuses = this->bulletinBoard.size();
//        size_t logicPrintSize;
//        if (_numOfStatuses < PRINT_STATUS)
//        {
//            logicPrintSize = _numOfStatuses;
//            cout << this->Member::getName() << " has only posted " << _numOfStatuses << " statuses:" << endl;
//        }
//
//        else
//        {
//            logicPrintSize = numToPrint;
//            cout << this->Member::getName() << "'s last " << numToPrint << " statuses:" << endl;
//        }
//
//        size_t to_Run = _numOfStatuses - logicPrintSize;
//        {
//            using reverseStatusIter = vector<Status>::const_reverse_iterator;
//            reverseStatusIter begin = this->bulletinBoard.rbegin();
//            reverseStatusIter end = this->bulletinBoard.rend();
//            for (reverseStatusIter rit = begin; rit != end && (to_Run < _numOfStatuses); ++rit)
//            {
//                cout << "------------------------------------\n\tStatus #"
//                << _numOfStatuses-- << "\n------------------------------------" << endl << *rit << endl;
//            }
//        }
//    }
//}
//----------------------------------------------------------
//void Member::addStatus() //Creates a new status.
//{
//    Date newDate;
//    Time newTime;
//    string statusContent;
//    cout << "Please enter a your Status content:" << endl;
//    getline(cin, statusContent);
//    if (!statusContent.empty())
//    {
//        setTimeAndDate(newTime, newDate);
//        this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
//    }
//    else
//        throw EmptyStatus();
//}
//----------------------------------------------------------
//void Member::addStatus(const string& statusContent) //For hard-coded data.
//{
//    Date newDate;
//    Time newTime;
//    setTimeAndDate(newTime, newDate);
//    this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
//}
//----------------------------------------------------------
//Member-to-FanPage Methods
//----------------------------------------------------------
//void Member::addPage(FanPage* fanPage_obj) //Adds a new page to the pages array.
//{
//    if (!this->Member::isFan(fanPage_obj->FanPage::getName()))
//        this->pages[fanPage_obj->getName()] = fanPage_obj;
//
//    else
//        throw addAFanException();
//}
//----------------------------------------------------------
//void Member::removePage(const string& fanPage_name) //Removes a page from the page array.
//{
//    if (this->Member::isFan(fanPage_name))
//        this->pages.erase(fanPage_name);
//
//    else
//        throw removeAFanException();
//}
//----------------------------------------------------------
//----------------------------------------------------------
//void Member::printAllPages() const //Prints a member's pages list.
//{
//    unordered_map<string, FanPage*> u_fanMap = this->Member::getPagesArr();
//    if (u_fanMap.empty())
//        throw printPagesException();
//
//    for (const auto& kv : u_fanMap)
//        cout << kv.first << endl;
//}
//----------------------------------------------------------
//Operators Methods
//----------------------------------------------------------
//ostream& operator<<(ostream& out, Member* _member) //Print operator.
//{
//    return out << _member->Member::getName();
//}
//const Member &Member::operator+=(FanPage* _fanPage) //Member + FanPage operator.
//{
//    try {this->Member::addPage(_fanPage);}
//    catch (addAFanException& error) { throw addAFanException(error); }
//    catch (...) {throw GlobalExceptions();}
//    return *this;
//}
//----------------------------------------------------------
//const Member &Member::operator-=( FanPage* _fanPage) //Member - FanPage operator.
//{
//    try {this->Member::removePage(_fanPage->FanPage::getName());}
//    catch (removeAFanException& error) {throw removeAFanException(error);}
//    catch (...) {throw GlobalExceptions();}
//    return *this;
//}
//----------------------------------------------------------
//bool Member::operator<(const Member& _member) const //Member < Member operator.
//{
//    return this->Member::getNumOfFriends() < _member.Member::getNumOfFriends();
//}
//----------------------------------------------------------
//bool Member::operator<=(const Member& _member) const //Member <= Member operator.
//{
//    return this->Member::getNumOfFriends() <= _member.Member::getNumOfFriends();
//}
//----------------------------------------------------------
//bool Member::operator>(const Member& _member) const //Member > Member operator.
//{
//    return this->Member::getNumOfFriends() > _member.Member::getNumOfFriends();
//}
//----------------------------------------------------------
//bool Member::operator>=(const Member& _member) const //Member >= Member operator.
//{
//    return this->Member::getNumOfFriends() >= _member.Member::getNumOfFriends();
//}
//----------------------------------------------------------