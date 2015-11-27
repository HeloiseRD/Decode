#include "DecodeApp.h"

#include "ScreenViewController1.h"
#include "ScreenViewController2.h"

#include <screen/YiScreenTransition.h>

DecodeApp::DecodeApp() :
m_pScreen1(YI_NULL),
m_pScreen2(YI_NULL)
{

}

DecodeApp::~DecodeApp()
{
    m_screenTransitionManager.Disconnect(m_pScreen1);
    m_screenTransitionManager.Disconnect(m_pScreen2);

    delete m_pScreen1;
    m_pScreen1 = YI_NULL;

    delete m_pScreen2;
    m_pScreen2 = YI_NULL;
}

bool DecodeApp::UserInit()
{
    m_pScreen1 = new ScreenViewController1(GetSceneManager(), this, "Screen1", "Screen1_MainComp.layout");
    m_pScreen1->Init();

    m_pScreen2 = new ScreenViewController2(GetSceneManager(), this, "Screen2", "Screen2_MainComp.layout");
    m_pScreen2->Init();

    CYIScreenTransition *pScreenTransition = new CYIScreenTransition(YI_NULL, 0);
    m_screenTransitionManager.UseTransition(pScreenTransition);

    m_screenTransitionManager.Connect(m_pScreen1);
    m_screenTransitionManager.Connect(m_pScreen2);
    m_screenTransitionManager.PushScreen(m_pScreen1);
    
    return true;
}

bool DecodeApp::UserStart()
{
   return true;
}

void DecodeApp::UserUpdate()
{

}

void DecodeApp::GoToScreen1()
{
    m_screenTransitionManager.PushScreen(m_pScreen1);
}

void DecodeApp::GoToScreen2()
{
    m_screenTransitionManager.PushScreen(m_pScreen2);
}

void DecodeApp::GoBack()
{
    m_screenTransitionManager.PopScreen();
}
