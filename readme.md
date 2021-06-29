This Simon game is built with C++. In  this Simon game, 4 colors that are , RED GREEN BLUE YELLOW appears in a pattern and disappears , user Input same pattern , if it matched another pattern appears with 1  more light , if it does not match final score of user displays.

First welcome screen displays with some information of how to play game.
Welcome to the Simon color game!
R=red , G= greeen , B= blue , Y = yellow
Enter the patern in specific order it displays everytime, without space

Press any key to continue . . .

When user press any keys, pattern appears and disappears.
 
Then User is asked to enter pattern.
If User enter correct pattern then it increment score and display next patern.
 
New patterns appears with addition of one more color from colors, if user then inputs wrong pattern then it terminates

 
One more play:
1st PATERN:  GBRG
2ND PATERN: GYBGY
3RD PATERN: GBGYRY
4TH  PATERN: BRYGGGR
5TH PATERN: BYRGYRGRG
CONCOLE RUN:
Welcome to the Simon color game!
R=red , G= greeen , B= blue , Y = yellow
Enter the patern in specific order it displays everytime, without space

Press any key to continue . . .

 Enter patern
GBRG
Your guess is right, your score is 1

 Enter patern GYBGY
Your guess is right, your score is 2

 Enter patern GBGYRY
Your guess is right, your score is 3

 Enter patern BRYGGGR
Your guess is right, your score is 4

 Enter patern BYRGRGG
Your guess is wrong , your final score is 4
Thank you!!

Logic:
 There are 3 global vector strings:

```c++
std::vector<std::string> colour{ "R", "B", "G","Y" }; 
std::vector<std::string> pattern;
std::vector<string> userpatern;
```
1st vector is of available colors. 2nd vector is used to keep track of generated colors pattern. 3rd vector is sued to keep track of user input pattern.
First pattern is generated using display pattern function:
```c++
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
```
Whenever this function is call in main it clear the previous generated pattern and genreted new pattern with respect to r variable. r variable keeps track of each round user is in and it increment with every user right guess.
\33[2K erases the entire line your cursor is currently on. So that user cant see the generated pattern after sleep of 800ms. 
Then user input pattern function is call:
```c++
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
```
Which first erase previous user pattern and adds user input string with breakdown of characters in user pattern vector.

Then  compare pattern function is used to compare both patterns and to terminate or continue accordingly:
```c++
boolean comparePatern() {
    if (userpatern == pattern)
        return true;

    return false;
}
```
