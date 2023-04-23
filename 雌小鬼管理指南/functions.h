#include"struct.h"
using namespace std;
//input the information
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}
void addperson(Excel * book){
    if(book->number==MAX){
        cout<<"满了啊宅宅！杂鱼！杂鱼！";
        return;
    }
    else{
        cout << "你叫啥呀：" << endl;
		string name;
		cin >> name;
        book->PersonArray[book->number].name=name;

        cout<<"男孩子还是女孩子："<<endl;
        cout << "1——有小鸡鸡" << endl;
		cout << "2——没有小鸡鸡" << endl;
        int gender;
        while(true){
            cin>>gender;
            if(gender==1||gender==2){
                book->PersonArray[book->number].gender=gender;
                break;
            }
            else{
                cout<<"输错了！杂鱼！"<<endl;
                break;
            }
        }

        cout<<"你多大了："<<endl;
        int age=0;
        cin>>age;
        while(true){
            if(age<=0||age>=100){
                cout<<"输错了！杂鱼！"<<endl;
            }
            else{
                book->PersonArray[book->number].age=age;
                break;
            }
        }
        cout<<"你住哪里:"<<endl;
        string address=" ";
        cin>>address;
        book->PersonArray[book->number].address=address;

        book->number++;
        printf("%s","干完了耶！");
        system("pause");
        system("cls");
    }
}
void showperson(Excel * book){
    if(book->number==0){
        cout<<"没东西呢！";
    }else{
        for(int i=0;i<book->number;i++){
            cout<< "姓名：" <<book->PersonArray[i].name<<"\t";
            cout<< "性别：" <<(book->PersonArray[i].gender==1?"男":"女")<<"\t";
            cout<< "年龄："<<book->PersonArray[i].age<<"\t";
            cout<< "住址："<<book->PersonArray[i].address<<endl;
        }   
    }
    system("pause");
    system("cls");
}

int isexist(Excel * book,string name){
    getline(cin,name);
    for(int i=0;i<(book->number);i++){
        if((book->PersonArray[i].name)==name){
            return i;
            break;
        }else{
            return -1;
        }
    }
}
void deleteperson(Excel * book){
    printf("%s","不找谁去玩了杂鱼？");
    int temp=0;
    string name=" ";
    cin>>name;
    temp=isexist((Excel*) book,name);
    if(temp!=-1){
        for (int i = temp; i < book->number && i < MAX - 1; i++) {
			book->PersonArray[i] = book->PersonArray[i + 1];
		}
		book->number--;
		cout << "删除成功！" << endl;
	}else{
        printf("%s","记错了欸宅宅！");
    }
    system("pause");
    system("cls");
}

void findperson(Excel * book){
    printf("%s","你想找谁玩去？");
    string name=" ";
    getline(cin,name);
    for(int i=0;i<(book->number);i++){
        if(name==book->PersonArray[i].name){
            cout<< "姓名：" <<book->PersonArray[i].name<<"\t";
            cout<< "性别：" <<(book->PersonArray[i].gender==1?"男":"女")<<"\t";
            cout<< "年龄："<<book->PersonArray[i].age<<"\t";
            cout<< "住址："<<book->PersonArray[i].address<<endl;
        }else{
            cout<<"没有呢，记错了吧杂鱼！"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void changeperson(Excel * book){
    printf("%s","想改谁？杂鱼！\n");
    string name=" ";
    getline(cin,name);
    while(true){
        for(int i=0;i<book->number;i++){
            if(name==book->PersonArray[i].name){
                printf("%s","改啥？\t1——名字\t2——性别\t3——年龄\t4——住址");
                int temp;
                cin>>temp;
                switch(temp){
                    case 1 :{
                        cout<<"改成啥？"<<endl;
                        string name=" ";
                        cin>>name;
                        book->PersonArray[i].name=name;
                        break;}
                    case 2 :{
                        cout<<"男的女的还搞混？\t男——1\t女——2"<<endl;
                        int gender=0;
                        cin>>gender;
                        book->PersonArray[i].gender=gender;
                        break;}
                    case 3 :{
                        cout<<"改成多大的？"<<endl;
                        long long age;
                        cin>>age;
                        book->PersonArray[i].age=age;
                        break;}
                    case 4 :{
                        cout<<"别上错床！"<<endl;
                        string address=" ";
                        cin>>address;
                        book->PersonArray[i].address=address;
                        break;}
                    default :{
                        cout<<"输入错了呢！杂鱼杂鱼！重新输入！"<<endl;}
                }
            }else{
                cout<<"输入错了呢！杂鱼杂鱼！重新输入！"<<endl;
            }
        }
    }
}

void emptyperson(Excel * book){
    cout << "不找他们玩去了嘛？" << endl;
	cout << "1、是" << "\t" << "2、否" << endl;
	int temp;
	cin >> temp;
	if (temp == 1) {
		book->number = 0;
		cout << "杂鱼已清空！" << endl;
	} else {
		cout << "杂鱼已取消!" << endl;
	}
	system("pause");
	system("cls");
}

void exit(){
    cout<<"懒鬼！快滚蛋！";
    system("pause");
    return;
}