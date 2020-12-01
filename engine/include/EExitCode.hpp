#pragma once

/// @brief Dirt Machine game engine namespace
namespace DirtMachine
{
	/// @brief Game exit code enumerator
	enum class EExitCode
	{
		/// @brief Game exited successfully
		Success,

		/// @brief Failed to create window for game
		FailedCreatingWindow,

		/// @brief An unhandled exception was thrown
		UnhandledException,

		/// @brief An unknown error occured
		UnknownError
	};
}
