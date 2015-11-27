
#include "AppFactory.h"
#include "DecodeApp.h"

#define APP_NAME "DecodeApp"

#define APP_DENSITY (72)
#if defined(YI_XBOX_ONE) || defined(YI_PS4)
#define APP_WIDTH (1920)
#define APP_HEIGHT (1080)
#else
#define APP_WIDTH (640)
#define APP_HEIGHT (480) 
#endif

CYIApp *AppFactory::Create()
{
    return new DecodeApp();
}

int AppFactory::GetWindowWidth()
{
    return APP_WIDTH;
}

int AppFactory::GetWindowHeight()
{
    return APP_HEIGHT;
}

int AppFactory::GetScreenDensity()
{
    return APP_DENSITY;
}

const char * AppFactory::GetWindowName()
{
    return APP_NAME;
}
