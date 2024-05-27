#include <iostream>
#include <string>
#include <random>
#include <array>
using namespace std;


//----------------------------- configuration --------------------------------

const int init_population = 100;
const int repeat = 10;
const float mutation_rate = 0.5;

//----------------------------------------------------------------------------
//---------------------------- number generator ------------------------------

int randomnum () {
    random_device r;
    uniform_int_distribution<int> number(0,9);
    return number(r);
}

//----------------------------------------------------------------------------
//---------------------------- fintness function -----------------------------

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

//----------------------------------------------------------------------------
//--------------------------------- sort -------------------------------------

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

//----------------------------------------------------------------------------
//------------------------------ cross over ----------------------------------

void cross_over(int(&numbers)[init_population][5]){
    for (int i=0 ; i<init_population/2 ; i+=2){

        numbers[i + (init_population/2)][0] = numbers[i][0];
        numbers[i + (init_population/2)][1] = numbers[i][1];
        numbers[i + (init_population/2)][2] = numbers[i+1][2];
        numbers[i + (init_population/2)][3] = numbers[i+1][3];
        
        numbers[i + (init_population/2) +1][0] = numbers[i+1][0];
        numbers[i + (init_population/2) + 1][1] = numbers[i+1][1];
        numbers[i + (init_population/2) + 1][2] = numbers[i][2];
        numbers[i + (init_population/2) + 1][3] = numbers[i][3];      
    }
}

//----------------------------------------------------------------------------
//-------------------------------- print -------------------------------------

void print(int(&numbers)[init_population][5]) {
    for (int i =0 ; i<init_population ; i++) {
        for (int j =0 ; j<5 ; j++){
            cout << numbers[i][j];
        }   
        cout << endl;
    } 
}

//----------------------------------------------------------------------------
//------------------------------- Mutation -----------------------------------

void mutation(int(&numbers)[init_population][5]){    
    for(int i=0 ; i< int(init_population * mutation_rate) ; i++) {
        numbers[randomnum()][randomnum()] = randomnum();
    }
}

//----------------------------------------------------------------------------
//-------------------------------- M A I N -----------------------------------
//----------------------------------------------------------------------------

int main() {

    //setting the target
    int target[4];
    cout << "enter a 4-digit number: ";                          
    for(int i=0 ; i<4 ; i++){
        cin >> target[i];
    }

    //creating our initial population
    int numbers[init_population][5];
    for(int i=0;i<init_population;i++) {         
        for(int j=0;j<4;j++) {
            numbers[i][j] = randomnum();
        }
    }
    int generation = 0;

    
    for(int rpt=0 ; rpt < repeat ; rpt++) {

        //evaluating and sorting the result
        evaluate(numbers, target);
        sort(numbers);

        //checking for the target
        if(numbers[0][4] == 4) {
            cout << "target was found in generation " << generation;
            break;

        } else {
            cout << "best case found in generation " << generation << " is : " ;
            for (int i=0 ; i<4 ; i++) {
                cout << numbers[0][i];
            }
            cout << endl;

            //creating the next generation
            cross_over(numbers);
            mutation(numbers);
            generation++;
        }       
    }   
    return 0;
}
