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
	NoLifeNoCry::Engine::EExitCode ret(NoLifeNoCry::Engine::EExitCode::UnknownError);
	try
	{
		NoLifeNoCry::Game::GameWindow game_window(static_cast<std::size_t>(800), static_cast<std::size_t>(600), "No Life, No Cry", NoLifeNoCry::Engine::EWindowStyle::Default);
		ret = game_window.Start();
	}
	catch (const std::exception& e)
	{
		ret = NoLifeNoCry::Engine::EExitCode::UnhandledException;
		std::cerr << e.what() << std::endl;
	}
	catch (int e)
	{
		ret = NoLifeNoCry::Engine::EExitCode::UnhandledException;
		std::cerr << "Error code: " << e << std::endl;
	}
	catch (...)
	{
		ret = NoLifeNoCry::Engine::EExitCode::UnhandledException;
		std::cerr << "An unknown exception was thrown. :(" << std::endl;
	}
	switch (ret)
	{
	case NoLifeNoCry::Engine::EExitCode::Success:
		std::cout << "Game has been terminated successfully!" << std::endl;
		break;
	case NoLifeNoCry::Engine::EExitCode::FailedCreatingWindow:
		std::cerr << "Failed to create window!" << std::endl;
		break;
	case NoLifeNoCry::Engine::EExitCode::UnhandledException:
		std::cerr << "Game has been terminated with an unhandled exception!" << std::endl;
		break;
	case NoLifeNoCry::Engine::EExitCode::UnknownError:
		std::cerr << "Game has been terminated with an unknown error!" << std::endl;
		break;
	}
	return static_cast<int>(ret);
}
