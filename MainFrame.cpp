#include "MainFrame.h"
#include <bitset>
#include <string>

using namespace std;


void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    string message = textCtrl1->GetValue().ToStdString();
    string key = textCtrl2->GetValue().ToStdString();
    string encrypted;
    string process;
    char msgValue;
    char keyValue;
    char result;
    char i;

    for (i = 0; i < message.length(); i++) {
        msgValue = Binary(message[i]);
        keyValue = Binary(key[i % key.length()]);

        if (msgValue == -1 || keyValue == -1) {
            wxMessageBox("Error: Use only A-Z and symbols , . space - ( )", "Error", wxOK | wxICON_ERROR);
            return;
        }

        bitset<5> msgBits(msgValue);
        bitset<5> keyBits(keyValue);
        bitset<5> resultBits = msgBits ^ keyBits;
        result = Char(resultBits.to_ulong());

        process += message[i] + string(" (") + msgBits.to_string() + ") + " +
            key[i % key.length()] + " (" + keyBits.to_string() + ") = " +
            result + " (" + resultBits.to_string() + ")\n";
            
        encrypted += result;
    }
     
    textCtrl3->SetValue(process);
    textCtrl4->SetValue(encrypted);
}

void MainFrame::OnClearButtonClicked(wxCommandEvent& event) {
    // Очищаем все текстовые поля
    textCtrl1->Clear();
    textCtrl2->Clear();
    textCtrl3->Clear();
    textCtrl4->Clear();
}

char MainFrame::Binary(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') return c - 'A';
    else if (c == ' ') return 26;
    else if (c == '.') return 27;
    else if (c == ',') return 28;
    else if (c == '-') return 29;
    else if (c == '(') return 30;
    else if (c == ')') return 31;
    return -1;
}

char MainFrame::Char(char value) {
    if (value >= 0 && value <= 25) return 'A' + value;
    else if (value == 26) return ' ';
    else if (value == 27) return '.';
    else if (value == 28) return ',';
    else if (value == 29) return '-';
    else if (value == 30) return '(';
    else if (value == 31) return ')';
    return '!';
}