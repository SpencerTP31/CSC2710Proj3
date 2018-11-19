/*
 * Author: Spencer Peters
 * Date: 9/23/18
 * Class: CSC-2710
 * File Location: ~/CSC2710/Proj3
 *
 * This program looks at graphs and determines if they're connected or disconnected
 * using floyd,warshalls algorithm
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function Prototypes
void load(int matrix[][64], string names[], int amtRela, int &loc);
int search(string names[], string test, int &loc);
void FloydWarshall(int matrix[][64], int &loc);
bool check(int matrix[][64], int &loc);

/*Main Function:
 *      Is used to call all the other function in order to determine if the
 *      graph is disconnected or connected
 */
int main()
{
    int amtSets;
    cin >> amtSets;
    for (int k = 0; k < amtSets; k++)
    {
        string names[64];
        int matrix[64][64];
        int amtRela;
        int loc = 0;
        cin >> amtRela;
        for (int i = 1; i <= amtRela; i++) {
            for (int j = 1; j <= amtRela; j++) {
                matrix[i][j] = 0;
            }
        }
        load(matrix, names, amtRela, loc);
        FloydWarshall(matrix, loc);
        bool checker = check(matrix, loc);
        if(checker == true)
        {
            cout << "Connected" << endl;
        }
        else
        {
            cout << "Disconnected" << endl;
        }
    }
    return 0;
}

/*Load Function:
 *      Reads in the price of the stock from the data file and calculates the change
 *
 *precondition:
 *      takes a matrix that is intialized to all zeros and then fills the array of names
 *      then sends the name to search in order to tell if it has been scanned in before
 *      and loc keeps count of the different amount of names
 *
 *post conditon:
 *      once the function has run it will have filled the name array with all the names
 *      and no duplicate names and will use loc to have an accurate amount of names
 */
void load(int matrix[][64], string names[], int amtRela, int &loc)
{
    string firstName;
    string secondName;
    string throwAway;
    int subofFirst;
    int subofSecond;
    for (int i = 1; i <= amtRela; i++)
    {
        cin >> firstName;
        cin >> throwAway;
        cin >> secondName;
        subofFirst = search(names,firstName,loc);
        subofSecond = search(names,secondName,loc);
        matrix[subofFirst][subofSecond] = 1;
    }
}

/*Search Function:
 *      This is a function called in the load function in order to search through the
 *      array of names to see
 *
 *precondition:
 *      takes a matrix that is intialized to all zeros and then fills the array of names
 *      then sends the name to search in order to tell if it has been scanned in before
 *      and loc keeps count of the different amount of names
 *
 *post conditon:
 *      once the function has run it will have filled the name array with all the names
 *      and no duplicate names and will use loc to have an accurate amount of names
 */
int search(string names[], string test, int &loc)
{
    for (int i = 1; i <= loc; i++)
    {
        if(names[i] == test)
        {
            return i;
        }
    }
    loc++;
    names[loc] = test;
    return loc;
}

/*FloydWarshall Function:
 *      This function sees if all the names are connected and if they are places a 1 in the matrix
 *      and if they aren't it puts a 0 in the matrix
 *
 *precondition:
 *      it's going to take the matrix[][] array and fill it out based on the amount of names
 *      that was previously found in the load function
 *
 *post conditon:
 *      once the function has ran it will have properly filled the matrix with 0 and 1  based
 *      on the connections
 */
void FloydWarshall(int matrix[][64], int &loc)
{
    int i, j, k;
    for (int k = 1  ; k <= loc; k++)
    {
        for (int i = 1; i <= loc; i++)
        {
            for (int j = 1; j <= loc; j++)
            {
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
}

/*Check Function:
 *      This function checks to see if the graph is connected of disconnected
 *
 *precondition:
 *      it is going to be given the 2D array that has just gone through the warshall
 *      function and is going to check for 0 and 1
 *
 *post conditon:
 *      if any 0 are found it will return false meaning the graph is disconnected
 *      if it returns true that means no zeros were found and this means the graph is
 *      connected
 */
bool check(int matrix[][64], int &loc)
{
    for (int i = 1; i <= loc; i++)
    {
        for (int j = 1; j <= loc; j++)
        {
            if(matrix[i][j] == 0)
            {
                return false;
            }
        }

    }
    return true;
}