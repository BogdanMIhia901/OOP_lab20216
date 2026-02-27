#include <iostream>
#include <string>

struct kunde {
    int nummer;
    std::string name;
    int postleitzahl;
    std::string ortsnahme;
};

int main() {
    kunde array[10];

    for (int i = 0;i<3;i ++) {
        std::cout<<"Bitte geben sie ihre Daten an,";
        std::cout<<"Nummer:";
        std::cin >> array[i].nummer;

        std::cout<<"Name:";
        std::cin >> array[i].name;

        std::cout<<"Postleitzeit:";
        std::cin >> array[i].postleitzahl;

        std::cout<<"Ortsnahme:";
        std::cin >> array[i].ortsnahme;
    }

    for (int i = 0;i<3;i ++) {
        std::cout<<array[i].name<<" hat die Nummer "<<array[i].nummer <<" und die Postleitezeit "<< array[i].postleitzahl<<" und die Ortsnahme "<<array[i].ortsnahme<<".";
        std::cout << "\n";
    }

    return 0;
}
