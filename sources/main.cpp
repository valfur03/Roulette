#include <iostream>
#include <memory>
#include "../includes/Game.h"

// Functions prototype

int menu(); // Show the main menu and ask the user to choose
Game* initializeGame(); //Return a game object
void playGame(std::unique_ptr<Game> &game); // Play the game

int main() {

	switch (menu()) {
	case 1: {

		// Initialize and play the game

		std::unique_ptr<Game> game(initializeGame());
		playGame(game);

		break;
	}

	case 2:
		break;

	case 3:
		break;
	}

	return 0;
}

int menu() {
	std::cout << "===== MENU =====" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Jouer" << std::endl;
	std::cout << "2. Parametres" << std::endl;
	std::cout << "3. Regles" << std::endl;
	std::cout << std::endl;
	std::cout << "Entrez un nombre -> ";

	int choice = 0;

	do {
		std::cin >> choice;

		if (choice < 1 || choice > 3) {
			std::cout << "Ce nombre n'est pas valide..." << std::endl;
		}
	} while (choice < 1 || choice > 3);

	return choice;
}

Game* initializeGame() {
	return new Game;
}

void playGame(std::unique_ptr<Game>&game) {
	do {
		system("cls");
		game->summary();
		long int gain = game->proceedBet();
		game->addGain(gain);
		system("pause");
	} while (!game->isLost());

	std::cout << std::endl << "Vous n'avez plus d'argent... Vous avez perdu..." << std::endl;
	system("pause");
}