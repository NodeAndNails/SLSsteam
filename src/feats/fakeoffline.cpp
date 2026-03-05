#include "fakeoffline.hpp"


#include "../sdk/IClientUtils.hpp"

#include "../config.hpp"

#include "fakeappid.hpp"


bool FakeOffline::shouldFakeOffline()
{
	if (!g_pClientUtils)
	{
		return false;
	}
	
	const uint32_t appId = FakeAppIds::getRealAppIdForCurrentPipe();
	if (!appId || !g_config.fakeOffline.get().contains(appId))
	{
		return false;
	}

	g_pLog->once("Faking offline mode for %u\n", appId);
	return true;
}
