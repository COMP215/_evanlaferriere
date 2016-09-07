//data gen X strings of Y length (or less) outputs to file
//prog that takes in that file and saves on memory the strings in lexographic order on mem
//sorts strings using those program and sorts into three data sets, (runs three times,

using namespace std;
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct parameters{ //A struct to carry all arguments
    int numWords;
    string fileName;
    string* words;
};

int three(parameters words)
{
    srand(time(NULL));
    long startTime = time(NULL);
    string wordHolder;
    bool unsorted = true;
    int place = rand()%words.numWords;
    while (unsorted)
    {
        unsorted = false;
        for(int i = 1; i < words.numWords; i++)
        {
            if(words.words[words.numWords-i].compare(words.words[words.numWords-1])>0)
            {
                wordHolder = words.words[words.numWords-i];
                words.words[words.numWords-i] = words.words[words.numWords-1];
                words.words[words.numWords-1] = wordHolder;
                unsorted = true;
            }
        }
    }
    long endTime = time(NULL);
    return (endTime - startTime);
}

parameters one()
{
    srand (time(NULL));
    int lengthWords;
    parameters userInput;
    const string randGen = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz";

    cout << "How many words would you like to generate? ";
    cin >> userInput.numWords;
    cout << "How long would you like your words to be? ";
    cin >> lengthWords;
    cout << "And under what name would you like to save the file? ";
    cin >> userInput.fileName;
    ofstream outfile;
    outfile.open(userInput.fileName.c_str());

    for(int i=0; i < userInput.numWords; i++)
    {
        string word = "";
        for(int j=0; j < lengthWords; j++)
        {
            int t = rand();
            word = word + (randGen[t%randGen.length()]);
        }
        outfile << word << endl;
    }
    outfile.close();
    return userInput;
}

parameters two(parameters words)
{
    bool unsorted = true;
    ifstream in(words.fileName.c_str());
    words.words = new string[words.numWords];
    for (int i = 0; i < words.numWords; i++)
    {
         getline(in, words.words[i]);
    }
    while (unsorted)
    {
        unsorted = false;
        for(int i = 0; i+1 < words.numWords; i++)
        {
            string holder;
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

int main()
{
    int processingTime1 = three(two(one()));
    cout << "Completed in " << processingTime1 << " seconds." << endl;
    int processingTime2 = three(two(one()));
    cout << "Completed in " << processingTime2 << " seconds." << endl;
    int processingTime3 = three(two(one()));
    cout << "Completed in " << processingTime3 << " seconds." << endl;
    cout << "Done! It took " << processingTime1+processingTime2+processingTime3 << " seconds.";
    return 0;
}
