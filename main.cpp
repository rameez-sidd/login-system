#include <iostream>
#define STD_OUTPUT_HANDLE (DWORD)(0xfffffff5)
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <conio.h>
using namespace std;

enum IN {
    IN_BACK = 8,
	IN_RET = 13

};


// FUNCTION DECLARATIONS :-
void welcomeScreen();
void mainMenu();
void choice(char);
bool isNumber(const string&);
void setcolor(int color);


// FILES DECLARATIONS :-
ofstream phoneOut;
ifstream phoneIn;
ifstream detailsIn;
ofstream detailsOut;
ofstream fileOut;
ifstream fileIn;
ifstream usernameIn;
ofstream usernameOut;


// CLASS DEFINITIONS :-
class SignUp
{
private:
    string username;
    string password;
    string name;
    char gender;
    string age;
    string phone;
    int l;

public:
    string keepPasswordHidden(){
        l = password.length();
        string str;
        for(int i=0; i<l; i++){
            str.insert(0,"*");
        }
        return str;
    }
    string takePasswdFromUser(char sp = '*'){
        string passwd = "";
        char ch_ipt;
        while (true) {
            ch_ipt = getch();
            if (ch_ipt == IN::IN_RET) {
                cout << endl;
                return passwd;
            }
            else if (ch_ipt == IN::IN_BACK
                    && passwd.length() != 0) {
                passwd.pop_back();
                cout << "\b \b";

                continue;
            }
            else if (ch_ipt == IN::IN_BACK
                    && passwd.length() == 0) {
                continue;
            }

            passwd.push_back(ch_ipt);
            cout << sp;
        }
    }

    void openPhoneFileForWriting(){
        string filename = "Login Database\\Data\\Details\\Phone\\" + username + "_phone.txt";
        phoneOut.open(filename.c_str(), ios::out);
    }
    void closePhoneFileForWriting(){
        phoneOut.close();
    }
    void openDetailsFileForWriting(){
        string filename = "Login Database\\Data\\Details\\" + username + "_details.txt";
        detailsOut.open(filename.c_str(), ios::out);
    }
    void closeDetailsFileForWriting(){
        detailsOut.close();
    }
    void openUsernameFiles()
    {
        usernameIn.open("Login Database\\Data\\Username\\usernames.txt", ios::in);
        usernameOut.open("Login Database\\Data\\Username\\usernames.txt", ios::app);
    }
    void closeUsernameFiles()
    {
        usernameIn.close();
        usernameOut.close();
    }
    void openIndividualUserFileForWriting()
    {
        string filename = "Login Database\\Data\\Password\\" + username + ".txt";
        fileOut.open(filename.c_str(), ios::out);
    }
    void closeIndividualUserFileForWriting()
    {
        fileOut.close();
    }
    void getName(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER NAME      : ";
        setcolor(7);
        cout << setw(5) << " ";
        getline(cin, name);
        checkName();
    }
    void getAge(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER AGE       : ";
        setcolor(7);
        cout << setw(5) << " ";
        cin >> age;
        checkAge();
    }
    void getGender(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " CHOOSE GENDER   : " << endl;
        setcolor(7);
        cout << setw(17) << " ";
        cout << "1.Male" << endl;
        cout << setw(17) << " ";
        cout << "2.Female" << endl;
        cout << setw(17) << " ";
        cout << "3.Rather Not To Say";
        cout << setw(5) << " ";
        cin >> gender;
        checkGender();
        showUsername();
        showPassword();
        showName();
        showAge();
        showGender();

    }
    void getPhone(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER PHONE.NO  : ";
        setcolor(7);
        cout << setw(5) << " ";
        cin >> phone;
        checkPhone();
    }
    void getUsername()
    {
        cout << "\n\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " CHOOSE USERNAME : ";
        setcolor(7);
        cout << setw(5) << " ";
        cin >> username;
        checkUsername();

    }
    void getPassword()
    {
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " CHOOSE PASSWORD : ";
        setcolor(7);
        cout << setw(5) << " ";
        //cin >> password;
        password = takePasswdFromUser();
        checkPassword();
        cin.ignore();

    }

