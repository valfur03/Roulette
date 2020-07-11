#include <iostream>

int menu();

int main() {
	std::cout << menu() << std::endl;

	return 0;
}

int menu() {
	std::cout << "===== MENU =====" << std::endl;
	std::cout << "1. Jouer" << std::endl;
	std::cout << "2. Parametres" << std::endl;
	std::cout << "3. Règles" << std::endl;
	std::cout << "4. Quitter" << std::endl;

	std::cout << "Entrez un nombre -> ";

	int choice = 0;

	do {
		std::cin >> choice;

		if (choice < 1 || choice > 4) {
			std::cout << "Ce nombre n'est pas valide..." << std::endl;
		}
	} while (choice < 1 || choice > 4);

	return choice;
}