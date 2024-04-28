#include <iostream>
#include <string>
#include <random>
#include <array>
using namespace std;

const int init_population = 60;
const float population_rate = 0.6;

int randomnum () {

    random_device r;

    uniform_int_distribution<int> number(0,9);

    return number(r);
}




void evaluate (int(&numbers)[init_population][5], int target[4]) {
    
    for (int i=0 ; i<init_population ; i++) {
        
        int counter = 0;
 
        for (int j=0 ; j<4 ; j++){
            
            if (numbers[i][j] == target [j]) {
                counter ++;
            }
            numbers[i][4] = counter;
        }
    }
}


void sort(int(&numbers)[init_population][5]) {

    for(int i=0 ; i<init_population ; i++) {

        int maxvalue[2] = {i, numbers[i][4]};
        

        for(int j=i ; j<init_population ; j++) {

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


//cross_over();


void mutation(int(&numbers)[init_population][5]){
    
    for(int i=0 ; i< int(init_population * population_rate) ; i++) {

        numbers[randomnum()][randomnum()] = randomnum();
    }
}


int main() {

    cout << "enter a 4-digit number: ";

    int target[4];

    for(int i=0 ; i<4 ; i++){
        cin >> target[i];
    }

    int numbers[init_population][5];

    for(int i=0;i<init_population;i++) {

        for(int j=0;j<4;j++) {

            numbers[i][j] = randomnum();
        }
    }

    int generation = 0;
    
    while(1) {

        evaluate(numbers, target);


        sort(numbers);


        if(numbers[0][4] == 4) {

            cout << "target was found in generation " << generation;
            break;

        } else {

            cout << "best case found so far: ";

            for (int h = 0 ; h<4 ; h++){

                cout << numbers[0][h];
            }

            //call crossover

        
            mutation(numbers);
        }
    }
    
    
    return 0;
}
