#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <array>
#include <list>
using namespace std;


int randomnum() {
    random_device r;
    uniform_int_distribution<int> number(0,9);
}

int sort(int numbers) {

}

int main() {
    cout << "enter a 4-digit number: ";
    string target;
    cin >> target;
    int numbers[40][5];
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            numbers[i][j] = randomnum();
        }
    }

}
