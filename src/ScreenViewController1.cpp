#include "ScreenViewController1.h"

#include "DecodeApp.h"

#include <scenetree/YiSceneManager.h>
#include <view/YiPushButtonView.h>
#include <view/YiSceneView.h>

static const CYIString LOG_TAG("ScreenViewController1");

ScreenViewController1::ScreenViewController1(CYISceneManager *pSceneManager, DecodeApp *pApplication, const CYIString &screenName, const CYIString &layoutFile)
: CYIAbstractScreenViewController(pSceneManager, pApplication)
, m_pNextScreenButton(YI_NULL)
, m_screenName(screenName)
, m_layoutFile(layoutFile)
, m_pApplication(pApplication)
{

}

ScreenViewController1::~ScreenViewController1()
{

};

CYISceneView *ScreenViewController1::BuildView()
{
    CYISceneView *pPlayerScreen = m_pSceneManager->LoadScene(m_layoutFile, CYISceneManager::SCALE_STRETCH, CYISceneManager::V_ALIGN_CENTER, CYISceneManager::H_ALIGN_CENTER);
    if(!pPlayerScreen)
    {
        YI_LOGE(LOG_TAG, " scene has failed");
        return YI_NULL;
    }

    m_pSceneManager->AddScene(m_screenName, pPlayerScreen);
    m_pSceneManager->UnStageScene(m_screenName);

    return pPlayerScreen;
}

void ScreenViewController1::OnInitScreen()
{
    m_pNextScreenButton = m_pView->GetNode<CYIPushButtonView>("NextButton");
    YI_ASSERT(m_pNextScreenButton, LOG_TAG, "Could not find push button 'NextButton'");
    m_pNextScreenButton->ButtonClicked.Connect(*m_pApplication, &DecodeApp::GoToScreen2);
}

void ScreenViewController1::OnPreloadValidateScreen(CYIBundle bundle)
{
    YI_UNUSED(bundle);
    PreloadValidateSucceeded(this);
}

void ScreenViewController1::OnPreloadScreen(CYIBundle bundle, const CYIPersistentStore &StateData)
{
    YI_UNUSED(bundle);
    YI_UNUSED(StateData);
    PreloadFinished(this);
}

void ScreenViewController1::OnLoadScreen(const CYIPersistentStore &StateData)
{
    YI_UNUSED(StateData);
}

void ScreenViewController1::OnUnloadScreen(CYIPersistentStore & StateData)
{
    YI_UNUSED(StateData);
}

void ScreenViewController1::OnStageScreen()
{
    /*
        We stage the scene we're managing so that it will be included in the subsequent draws. 

        This hook will be called on the same frame as the prior screen's Unstage, ensuring uninterrupted rendering.

        Besides this call to Stage, nothing should be done here.
    */
    m_pSceneManager->StageScene(m_screenName);
}

void ScreenViewController1::OnUnstageScreen()
{
    /*
        We must unstage the scene which we're managing so that the next screen can take its place.

        This hook will be called at the appropriate time after any unload animations have been completed, and on
        the same frame as the next screen's OnStageScreen is called ensuring uninterrupted rendering.

        Besides this call to Unstage, nothing should be done here.
    */
    m_pSceneManager->UnStageScene(m_screenName);
}
