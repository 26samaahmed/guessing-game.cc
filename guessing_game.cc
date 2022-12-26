#include <cmath>
#include <iostream>
#include <string>

const int kSecretNumber = {42};

int main(int argc, char const *argv[])
{
  int guess = 0;
  int last_guess = 0;
  bool is_game_over{false};
  std::string answer;
  std::cout << "Hi - I'm a computer and I've thought of a number between "
               "1 and 100.\n";
  std::cout << "Let's play a guessing game...\n";
  do
  {
    std::cout << "What's your guess?";
    std::cin >> guess;
    if (guess == kSecretNumber)
    {
      std::cout << "Correct, you win!!!\n";
      std::cout << "Do you want to play again? (y or n) \n";
      std::cin >> answer;
      if (answer == "y")
      {
        is_game_over = false;
      }
      else if (answer == "n")
      {
        break;
      }
      else
      {
        std::cout << "you did not choose y or n.. try again";
      }
    }
    else if (guess < 1 || guess > 100)
    {
      std::cout << "You need to enter a number between 1 and 100 \n";
    }
    else if (std::abs(kSecretNumber - guess) <
             std::abs(kSecretNumber - last_guess))
    {
      std::cout << "You're getting warmer!\n";
    }
    else
    {
      std::cout << "You're getting colder.\n";
    }
    last_guess = guess;
  } while (!is_game_over);
  return 0;
}