    void getData()
    {
        system("cls");
        cout << "\n";
        cout << setw(17) << " ";
        cout << "S I G N - U P" << endl;
        getUsername();
        getPassword();
        getName();
        getAge();
        getGender();
        getPhone();


        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*0+2);
        cout << "S I G N - U P  S U C C E S S F U L" << endl;
        setcolor(7);
    }
    void showUsername(){
        system("cls");
        cout << "\n";
        cout << setw(17) << " ";
        cout << "S I G N - U P" << endl;
        cout << "\n\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " CHOOSE USERNAME : ";
        setcolor(7);
        cout << setw(5) << " " << username << endl;
    }
    void showPassword(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " CHOOSE PASSWORD : ";
        setcolor(7);
        cout << setw(5) << " " << keepPasswordHidden() << endl;
    }
    void showName(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER NAME      : ";
        setcolor(7);
        cout << setw(5) << " " << name << endl;
    }
    void showAge(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER AGE       : ";
        setcolor(7);
        cout << setw(5) << " " << age << endl;
    }
    void showGender(){
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " CHOOSE GENDER   : " << endl;
        setcolor(7);
        cout << setw(17) << " ";
        cout << "1.Male" << endl;
        cout << setw(17) << " ";
        cout << "2.Female" << endl;
        cout << setw(17) << " ";
        cout << "3.Rather Not To Say";
        cout << setw(5) << " " << displayGender() << endl;
    }
    void encrypt()
    {
        int l = password.length();
        openIndividualUserFileForWriting();
        for (int i = 0; i < l; i++)
        {
            fileOut << char(password.at(i) + 37);
        }
    }
    void storeData()
    {
        encrypt();
        closeIndividualUserFileForWriting();
    }
    void checkUsername()
    {
        openUsernameFiles();
        string word;
        int f = 0;
        usernameIn.seekg(0, ios::end);
        int length = usernameIn.tellg();
        if (length == 0)
        {
            return;
        }
        else
        {
            usernameIn.seekg(0, ios::beg);
            while (usernameIn >> word)
            {

                if (word == username)
                {
                    f++;
                }
            }
            if (f == 0)
            {
                return;
            }
            else
            {
                cout << setw(17) << " ";
                setcolor(16 * 0 + 4);
                cout << "Username Not Available \a" << endl;
                setcolor(7);
                Sleep(1200);
                closeUsernameFiles();
                system("cls");
                cout << "\n";
                cout << setw(17) << " ";
                cout << "S I G N - U P" << endl;
                getUsername();
            }
        }
    }
    void checkPassword()
    {
        if (password.length() < 8)
        {
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Minimum 8 characters \a";
            setcolor(7);
            Sleep(1200);
            showUsername();
            getPassword();
        }
    }
    void checkName(){
        if(isNumber(name)){
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Invalid Name \a";
            setcolor(7);
            Sleep(1200);
            showUsername();
            showPassword();
            getName();
        }
    }
    void checkAge(){
        if(!isNumber(age)){
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Invalid Age \a";
            setcolor(7);
            Sleep(1200);
            getAge();
        }
        if(age.length()>2 || age.length()<2 || (age.length()==2 && age.at(0)=='1' && age.at(1)<'5')){
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Not Eligible \a";
            setcolor(7);
            Sleep(1200);
            showUsername();
            showPassword();
            showName();
            getAge();

        }
    }
    string displayGender(){
        if(gender=='1'){
            return "Male";
        }
        else if(gender=='2'){
            return "Female";
        }
        else if(gender=='3'){
            return "Rather Not To Say";
        }
        return NULL;
    }

    void checkGender(){
        if(gender!='1' && gender!='2' && gender!='3'){
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Invalid Choice \a";
            setcolor(7);
            Sleep(1200);
            showUsername();
            showPassword();
            showName();
            showAge();
            getGender();

        }
    }
    void checkPhone(){
        if(phone.length()<10 || phone.length()>10 || !isNumber(phone)){
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Invalid Phone Number \a";
            setcolor(7);
            Sleep(1200);
            showUsername();
            showPassword();
            showName();
            showAge();
            showGender();
            getPhone();
        }
    }
    void storeDetails(){
        openDetailsFileForWriting();
        detailsOut << "NAME : " << name << endl;
        detailsOut << "USERNAME : " << username << endl;
        detailsOut << "AGE : " << age << endl;
        detailsOut << "GENDER : " << displayGender() << endl;
        detailsOut << "PHONE.NO : " << phone << endl;
        closeDetailsFileForWriting();
        usernameOut << username << endl;
        closeUsernameFiles();
        storeData();
        openPhoneFileForWriting();
        phoneOut << phone;
        closePhoneFileForWriting();

    }
};


