// MtgRankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char ValidateAnswer(std::string message);

static char yes = 'Y';
static char no = 'N';

static std::string questionAnswerString = "\n Y) Yes \n N) No\n";

int main()
{
    bool running = true;
    std::string deckName;
    char comDraw;
    char combo;
    char tutor;
    char graveYard;
    char landDes;
    char comManaCheat;
    char fastMana;
    char Free;
    char stax;
    char winCon;
    char phases;
    char companion;
    int points;

    while (running)
    {
        points = 0;
        std::cout << "What is the name of your deck?\n";
        std::cin >> deckName;

        comDraw = ValidateAnswer("\nDoes your commamder have card draw on it?");

        if (comDraw = yes)
        {
            points += 2;
        }

        combo = ValidateAnswer("\nDo you have a 2 to 3 card infinte combo in the deck?");

        if (combo = yes)
        {
            points += 2;
        }

        tutor = ValidateAnswer("\nDoes this deck have any tutors in it?");

        if (tutor = yes)
        {
            points += 2;
        }

        char answer = ValidateAnswer("\nDo you wish to tell me another deck's name?");

        if (answer == no)
        {
            running = false;
        }
    }

    std::cout << "\n\nRanking System Shutting Down......\n";
}

char ValidateAnswer(std::string message)
{
    char answer; 
    bool checkAgain = false;
    do
    {
        checkAgain = false;

        std::cout << message << questionAnswerString;
        std::cin >> answer;

        answer = toupper(answer);
        if (answer != yes && answer != no)
        {
            std::cout << answer << " is not a validate answer. Please try again valiad answers are " << yes << " and " << no << ".....\n";
            checkAgain = true;
        }

    } while (checkAgain);

    return answer;
}
