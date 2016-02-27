/**
 * @file Graphics.h
 *
 * @brief Graphics API. (interface)
 */

#pragma once

namespace Gfx {

enum class RenderDevices
{
	RENDER_DEVICE_None,

	RENDER_DEVICE_OpenGL
};

class BaseRenderDevice;

/**
 * Initialize graphics sub-system.
 *
 * @param[in] requestedDevice The requested device.
 * @return @c true if initialization successed @c false otherwise.
 */
bool Initialize(const RenderDevices requestedDevice);

/**
 * Shutdown graphics sub-system.
 *
 * @note It's safe to call it even if the subsystem is not initialized.
 */
void Shutdown(void);

/**
 * Begin graphical frame.
 *
 * @pre Before calling this method make sure the graphical subsystem is ready.
 */
void BeginFrame(void);

/**
 * End graphical frame.
 *
 * @pre Before calling this method make sure the graphical subsystem is ready.
 */
void EndFrame(void);

/**
 * @brief Gets active rendering device.
 *
 * @return Render device pointer in case render device exists @c nullptr otherwise.
 */
BaseRenderDevice *GetActiveDevice(void);

} /* namespace Gfx */

/* eof */
