#include <iostream>
#include <vector>


int max_seq(std::vector<int> seq) {
    int max = seq[0];

    for (int i =0; i< seq.size(); i++) {
        if (seq[i] > max) {
            max = seq[i];
        }
    }

    return max;
}

void output(std::vector<std::vector<int>> seq){
    std::cout<<"Biggest numbers out of every sequence:"<<'\n';
    int numb;
    std::vector<int> maxes;

    for (int i =0;i< seq.size(); i++) {
        numb = max_seq(seq[i]);
        std::cout<<numb<<'\n';
        maxes.push_back(numb);
    }

    std::cout<<"Global max:"<<'\n';

    numb = max_seq(maxes);
    std::cout<<numb;

}

void subpunkt_a(std::vector<std::vector<int>>& all_seq) {
    //vector ajutator unde voi memora fiecare subsecventa
    std::vector<int> seq;
    int numb;

    while (true) {
        std::cin >> numb;

        if (numb == -1) break;

        //memorarea subsecventei in all_seq si curatarea acesteia pentru a putea memora urmatoarea
        if (numb == 0) {
            if (!seq.empty()) {
                all_seq.push_back(seq);
                seq.clear();
            }
        }
        else seq.push_back(numb);
    }
    //memorarea ultimei secvente in caz ca exista
    if (!seq.empty())
        all_seq.push_back(seq);

    output(all_seq);

    std::cout<<'\n';
}

void subpunkt_b(const std::vector<std::vector<int>>& all_seq, int a, int b) {
    std::vector<int> all_numbs;

    //din vectorul de vectori creez un vector simplu
    for (int i = 0; i < all_seq.size(); i++) {
        for (int j = 0; j < all_seq[i].size(); j++) {
            all_numbs.push_back(all_seq[i][j]);
        }
    }

    int max_length = 0;
    int current_length = 0;
    int max_start = 0;
    int current_start = 0;

    for (int i = 0; i < all_numbs.size(); i++) {
        //verific conditia
        if (all_numbs[i] >= a && all_numbs[i] <= b) {
            //daca sunt la inceputul unei secvente noi luam ca inceput indexul curent
            if (current_length == 0) current_start = i;
            current_length++;

            //verific daca am gasit o secventa mai lunga decat cea dinainte
            if (current_length > max_length) {
                max_length = current_length;
                max_start = current_start;
            }
        }
        else {
            current_length = 0;
        }
    }

    //afisare
    if (max_length > 0) {
        for (int i = max_start; i < max_start + max_length; i++) {
            std::cout << all_numbs[i] << " ";
        }
        std::cout << '\n';
    }
    //caz in care lungimea finala maxima este 0
    else {
        std::cout << "No valid sequence found"<<'\n';
    }
}

int main() {
    std::vector<std::vector<int>> all_seq;
    std::vector<int> seq;
    int a;
    int b;

    subpunkt_a(all_seq);

    std::cout<<"Enter a interval(a < b):";

    std::cin >> a;
    std::cin >> b;

    subpunkt_b(all_seq , a , b);

    return 0;
}