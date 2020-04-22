#include "UltimateList.h"
#include <string>

//g++ -Wall -Werror -fsanitize=address -fsanitize=leak -fsanitize=undefined test.cpp
int main(int argc, char* argv[])
{
    //TEST1
    std::cout<<"******************TEST1******************"<<std::endl;
    List<std::string> *myUltimateList = new List<std::string>();
    myUltimateList->addElement("I ");
    myUltimateList->addElement("am ");
    myUltimateList->addElement("a ");
    myUltimateList->addElement("good ");
    myUltimateList->addElement("programmer.");

    for(auto& x: *myUltimateList)
        std::cout<<x; 
    
    delete myUltimateList;
    std::cout<<std::endl;


    //TEST2
    std::cout<<"******************TEST2******************"<<std::endl;
    List<std::string> L;
    L.addElement("List");
    L.addElement("LIst1");
    L.addElement("LIst2");
    L.addElement("LIst3");
    L.addElement("LIst4");
    L.addElement("LIst5");
    L.addElement("LIst6");
    L.addElement("LIst7");
    L.addElement("LIst8");
    L.addElement("LIst9");
    for(auto& x: L)
    {
        std::cout<<x<<std::endl;
    }    
}