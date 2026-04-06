#include "IClientApps.hpp"

#include "../memhlp.hpp"
#include "../vftableinfo.hpp"

#include <cstdint>


uint32_t IClientApps::getAppDataSection(uint32_t appId, EAppInfoSection section, const char* pChOut, uint32_t outSize)
{
	return MemHlp::callVFunc<uint32_t(*)(void*, uint32_t, uint32_t, const char*, uint32_t, uint8_t)>
	(
		 VFTIndexes::IClientApps::GetAppDataSection,
		 this,
		 appId,
		 section,
		 pChOut,
		 outSize,
		 1
	);
}

EAppType IClientApps::getAppType(uint32_t appId)
{
	return MemHlp::callVFunc<EAppType(*)(void*, uint32_t)>(VFTIndexes::IClientApps::GetAppType, this, appId);
}

IClientApps* g_pClientApps;
