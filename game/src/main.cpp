#include <filesystem>
#include <iostream>
#include <string>

#include "Game.hpp"

/// @brief Configuration path
static const std::filesystem::path configurationPath("./config.xml");

/// @brief Main entry point
/// @param argc Command line argument count
/// @param argv Command line arguments
/// @return Exit code
int main(int argc, char* argv[])
{
	BA3GameProgrammingTemplate::EGameExitCode ret(BA3GameProgrammingTemplate::EGameExitCode::UnknownError);
	try
	{
		BA3GameProgrammingTemplate::Game game(static_cast<std::size_t>(800), static_cast<std::size_t>(600), "BA3 Game Programming Template", BA3GameProgrammingTemplate::EGameWindowStyle::Default);
		std::unordered_map<std::string, std::string> configuration;
		if (game.ReadConfigurationFile(configurationPath, configuration))
		{
			std::cout << "Configuration:" << std::endl;
			for (const std::pair<std::string, std::string>& configuration_entry : configuration)
			{
				std::cout << "\t\"" << configuration_entry.first << "\" : \"" << configuration_entry.second << "\"" << std::endl;
			}
		}
		else
		{
			std::cerr << "Failed to open configuration file \"" << configurationPath << "\"" << std::endl;
		}
		ret = game.Start();
	}
	catch (const std::exception& e)
	{
		ret = BA3GameProgrammingTemplate::EGameExitCode::UnhandledException;
		std::cerr << e.what() << std::endl;
	}
	catch (int e)
	{
		ret = BA3GameProgrammingTemplate::EGameExitCode::UnhandledException;
		std::cerr << "Error code: " << e << std::endl;
	}
	catch (...)
	{
		ret = BA3GameProgrammingTemplate::EGameExitCode::UnhandledException;
		std::cerr << "An unknown exception was thrown. :(" << std::endl;
	}
	switch (ret)
	{
	case BA3GameProgrammingTemplate::EGameExitCode::Success:
		std::cout << "Game has been terminated successfully!" << std::endl;
		break;
	case BA3GameProgrammingTemplate::EGameExitCode::FailedCreatingWindow:
		std::cerr << "Failed to create window!" << std::endl;
		break;
	case BA3GameProgrammingTemplate::EGameExitCode::UnhandledException:
		std::cerr << "Game has been terminated with an unhandled exception!" << std::endl;
		break;
	case BA3GameProgrammingTemplate::EGameExitCode::UnknownError:
		std::cerr << "Game has been terminated with an unknown error!" << std::endl;
		break;
	}
	return static_cast<int>(ret);
}
