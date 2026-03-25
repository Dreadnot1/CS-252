#include <iostream>
#include <random>
#include <set>
using namespace std;

const int MIN = 0, MAX = 49, SIZE = 20;

set<string> create_set(string input[SIZE]);

int main()
{
    srand(time(0));
    
    string words[50] = {"cat","dog","bat","rat","hat","map","cup","bus",
    
    "sun","fan","pen","box","fox","log","fog","bed","red","leg","web",
    
    "jet","ant","arm","art","axe","bay","bee","big","bit","bow","bug",
    
    "bun","cab","can","cap","car","cod","cog","cot","cow","cry","cub",
    
    "dew","dig","dim","dip","dot","dry","dug","dye","ear"};
    
    set<string> rnd_words = create_set(words);
    
    for (auto word : rnd_words) {
        cout << word << " ";
    }

    return 0;
}

/*create_set takes a string array argument, uses random numbers to index it, 
inserts the results into a temporary set until it reaches a fixed size, and
then returns the set.*/
set<string> create_set(string input[SIZE]) {
    set<string> temp_set;
    string temp_word;
    
    while (temp_set.size() < SIZE) {
        int rnd = rand() % (MAX - MIN + 1) + MIN;
        temp_word = input[rnd];
        temp_set.insert(temp_word);
    }
    return temp_set;
}