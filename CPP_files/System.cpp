#include "../Headers/System.h"

//Start Function
//----------------------------------------------------------
void System::Start() //Hard-coded data for our system.
{
    this->initialData();
    cout << "Welcome to our social network!" << endl;
    printMenu();
    cout << "Please choose your action: " << flush;
    cin >> userDecision;

    while (userDecision != EXIT)
    {
        try {setDecision(userDecision);}
        catch (std::invalid_argument &error) {cout << error.what() << endl;}
        catch (...) {cout << "General Error" << endl;}
        printMenu();
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
    }
}
//----------------------------------------------------------
void System::initialData() //Inserts hard-coded data.
{
    Date eliDay = { "24", "4", "1995" };
    Date bencoDay = { "23", "5", "1990" };
    Date benhanDay = { "5", "9", "1983" };
    Date ramezDay = { "14", "12", "2005" };
    this->members.reserve(4);
    this->pages.reserve(4);
    this->createMember("Elior Migdal", eliDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Facebook!");
    this->createMember("Ben Cohen", bencoDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Ben :) Wassup! @Ben Cohen");
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Cohen"));
    this->newStatus("Ben Cohen", MEMBER, "Eli ya habibi");
    this->createMember("Ben Hanover", benhanDay);
    this->newStatus("Ben Hanover", MEMBER, "Yoooooyooooooo");
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Hanover"));
    this->newStatus("Elior Migdal", MEMBER, "Yo Yo Ben!");
    this->createMember("Ramez Mannaa", ramezDay);
    this->newStatus("Ben Cohen", MEMBER, "I'm the king!");
    this->newStatus("Ben Hanover", MEMBER, "I know I'm the king bro");
    this->newStatus("Ramez Mannaa", MEMBER, "I'm here too!");
    this->newStatus("Ramez Mannaa", MEMBER, "Who wants to be my friend?");
    this->connectMembersHardCoded(this->members.at("Ben Cohen"), this->members.at("Ramez Mannaa"));
    this->connectMembersHardCoded(this->members.at("Ben Cohen"), this->members.at("Ben Hanover"));
    this->createFanPage("The Bens");
    this->createFanPage("We love Tel-Aviv");
    this->createFanPage("They were on a break!");
    this->connectMembersHardCoded(this->members.at("Ramez Mannaa"), this->members.at("Elior Migdal"));
    this->connectMembersHardCoded(this->members.at("Ramez Mannaa"), this->members.at("Ben Hanover"));
    this->newStatus("The Bens", FAN_PAGE, "We are the Bens!");
    this->addFanHardCoded("The Bens", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "I JOINED THE BENS!!!");
    this->addFanHardCoded("The Bens", "Ben Hanover");
    this->newStatus("Ben Hanover", MEMBER, "ME TOO!");
    this->newStatus("The Bens", FAN_PAGE, "WE HAVE TWO NEW MEMBERS!!");
    this->removeFanHardCoded("The Bens", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "Now I left...");
    this->newStatus("The Bens", FAN_PAGE, ":(");
    this->addFanHardCoded("The Bens", "Ramez Mannaa");
    this->addFanHardCoded("They were on a break!", "Elior Migdal");
    this->addFanHardCoded("They were on a break!", "Ben Cohen");
    this->addFanHardCoded("They were on a break!", "Ben Hanover");
    this->newStatus("Elior Migdal", MEMBER, "They were on a break!!!");
    this->newStatus("They were on a break!", FAN_PAGE, "@Elior yes they were!");
    this->newStatus("They were on a break!", FAN_PAGE, "@Ben Cohen what do you think?");
    this->newStatus("Ben Cohen", MEMBER, "Yes yes");
    this->newStatus("They were on a break!", FAN_PAGE, "Good good");
    this->newStatus("Ben Hanover", MEMBER, "YES!!!!!!!!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "We LOVE Tel Aviv!!");
    this->addFanHardCoded("We love Tel-Aviv", "Ramez Mannaa");
    this->addFanHardCoded("We love Tel-Aviv", "Ben Cohen");
    this->addFanHardCoded("We love Tel-Aviv", "Ben Hanover");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Welcome Tel Aviv Lovers!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Where is @Elior Migdal?");
    this->newStatus("Ramez Mannaa", MEMBER, "@WLTLV He Hates TLV!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "NO WAY!!!!%^%$^#%");
    this->disconnectMembersHardCoded(this->members.at("Ben Cohen"), this->members.at("Elior Migdal"));
    this->disconnectMembersHardCoded(this->members.at("Ben Hanover"), this->members.at("Elior Migdal"));
    this->disconnectMembersHardCoded(this->members.at("Ramez Mannaa"), this->members.at("Elior Migdal"));
    this->newStatus("Elior Migdal", MEMBER, "LOL you all left me!");
    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Hanover"));
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Cohen"));
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ramez Mannaa"));
    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
    this->newStatus("Elior Migdal", MEMBER, "yeaaaaaaa");
    this->newStatus("Elior Migdal", MEMBER, "hello people");
    this->newStatus("Elior Migdal", MEMBER, "wassup");
    this->newStatus("Elior Migdal", MEMBER, "I LOVE C++");
    this->newStatus("Elior Migdal", MEMBER, "but python is better");
    this->newStatus("Elior Migdal", MEMBER, "just kidding");
    this->newStatus("Elior Migdal", MEMBER, "or not....");
    this->newStatus("Elior Migdal", MEMBER, ";)");
}
//----------------------------------------------------------

//System-to-user methods
//----------------------------------------------------------
inline void System::printMenu() //Prints the menu for the user.
{
    cout << "------------------------------------\n1 - Create a member\t\t7 - Disconnect 2 members"
        "\n2 - Create a fan page\t\t8 - Add a member to a fan page"
        "\n3 - Create a status\t\t9 - Remove a member from a fan page"
        "\n4 - Show all statuses\t\t10 - View all members and fan pages"
        "\n5 - 10 last statuses of member\t11 - View all member's friends or Fan page's fans"
        "\n6 - Connect 2 members\t\t12 - Exit" << endl;
}
//----------------------------------------------------------
void System::setDecision(size_SI& _decision) //Gets the decision from user and acts on it.
{
    if (_decision < (size_SI)CREATEMEMBER || _decision  > (size_SI)EXIT)
        throw std::invalid_argument("Invalid decision.");

    switch (_decision )
    {
        default:
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CREATEMEMBER:
            try { System::createMember(); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CREATEFANPAGE:
            try { System::createFanPage(); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)NEWSTATUS:
            try { System::newStatus(); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLSTATUSES:
            try { System::printAllStatuses(); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTTENLASTSTATUSES:
            try{ System::printTenLastStatuses(); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
            //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CONNECTMEMBERS:
            try{ System::Connect_OR_DisconnectMember(&System::connectMembers); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)DISCONNECTMEMBERS:
            try{ System::Connect_OR_DisconnectMember(&System::disconnectMembers); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)ADDFAN:
            try{ System::Add_OR_RemoveFAN(&System::addFan); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)REMOVEFAN:
            try{ System::Add_OR_RemoveFAN(&System::removeFan); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLENTITIES:
            try{System::printAllEntities();}
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLFRIENDS:
            try { System::printAllFriends(); }
            catch (std::invalid_argument &error) { throw std::invalid_argument(error.what()); }
            catch(...) { cout << "General error." << endl; }
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
    }
}
//----------------------------------------------------------
int System::memberOrFanPage() //Gets user decision for specific functions.
{
    int decision = 0;
    cout << "\n1 - A Member\n2 - A Fan Page" << endl;
    cin >> decision;
    cin.ignore();

    if (decision != 1 && decision != 2)
        throw std::invalid_argument("Decision must be 1 or 2.");

    if (decision == 1)
        cout << "Please enter a member's name: ";

    else if (decision == 2)
        cout << "Please enter a fan page's name: ";

    return decision;
}
//----------------------------------------------------------

//General Methods
//---------------------------------------------------------
string System::InputOperation(const size_SI& type, bool readAfter = false) //Returns the string according to each situation.
{
    int counter = 0;
    string input;
    bool found;

    switch (type)
    {
    case FAN_PAGE:
        cout << "Please enter a fan page's name:" << endl;
        if (readAfter) {
            cin.ignore();
            getline(cin, input);
        }
        else getline(cin, input);
        found = pages.find(input) == pages.end();
        while (found && counter < MAX_ATTEMPTS)
        {
            cout << input << " Fan Page was not found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a Fan Page's name:" << endl;
            getline(cin, input);
            counter++;
            found = pages.find(input) == pages.end();
        }
        if (counter == MAX_ATTEMPTS && found)
        {
            cout << "Cannot find fan page.\nToo many entries, redirecting to main menu" << endl;
            return "";
        }
        else
            cout << "Fan Page: " << input << " found!" << endl;

        break;
        //////////////////////////////////////////////////////////////////////////
    case FAN_PAGE_CREATION: //Temp index
        cout << "Please enter a fan page's name:" << endl;
        cin.ignore();
        getline(cin, input);
        found = pages.find(input) != pages.end();
        while (found && counter < MAX_ATTEMPTS)
        {
            cout << input << " Already found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a fan page's name:" << endl;
            getline(cin, input);
            counter++;
            found = pages.find(input) != pages.end();
        }
        if (counter == MAX_ATTEMPTS && found)
        {
            cout << "Fan Page: " << input << " already exists.\nToo many entries, redirecting to main menu." << endl;
            return "";
        }
        break;
        //////////////////////////////////////////////////////////////////////////
    case MEMBER:
        cout << "Please enter a member's name:" << endl;
        if (readAfter) {
            cin.ignore();
            getline(cin, input);
        }
        else getline(cin, input);
        found = members.find(input) == members.end();
        while (found && counter < MAX_ATTEMPTS)
        {
            cout << input << " was not found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a member's name:" << endl;
            getline(cin, input);
            counter++;
            found = members.find(input) == members.end();
        }
        if (counter == MAX_ATTEMPTS && found)
        {
            cout << "Cannot find member.\nToo many entries, redirecting to main menu." << endl;
            return "";
        }
        else 
            cout << "User: " << input << " found!" << endl;

        break;
        //////////////////////////////////////////////////////////////////////////
    case MEMBER_CREATION:

        cout << "Please enter a member's name:" << endl;
        cin.ignore();
        getline(cin, input);
        found = members.find(input) != members.end();
        while (found && counter < MAX_ATTEMPTS)
        {
            cout << input << " was found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a member's name:" << endl;
            getline(cin, input);
            counter++;
            found = members.find(input) != members.end();
        }
        if (counter == MAX_ATTEMPTS && found)
        {
            cout << "Member: " << input << " already exists.\nToo many entries, redirecting to main menu." << endl;
            return "";
        }
        break;
        //////////////////////////////////////////////////////////////////////////
    default:
        break;
    }
    return input;
}
//---------------------------------------------------------

//Member Methods
//----------------------------------------------------------
void System::createMember() //Read name and birthday from the user with validation checks.
{
    string name;
    cout << "Please enter a member's name: ";
    cin.ignore();
    getline(cin, name);

    /*name = InputOperation(MEMBER_CREATION);*/
    if (members.find(name) == members.end())
    {
        cout << "Please enter member's birthday:" << endl;
        Date Birthday = { "0","0","0" };
        readBirthday(Birthday);
        if (!BirthdayCheck(Birthday)) //not good need to change
            throw std::invalid_argument ("Invalid birthday input.");

        this->members[name] = Member{ name, Birthday };
    }

    else
        throw std::invalid_argument("User already exists in our system.");
}
//----------------------------------------------------------
void System::createMember(const string& _name, Date& _date) //For hard-coded data.
{
    if (this->members.find(_name) == this->members.end())
        this->members[_name] = Member{ _name,_date };
}
//----------------------------------------------------------
void System::connectMembersHardCoded(Member& member1, Member& member2) //Connect members for
// hard-coded data.
{
    member1 += member2;
    member2 += member1;
}
//----------------------------------------------------------
void System::disconnectMembersHardCoded(Member& member1, Member& member2) //Disconnect members for
// hard-coded data.
{
    member1 -= member2;
    member2 -= member1;
}
//----------------------------------------------------------

//FanPage Methods
//----------------------------------------------------------
void System::createFanPage() //Creates a fan page.
{
    string name;
    cout << "Please enter a fan page's name: ";
    cin.ignore();
    getline(cin, name);
    /*name = InputOperation(FAN_PAGE_CREATION);*/

    if (pages.find(name) == pages.end())
    {
        try {this->pages[name] = new FanPage(name);}
        catch (std::bad_alloc& error) {throw std::bad_alloc(error);}
        catch (...) {throw std::exception();}
    }

    else
        throw std::invalid_argument("Page already exists in our system.");
}
//----------------------------------------------------------
void System::createFanPage(const string& _name) //Creates a fan page for hard-coded data.
{
    try {this->pages[_name] = new FanPage(_name);}
    catch (std::bad_alloc& error) {throw std::bad_alloc(error);}
    catch (...) {throw std::exception();}
}
//----------------------------------------------------------
void System::Add_OR_RemoveFAN(void(System::*operation)(const string&,const string&)) //Adds or removes a fan.
{
    string fanPageName, memberName;
    cout << "Enter a member's name and a fan page's name (by that order): ";
    cin.ignore();
    getline(cin, memberName);
    getline(cin, fanPageName);

    /*memberName = InputOperation(MEMBER, true);*/
    if (members.find(memberName) != members.end() && pages.find(fanPageName) != pages.end())
    {
        /*fanPageName = InputOperation(FAN_PAGE);*/
        try {(this->*operation)(fanPageName, memberName);}
        catch (std::invalid_argument& error) {throw std::invalid_argument(error.what());}
        catch(...) {throw std::exception();}
    }

    else
        throw std::invalid_argument("At least on of the entities does not exist in our system.");
}
//----------------------------------------------------------
void System::addFan(const string& fanPageName, const string& memberName) //Adds a fan to a fan page's members array.
{
    bool isFan = this->pages.at(fanPageName)->FanPage::checkIfFan(memberName);
    if (!isFan)
    {
        this->members.at(memberName) += this->pages.at(fanPageName);
        *this->pages.at(fanPageName) += this->members.at(memberName);
    }
    else
        throw std::invalid_argument("Member is already a fan of this fan page.");
}
//----------------------------------------------------------
void System::removeFan(const string& fanPageName, const string& memberName) //Removes a fan from a fan page's
// members array.
{
    bool isFan = this->pages.at(fanPageName)->FanPage::checkIfFan(memberName);
    if (isFan)
    {
        *this->pages.at(fanPageName) -= this->members.at(memberName);
        this->members.at(memberName) -= this->pages.at(fanPageName);
    }

    else
        throw std::invalid_argument("Member is already not a fan of this fan page.");
}
//----------------------------------------------------------
void System::addFanHardCoded(const string& pageName, const string& fanName) //Add fan for hard-coded data.
{
    this->members.at(fanName) += this->pages.at(pageName);
    *this->pages.at(pageName) += this->members.at(fanName);
}
//----------------------------------------------------------
void System::removeFanHardCoded(const string& pageName, const string& fanName) //Remove fan for hard-coded data.
{
    *this->pages.at(pageName) -= this->members.at(fanName);
    this->members.at(fanName) -= this->pages.at(pageName);
}
//----------------------------------------------------------

//Status Methods
//----------------------------------------------------------
void System::newStatus() //Creates a new status.
{
    string name;
    int decision;
    cout << "Please choose the entity which you would like to add a status to:";

    try {decision = memberOrFanPage();}
    catch(std::invalid_argument& error) {throw std::invalid_argument(error.what());}
    catch(...) {throw std::exception();}

    getline(cin, name);

    if (pages.find(name) != pages.end() || members.find(name) != members.end())
    {
        if (decision == 1)
        {
            try { members.at(name).Member::addStatus(); }
            catch (...) { throw std::exception(); }
        }

        else if (decision == 2)
        {
            try { pages.at(name)->FanPage::addStatus(); }
            catch (...) { throw std::exception(); }
        }
    }

    else
        throw std::invalid_argument("Entity was not found in our system!");
}
//----------------------------------------------------------
void System::newStatus(const string& name, const size_SI& type, const string& statusContent) //Creates a new status for
// hard-coded data.
{
    if (type == MEMBER)
    {
        try { this->members.at(name).Member::addStatus(statusContent); }
        catch(...) {throw std::exception();}
    }


    else
    {
        try { this->pages.at(name)->FanPage::addStatus(statusContent); }
        catch(...) {throw std::exception();}
    }
}
//----------------------------------------------------------

//Private Global Methods
//----------------------------------------------------------
inline bool System::BirthdayCheck(const Date& _birthday) //Verifies birthday inserted correctly.
{
    return (_birthday.day > "0" && _birthday.day < "32" &&
        _birthday.month > "0" && _birthday.month < "13"
        && _birthday.year>"1900" && _birthday.year < "2023") ? true : false;
}
//----------------------------------------------------------

//Private Printer Methods
//----------------------------------------------------------
void System::printAllStatuses() //Prints an entity's statuses.
{
    int decision;
    string name;
    cout << "Please choose the entity of which you want to view statuses:";

    try {decision = memberOrFanPage();}
    catch(std::invalid_argument& error) {throw std::invalid_argument(error.what());}
    catch(...) {throw std::exception();}
    getline(cin, name);

    /*(decision == 1 ) ?
            name = InputOperation(MEMBER)
                     :
            name = InputOperation(FAN_PAGE);*/

    if (pages.find(name) != pages.end() || members.find(name) != members.end())
    {
        if (decision == 1)
        {
            try { members.at(name).Member::printStatuses(members.at(name).getNumOfStatuses()); }
            catch (std::invalid_argument& error) { throw std::invalid_argument(error.what()); }
            catch (...) { throw std::exception(); }
        }

        else if (decision == 2)
        {
            try { pages.at(name)->printStatuses(); }
            catch (std::invalid_argument& error) { throw std::invalid_argument(error.what()); }
            catch (...) { throw std::exception(); }
        }
    }

    else
        throw std::invalid_argument("Entity was not found in our system!");
}
//----------------------------------------------------------
void System::printTenLastStatuses() //Prints a member's friends ten last statuses.
{
    string name;
    int i = 0;
    cout << "Please enter a member's name: ";
    cin.ignore();
    getline(cin, name);
    /*name = InputOperation(MEMBER,true);*/

    if (members.find(name) != members.end())
    {
        if (!this->members[name].Member::getFriendsArr().empty())
        {
            for (const auto& kv : this->members[name].Member::getFriendsArr())
            {
                auto& key = kv.first;
                auto& value = kv.second;
                if (key != name) // need to change after creating all the classes operators
                {
                    cout << "####################################\nFriend #" << ++i
                    << "\n####################################" << endl;
                    try {value.Member::printStatuses(PRINT_STATUS);}
                    catch (std::invalid_argument& error) {cout << key << ": "
                    << error.what() << endl;}
                    catch (...) {cout << "General error." << endl;}
                }
            }
        }

        else
            throw std::invalid_argument("User has no friends.");
    }

    else
        throw std::invalid_argument("Member was not found in our system!");

}
//----------------------------------------------------------
void System::printAllEntities() const //Prints all entities.
{
    if (this->members.empty())
        throw std::invalid_argument("System has no members.");
    else
    {
        cout << "------------------------------------\nOur system's "
                "members list:\n------------------------------------" << endl;
    
        for (const auto& kv:this->members)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }        
    if (this->pages.empty())
        throw std::invalid_argument("System has no fan pages.");

    else
    {
        cout << "------------------------------------\nOur system's "
                "fan pages list:\n------------------------------------" << endl;

        for (const auto& kv : this->pages)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }

}
//----------------------------------------------------------
void System::printAllFriends() //Prints an entity's friends.
{
    int decision;
    string entityName;
    cout << "Please enter the entity of which you want to view its friends:";

    try {decision = memberOrFanPage();}
    catch(std::invalid_argument& error) {throw std::invalid_argument(error.what());}
    catch(...) {throw std::exception();}
    getline(cin, entityName);

    /*(decision == 1) ? entityName = InputOperation(MEMBER,true):
            entityName = InputOperation(FAN_PAGE, true);*/

    if (pages.find(entityName) != pages.end() || members.find(entityName) != members.end())
    {
        if (decision == 1)
        {
            try { members.at(entityName).Member::printFriendsArr(); }
            catch (std::invalid_argument& error) { throw std::invalid_argument(error.what()); }
            catch (...) { throw std::exception(); }
        }

        else if (decision == 2)
        {
            try { System::printAllFans(pages.at(entityName)); }
            catch (std::invalid_argument& error) { throw std::invalid_argument(error.what()); }
            catch (...) { throw std::exception(); }
        }
    }

    else
        throw std::invalid_argument("Entity was not found in our system!");
}
//----------------------------------------------------------
void System::printAllFans(FanPage* fanPage) //Prints a fan page's fans list.
{
    unordered_map<string, Member> MembersMap = fanPage->getMemberArr();
    if (MembersMap.empty())
        throw std::invalid_argument("Page has no fans.");

    else
    {
        cout << "------------------------------------\n"
        << fanPage->FanPage::getName() << "'s fans list:\n------------------------------------" << endl;
        for (const auto& kv : MembersMap)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }
}
//----------------------------------------------------------

//Private System-Member Methods
//----------------------------------------------------------
void System::Connect_OR_DisconnectMember(void(System::* operation)(const string&, const string&)) //Connects or
// Disconnects Members.
{
    string firstMemberName, secondMemberName;
    cout << "Please enter two member names: ";
    cin.ignore();
    getline(cin, firstMemberName);
    getline(cin, secondMemberName);
    /*firstMemberName = InputOperation(MEMBER, true);*/
    if (members.find(firstMemberName) != members.end() && members.find(secondMemberName) != members.end())
    {
        /*secondMemberName = InputOperation(MEMBER);*/
        try {(this->*operation)(firstMemberName, secondMemberName);}
        catch (std::invalid_argument& error) {throw std::invalid_argument(error.what());}
        catch(...) {throw std::exception();}
    }

    else
        throw std::invalid_argument("At least one member does not exist in our system.");
}
//----------------------------------------------------------
void System::connectMembers(const string& firstMemberName, const string& secondMemberName) //Connects two members.
{
    if (firstMemberName != secondMemberName)
    {
        bool areFriends = members[firstMemberName].Member::checkIfFriend(members[secondMemberName].getName());
        if (!areFriends)
        {
            members[firstMemberName] += members[secondMemberName];
            members[secondMemberName] += members[firstMemberName];
        }
        else
            throw std::invalid_argument("Members are already friends.");
    }
    else
        throw std::invalid_argument("Cannot add yourself to your friends list.");
    
}
//----------------------------------------------------------
void System::disconnectMembers(const string& firstMemberName, const string& secondMemberName) //Disconnects two members.
{
    if (firstMemberName != secondMemberName)
    {
        bool areFriends = members[firstMemberName].Member::checkIfFriend(members[secondMemberName].getName());
        if (areFriends)
        {
            members[firstMemberName] -= members[secondMemberName];
            members[secondMemberName] -= members[firstMemberName];
        }
        else
            throw std::invalid_argument("Members are already not friends.");
    }
    else
        throw std::invalid_argument("Cannot remove yourself from your friends list.");
}
//----------------------------------------------------------