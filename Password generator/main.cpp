/*
    This program let you generate a random password.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int userInput;
string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string numbers = "0123456789";
string symbols = "~`!@#$%^&*()_-+={[}]|:;<,>.?/";



void PrintMenu();
string GenerateRandomPassword();
void GenerateRandomPasswordFromParameters();

int main(){

    srand (time(NULL));

    //menu loop
    while(userInput != 3){
        PrintMenu();

        //execute the function in base of the user input
        if(userInput == 1){
            cout<<"____________________________________________________________"<<endl;
            cout<<"Your randomly generated password is: " << GenerateRandomPassword()<<endl;
            cout<<"____________________________________________________________"<<endl;
        }else if(userInput == 2){
            cout<<"____________________________________________________________"<<endl;
            GenerateRandomPasswordFromParameters();
            cout<<"____________________________________________________________"<<endl;
        }else if(userInput == 3){
            return 0;
        }
    }

}

void PrintMenu(){

    cout<<"____________________________________                                "<<endl;
    cout<<"| Password generator by @ryuk4real |"<<endl;
    
    cout<<"Send the number to select a command: "<<endl;
    cout<<"1 - generate random password"<<endl;
    cout<<"2 - choose parameters to generate a new password"<<endl;
    cout<<"3 - exit :)"<<endl;

    //the user chooses a command
    cin>>userInput;
    return;
}

string GenerateRandomPassword(){
    srand (time(NULL));
    unsigned passLenght = rand() % 26 + 6;

    //generate a blank string with passLenght number of characters
    char blankChar = ' ';
    string password = "";

    for(unsigned i = 0; i < passLenght; i++){
        password += blankChar;
    }

    //Create password--------------------------------------------------------
    for(unsigned i = 0; i < passLenght; i++){
        //choose a type (from numb. lett. or symb)
        unsigned randomType = rand() % 100;
        if(randomType < 40){

            //choose a random letter
            unsigned randomLetter = rand() % letters.length();
            password[i] = letters[randomLetter];

        }else if(randomType >= 40 && randomType <= 65){

            //choose a random number
            unsigned randomNumber = rand() % numbers.length();
            password[i] = numbers[randomNumber];

        }else if(randomType > 65){

            //choose a random symbol
            unsigned randomSymbol = rand() % symbols.length();
            password[i] = symbols[randomSymbol];

        } 
    }
    return password;
}



void GenerateRandomPasswordFromParameters(){

    //password lenght
    unsigned passLenght;
    cout<<"Choose a string lenght: ";
    cin>>passLenght;


    //generate a blank string with passLenght number of characters
    char blankChar = ' ';
    string password = "";

    for(unsigned i = 0; i < passLenght; i++){
        password += blankChar;
    }

    //Create password--------------------------------------------------------
    for(unsigned i = 0; i < passLenght; i++){
        //choose a type (from numb. lett. or symb)
        unsigned randomType = rand() % 100;
        if(randomType < 40){

            //choose a random letter
            unsigned randomLetter = rand() % letters.length();
            password[i] = letters[randomLetter];

        }else if(randomType >= 40 && randomType <= 85){

            //choose a random number
            unsigned randomNumber = rand() % numbers.length();
            password[i] = numbers[randomNumber];

        }else if(randomType > 85){

            //choose a random symbol
            unsigned randomSymbol = rand() % symbols.length();
            password[i] = symbols[randomSymbol];

        } 
    }
    cout << "Your password is: " << password << endl;
    return;

}