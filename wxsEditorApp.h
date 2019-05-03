/***************************************************************
 * Name:      wxsEditorApp.h
 * Purpose:   Defines Application Class
 * Author:    Isaac Smith ()
 * Created:   2016-11-20
 * Copyright: Isaac Smith ()
 * License:
 **************************************************************/


#ifndef WXSEDITORAPP_H
#define WXSEDITORAPP_H

#include <wx/app.h>

// For command line args
#include <wx/wxprec.h>
#include <wx/cmdline.h>

class wxsEditorApp : public wxApp
{
    public:
        virtual bool OnInit();

        // For command line args
        virtual int OnExit();
        virtual int OnRun();
        virtual void OnInitCmdLine(wxCmdLineParser& parser);
        virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

    private:
        // For command line args
        bool silent_mode;
        wxString cmdParam;
};

// For command line args
static const wxCmdLineEntryDesc g_cmdLineDesc [] =
{
     /* - 2.8.12
     { wxCMD_LINE_SWITCH, wxT("h"), wxT("help"), wxT("displays help on the command line parameters"),
          wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
     { wxCMD_LINE_SWITCH, wxT("s"), wxT("silent"), wxT("disables the GUI") },
     { wxCMD_LINE_PARAM, wxT("f"), wxT("file"), wxT("file to load"),
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM },

     { wxCMD_LINE_NONE }
     */
     { wxCMD_LINE_SWITCH, "h", "help", "displays help on the command line parameters",
          wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
     { wxCMD_LINE_SWITCH, "s", "silent", "disables the GUI" },
     { wxCMD_LINE_PARAM, "f", "file", "file to load",
          wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM },

     { wxCMD_LINE_NONE }
};

#endif // WXSEDITORAPP_H
