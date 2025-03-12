#include "MainFrame.h"
#include "App.h"

#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("C++ GUI XOR Encryption");
    mainFrame->SetClientSize(800, 450);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this);

    // Создаём шрифт с увеличенным размером (например, 12   пунктов)
    wxFont largeFont(12, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont largeFont2(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    // Текст "Write text"
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "Write text", wxPoint(55, 30));
    staticText1->SetFont(largeFont); // Применяем шрифт
    textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 50), wxSize(350, 25));
    textCtrl1->SetFont(largeFont);

    // Ключ "Write key"
    wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, "Write key", wxPoint(55, 80));
    staticText2->SetFont(largeFont);
    textCtrl2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 100), wxSize(350, 25));
    textCtrl2->SetFont(largeFont);

    // Процесс XOR
    wxStaticText* staticText3 = new wxStaticText(panel, wxID_ANY, "XOR Process", wxPoint(455, 30));
    staticText3->SetFont(largeFont2);
    textCtrl3 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(450, 50), wxSize(300, 300), wxTE_MULTILINE | wxTE_READONLY);
    textCtrl3->SetFont(largeFont2);

    // Кнопка
    wxStaticText* staticText4 = new wxStaticText(panel, wxID_ANY, "Click the button to encode", wxPoint(55, 240));
    staticText4->SetFont(largeFont);
    wxButton* button = new wxButton(panel, wxID_ANY, "Encode", wxPoint(50, 260), wxSize(100, 35));
    button->SetFont(largeFont);
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    // Новая кнопка "Clear" (справа от "Encode")
    wxButton* clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(50, 360), wxSize(700, 30));
    clearButton->SetFont(largeFont);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);

    // Зашифрованный текст
    wxStaticText* staticText5 = new wxStaticText(panel, wxID_ANY, "Ciphertext", wxPoint(55, 305));
    staticText5->SetFont(largeFont);
    textCtrl4 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 325), wxSize(350, 25), wxTE_READONLY);
    textCtrl4->SetFont(largeFont);
    
    //
    wxStaticText* staticText6 = new wxStaticText(panel, wxID_ANY, "Use only A-Z and symbols , . space ; - ?", wxPoint(280, 410));
    staticText6->SetFont(largeFont);

}