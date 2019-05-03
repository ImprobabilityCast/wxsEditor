/***************************************************************
 * Name:      wxsEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Isaac Smith ()
 * Created:   2016-11-20
 * Copyright: Isaac Smith ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxsEditorApp.h"

//(*AppHeaders
#include "wxsEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxsEditorApp);

bool wxsEditorApp::OnInit()
{
    // call default behaviour (mandatory)
    if (!wxApp::OnInit())
        return false;

    // some application-dependent treatments...

    // Add this down there if it goes away:
    //      Frame->CheckCmdParamaters(cmdParam);
    //      Frame->Maximize();
    //(*AppInitialize
    bool wxsOK = true;
    if (!silent_mode) {
        wxInitAllImageHandlers();
        if ( wxsOK )
        {
            wxsEditorFrame* Frame = new wxsEditorFrame(0);
            Frame->Maximize();
            Frame->Show();
            Frame->CheckCmdParamaters(cmdParam);
            SetTopWindow(Frame);
        }
    }
    //*)

    return wxsOK;

}

//For command line args
int wxsEditorApp::OnExit()
{
    //clean up
    return 0;
}

int wxsEditorApp::OnRun()
{
    return wxApp::OnRun();
}

void wxsEditorApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc (g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars (wxT("-"));
}

bool wxsEditorApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    silent_mode = parser.Found(wxT("s"));

    // to get at your unnamed parameters use
    for (unsigned int i = 0; i < parser.GetParamCount(); i++)
    {
            cmdParam = parser.GetParam(i);
    }

    // and other command line parameters

    // then do what you need with them.

    return true;
}
