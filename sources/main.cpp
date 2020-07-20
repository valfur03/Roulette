#include <iostream>
#include <memory>
#include "../includes/Game.h"

// Functions prototype

int menu(); // Show the main menu and ask the user to choose
Game* initializeGame(); //Return a game object
Game* initializeGame(const int& start_money); //Return a game object with a start money value
void playGame(std::unique_ptr<Game> &game); // Play the game
void settings(); // Show the settings and ask the user to choose

long int start_money = 1000;

int main() {

	bool quit = false;

	do {
		system("cls");
		switch (menu()) {
		case 1: {

			// Initialize and play the game

			std::unique_ptr<Game> game(initializeGame(start_money));
			playGame(game);

			break;
		}

		case 2:
			settings();

			break;

		case 3:
			break;
		}
	} while (!quit);

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


	while (!(std::cin >> choice) || choice < 1 || choice > 3) { // While the user input isn't valid
		if (choice < 1 || choice > 3) {
			std::cout << "Ce nombre n'est pas valide..." << std::endl;
		}
		else {
			std::cout << "Veuillez entrer une valeur valide." << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}

	return choice;
}

Game* initializeGame() {
	return new Game;
}

Game* initializeGame(const int& start_money) {
	return new Game(start_money);
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

void settings() {

	bool quit = false;

	do {
		system("cls");
		std::cout << "===== PARAMETRES =====" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Argent de depart (actuellement : " << start_money << ")" << std::endl;
		std::cout << "2. Retour" << std::endl;
		std::cout << std::endl;
		std::cout << "Entrez un nombre -> ";

		int choice = 0;


		while (!(std::cin >> choice) || choice < 1 || choice > 3) { // While the user input isn't valid
			if (choice < 1 || choice > 3) {
				std::cout << "Ce nombre n'est pas valide..." << std::endl;
			}
			else {
				std::cout << "Veuillez entrer une valeur valide." << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
		}

		switch (choice) {
		case 1:
			system("cls");
			std::cout << "Entrez votre argent de depart : ";


			while (!(std::cin >> start_money) || start_money < 1) { // While the user input isn't valid
				if (start_money < 1) {
					std::cout << "Vous ne pouvez pas debuter une partie avec moins de 1 euro..." << std::endl;
				}
				else {
					std::cout << "Veuillez entrer une valeur valide." << std::endl;
					std::cin.clear();
					std::cin.ignore();
				}
			}
			break;

		case 2:
			quit = true;
			break;
		}
	} while (!quit);
}