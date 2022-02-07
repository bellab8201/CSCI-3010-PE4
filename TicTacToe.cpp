// create a 3x3 matrix and print it out
#include <vector>
#include <iostream>
using namespace std;
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

std::vector<int> GetPlayerChoice(int board[3][3])
{
    int row, col;
    std::cout << "Enter a row: ";
    std::cin >> row;
    std::cout << "Enter a column: ";
    std::cin >> col;
    if (board[row][col] == 0)
    {
        std::vector<int> choice = {row, col};
        return choice;
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

void PlaceMarker(std::vector<int> arr, int marker, int board[3][3])
{
    board[arr[0]][arr[1]] = marker;
}

bool IsGameOver(int board[3][3])
{
    // iterate over board and check if there are no more 0's
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
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
    while (!IsGameOver(board))
    {
        if (IsGameOver(board))
        {
            std::cout << "Game Over\n";
            break;
        }
        std::cout << "player 1: " << std::endl;
        std::vector<int> player1 = GetPlayerChoice(board);
        PlaceMarker(player1, 1, board);
        DisplayBoard(board);
        if (IsGameOver(board))
        {
            std::cout << "Game Over\n";
            break;
        }
        std::cout << "player 2: " << std::endl;
        std::vector<int> player2 = GetPlayerChoice(board);
        PlaceMarker(player2, 2, board);
        DisplayBoard(board);
    }
}
