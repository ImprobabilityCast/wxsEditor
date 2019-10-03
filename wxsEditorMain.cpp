/***************************************************************
 * Name:      wxsEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ImprobabilityCast
 * Created:   2016-11-20
 * Copyright: ImprobabilityCast
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxsEditorMain.h"

//(*InternalHeaders(wxsEditorFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxsEditorFrame)
const long wxsEditorFrame::ID_TEXTCTRL1 = wxNewId();
const long wxsEditorFrame::ID_BITMAPBUTTON1 = wxNewId();
const long wxsEditorFrame::ID_BITMAPBUTTON2 = wxNewId();
const long wxsEditorFrame::ID_PANEL1 = wxNewId();
const long wxsEditorFrame::idMenuOpen = wxNewId();
const long wxsEditorFrame::idMenuRefresh = wxNewId();
const long wxsEditorFrame::idMenuSave = wxNewId();
const long wxsEditorFrame::idMenuSaveAs = wxNewId();
const long wxsEditorFrame::idMenuClose = wxNewId();
const long wxsEditorFrame::idMenuQuit = wxNewId();
const long wxsEditorFrame::idMenuAbout = wxNewId();
const long wxsEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxsEditorFrame,wxFrame)
    //(*EventTable(wxsEditorFrame)
    //*)
END_EVENT_TABLE()

wxsEditorFrame::wxsEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxsEditorFrame)
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem2;
    wxGridBagSizer* GridBagSizer1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem4;
    wxMenu* Menu1;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem6;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("wxsEditor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxFULL_REPAINT_ON_RESIZE, _T("id"));
    SetClientSize(wxSize(600,400));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("wxsEditor.bmp"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(192,168), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    GridBagSizer1->AddGrowableCol(0);
    GridBagSizer1->AddGrowableRow(1);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxTE_DONTWRAP, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    if ( !TextCtrl1Font.Ok() ) TextCtrl1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    TextCtrl1Font.SetPointSize(11);
    TextCtrl1->SetFont(TextCtrl1Font);
    GridBagSizer1->Add(TextCtrl1, wxGBPosition(1, 0), wxGBSpan(1, 2), wxALL|wxEXPAND, 2);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("refresh-blue.png"))), wxDefaultPosition, wxSize(30,30), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBitmapDisabled(wxBitmap(wxImage(_T("refresh-grey.png"))));
    BitmapButton1->SetBitmapSelected(wxBitmap(wxImage(_T("refresh-blue.png"))));
    BitmapButton1->SetBitmapFocus(wxBitmap(wxImage(_T("refresh-cyan.png"))));
    BitmapButton1->Disable();
    BitmapButton1->SetToolTip(_("Refresh"));
    BoxSizer1->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BitmapButton2 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("save-blue.png"))), wxDefaultPosition, wxSize(30,30), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->SetBitmapDisabled(wxBitmap(wxImage(_T("save-grey.png"))));
    BitmapButton2->SetBitmapSelected(wxBitmap(wxImage(_T("save-blue.png"))));
    BitmapButton2->SetBitmapFocus(wxBitmap(wxImage(_T("save-cyan.png"))));
    BitmapButton2->SetToolTip(_("Save"));
    BoxSizer1->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    GridBagSizer1->Add(BoxSizer1, wxGBPosition(0, 0), wxDefaultSpan, wxALL, 0);
    Panel1->SetSizer(GridBagSizer1);
    GridBagSizer1->Fit(Panel1);
    GridBagSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpen, _("Open...\tCtrl-O"), _("Opens a file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem6 = new wxMenuItem(Menu1, idMenuRefresh, _("Refresh\tF5"), _("Reloads the current file (all unsaved changes will be lost)"), wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem4 = new wxMenuItem(Menu1, idMenuSave, _("Save\tCtrl-S"), _("Saves the current file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu1, idMenuSaveAs, _("Save As..."), _("Saves the current file with a new name"), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem7 = new wxMenuItem(Menu1, idMenuClose, _("Close"), _("Closes the current file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&wxsEditorFrame::OnTextCtrl1Text);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxsEditorFrame::OnRefresh);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxsEditorFrame::OnSave);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnOpen);
    Connect(idMenuRefresh,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnRefresh);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnSave);
    Connect(idMenuSaveAs,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnSaveAs);
    Connect(idMenuClose,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnCloseCurrentFile);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsEditorFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wxsEditorFrame::OnClose);
    //*)

    this->FILETYPES = _("wxWidgets XML files (*.wxs)|*.wxs|All files (*.*)|*.*");
    this->isTextChanged = false;
}

void wxsEditorFrame::CheckCmdParamaters(wxString& cmdParam)
{
    //for cmd line file loading
    if (cmdParam != wxEmptyString) {
        if (this->TextCtrl1->LoadFile(cmdParam)) {
            this->path = cmdParam;
            this->SetStatusText(this->path);
            this->BitmapButton1->Enable();
            this->isTextChanged = false;
        }
    }
}

wxsEditorFrame::~wxsEditorFrame()
{
    //(*Destroy(wxsEditorFrame)
    //*)
}

int wxsEditorFrame::AskSave()
{
    wxString message;
    if (this->path != wxEmptyString) {
        message =
            wxT("'") +
            this->path.AfterLast(wxFileName::GetPathSeparator()) +
            wxT("' has changed.  Do you wish to save your work?");
    }
    else{
        message = wxT("Do you wish to save your work?");
    }
        wxMessageDialog* messageDialog =
        new wxMessageDialog(
                            this,
                            message,
                            wxT("wxsEditor"),
                            wxYES_NO|wxCANCEL|wxCENTRE|wxICON_WARNING
                            );
    int modalReturn = messageDialog->ShowModal();
    delete messageDialog;
    return modalReturn;
}

void wxsEditorFrame::Save(bool showDialog)
{
    wxFileDialog* saveFileDialog =
            new wxFileDialog(
                            this,
                            wxT("Save As"),
                            wxEmptyString,
                            wxEmptyString,
                            FILETYPES,
                            wxFD_SAVE
                            );
    wxMessageDialog* messageDialog =
            new wxMessageDialog(
                            static_cast<wxWindow*>(saveFileDialog),
                            wxEmptyString,
                            wxT("wxsEditor"),
                            wxYES_NO|wxCENTRE|wxICON_WARNING
                            );
    int modalReturn = wxID_OK;

    if (showDialog || this->path.IsEmpty()) {
        struct stat file;
        int dialogReturn = wxID_NO;
        modalReturn = saveFileDialog->ShowModal();

        while (wxID_NO == dialogReturn && wxID_OK == modalReturn
                && 0 == stat(saveFileDialog->GetPath().mb_str(), &file)) {
            wxString message = wxT("'") + saveFileDialog->GetPath()
                    + wxT("' already exists.\n  Do you wish to replace it?");
            messageDialog->SetMessage(message);
            dialogReturn = messageDialog->ShowModal();
            if (dialogReturn == wxID_NO) {
                modalReturn = saveFileDialog->ShowModal();
            }
        }
    }

    // save the file
    if (modalReturn == wxID_OK) {
        wxString savePath = saveFileDialog->GetPath();
        if (!this->path.IsSameAs(savePath)) {
            this->path = savePath;
        }
        this->TextCtrl1->SaveFile(path);
        this->SetStatusText(path, 0);
        this->isTextChanged = false;
        this->BitmapButton1->Enable();
    }

    // clean up
    delete messageDialog;
    delete saveFileDialog;
}

void wxsEditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f) + wxT('\n') + VERSION_STRING;
    wxMessageBox(msg, _("wxsEditor"));
}

void wxsEditorFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog* openFileDialog =
        new wxFileDialog(
                         this,
                         wxT("Open"),
                         wxEmptyString,
                         wxEmptyString,
                         FILETYPES
                         );
    if (openFileDialog->ShowModal() == wxID_OK) {
        //check for unsaved changes
        if (isTextChanged) {
            int modalReturn = AskSave();
            //if message dialog returns wxID_NO
            //then open the selected file
            if (modalReturn == wxID_YES)
                this->Save(false);
            else if (modalReturn == wxID_CANCEL) {
                delete openFileDialog;
                return;
            }
        }
        //open the file
        this->path = openFileDialog->GetPath();
        this->TextCtrl1->LoadFile(path);
        this->SetStatusText(path, 0);
        this->isTextChanged = false;
        this->BitmapButton1->Enable();
    }
    delete openFileDialog;
}

void wxsEditorFrame::OnRefresh(wxCommandEvent& event)
{
    if (this->path != wxEmptyString) {
        this->TextCtrl1->LoadFile(path);
        this->isTextChanged = false;
    }
    else{
        wxMessageBox(_("Could not find file to refresh"), _("wxsEditor"));
        this->BitmapButton1->Disable();
    }
}

void wxsEditorFrame::OnSave(wxCommandEvent& event)
{
    this->Save(false);  //if file exists, don't siplay "Save As" dialog
}

void wxsEditorFrame::OnSaveAs(wxCommandEvent& event)
{
    this->Save(true); //always display "Save As" dialog
}

void wxsEditorFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
    this->isTextChanged = true;
}

void wxsEditorFrame::OnQuit(wxCommandEvent& event)
{
    this->Close();
}

void wxsEditorFrame::OnClose(wxCloseEvent& event)
{
    if (this->isTextChanged) {
        int modalReturn = AskSave();
        //if message dialog returns wxID_NO
        //then close without saving
        if (modalReturn == wxID_YES) {
            this->Save(false);
        } else if (modalReturn == wxID_CANCEL) {
            event.Veto(); //don't close
            return;
        }
    }
    this->Destroy();
}

void wxsEditorFrame::OnCloseCurrentFile(wxCommandEvent& event)
{
    if (this->isTextChanged) {
        int modalReturn = AskSave();
        if (modalReturn == wxID_YES) {
            this->Save(false);
        }
    }
    this->isTextChanged = false;
    this->BitmapButton1->Disable();
    this->TextCtrl1->Clear();
    this->SetStatusText(wxEmptyString);
}
