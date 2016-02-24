/**
 * @file BaseApplication.h
 *
 * @brief Base application (interface).
 */
#pragma once

class BaseApplication
{
public:
	/// Constructor.
			BaseApplication	();

	/// Destructor.
			~BaseApplication();

	/// Application pulse.
virtual void Pulse			(void);
};

/* eof */
