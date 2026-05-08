#include "Core/EngineMain.h"
#ifdef _DEBUG
    #include "Core/Debug/TracyMalloc.h"
#endif

int main()
{
    DoDebug(ZoneScopedN("Engine Entry"));
	return Core::RunEngine();
}


