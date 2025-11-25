#include <iostream>
#include <locale.h>
#include <fstream>
#include <string.h>

using namespace std;

char letters[36] = {
        'A','B','C','D','E','F',
        'G','H','I','J','K','L',
        'M','N','O','P','Q','R',
        'S','T','U','V','W','X',
        'Y','Z','1','2','3','4',
        '5','6','7','8','9','0'
};

char morse[36][6] = {
        ".-", "-...", "-.-.", "-..", ".",
        "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-",
        ".-.", "...", "-", "..-", "...-",
        ".--", "-..-", "-.--", "--..",
        ".----", "..---", "...--", "....-", ".....",
        "-....", "--...", "---..", "----.", "-----"
};

void encodeChar(char a, char out[]);
void encodeToMorse(const char inp[], char out[]);

char decodeChar(const char code[]);
void decodeToText(const char inp[], char out[]);

int main(void) {
    setlocale(LC_ALL, "Russian");
    char input[1000], output[2500];

    int mode = 0;
    cout << "Прочитать из файла text.txt - 1, прочитать с клавиатуры - 2" << endl;
    cin >> mode;
    cin.ignore();

    if (mode == 2) {
        cout << "Введите текст: " << endl;
        cin.getline(input, 1000);

        if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')) {
            encodeToMorse(input, output);
            cout << "Морзе: " << output << endl;
        } else {
            decodeToText(input, output);
            cout << "Текст: " << output << endl;
        }
    } else if (mode == 1){
        ifstream in("text.txt");
        if (!in.is_open())
        {
            cout<<"Файл text.txt не существует"<<endl;
            return -1;
        }
        in.getline(input, 500);
        in.close();
        cout << "Прочитано из файла: " << input << endl;

        if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')) {
            encodeToMorse(input, output);
            cout << "Морзе: " << output << endl;
        } else {
            decodeToText(input, output);
            cout << "Текст: " << output << endl;
        }
    }
    return 0;
}

char decodeChar(const char code[]){
    for (int i = 0; i < 36; i++)
    {
        if (strcmp(morse[i], code) == 0)
            return letters[i];
    }
    return ' ';
}

void decodeToText(const char inp[], char out[]){
    out[0] = '\0';

    char buffer[6];
    int pos = 0;
    int spaces = 0;
    int len = strlen(inp);

    for (int i = 0; i <= len; i++){
        if (inp[i] != ' ' && inp[i] != '\0'){
            buffer[pos++] = inp[i];
            spaces = 0;
        }
        else{
            buffer[pos] = '\0';
            pos = 0;

            if (buffer[0] != '\0'){
                char decoded = decodeChar(buffer);
                int L = strlen(out);
                out[L] = decoded;
                out[L + 1] = '\0';
            }
            spaces++;

            if (spaces==7){
                int L = strlen(out);
                out[L] = ' ';
                out[L + 1] = '\0';
                spaces = 0;
            }
        }
    }
}

void encodeChar(char a, char out[]){
    if (a>='a' && a<='z')
        a-=32;
    for (int i = 0; i < 36; i++){
        if (letters[i] == a){
            strcpy(out, morse[i]);
            return;
        }
    }
    out[0]='\0';
}

void encodeToMorse(const char inp[], char out[]){
    out[0] = '\0';

    char buffer[6];
    int len = strlen(inp);

    for (int i = 0; i< len; i++){
        if (inp[i] == ' '){
            strcat(out, "       ");
            continue;
        }
        encodeChar(inp[i],buffer);
        if (buffer[0] != '\0'){
            strcat(out,buffer);
            strcat(out, "   ");

        }
    }
}
