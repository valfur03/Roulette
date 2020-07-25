#include <iostream>
#include <memory>
#include "../includes/Game.h"

// Functions prototype

void clearConsole();
void pauseConsole();

int menu(); // Show the main menu and ask the user to choose
Game* initializeGame(); //Return a game object
Game* initializeGame(const int& start_money); //Return a game object with a start money value
void playGame(std::unique_ptr<Game> &game); // Play the game
void settings(); // Show the settings and ask the user to choose
void rules(); // Show the rules

long int start_money = 1000;

int main() {

	bool quit = false;

	do {
		clearConsole();
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
			rules();

			break;

		case 4:
			quit = true;

			break;
		}
	} while (!quit);

	return 0;
}

void clearConsole() {
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");

#endif
}

void pauseConsole() {
#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#else
	std::cout << "Appuyez sur entree pour continuer..." << std::endl;
	system("read read");

#endif
}

int menu() {
	std::cout << "===== MENU =====" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Jouer" << std::endl;
	std::cout << "2. Parametres" << std::endl;
	std::cout << "3. Regles" << std::endl;
	std::cout << "4. Quitter" << std::endl;
	std::cout << std::endl;
	std::cout << "Entrez un nombre -> ";

	int choice = 0;


	while (!(std::cin >> choice) || choice < 1 || choice > 4) { // While the user input isn't valid
		if (choice < 1 || choice > 4) {
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
		clearConsole();
		game->summary();
		long int gain = game->proceedBet();
		game->addGain(gain);
		pauseConsole();
	} while (!game->isLost());

	std::cout << std::endl << "Vous n'avez plus d'argent... Vous avez perdu..." << std::endl;
	pauseConsole();
}

void settings() {

	bool quit = false;

	do {
		clearConsole();
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
			clearConsole();
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

void rules() {
	clearConsole();
	std::cout << "===== REGLES =====" << std::endl;
	std::cout << std::endl;
	std::cout << "Vous commencez la partie avec " << start_money << " euros." << std::endl;
	std::cout << "Vous devez vous enrichir en pariant de l'argent sur un nombre entre 1 et 36." << std::endl;
	std::cout << "Lorsque vous tombez a zero, c'est perdu !" << std::endl;
	std::cout << "Bonne chance !" << std::endl;
	std::cout << std::endl;

	pauseConsole();
}