class Login
{
private:
    string username;
    string password;
    string pass;
    int count = 0;
public:
    string takePasswdFromUser(char sp = '*'){
        string passwd = "";
        char ch_ipt;
        while (true) {
            ch_ipt = getch();
            if (ch_ipt == IN::IN_RET) {
                cout << endl;
                return passwd;
            }
            else if (ch_ipt == IN::IN_BACK
                    && passwd.length() != 0) {
                passwd.pop_back();
                cout << "\b \b";

                continue;
            }
            else if (ch_ipt == IN::IN_BACK
                    && passwd.length() == 0) {
                continue;
            }

            passwd.push_back(ch_ipt);
            cout << sp;
        }
    }
    void openPhoneFileForReading(){
        string filename = "Login Database\\Data\\Details\\Phone\\" + username + "_phone.txt";
        phoneIn.open(filename.c_str(), ios::in);
    }
    void closePhoneFileForReading(){
        phoneIn.close();
    }
    void openDetailsFileForReading(){
        string filename = "Login Database\\Data\\Details\\" + username + "_details.txt";
        detailsIn.open(filename.c_str(), ios::in);
    }
    void closeDetailsFileForReading(){
        detailsIn.close();
    }
    void openUserFileForReading()
    {
        string filename = "Login Database\\Data\\Password\\" + username + ".txt";
        fileIn.open(filename.c_str(), ios::in);
    }
    void closeUserFileForReading()
    {
        fileIn.close();
    }
    void getUsername()
    {
        cout << "\n\n\n\n\n\n";
        cout << setw(17) << " ";
        cout << "L O G I N" << endl;
        cout << "\n\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER USERNAME : ";
        setcolor(7);
        cout << setw(5) << " ";
        cin >> username;
        openUserFileForReading();
        checkUsername();
        closeUserFileForReading();
    }
    string decrypt()
    {
        openUserFileForReading();
        fileIn.seekg(0, ios::end);
        int l = fileIn.tellg();
        char* name = new char[l];
        char ch;
        int i = 0;
        fileIn.seekg(0, ios::beg);
        while (fileIn.get(ch) && i<l)
        {
            name[i]=char(ch-37);
            i++;
        }
        closeUserFileForReading();
        string temp = convertToString(name, l);
        return temp;
    }
    string convertToString(char* a, int size){
        int i;
        string s = "";
        for (i = 0; i < size; i++) {
            s = s + a[i];
        }
        return s;
    }
    void getPassword()
    {
        cout << "\n";
        cout << setw(17) << " ";
        setcolor(16*7+0);
        cout << " ENTER PASSWORD : ";
        setcolor(7);
        cout << setw(5) << " ";
        password = takePasswdFromUser();
        pass = decrypt();
        checkPassword(pass);
    }
    void getData()
    {
        system("cls");
        getUsername();
        getPassword();
    }
    void checkUsername()
    {
        if (!fileIn)
        {
            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Username doesn't exist \a";
            setcolor(7);
            Sleep(1200);
            system("cls");
            getUsername();
        }
    }
    void showPersonDetails(){
        openDetailsFileForReading();
        Sleep(1500);
        system("cls");
        cout << "\n\n\n\n";
        string line;
        while(!detailsIn.eof()){
            getline(detailsIn, line);
            cout << setw(27) << " ";
            cout << line << "\n\n";
        }
        closeDetailsFileForReading();
        char in;
        cout << "\n\n";
        cout << setw(17) << " ";
        cout << "Press ESC to go to Main Menu...";
        in = getch();
        if(in==27){
            mainMenu();
        }
        else{
           exit(0);
        }

    }
    void checkPassword(string pass)
    {
        if (password == pass)
        {
            cout << "\n\n\n";
            cout << setw(17) << " ";
            setcolor(16*0+2);
            cout << "L O G I N  S U C C E S S F U L" << endl;
            setcolor(7);
            showPersonDetails();
        }
        else
        {

            cout << setw(17) << " ";
            setcolor(16 * 0 + 4);
            cout << "Wrong Password \a";
            setcolor(7);
            Sleep(1200);
            count++;
            recoverPassword();
            system("cls");
            cout << "\n\n\n\n\n\n";
            cout << setw(17) << " ";
            cout << "L O G I N" << endl;
            cout << "\n\n";
            cout << setw(17) << " ";
            setcolor(16*7+0);
            cout << " ENTER USERNAME : ";
            setcolor(7);
            cout << setw(5) << " " << username << endl;
            getPassword();
        }
    }
    void recoverPassword(){
        string tempPhone;
        string getPhoneNumber;
        if(count>5){
            system("cls");
            cout << "\n\n\n\n";
            cout << setw(17) << " ";
            cout << "T O O  M A N Y  A T T E M P T S" << endl;
            cout << "\n\n\n";
            cout << setw(17) << " ";
            cout << "To Recover your Password :-" << endl;
            cout << "\n";
            cout << setw(17) << " ";
            setcolor(16*7+0);
            cout << " VERIFY YOUR PHONE.NO  : ";
            setcolor(7);
            cout << setw(3) << " ";
            cin >> tempPhone;
            openPhoneFileForReading();
            while(!phoneIn.eof()){
                getline(phoneIn, getPhoneNumber);
            }
            if(tempPhone == getPhoneNumber){
                cout << "\n\n";
                cout << setw(17) << " ";
                cout << "Your Password is : ";
                setcolor(16*0+2);
                cout << pass << endl;
                setcolor(7);
                char ch;
                Sleep(1500);
                closePhoneFileForReading();
                cout << "\n\n\n\n";
                cout << setw(17) << " ";
                cout << "Press ESC to go to Main Menu...";
                ch = getch();
                if(ch==27){
                    mainMenu();
                }
                else{
                   exit(0);
                }
            }
            else{
                cout << "\n\n";
                cout << setw(17) << " ";
                setcolor(16*0+4);
                cout << "SORRY You Couldn't Recover Your Password" << endl;
                setcolor(7);
                closePhoneFileForReading();
                Sleep(1700);
                mainMenu();
            }

        }
        else{
            return;
        }
    }
};


