#ifndef _DECODEAPP_H_
#define _DECODEAPP_H_

#include <framework/YiApp.h>
#include <screen/YiScreenTransitionManager.h>
#include <signal/YiSignalHandler.h>

class ScreenViewController1;
class ScreenViewController2;

class DecodeApp : public CYIApp, public CYISignalHandler
{
public:
    DecodeApp();
    virtual ~DecodeApp();

    void GoToScreen1();
    void GoToScreen2();
    void GoBack();

protected:
    virtual bool UserInit();
    virtual bool UserStart();
    virtual void UserUpdate();

private:
    CYIScreenTransitionManager m_screenTransitionManager;

    //Screen view controllers
    ScreenViewController1 *m_pScreen1;
    ScreenViewController2 *m_pScreen2;
};

#endif // _DECODEAPP_H_
