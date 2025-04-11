
#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    drawBoard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }
    cout << "THANKS TO PLAY WITH ME I LONELY AI BOT";

    return 0;
}

void drawBoard(char *spaces)
{
    cout << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
    cout << "_____|_____|______" << "\n";

    cout << "     |     |     " << "\n";
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
    cout << "_____|_____|______" << "\n";

    cout << "     |     |     " << "\n";
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
    cout << "_____|_____|______" << "\n";
    cout << "\n";
}
void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--; // Convert 1–9 to 0–8

        if (number >= 0 && number <= 8 && spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
        else
        {
            cout << "Invalid move. Try again.\n";
        }

    } while (true);
}

void computerMove(char *spaces, char computer)
{

    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer)
{

    // row check
    if (spaces[0] != ' ' && (spaces[0] == spaces[1] && spaces[1] == spaces[2]))
    {
        spaces[0] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    else if (spaces[3] != ' ' && (spaces[3] == spaces[4] && spaces[4] == spaces[5]))
    {
        spaces[3] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    else if (spaces[6] != ' ' && (spaces[6] == spaces[7] && spaces[7] == spaces[8]))
    {
        spaces[6] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    // colum check
    else if (spaces[0] != ' ' && (spaces[0] == spaces[3] && spaces[3] == spaces[6]))
    {
        spaces[0] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    else if (spaces[1] != ' ' && (spaces[1] == spaces[4] && spaces[4] == spaces[7]))
    {
        spaces[1] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    else if (spaces[2] != ' ' && (spaces[2] == spaces[5] && spaces[5] == spaces[8]))
    {
        spaces[2] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }

    // now diagonal
    else if (spaces[0] != ' ' && (spaces[0] == spaces[4] && spaces[4] == spaces[8]))
    {
        spaces[0] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    else if (spaces[2] != ' ' && (spaces[2] == spaces[4] && spaces[4] == spaces[6]))
    {
        spaces[2] == player ? cout << "YOU WIN!" : cout << "YOU LOOSE!";
    }
    else
    {
        return false;
    }
    return true;
}
bool checkTie(char *spaces)
{

    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }

    cout << "ITS TIE";

    return true;
}
