#include <filesystem>
#include <iostream>
#include <string>
#include <GameWindow.hpp>

/// @brief Configuration path
static const std::filesystem::path configurationPath("./config.xml");

/// @brief Main entry point
/// @param argc Command line argument count
/// @param argv Command line arguments
/// @return Exit code
int main(int argc, char* argv[])
{
	DirtMachine::EExitCode ret(DirtMachine::EExitCode::UnknownError);
	try
	{
		NoLifeNoCry::GameWindow game_window(static_cast<std::size_t>(800), static_cast<std::size_t>(600), "No Life, No Cry", DirtMachine::EWindowStyle::Default);
		ret = game_window.Start();
	}
	catch (const std::exception& e)
	{
		ret = DirtMachine::EExitCode::UnhandledException;
		std::cerr << e.what() << std::endl;
	}
	catch (int e)
	{
		ret = DirtMachine::EExitCode::UnhandledException;
		std::cerr << "Error code: " << e << std::endl;
	}
	catch (...)
	{
		ret = DirtMachine::EExitCode::UnhandledException;
		std::cerr << "An unknown exception was thrown. :(" << std::endl;
	}
	switch (ret)
	{
	case DirtMachine::EExitCode::Success:
		std::cout << "Game has been terminated successfully!" << std::endl;
		break;
	case DirtMachine::EExitCode::FailedCreatingWindow:
		std::cerr << "Failed to create window!" << std::endl;
		break;
	case DirtMachine::EExitCode::UnhandledException:
		std::cerr << "Game has been terminated with an unhandled exception!" << std::endl;
		break;
	case DirtMachine::EExitCode::UnknownError:
		std::cerr << "Game has been terminated with an unknown error!" << std::endl;
		break;
	}
	return static_cast<int>(ret);
}
