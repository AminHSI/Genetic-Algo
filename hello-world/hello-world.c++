//...Welcome...
// this is "hello world" program built whit genetic algorithm

#include <iostream>
#include <limits>
#include <string>
#include <random>

using namespace std;

const int MAX_f = 4;
const int MAX_s = 5;

string gen_random(int first_part,int sec_part){
    char alphabet_f[MAX_f] = {
    'e','h','l','o'
    };
    char alphabet_s[MAX_s] = {
    'd','l','o','r','w'
    };
    string res1 = "";
    string res2 = "";
    string f_res = "";

    for (int i = 0; i < first_part; i++){
    res1 = res1 + alphabet_f[rand() % MAX_f];
    }
    for (int j = 0; j < sec_part; j++){
    res2 = res2 + alphabet_s[rand() % MAX_s];
    }

    f_res = res1 + " " + res2;
    return f_res;
}

void cross_over(string(&pre_population),int length){
    string population[length];
    for (int i = 0;i<(length/2);i+=2){
        string baby_1 = pre_population[i][1] + pre_population[i+1][-1];
        string baby_2 = pre_population[i][-1] + pre_population[i+1][1];
        
        pre_population[i] = baby_1;
        pre_population[i+1] = baby_2;
        
    }

    
}


void evalute(string population[],int length,string target_word){
    for (int i =0;i<length;i++){
        if (population[i] == target_word){
            cout << population[i] << ": our hello world!" << endl;
        }
    }
}

int main(){

// initialazing algo req.

    int init_population = 1000;
    int letter_num_f = 5;
    int letter_num_s = 5;

    string population[init_population];
    string target_word = "hello world";
    srand(time(NULL));

//generating an array of random words
    for (int j=0; j<init_population;j++){
        population[j] = gen_random(letter_num_f,letter_num_s);

    }
    
    for (int k =0;k<init_population;k++){
        cout << population[k] <<endl;
        
    }

//evalutaing 

    evalute(population,init_population,target_word);

//crossing over between arrays

    cross_over(population,init_population);
    
    cout << "second attempt"<< endl;

    for (int k =0;k<init_population;k++){
        cout << population[k] <<endl;
        
    }

    return 0;
}