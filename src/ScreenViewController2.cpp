#include "ScreenViewController2.h"

#include "DecodeApp.h"

#include <scenetree/YiSceneManager.h>
#include <view/YiPushButtonView.h>
#include <view/YiSceneView.h>

static const CYIString LOG_TAG("ScreenViewController2");

ScreenViewController2::ScreenViewController2(CYISceneManager *pSceneManager, DecodeApp *pApplication, const CYIString &screenName, const CYIString &layoutFile)
: CYIAbstractScreenViewController(pSceneManager, pApplication)
, m_pPreviousScreenButton(YI_NULL)
, m_screenName(screenName)
, m_layoutFile(layoutFile)
, m_pApplication(pApplication)
{

}

ScreenViewController2::~ScreenViewController2()
{

};

CYISceneView *ScreenViewController2::BuildView()
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

void ScreenViewController2::OnInitScreen()
{
    m_pPreviousScreenButton = m_pView->GetNode<CYIPushButtonView>("PreviousButton");
    YI_ASSERT(m_pPreviousScreenButton, LOG_TAG, "Could not find push button 'PreviousButton'");
    m_pPreviousScreenButton->ButtonClicked.Connect(*m_pApplication, &DecodeApp::GoBack);
}

void ScreenViewController2::OnPreloadValidateScreen(CYIBundle bundle)
{
    YI_UNUSED(bundle);
    PreloadValidateSucceeded(this);
}

void ScreenViewController2::OnPreloadScreen(CYIBundle bundle, const CYIPersistentStore &StateData)
{
    YI_UNUSED(bundle);
    YI_UNUSED(StateData);
    PreloadFinished(this);
}

void ScreenViewController2::OnLoadScreen(const CYIPersistentStore &StateData)
{
    YI_UNUSED(StateData);
}

void ScreenViewController2::OnUnloadScreen(CYIPersistentStore & StateData)
{
    YI_UNUSED(StateData);
}

void ScreenViewController2::OnStageScreen()
{
    /*
        We stage the scene we're managing so that it will be included in the subsequent draws. 

        This hook will be called on the same frame as the prior screen's Unstage, ensuring uninterrupted rendering.

        Besides this call to Stage, nothing should be done here.
    */
    m_pSceneManager->StageScene(m_screenName);
}

void ScreenViewController2::OnUnstageScreen()
{
    /*
        We must unstage the scene which we're managing so that the next screen can take its place.

        This hook will be called at the appropriate time after any unload animations have been completed, and on
        the same frame as the next screen's OnStageScreen is called ensuring uninterrupted rendering.

        Besides this call to Unstage, nothing should be done here.
    */
    m_pSceneManager->UnStageScene(m_screenName);
}
