#include <iostream>
#include <random>
#include "../includes/Game.h"

Game::Game() : m_money(1000) {
	std::cout << "Partie lancee avec " << m_money << " euros." << std::endl;
}

Game::Game(const int& start_money) : m_money(start_money) {
	std::cout << "Partie lancee avec " << m_money << " euros." << std::endl;
}

void Game::summary() {
	std::cout << "Vous avez " << m_money << " euros." << std::endl;
}

long int Game::proceedBet() {

	std::cout << "Entrez votre mise d'argent : ";

	long int money_bet = 0;
	while (!(std::cin >> money_bet) || money_bet > m_money) { // While the user input isn't valid
		if (money_bet > m_money) {
			std::cout << "Vous ne pouvez pas jouer plus d'argent que ce que vous avez." << std::endl;
		}
		else {
			std::cout << "Veuillez entrer une valeur valide." << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}

	std::cout << "Entrez votre nombre : ";

	int bet_number = 0;
	while (!(std::cin >> bet_number) || bet_number > 36 || bet_number < 1) { // While the user input isn't valid
		if (bet_number > 36 || bet_number < 1) {
			std::cout << "Vous ne pouvez parier qu'un numero entre 1 et 36 inclus." << std::endl;
		}
		else {
			std::cout << "Veuillez entrer une valeur valide." << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}

	// Prepare the random int generator

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 36);
	int random_number = distr(gen);

	int gain = 0;

	std::cout << std::endl << "Le numero tire est le " << random_number << " !" << std::endl;

	if (bet_number == random_number) {
		gain = money_bet * 2;
		std::cout << "Vous gagnez " << gain << " euro(s) !" << std::endl;
	}
	else if (bet_number % 2 == random_number % 2) {
		gain = money_bet;
		std::cout << "Vous gagnez " << gain << " euro(s) !" << std::endl;
	}
	else {
		gain = -money_bet;
		std::cout << "Vous perdez " << -gain << " euro(s)..." << std::endl;
	}

	std::cout << std::endl;

	return gain;
}

void Game::addGain(const long int& gain) {
	m_money += gain;
}

bool Game::isLost() {
	return m_money == 0;
}