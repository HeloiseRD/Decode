#ifndef _YI_SCREEN_VIEW_CONTROLLER_1_H_
#define _YI_SCREEN_VIEW_CONTROLLER_1_H_

#include <screen/YiAbstractScreenViewController.h>

class CYIPushButtonView;

class DecodeApp;

class ScreenViewController1 : public CYIAbstractScreenViewController
{
public:
    /*!
     \details

     The additional parameters \sa screenName and \sa layoutFile allow us to re-use this view controller with different names and source layouts. In most circumstances a \sa CYIAbstractScreenViewController could get by with a hard-coded name and layout file.
    */
    ScreenViewController1(CYISceneManager *pSceneManager,
                          DecodeApp *pApplication,
                          const CYIString &screenName,
                          const CYIString &layoutFile);

    ~ScreenViewController1();

protected:

    /*!
     \details Here we load our scene from disk into the scene manager. Initialization will occur in \sa OnInitScreen().
    */
    CYISceneView *BuildView();

    /*!
     \details Here we cache our sub-views and connect to our view signals.
    */
    void OnInitScreen();

    /*!
     \details
     */
    void OnPreloadValidateScreen(CYIBundle bundle);

    /*!
     \details
    */
    void OnPreloadScreen(CYIBundle bundle, const CYIPersistentStore &StateData);

    /*!
     \details
    */
    void OnLoadScreen(const CYIPersistentStore &StateData);

    /*!
     \details
    */
    void OnUnloadScreen(CYIPersistentStore & StateData);

    /*!
    \details
    */
    void OnStageScreen();

    /*!
     \details
    */
    void OnUnstageScreen();


private:

    CYIPushButtonView *m_pNextScreenButton;

    CYIString m_screenName;
    CYIString m_layoutFile;

    DecodeApp *m_pApplication;
};

#endif //_YI_SCREEN_VIEW_CONTROLLER_1_H_
