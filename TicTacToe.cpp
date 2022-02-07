// create a 3x3 matrix and print it out
#include <iostream>
void CreateBoard(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}
// should prompt the user for a location to play, then return that coordinate

int GetPlayerChoice(int board[3][3])
{
    int row, col;
    std::cout << "Enter a row: ";
    std::cin >> row;
    std::cout << "Enter a column: ";
    std::cin >> col;
    if (board[row][col] == 0)
    {
        int res = board[row][col];
        return res;
    }
    else
    {
        std::cout << "That location is already taken.\n";
        GetPlayerChoice(board);
    }
}

void DisplayBoard(int board[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void PlaceMarker(int arr[2], int marker, int board[3][3]){
    board[arr[0]][arr[1]] = marker;
}

int main()
{
    int board[3][3];
    CreateBoard(board);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
