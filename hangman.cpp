#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "hangman.hpp"


std::string Hangman::get_solution(){
    return solution;
}

void Hangman::set_index(int new_index) {
    new_index -= 1;
    index = new_index % words.size();
    return;
}

void Hangman::solution_init() {
    std::string word = get_word();
    int length = word.length();
    for (int i = 0; i < length; i++){
        solution.append("_");
    }
}

int Hangman::check_guess(char guess){
    std::string new_solution = get_solution();
    std::string word = get_word();
    int length = word.length();
    int wrong = 0;
    std::string::iterator word_it = word.begin();
    std::string::iterator sol_it = new_solution.begin();
    for (int i = 0; i < length; i++){
        char letter = *(word_it+i);
        if(letter==guess){
            *(sol_it + i) = letter;
        } else {
            wrong ++;
        }
    }
    if (wrong == length) {
        fails ++;
        return 0;
    }
    solution = new_solution;
    return 1;
}


int Hangman::game_status() {
    std::string word = get_word();
    std::string sol = get_solution();
    if (word == sol) return 0;
    else if (fails == 7) return 2;
    else return 1;
}

