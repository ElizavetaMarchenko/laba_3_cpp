#include"Engine.h"
#include<iostream>

void Engine::register_command(Wrapper* wrapper, std::string command) {
	if (commands.find(command) != commands.end()) {
		throw std::exception(); 
	}
	commands.insert({ command, wrapper });
}

int Engine::execute(std::string command, std::map<std::string, int> args) {
	if (commands.find(command) == commands.end()) {
		throw std::exception();
	}
	if (!commands[command]) {
		throw std::exception();
	}

	int result = 0;
	try {
		result = commands[command]->Encaps_start(args);
	}
	catch (...) {
		std::cout << "Error ";
	}
	return result;
}