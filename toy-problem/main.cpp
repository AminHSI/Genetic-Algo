#include <iostream>
#include <string>
#include <random>
#include <array>
using namespace std;


int randomnum () {

    random_device r;

    uniform_int_distribution<int> number(0,9);

    return number(r);
}


void evaluate (int(&numbers)[40][5], int target[4]) {
    
    for (int i=0 ; i<40 ; i++) {
        
        int counter = 0;

        for (int j=0 ; j<4 ; j++){
            
            if (numbers[i][j] == target [j]) {
                counter ++;
            }
            numbers[i][4] = counter;
        }
    }
}


void sort(int(&numbers)[40][5]) {

}


int main() {

    cout << "enter a 4-digit number: ";

    int target[4];

    for(int i=0 ; i<4 ; i++){
        cin >> target[i];
    }

    int numbers[40][5];

    for(int i=0;i<40;i++) {

        for(int j=0;j<4;j++) {

            numbers[i][j] = randomnum();
        }
    }

    
    evaluate(numbers, target);

    for(int i=0;i<40;i++) {

        for(int j=0;j<5;j++) {

            cout << numbers[i][j];
        }
        cout << endl;
    }

    sort(numbers);

    return 0;
}
