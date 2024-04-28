#include <iostream>
#include <string>
#include <random>
#include <array>
using namespace std;

const int init_population = 10;

const int repeat = 7;

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


void cross_over(int(&numbers)[init_population][5]){
    for (int i = 0;i<init_population/2;i+=2){
        for (int j = init_population/2; j < init_population; j+=2)
        {
            numbers[j][0] = numbers[i][0]; numbers[j][1] = numbers[i][1];
            numbers[j][2] = numbers[i+1][2]; numbers[j][3] = numbers[i+1][3];

            numbers[j+1][0] = numbers[i+1][0]; numbers[j+1][1] = numbers[i+1][1];
            numbers[j+1][2] = numbers[i][2]; numbers[j+1][3] = numbers[i][3]; 
        }
        
    }
}


void print(int(&numbers)[init_population][5]){
    for (int k =0;k<init_population;k++){
        for (int w =0;w<5;w++){
            cout << numbers[k][w];
        }   
        cout << endl;
    } 
}


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

        print(numbers);

        if(numbers[0][4] == 4) {

            cout << "target was found in generation " << generation;
            break;

        } else {

            cout << "best case found so far: ";
            for (int h = 0 ; h<4 ; h++) {
                cout << numbers[0][h];
            }
            cout << endl;
            cross_over(numbers);
            mutation(numbers);
            generation++;
        }
        
        
    }
    


    


    
    return 0;
}
