//Programer - Siddhesh Palav
//Subject - CS570
// Mid- Term Exam Solution.
// My solution has multiple output which are similar and thats due to the logic I used ( which you can see in the code below ). 
//I made the basic assumption that swapping positions of the adjescent knight could be consider as a new comibation on the board( consideration of the coordinates of the position of the knights is the key for swapping the postions of the knight and consider it as a new postion )


#include <iomanip>
#include <vector>
#include<iostream>
using namespace std;

//declaration of static variable 
bool** knights;
// Taking user input for board dimension
int n;
//checking % progress of the program.
float progress = 0.0;
//Function Prototype
void start();
// checking rows for finding placement spot
int Generaterow(int, int);
// checking column for finding placement spot
int Generatecol(int, int);
//printing result
void printresult(int);
//board reset 
void resetboard();
//to check whether selected position is colliding with other knight or not 
bool checkSafe(int, int);
// starting of the main function
int main()
{
	// taking user input 'Q' to terminate the program
	char q;
	do
	{
		start();
		cout << "press q to quit";
		cin >> q;

	} 
	
	while ( q!='q');
	return 0;

}
// starting the main functionality 
void start()
{
	// taking input to determine board size
	cout << "Enter the Board Size : ";
	cin >> n;
	// checking wheter the input is valid or not 
	 	while (cin.fail()) 
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  Enter a NUMBER: ";
		cin >> n;
	}
	n = n + 4;
	int result;
	int serial = 1;
	//Creation of Dynamic two dimension Array for storing the position 
	knights = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		knights[i] = new bool[n];
	}
	//Now Lets reset the board to false
	resetboard();
	//Check by placing the first knight at each position of the board
	for (int i = 2; i < (n - 2); i++)
	{
		for (int j = 2; j < (n - 2); j++)
		{
			//Check row wise
			result = Generaterow(i, j);
			//If more than 2*n knights are on the board than print the result
			if (result >= (2 * (n - 4)))
			{
				printresult(serial);
				serial++;
			}
			//Reset the board for next operation
			resetboard();
			//Check column wise
			result = Generatecol(i, j);
			//If more than 2*n knights are on the board than print the result
			if (result >= (2 * (n - 4)))
			{
				printresult(serial);
				
				serial++;
			}
			//Reset the board for next operation
		}
	}
}
int Generaterow(int row, int col)
{
	int temp = 0;
	knights[row][col] = true;
	for (int i = 2; i < (n - 2); i++)
	{
		for (int j = 2; j < (n - 2); j++)
		{
			if (checkSafe(i, j))
			{
				knights[i][j] = true;
				temp++;
			}
		}
	}
	return temp;
}
int Generatecol(int row, int col)
{
	int temp = 0;
	knights[row][col] = true;
	for (int i = 2; i < (n - 2); i++)
	{
		for (int j = 2; j < (n - 2); j++)
		{
			if (checkSafe(j, i))
			{
				knights[j][i] = true;
				temp++;
			}
		}
	}
	return temp;
}
void printresult(int count)
{
	

	cout << "\n---Solution Number : " << count << " ---" << endl;
	
	
	for (int i = 2; i < (n - 2); i++)
	{
		for (int j = 2; j < (n - 2); j++)
		{
			if (knights[i][j] == true)
			{
				cout << "K";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
	cout << int(progress * 100.0) << " % completed";
	//cout.flush();
	progress += 0.035;
		
	
}
void resetboard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			knights[i][j] = false;
		}
	}
}

//checking the safe position for the placement of the knight
bool checkSafe(int row, int col)
{
	if (knights[row - 1][col - 2] == true || knights[row + 1][col - 2] == true ||
		knights[row - 2][col - 1] == true || knights[row - 2][col + 1] == true ||
		knights[row - 1][col + 2] == true || knights[row + 1][col + 2] == true ||
		knights[row + 2][col - 1] == true || knights[row + 2][col + 1] == true)
		return false;
	else
		return true;
}
