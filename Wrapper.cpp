#include"Wrapper.h"

int Wrapper::Encaps_start(std::map<std::string, int> args) {
	if (args.size() != arg_names.size()) {
		throw std::exception();
	}

	for (auto&& arg : args) {
		if (arg_names.count(arg.first) != 1) {
			throw std::exception();
		}
		else {
			arg_names[arg.first] = arg.second;
		}
	}

	std::vector<int> list;
	for (auto&& item : arg_names) {
		list.push_back(item.second);
	}
	return Encapsulation(list);
}