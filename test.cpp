#include "UltimateList.h"
#include <string>

    //TEST1
void ListDynamicAllocTest() 
{
    std::cout<<"******************TEST1******************"<<std::endl;
    List<std::string> *myUltimateList = new List<std::string>();
    myUltimateList->addElement("I");
    myUltimateList->addElement("am");
    myUltimateList->addElement("a");
    myUltimateList->addElement("good");
    myUltimateList->addElement("programmer");
    myUltimateList->printElements();    
    delete myUltimateList;
    std::cout<<std::endl;
}

    //TEST2
void ListStackAllocTest()
{
    std::cout<<"******************TEST2******************"<<std::endl;
    List<std::string> L;
    L.addElement("List");
    L.addElement("List1");
    L.addElement("List2");
    L.addElement("List3");
    L.addElement("List4");
    L.addElement("List5");
    L.addElement("List6");
    L.addElement("List7");
    L.addElement("List8");
    L.addElement("List9");
    L.printElements();
    std::cout<<std::endl;
}

    //TEST3
void ListAddElementSortedTest()
{
    std::cout<<"******************TEST3******************"<<std::endl;
    List<int> L;
    L.addElementSorted(19);
    L.addElementSorted(3);
    L.addElementSorted(1);
    L.addElementSorted(100);
    L.addElementSorted(79);
    L.printElements();
    std::cout<<std::endl;
}

    //TEST4
void ListReverseListTest()
{
    std::cout<<"******************TEST4******************"<<std::endl;
     List<int> L;
    L.addElementSorted(19);
    L.addElementSorted(3);
    L.addElementSorted(1);
    L.addElementSorted(100);
    L.addElementSorted(79);
    L.printElements();
    L.reverseList();
    std::cout<<"\nreversed: \n";
    L.printElements();
    std::cout<<std::endl;
}

//g++ -Wall -Werror -fsanitize=address -fsanitize=leak -fsanitize=undefined test.cpp
int main(int argc, char* argv[])
{
    ListDynamicAllocTest();
    ListStackAllocTest();
    ListAddElementSortedTest();
    ListReverseListTest();
}