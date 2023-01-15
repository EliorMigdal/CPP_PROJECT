#include "../Headers/Member.h"
#include "../Headers/FanPage.h"

//Constructor
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
    return this->pages.find(_fanPage.FanPage::getName()) != this->pages.end();
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
        size_t numToPrint;

        if (_numOfStatuses < PRINT_STATUS)
        {
            cout << this->Member::getName() << " has only posted " << _numOfStatuses << " statuses:" << endl;
            numToPrint = _numOfStatuses;
        }

        else
        {
            cout << this->Member::getName() << "'s last " << PRINT_STATUS << " statuses:" << endl;
            numToPrint = PRINT_STATUS;
        }

        {
            using reverseStatusIter = vector<Status*>::const_reverse_iterator;
            reverseStatusIter begin = this->bulletinBoard.crbegin();
            reverseStatusIter end = this->bulletinBoard.crend();
            for (reverseStatusIter rit = begin; rit != end && numToPrint > 0; ++rit)
            {
                cout << "------------------------------------\n\tStatus #"
                     << _numOfStatuses-- << "\n------------------------------------" << endl << **rit;
                --numToPrint;
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
    try {this->Entity::addMember(_member);}
    catch (connectedEntities& error) {throw addAFriendException();}
    catch (...) {throw memberExceptions();}
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator-=(Member& _member) //Member -= Member operator.
{
    try {this->Member::removeMember(_member);}
    catch (disconnectedEntities& error) {throw removeAFriendException();}
    catch (...) {throw memberExceptions();}
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator+=(FanPage &fanPage) noexcept(false) //Member += FanPage operator.
{
    try {this->Member::addFanPage(fanPage);}
    catch (addAFanException& error) {throw addAFanException(error);}
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator-=(FanPage &fanPage) noexcept(false) //Member -= FanPage operator.
{
    try {this->Member::removeFanPage(fanPage);}
    catch (removeAFanException& error) {throw removeAFanException(error);}
    catch(...) {throw GlobalExceptions();}

    return *this;
}
//----------------------------------------------------------