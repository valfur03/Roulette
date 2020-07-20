#ifndef GAME_H_INCLUDE
#define GAME_H_INCLUDE

class Game {
public:

	Game();
	void summary(); // Display some informations about the current game
	long int proceedBet(); // Proceed the bet of the player
	void addGain(const long int &gain); // Proceed the bet of the player
	bool isLost(); // Return whether or not the game is lost

private:

	long int m_money;
};

#endif