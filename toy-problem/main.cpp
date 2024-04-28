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

    for(int i=0 ; i<40 ; i++) {

        int maxvalue[2] = {i, numbers[i][4]};
        

        for(int j=i ; j<40 ; j++) {

            if(numbers[j][4] > maxvalue[1]) {

                maxvalue[0] = j; maxvalue[1] = numbers[j][4];
            }
        }
        
        int tempnum[5];

        for(int j=0 ; j<5 ; j++) {
            tempnum[j] = numbers[i][j];
        }
        for(int j=0 ; j<5 ; j++) {
            numbers[i][j] = numbers[maxvalue[0]][j];
        }
        for(int j=0 ; j<5 ; j++) {
            numbers[maxvalue[0]][j] = tempnum[j];
        }

    }
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

    int generation = 0;
    
    evaluate(numbers, target);


    sort(numbers);


    if(numbers[0][4] == 4) {
        cout << "best case was found in generation " << generation;
    }
    



    
    return 0;
}
