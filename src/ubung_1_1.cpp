#include <iostream>


int main() {
    //ex1
    std::cout<<"Ihr Vornamen:" ;
    std::string vorname;
    std::cin >> vorname;

    std::cout <<"Ihr Nachnamen:" ;
    std::string nachname;
    std::cin >> nachname;

    std::cout  <<"Hallo, "<<vorname <<" "<< nachname<<"."<<"\n";
    std::cout<<"Anzahl der Zeichen ihres Namens:"<<nachname.size() + vorname.size();

    return 0;
}