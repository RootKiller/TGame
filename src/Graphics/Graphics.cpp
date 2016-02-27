/**
 * @file Graphics.cpp
 *
 * @brief Graphics API. (implementation)
 */

#include <assert.h>

#include "Renderer/BaseRenderDevice.h"

#include "Graphics.h"

#include "Logger.h"

namespace Gfx {

/**
 * Current active render device.
 */
static BaseRenderDevice *g_renderDevice = nullptr;

bool Initialize(const RenderDevices requestedDevice)
{
	switch (requestedDevice)
	{
	case RenderDevices::RENDER_DEVICE_OpenGL:
		Logger::Error("Tried to create unimplemented render device.");
		break;
	default:
		Logger::Error("Tried to create unimplemented render device. (%d)", requestedDevice);
		break;
	}

	return false;
}

void Shutdown(void)
{
	if (g_renderDevice) {
		delete g_renderDevice;
		g_renderDevice = nullptr;
	}
}

void BeginFrame(void)
{
	assert(g_renderDevice);
	g_renderDevice->BeginFrame();
}

void EndFrame(void)
{
	assert(g_renderDevice);
	g_renderDevice->EndFrame();
}

BaseRenderDevice *GetActiveDevice(void)
{
	return g_renderDevice;
}

} /* namespace Gfx */

/* eof */
