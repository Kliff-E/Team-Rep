#include <iostream>
#include <cstdlib>
#include <ctime>

void startgame();

int main()
{
    char playAgain;

    do{

    startgame();

    std::cout << "Would you like to play again? (y/n): ";
    std::cin >> playAgain;

    }while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Goodbye.\n";
    


    return 0;
}

void startgame()
{
    const int MAX_ATTEMPTS(10);
    int secretnr, guess;
    int attempts(0);

    std::srand(static_cast<unsigned int>(std::time(0)));
    secretnr = std::rand() % 100; // Random number between 0 and 99

    std::cout << "I have chosen a secret number between 0 and 99.\n";
    std::cout << "You have " << MAX_ATTEMPTS << " attempts to guess it.\n";


    while (attempts < MAX_ATTEMPTS)
    {
        std::cout << "Attempt #" << (attempts + 1) << ": Enter your guess ";
        std::cin >> guess;

        if (guess < secretnr)
        {
            std::cout << "Too small! Try again.\n";
        }
        else if(guess > secretnr)
        {
            std::cout << "Too big! Try again.\n";
        }
        else{
            std::cout << "Correct! You've guessed the number in " << (attempts + 1) << " attempts.\n";
            return;
        }

        attempts++;
        
        
    }

    std::cout << "Sorry, you've used all " << MAX_ATTEMPTS << " attempts. The secret number was: " << secretnr << "\n";
    

}
