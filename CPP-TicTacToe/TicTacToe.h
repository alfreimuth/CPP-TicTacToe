#pragma once

#include "Game.h"


#include <vector>

class TicTacToe : public Game
{
private:

	bool m_isGameOver = 0;
	bool m_player = 0;
	char m_board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	

public:

	TicTacToe() { }
	~TicTacToe() { }

	char GetBoard(int x) const { return m_board[x]; }
	int GetPlayer() const { return m_player; }

	void SetPlayer(const int x) { m_player = x; }
	void SetBoard(const int x, const char y) { m_board[x] = y; }

	virtual bool IsGameOver() const {
		//This function should return true if the game is over, and false otherwise. 
		//The game is over when one player has won, or the board is full and the game ends in a tie.

		const int winConditions[8][3] = { 
			// Asked ai for how to do something better than if 0 == 1 && 0 == 2 for all 8 outcomes
			// Then looked into multi dimensional arrays
			{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Horizontal
			{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Vertical
			{0, 4, 8}, {2, 4, 6} // Diagonal
		};

		for (int i = 0; i < 8; i++) {
			int a = winConditions[i][0];
			int b = winConditions[i][1];
			int c = winConditions[i][2];
			if ((GetBoard(a) != ' ') && (GetBoard(a) == GetBoard(b)) && (GetBoard(a) == GetBoard(c))) {
				if (GetPlayer() == 0) {
					std::cout << "\nPlayer 2 wins!\n"; // Had to add \n at the end since we couldnt change the main.cpp, you should add one there instead though imo
				}
				else std::cout << "\nPlayer 1 wins!\n"; // Same here
				return 1;
			}

		}

		return 0;
	}
	

	virtual void TakeTurn() {
	//This function should allow the current player to take their turn. You should prompt the player to enter the position (1 - 9) where they want to place their mark. 
	//If the position is invalid (out of range, or already taken), you should prompt the player to enter a valid position.
		int pos;

		std::cout << "\nEnter position (1-9): ";
		std::cin >> pos;

		if (std::cin.fail()) { // Try {} Catch {} didnt work here, so looked into forcing cin to only take int
			std::cin.clear(); // Removes the flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the data
		}

		pos -= 1;
		if ((0 <= pos < 10) && (GetBoard(pos) == ' ')) {
			if (GetPlayer() == 0) {
				SetBoard(pos, 'X');
				SetPlayer(1);
			}
			else {
				SetBoard(pos, 'Y');
				SetPlayer(0);
			}
		}
		else {
			std::cout << "\nInvalid position, try again";
			TakeTurn();
		}
	}
	

	virtual void Display() const {
		//This function should display the current state of the game to the console window. 
		//You should display the board with the current marks of each player, and indicate whose turn it is.
		system("cls");
		std::cout << "\nPlayer " << GetPlayer();
		for (int i = 0; i < 9; i++) {
			if (i % 3 == 0) {
				std::cout << "\n";
			}
			std::cout << GetBoard(i);
		}
	}
};