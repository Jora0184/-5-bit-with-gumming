#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    wxTextCtrl* textCtrl1; // Поле для сообщения
    wxTextCtrl* textCtrl2; // Поле для ключа
    wxTextCtrl* textCtrl3; // Поле для процесса шифрования
    wxTextCtrl* textCtrl4; // Поле для результата

    void OnButtonClicked(wxCommandEvent& event); // Обработчик кнопки "Encode"
    void OnClearButtonClicked(wxCommandEvent& event); // Новый обработчик кнопки "Clear"
    // Преобразование символа в число (A-Z и дополнительные символы -> 0-31)
    char Binary(char c);
    // Преобразование числа в символ (0-31 -> A-Z, , . = ; - ?)
    char Char(char value);
};

#endif