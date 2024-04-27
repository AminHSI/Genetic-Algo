//...Welcome...
// this is "hello world" program built whit genetic algorithm

#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int MAX = 8;
//generating a string of random alphabets 
string gen_random(int n){
    /*char alphabet[MAX] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y','z',' '};*/
    char alphabet[MAX] = {
    'd','e','h','l','o','r','w',' '
    };
    string res = "";
    for (int i = -1; i < n; i++){
    res = res + alphabet[rand() % MAX];
    }
    return res;
}

int main(){

    int init_population = 500;
    int letter_num = 10;
    string population[init_population];
    int correct = 0;

    char word[11];
    char alphabet[28] = {};
    string target_word = "hello world";

    srand(time(NULL));


    for (int i = 0; i < 11; i++) {
        word[i] = target_word[i];
    }

    for (int j=0; j<init_population;j++){
        
        population[j] = gen_random(letter_num);
        string test_word = population[j];
        for (int l=0;l<letter_num;l++){
            if (test_word[l] == target_word[l]){
                correct += 1;
            }
        }

    }
    
    for (int k =0;k<init_population;k++){
        cout << population[k] <<endl;
        
    }

    




    return 0;
}