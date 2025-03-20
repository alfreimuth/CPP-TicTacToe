#pragma once

#include "Game.h"

#include <conio.h>

class TicTacToe : public Game
{
private:

	bool m_isGameOver = 0;
	bool m_player = 0;
	std::u32string m_board = U"╔═╦═╦═╗";

public:

	TicTacToe() { }
	~TicTacToe() { }

	virtual bool IsGameOver() const {
		//This function should return true if the game is over, and false otherwise. 
		//The game is over when one player has won, or the board is full and the game ends in a tie.
		return 0;
	}
	

	virtual void TakeTurn() {
	//This function should display the current state of the game to the console window. 
	//You should display the board with the current marks of each player, and indicate whose turn it is.

	}
	

	virtual void Display() const {
	//This function should allow the current player to take their turn. You should prompt the player to enter the position (1 - 9) where they want to place their mark. 
	//If the position is invalid (out of range, or already taken), you should prompt the player to enter a valid position.
		std::wcout << L"Unicode text: " << (wchar_t*)m_board.c_str() << std::endl;
		(void)_getch();
	}
};