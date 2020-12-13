#include <iostream>
#include <string>
#include <UI/EditorWindow.hpp>

/// @brief Main entry point
/// @param argc Command line argument count
/// @param argv Command line arguments
/// @return Exit code
int main(int argc, char* argv[])
{
	DirtMachine::EExitCode ret(DirtMachine::EExitCode::UnknownError);
	try
	{
		DirtyFinger::UI::EditorWindow editor_window(static_cast<std::size_t>(800), static_cast<std::size_t>(600), "Dirty Finger - Dirt Machine Editor", DirtMachine::EWindowStyle::Default);
		ret = editor_window.Start();
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
		std::cout << "Editor has been terminated successfully!" << std::endl;
		break;
	case DirtMachine::EExitCode::FailedCreatingWindow:
		std::cerr << "Failed to create window!" << std::endl;
		break;
	case DirtMachine::EExitCode::UnhandledException:
		std::cerr << "Editor has been terminated with an unhandled exception!" << std::endl;
		break;
	case DirtMachine::EExitCode::UnknownError:
		std::cerr << "Editor has been terminated with an unknown error!" << std::endl;
		break;
	}
	return static_cast<int>(ret);
}
