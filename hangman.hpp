#ifndef hangman_hpp
#define hangman_hpp


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class Hangman {
    private:
        std::vector<std::string> words = {"computer", "violin", "fidget", "basketball", "react", "shirt",
        "hallway", "dinosaur", "electric", "christmas", "allowance", "desktop", "alphabet", "headlight", "spatula", "purple",
        "coding", "construction", "application", "sticky", "france", "kitchen"};
        int index = 4;
        int fails = 0;
        std::string solution = "";
    public:
        std::string get_word() {
            return words[index];
        }
        //returns the word of the current game

        int get_index() {
            return index;
        }

        int get_fails() {
            return fails;
        }

        std::string get_solution();
        //returns the current solution

        void solution_init();
        //initialize the solution to be all blank spaces

        void set_index(int new_index);
        //set the index to be in the range of word list
        
        int check_guess(char guess);
        //check the word against the guess
        
        int game_status();
        //check to see if the game is finished or not
        
};


#endif 