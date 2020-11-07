#include <filesystem>
#include <iostream>
#include <string>

#include "EditorWindow.hpp"

/// @brief Configuration path
static const std::filesystem::path configurationPath("./editorconfig.xml");

/// @brief Main entry point
/// @param argc Command line argument count
/// @param argv Command line arguments
/// @return Exit code
int main(int argc, char* argv[])
{
	NoLifeNoCry::Engine::EExitCode ret(NoLifeNoCry::Engine::EExitCode::UnknownError);
	try
	{
		NoLifeNoCry::Editor::EditorWindow editor_window(static_cast<std::size_t>(800), static_cast<std::size_t>(600), "No Life, No Cry - Editor", NoLifeNoCry::Engine::EWindowStyle::Default);
		ret = editor_window.Start();
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
		std::cout << "Editor has been terminated successfully!" << std::endl;
		break;
	case NoLifeNoCry::Engine::EExitCode::FailedCreatingWindow:
		std::cerr << "Failed to create window!" << std::endl;
		break;
	case NoLifeNoCry::Engine::EExitCode::UnhandledException:
		std::cerr << "Editor has been terminated with an unhandled exception!" << std::endl;
		break;
	case NoLifeNoCry::Engine::EExitCode::UnknownError:
		std::cerr << "Editor has been terminated with an unknown error!" << std::endl;
		break;
	}
	return static_cast<int>(ret);
}
