#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "hangman.hpp"

using namespace std;

void game_loop (Hangman * game) {
    cout<<"Guess a letter: ";
    char guess;
    cin>>guess;
    int score = game->check_guess(guess);
    if (score==0){
        cout<<"Bad guess. You have "<<7 - game->get_fails()<<" lives remaining."<<endl;
    } else {
        cout<<game->get_solution()<<endl;
    }
}
int main () {
   
   //initialize the game and collect the seed to determine word
    Hangman * game = new(Hangman);
    cout<<"Welcome to Hangman!"<<endl<<"Enter a number to begin: ";
    int index;
    cin>>index;
    game->set_index(index);
    string word = game->get_word();

    //initialize the solution and start the guessing
    game->solution_init();
    cout<<game->get_solution()<<endl<<"("<<word.length()<<" letters)"<<endl;
    while (game->game_status() == 1) {
        game_loop(game);
    }
    if (game->game_status() == 2) {
        cout<<"Better luck next time."<<endl;
    }
    if (game->game_status() == 0) {
        cout<<"You win!"<<endl;
    }
    cout<<"The word was "<<word<<"."<<endl;


    return 0;
}