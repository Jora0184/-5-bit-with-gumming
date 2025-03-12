#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    wxTextCtrl* textCtrl1; // ���� ��� ���������
    wxTextCtrl* textCtrl2; // ���� ��� �����
    wxTextCtrl* textCtrl3; // ���� ��� �������� ����������
    wxTextCtrl* textCtrl4; // ���� ��� ����������


    void OnButtonClicked(wxCommandEvent& event); // ���������� ������ "Encode"
    void OnClearButtonClicked(wxCommandEvent& event); // ����� ���������� ������ "Clear"
    // �������������� ������� � ����� (A-Z � �������������� ������� -> 0-31)
    char Binary(char c);
    // �������������� ����� � ������ (0-31 -> A-Z, , . = ; - ?)
    char Char(char value);
};

#endif