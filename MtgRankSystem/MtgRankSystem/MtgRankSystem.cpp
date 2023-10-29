// MtgRankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    bool running = true;
    std::string deckName;

    while (running)
    {
        std::cout << "What is the name of your deck?\n";

        std::cin >> deckName;

        std::cout << "Do you wish to tell me another deck's name?\n Y) Yes \n N) No\n";

        char answer;
        std::cin >> answer;

        if (toupper(answer) == 'N')
        {
            running = false;
        }
    }

    std::cout << "\n\nRanking System Shutting Down......\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
