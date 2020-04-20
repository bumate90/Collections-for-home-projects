#include "UltimateList.h"
#include <string>

int main(int argc, char* argv[])
{
/*     List<string> *myUltimateList = new List<string>();
    
    myUltimateList->addElement("This ");
    
    myUltimateList->addElement("is ");
    myUltimateList->addElement("a ");
    myUltimateList->addElement("test!");

    for(auto& x: *myUltimateList)
        cout<<x.value; */

    List<std::string> L;
    L.addElement("TEST");
    for(auto& x: L)
    {
        std::cout<<x.value<<std::endl;
    }    
}