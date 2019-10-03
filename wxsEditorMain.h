/***************************************************************
 * Name:      wxsEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    ImprobabilityCast
 * Created:   2016-11-20
 * Copyright: ImprobabilityCast
 * License:
 **************************************************************/


#define MAJOR_VERSION      1
#define MINOR_VERSION      2
#define RELEASE_NUMBER     1
#define SUBRELEASE_NUMBER  35
#define VERSION_STRING   wxT("wxsEditor v1.2.1")

#ifndef WXSEDITORMAIN_H
#define WXSEDITORMAIN_H

#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <fstream>
#include <sys/stat.h>

//(*Headers(wxsEditorFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class wxsEditorFrame: public wxFrame
{
    public:

        wxsEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxsEditorFrame();

        //added my function
        void CheckCmdParamaters(wxString& cmdParam);

    private:

        //my added variables
        wxString path;
        //wxString fileName;
        bool isTextChanged;
        //define file types
        const wxChar* FILETYPES;

        //added my functions
        int AskSave();
        void Save(bool showDialog);

        //(*Handlers(wxsEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnRefresh(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnCloseCurrentFile(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxsEditorFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_PANEL1;
        static const long idMenuOpen;
        static const long idMenuRefresh;
        static const long idMenuSave;
        static const long idMenuSaveAs;
        static const long idMenuClose;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxsEditorFrame)
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSEDITORMAIN_H
