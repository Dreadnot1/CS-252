#include <iostream>
#include <random>
#include <vector>
#include <list>
using namespace std;

const int MIN = 0, MAX = 49;

list<string> create_list(vector<string> input);

int main()
{
    srand(time(0));
    
    vector<string> words = {"cat","dog","bat","rat","hat","map","cup","bus",
    
    "sun","fan","pen","box","fox","log","fog","bed","red","leg","web",
    
    "jet","ant","arm","art","axe","bay","bee","big","bit","bow","bug",
    
    "bun","cab","can","cap","car","cod","cog","cot","cow","cry","cub",
    
    "dew","dig","dim","dip","dot","dry","dug","dye","ear"};
    
    list<string> rnd_words = create_list(words);
    
    for (auto word : rnd_words) {
        cout << word << " ";
    }

    return 0;
}

/*create_list takes a string vector argument, uses random numbers to index it, 
inserts the results into a temporary list until it reaches a fixed size, and
then returns the list.*/
list<string> create_list(vector<string> input) {
    list<string> temp_list;
    string temp_word;
    
    for (int i = 0; i < 20; i++) {
        int rnd = rand() % (MAX - MIN + 1) + MIN;
        temp_word = input[rnd];
        temp_list.push_back(temp_word); 
    }
    return temp_list;
}