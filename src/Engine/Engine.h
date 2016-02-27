/**
 * @file Engine.h
 *
 * @brief Engine main class (interface).
 */

#pragma once

/**
 * Engine exit codes enum.
 */
enum ExitCodes
{
	/// Engine has not been initialized yet.
	EXIT_CODE_UNINITIALIZED = -1,

	/// Generic error.
	EXIT_CODE_GENERIC_ERROR = 0,

	/// Everything looks "OK".
	EXIT_CODE_OK = 1,
};

class	BaseApplication;

class Engine
{
private:
	/// Engine exit code.
	int		m_exitCode;

	/// Flag indicating if the engine application is still running.
	bool	m_isRunning;

	/// Current application.
	BaseApplication *m_app;

	/// The application window.
struct SDL_Window	*m_window;
public:
	/// Constructor.
			Engine			();

	/// Destructor.
			~Engine			();

	/**
	 * Initialize engine.
	 *
	 * @param[in] argc The command line parameters count.
	 * @param[in] argv The command line parameters data.
	 *
	 * @return @c true in case of success @c false otherwise.
	 */
	bool	Initialize		(const int argc, const char *const argv[]);

	/**
	 * Runs the application.
	 *
	 * @param[in] app The application.
	 */
	void	Run				(BaseApplication *const app);

	/**
	 * Get engine exit code.
	 *
	 * @return engine exit code.
	 */
	int		GetExitCode		(void) const;
};

/* eof */
