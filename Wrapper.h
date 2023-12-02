#pragma once
#include<functional>
#include<vector>
#include<map>
#include<string>


class Wrapper {
public:
	template<typename classType, typename...Args>
	Wrapper(classType* origin, int(classType::* Function)(Args...), std::map<std::string, int> args);

	int Encaps_start(std::map<std::string, int> args);
private:
	std::map<std::string, int> arg_names;
	std::function<int(std::vector<int> args)> Encapsulation;

	template<typename classType, typename funcType, size_t...index>
	int arg_indexing(classType origin, funcType Function, std::vector<int> args,
		std::index_sequence<index...>);
};

template<typename classType, typename funcType, size_t...index>
int Wrapper::arg_indexing(classType origin, funcType Function, std::vector<int> args,
	std::index_sequence<index...>) {
	return (origin->*Function)(args[index]...);
}

template<typename classType, typename...Args>
Wrapper::Wrapper(classType* origin, int(classType::* Function)(Args...), std::map<std::string, int> args) {
	for (auto&& arg : args) {
		if (arg_names.find(arg.first) != arg_names.end()) {
			throw std::exception();
		}
		else {
			arg_names.insert(arg);
		}
	}
	Encapsulation = [this, origin, Function](std::vector<int> args) {
		if (sizeof...(Args) != args.size()) {
			throw std::exception();
		}
		return arg_indexing(origin, Function, args, std::make_index_sequence<sizeof...(Args)>{});
	};
}