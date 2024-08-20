## Aryan Chhabra
## 08/22/2023
  

import random;
import check_input;


def main():

  print("I'm thinking of a number between 1 and 100!")
  guessNum = 0
  randomNum = random.randint(1, 100); ## Generates a random number between 1 and 100
  running = 0

  ## The while loop allows the program to continuously run until the number is guessed
  while(running == 0):
    guessNum = guessNum + 1
    
  
    guess = check_input.get_int_range("Guess the number: ", 1, 100)
    
    ## Tells user if number is correct, if not prints
    ##Too high or too low
    if(guess == randomNum):
      print("You guessed the number!")
      print("Number of tries: ", guessNum)
      running = 1
        
    elif(guess > randomNum):
      print("Too high!")
        
    elif(guess < randomNum):
      print("Too low!")


main()