// MAIN FUNCTION :-
int main()
{
    welcomeScreen();
    mainMenu();
    getch();
    return 0;
}

// FUNCTION DEFINITIONS :-
void welcomeScreen(){
    system("cls");
    char ch = 219;
    cout << "\n\n\n\n\n";
    cout << setw(22) << " ";
    cout << ch << "      " << ch << ch << ch << ch << "   " << ch << ch << ch << ch << "   " << ch << ch << ch << "   " << ch << ch << "   " << ch << endl;
    cout << setw(22) << " ";
    cout << ch << "      " << ch << " " << " " << ch << "   " << ch << " " << " " << " " << "   " << " " << ch << " " << "   " << ch << " " << ch << "  " << ch << endl;
    cout << setw(22) << " ";
    cout << ch << "      " << ch << " " << " " << ch << "   " << ch << " " << " " << " " << "   " << " " << ch << " " << "   " << ch << " " << ch << "  " << ch << endl;
    cout << setw(22) << " ";
    cout << ch << "      " << ch << " " << " " << ch << "   " << ch << " " << " " << ch << "   " << " " << ch << " " << "   " << ch << "  " << ch << " " << ch << endl;
    cout << setw(22) << " ";
    cout << ch << "      " << ch << " " << " " << ch << "   " << ch << " " << " " << ch << "   " << " " << ch << " " << "   " << ch << "  " << ch << " " << ch << endl;
    cout << setw(22) << " ";
    cout << ch << ch << ch << ch << "   " << ch << ch << ch << ch << "   " << ch << ch << ch << ch << "   " << ch << ch << ch << "   " << ch << "   "<< ch << ch << endl << endl;
    cout << setw(21) << " ";
    setcolor(16*7+0);
    cout << "     S    Y    S    T    E    M    " << endl << endl;
    setcolor(7);
    cout << "\n\n\n\n\n\n\n\n";
    cout << setw(25) << " ";
    cout << "copyright @ Rameez Siddiqui";
    getch();
}
void mainMenu(){
    system("cls");
    char c;
    cout << "\n\n\n\n\n\n\n\n";
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << setw(24) << " " << endl;
    setcolor(7);
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << "       1. SIGN UP       " << endl;
    setcolor(7);
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << setw(24) << " " << endl;
    setcolor(7);
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << "       2. LOG IN        " << endl;
    setcolor(7);
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << setw(24) << " " << endl;
    setcolor(7);
    cout << "\n";
    cout << setw(27) << " ";
    cout << "Enter Your Choice : ";
    cin >> c;
    choice(c);
}

void choice(char c){
    if(c=='1'){
        SignUp s;
        system("cls");

        s.getData();
        s.storeDetails();
        char ch;
        Sleep(1500);
        cout << "\n\n";
        cout << setw(17) << " ";
        cout << "Press ESC to go to Main Menu...";
        ch = getch();
        if(ch==27){
            mainMenu();
        }
        else{
           exit(0);
        }


    }
    else if(c=='2'){
        Login l;
        l.getData();
        char ch;
        Sleep(1500);
        cout << "\n\n";
        cout << setw(17) << " ";
        cout << "Press ESC to go to Main Menu...";
        ch = getch();
        if(ch==27){
            mainMenu();
        }
        else{
           exit(0);
        }
    }
    else{
        cout << setw(27) << " ";
        setcolor(16*0+4);
        cout << "Invalid Choice \a";
        setcolor(7);
        Sleep(1200);
        mainMenu();

    }
}

bool isNumber(const string& str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}

void setcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}
