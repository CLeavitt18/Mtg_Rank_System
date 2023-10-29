// MtgRankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char VaildateAnswer(char* answer, std::string message);

static char yes = 'Y';
static char no = 'N';

static std::string questionAnswerString = "\n Y) Yes \n N) No\n";

int main()
{
    bool running = true;
    std::string deckName;
    char comDraw;

    while (running)
    {
        std::cout << "What is the name of your deck?\n";
        std::cin >> deckName;

        VaildateAnswer(&comDraw, "\nDoes yor commamder have card draw on it?");

        char answer;

        VaildateAnswer(&answer, "\nDo you wish to tell me another deck's name?");

        if (answer == no)
        {
            running = false;
        }
    }

    std::cout << "\n\nRanking System Shutting Down......\n";
}

char VaildateAnswer(char *answer, std::string message)
{

    bool checkAgain = false;
    do
    {
        checkAgain = false;

        std::cout << message << questionAnswerString;
        std::cin >> *answer;

        *answer = toupper(*answer);
        if (*answer != yes && *answer != no)
        {
            std::cout << *answer << " is not a validate answer. Please try again valiad answers are " << yes << " and " << no << ".....\n";
            checkAgain = true;
        }

    } while (checkAgain);

    return *answer;
}
