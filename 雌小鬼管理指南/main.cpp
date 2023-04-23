#include <iostream>
#include"functions_statement.h"
using namespace std;
int main(){
    struct Excel book;
    book.number=0;
    int con=0;
    while(true){
        showMenu();
        cin>>con;
        switch(con){
            case 1:
                addperson(&book);
                break;
            case 2:
                showperson(&book);
                break;
            case 3:
                deleteperson(&book);
                break;
            case 4:
                findperson(&book);
                break;
            case 5:
                changeperson(&book);
                break;
            case 6:
                emptyperson(&book);
                break;
            case 0:
                exit();
                return 0;
            default:
                break;
        }
        
    }
    system("pause");
    return 0;
}