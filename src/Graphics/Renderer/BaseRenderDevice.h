/**
 * @file BaseRenderDevice.h
 *
 * @brief Base render device class.
 */

#pragma once

namespace Gfx {

/**
 * Base rendering device.
 *
 * This is the base class of all rendering implementations.
 */
class BaseRenderDevice
{
public:
	/// Constructor.
			BaseRenderDevice		();

	/// Destructor.
	virtual ~BaseRenderDevice		();

	/**
	 * Begin of the rendering frame.
	 *
	 * Called directly from the rendering method in the engine.
	 *
	 * You should perform here all the screen and buffers cleanups.
	 */
	virtual void BeginFrame			(void);

	/**
	 * End of the rendering frame.
	 *
	 * Called directly from the rendering method in the engine.
	 *
	 * You should perform here the swap of the buffers or present.
	 */
	virtual void EndFrame			(void);
};

} /* namespace Gfx */

/* eof */
