#include <iostream>

#include "image_list.hpp"
#include "utils/settings.hpp"
#include "screen_saver.hpp"

namespace Arg {
	const std::string Configuration = "--conf";
}

using Args = std::map<std::string, std::string>;

std::string findArg(const std::vector<std::string>& args, const std::string& target, const std::string& default_value)
{
	if(args.empty())
		return default_value;

	const size_t end = args.size() - 1;
	for(size_t i = 0; i < end; ++i)
	{
		if(args[i] == target)
			return args[i+1];
	}

	return default_value;
}

Args readArgs(int argc, char *argv[])
{
	Args results;

	if(argc == 0)
		return results;

	// Extract list of args into a vector
	std::vector<std::string> args;
	args.reserve(argc - 1);
	for(int i = 1; i < argc; ++i)
		args.emplace_back(argv[i]);

	results[Arg::Configuration] = findArg(args, Arg::Configuration, "settings.json");

	return results;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	{
		const Args args = readArgs(argc, argv);
		Settings::init(args.at(Arg::Configuration));
	}

	auto image_list = std::make_shared<ImageList>(Settings::folder());
	if(!image_list->isValid())
	{
		std::cerr << "Target directory must contains at least two png images.";
		return EXIT_FAILURE;
	}

	ScreenSaver screen_saver {image_list};
	screen_saver.start();

	return EXIT_SUCCESS;
}
