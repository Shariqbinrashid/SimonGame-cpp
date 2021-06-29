#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <vector>


using namespace std;

int score = 0;
int v1 = 0;

void instructions();
void displayPatern();
void userInput();
boolean comparePatern();

std::vector<std::string> colour{ "R", "B", "G","Y" }; 
std::vector<std::string> pattern;
std::vector<string> userpatern;



int r = 1;


int main()
{



    instructions();
    cout << "\n";
    system("PAUSE");

    while (1) {

       

        displayPatern();

        r++;

        userInput();

        if (comparePatern()) {
            score++;
            cout << "Your guess is right, your score is " << score << endl;
        }
        else {
            cout << "Your guess is wrong , your final score is " << score << endl;
            break;
        }
    }
  
    cout << "Thank you!!"; 

   // system("CLS");

  
   
    
}

void instructions() {
    cout << "Welcome to the Simon color game!" << endl;

    cout << "R=red , G= greeen , B= blue , Y = yellow" << endl;
    cout << "Enter the patern in specific order it displays everytime, without space" << endl;
}


void displayPatern() {
    pattern.clear();
    srand(time(NULL));
    for (int i = 0; i < r+3; i++) {
        v1 = rand() % 4;
        Sleep(300);
        std::cout << colour[v1] << " ";
        pattern.push_back(colour[v1]);
    }
    Sleep(800);
    cout << "\33[2K";
    cout << "\n Enter patern ";
}

void userInput() {
    userpatern.clear();
    string temp;
    std::cin >> temp;
    int n = temp.length();
   

    for (int i = 0; i < temp.length(); i++) {
        string s(1, temp[i]);
        userpatern.push_back(s);
    }
    
   
}

boolean comparePatern() {
    if (userpatern == pattern)
        return true;

    return false;
}

