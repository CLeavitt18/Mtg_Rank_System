// MtgRankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void NewDeck();
char ValidateAnswer(std::string message, char answers[], std::string answerMessages[], int legnth);
void AddPoints();
void GetRank();
void Save(std::string deckName);
void Load(std::string deckName);

static int ranges[6][2] = { { 0,1 }, { 2,3 }, {4, 7}, { 8, 11}, {12, 15}, {16, 19} };
static std::string ranks[6] = { "D", "C", "B", "A", "S", "S+"};

static char answers[] = { 'Y','N' };
static std::string answerMessages[2] = { "Yes", "No"};
    
static char criteria[12];
static int points[12] = { 2,2,2,2,2,1,1,2,1,2,1,1 };
static int pointTotal;
static std::string rank;

static std::string deckQuestions[12] = 
    { "\nDoes your commamder have card draw on it?",
      "\nDo you have a 2 to 3 card infinte combo in the deck?",
      "\nDoes this deck have any tutors in it?",
      "\nDo you have a way of getting things out of the grave yard repeatedly?",
      "\nCan you destroy lands on mass?",
      "\nDoes your commander have a way of cheating on mana?",
      "\nDo you have fast mana",
      "\nDo you have free interaction",
      "\nDo you have any stax pieces in this deck?",
      "\nIs there an alternate win con in the deck?",
      "\nDo you have any way of getting extra phases in this deck?",
      "\nIs there a companion or partener of this deck?"
    };


int main()
{
    bool running = true;
    std::string deckName;

    char options[] = { '1', '2' };
    std::string optionMessages[] = { "New Deck", "Load Deck" };
    char answer;
    
    while (running)
    {
        system("CLS");

        answer = ValidateAnswer("\nWhat would you like to do?", options, optionMessages, 2);

        switch (answer)
        {
            case '1':
                NewDeck();
                break;
            case '2':
                break;
        };

        if (ValidateAnswer("\nDo you wish to rank another deck?", answers, answerMessages, 2) == answers[1])
        {
            running = false;
        }
    }

    std::cout << "\n\nRanking System Shutting Down......\n";
    return 0;
}

void NewDeck()
{
    std::string deckName;

    std::cout << "What is the name of your deck?\n>";
    std::cin >> deckName;

    for (size_t i = 0; i < 12; i++)
    {
        criteria[i] = ValidateAnswer(deckQuestions[i], answers, answerMessages, 2);
    }

    AddPoints();
    GetRank();

    std::cout << "\n\nPoint Total: " << pointTotal << "\nRank: " << rank << '\n';

    if (ValidateAnswer("\nWould you like to save this deck?\n", answers, answerMessages, 2) == answers[0])
    {
        Save(deckName);
    }
}

char ValidateAnswer(std::string message, char answers[], std::string answerMessages[], int length)
{
    char answer; 
    bool checkAgain = false;
    int y;

    do
    {
        std::cout << message;
        for (size_t i = 0; i < length; ++i)
        {
            std::cout << "\n" << answers[i] << ") " << answerMessages[i];
        }

        std::cout << "\n>";
        std::cin >> answer;

        answer = toupper(answer);

        y = 1;

        for (size_t i = 0; i < length; i++)
        {
            if (answer == answers[i])
            {
                y = 0;
                break;
            }
        }

        if (y == 1)
        {
            std::cout << '\n' << answer << " is not a validate answer. Please try again valiad answers are:\n";
            
            for (size_t i = 0; i < length; i++)
            {
                std::cout << answers[i] << ") " << answerMessages[i] << '\n';
            }

            std::cout << "\n";
            checkAgain = true;
        }
        else
        {
            checkAgain = false;
        }

    } while (checkAgain);

    return answer;
}

void AddPoints()
{
    pointTotal = 0;

    for (size_t i = 0; i < 12; i++)
    {
        if (criteria[i] == answers[0])
        {
            pointTotal += points[i];
        }
    }
}

void GetRank()
{
    for (size_t i = 0; i < 6; i++)
    {
        if (pointTotal >= ranges[i][0] && pointTotal <= ranges[i][1])
        {
            rank = ranks[i];
        }
    }
}

void Save(std::string deckName)
{
    std::ofstream file(deckName + ".deck");

    std::string _string = "";

    for (size_t i = 0; i < 12; i++)
    {
        _string += std::to_string(criteria[i]) +"\n";
    }

    _string += std::to_string(pointTotal) + "\n";
    _string += rank;

    file << _string;

    file.close();
}

void Load(std::string name)
{
    std::ifstream file(name + ".deck");
    std::string temp = "";

    if (file.is_open() == false)
    {
        // give error message
        return;
    }
       
    for (size_t i = 0; i < 12; i++)
    {
        std::getline(file, temp);
        criteria[i] = temp[0];
    }

    AddPoints();
    GetRank();

    file.close();
}

void DisplayDeck(std::string deckName)
{

}