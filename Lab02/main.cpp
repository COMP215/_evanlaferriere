//data gen X strings of Y length (or less) outputs to file
//prog that takes in that file and saves on memory the strings in lexographic order
//sorts strings using those program and sorts into three data sets, (runs three times)

using namespace std;
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct Parameters{ //A struct to carry all arguments
    int num_words;
    string file_name;
    string* words;
};

int Three(Parameters words)
{
    srand(time(NULL));
    long startTime = time(NULL);
    string wordHolder;
    bool unsorted = true;
    int place = rand()%words.num_words;
    while (unsorted)
    {
        unsorted = false;
        for(int i = 1; i < words.num_words; i++)
        {
            if(words.words[words.num_words-i].compare(words.words[words.num_words-1])>0)
            {
                wordHolder = words.words[words.num_words-i];
                words.words[words.num_words-i] = words.words[words.num_words-1];
                words.words[words.num_words-1] = wordHolder;
                unsorted = true;
            }
        }
    }
    long endTime = time(NULL);
    return (endTime - startTime);
}

Parameters Two(Parameters words)
{
    bool unsorted = true;
    ifstream in(words.file_name.c_str());
    words.words = new string[words.num_words];
    for (int i = 0; i < words.num_words; i++)
    {
         getline(in, words.words[i]);
    }
    while (unsorted)
    {
        unsorted = false;
        for(int i = 0; i+1 < words.num_words; i++)
        {
            string holder = ""; //for sorting
            if (words.words[i].compare(words.words[i+1]) > 0)
            {
                holder = words.words[i];
                words.words[i] = words.words[i+1];
                words.words[i+1] = holder;
                unsorted = true;
            }
        }
    }
    return words;
}
Parameters One()
{
    srand (time(NULL));
    Parameters user_input;
    const string randGen = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz";

    cout << "How many words would you like to generate? ";
    cin >> user_input.num_words;
    cout << "How long would you like your words to be? ";
    int length_words;
    cin >> length_words;
    cout << "And under what name would you like to save the file? ";
    cin >> user_input.file_name;
    ofstream outfile(user_input.file_name.c_str());

    for(int i=0; i < user_input.num_words; i++)
    {
        string word = "";
        for(int j=0; j < length_words; j++)
        {
            int t = rand();
            word = word + (randGen[t%randGen.length()]);
        }
        outfile << word << endl;
    }
    outfile.close();
    return user_input;
}


int main()
{
    int processingTime1 = Three(Two(One()));
    cout << "Completed in " << processingTime1 << " seconds." << endl;
    int processingTime2 = Three(Two(One()));
    cout << "Completed in " << processingTime2 << " seconds." << endl;
    int processingTime3 = Three(Two(One()));
    cout << "Completed in " << processingTime3 << " seconds." << endl;
    cout << "Done! It took " << processingTime1+processingTime2+processingTime3 << " seconds.";
    return 0;
}
