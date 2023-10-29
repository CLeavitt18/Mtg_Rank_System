// MtgRankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char ValidateAnswer(std::string message);
int AddPoints();
char GetRank();

static char yes = 'Y';
static char no = 'N';
    
static char criteria[12];
static int points[12] = { 2,2,2,2,2,1,1,2,1,2,1,1 };

static std::string questionAnswerString = "\n Y) Yes \n N) No\n";

int main()
{
    bool running = true;
    std::string deckName;
    int points;

    while (running)
    {
        system("CLS");
        std::cout << "What is the name of your deck?\n";
        std::cin >> deckName;

        criteria[0] = ValidateAnswer("\nDoes your commamder have card draw on it?");
        criteria[1] = ValidateAnswer("\nDo you have a 2 to 3 card infinte combo in the deck?");
        criteria[2] = ValidateAnswer("\nDoes this deck have any tutors in it?");
        criteria[3] = ValidateAnswer("\nDo you have a way of getting things out of the grave yard repeatedly?");
        criteria[4] = ValidateAnswer("\nCan you destroy lands on mass?");
        criteria[5] = ValidateAnswer("\nDoes your commander have a way of cheating on mana?");
        criteria[6] = ValidateAnswer("\nDo you have fast mana");
        criteria[7] = ValidateAnswer("\nDo you have free interaction");
        criteria[8] = ValidateAnswer("\nDo you have any stax pieces in this deck?");
        criteria[9] = ValidateAnswer("\nIs there an alternate win con in the deck?");
        criteria[10] = ValidateAnswer("\nDo you have any way of getting extra phases in this deck?");
        criteria[11] = ValidateAnswer("\nIs there a companion or partener of this deck?");

        points = AddPoints();

        std::cout << "\n\nPoint Total: " << points;

        char answer = ValidateAnswer("\nDo you wish to rank another deck?");

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

int AddPoints()
{
    int returnValue = 0;

    for (size_t i = 0; i < 12; i++)
    {
        if (criteria[i] == yes)
        {
            returnValue += points[i];
        }
    }

    return returnValue;
}

char GetRank()
{
    return '\0';
}
