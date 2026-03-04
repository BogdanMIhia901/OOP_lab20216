#include <iostream>
#include <vector>
#include <cmath>

double sqrt(double n) {
    if (n<0)return -1;
    if (n==0 || n==1)return n;

    double start = 0;
    double end = n;
    double mid = 0;

    for (int i = 0;i < 10;i++) {
        mid = (start + end)/2;
        if (mid*mid < n) {
            start = mid;
        }
        else if (mid*mid > n) {
            end = mid;
        }
    }
    return mid;
}
bool is_prime(int n) {
    if (n <= 1)return false;
    if (n <= 3)return true;

    for (int i = 2; i*i <= n ;i++) {
        if (n% i == 0)return false;
    }
    return true;
}
double subpunkt_a(double n) {
    return sqrt(n);
}
void subpunkt_b(std::vector<int> list) {
    int start;
    int end = 0;
    int fin_start = 0;
    int fin_end = 0;

    int fin_len = 0;
    int len ;
    int i = 0;

    while (i<list.size()){

        if (i == list.size() -1) {
            break;
        }

        start = i;
        len = 0;

        if (is_prime(abs(list[i] - list[i+1]))) {
            len++;
            end = i+1;

            for (int j = i+1;j<list.size() - 1;j++) {
                if (is_prime(abs(list[j] - list[j+1]))) {
                    len++;
                    end =j+1;
                }
                else break;
            }
            if (len>fin_len) {
                fin_start = start;
                fin_end = end;
                fin_len = len;
            }
            i = end;
        }
        else i++;
    }

    if (fin_len == 0) {
        std::cout << "There are no valid sequences"<<'\n';
        return;
    }

    std::vector<int> fin;

    for (int index = fin_start;index<=fin_end;index++) {
        fin.push_back(list[index]);
    }
    std::cout<<"Longest sequence of elements with the difference a prime number is:"<<'\n';

    for (int index = 0;index<fin.size();index ++) {
        std::cout<<fin[index]<<' ';
    }
    std::cout<<'\n';
}

int main() {
    int x;
    std::cout<<"Write a number:";
    std::cin>>x;
    std::cout<<"The square root of the number is "<<subpunkt_a(x)<<'\n';

    int n;
    std::cout<<"Number of elements in the vector:"<<'\n';
    std::cin>>n;

    std::vector<int> vector;
    int element;
    for (int i = 0;i<n;i++) {
        std::cin>>element;
        vector.push_back(element);
    }

    subpunkt_b(vector);

    return 0;
}
