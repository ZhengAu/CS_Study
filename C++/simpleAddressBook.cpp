#include<iostream>
#include<string>
#include<windows.h>
#include<iomanip>
#include<fstream>
using namespace std;

class AddressBook;
class Person        //联系人信息结点
{
public:
    friend AddressBook;
    Person(string name,string gender,string phone,string QQ,string birthday,string native,string email,int code);
protected:
    string name;    //姓名
    string gender;  //性别
    string phone;   //联系电话
    string QQ;      //QQ号
    string birthday;//生日
    string native;  //籍贯
    string email;   //邮箱
    int code;       //邮政编码
    Person *next;
};

class AddressBook   //通讯录
{
public:
    AddressBook();                   //初始化通讯录
    ~AddressBook();                  //清空内存
    void add_Person();               //添加联系人
    void search_Person();            //查找联系人
    void delete_Person();            //删除联系人
    void modify_Person();            //修改联系人信息
    void show_Person();              //显示所有联系人
    void display_head();             //显示记录信息表头
    void display_Person(Person *per);//显示一个联系人
    void clear_Book();               //清空通讯录记录
    void Read();                     //读入文件
    void save_to_file();             //存入文件
    void get_from_file();            //读取记录
    void execute();                  //执行函数
private:
    Person *person;
};

//联系人构造函数，初始化数据
Person::Person(string name,string gender,string phone,string QQ,string birthday,string native,string email,int code)
{
    this->name = name;
    this->gender = gender;
    this->phone = phone;
    this->QQ = QQ;
    this->birthday = birthday;
    this->native = native;
    this->email = email;
    this->code = code;
}
AddressBook::AddressBook()
{
    person = NULL;
}
AddressBook::~AddressBook()
{
    /*clear_Book();
    delete person;
    person = NULL;*/
}

//添加新联系人信息函数，创建链表
void AddressBook::add_Person()
{
    string _name,_gender,_native,_email,_birthday,_phone,_QQ;
    int _code;
    while(1)
    {
        system("cls");
        cout << "\n\t\t(*^__^*) 输入 0 代表结束输入操作! (*^__^*)\n" << endl;
        cout << "请输入姓名：" ;
        cin >> _name;
        if(_name == "0")
        {
            system("cls");
            break;
        }
        cout << "请输入性别：";
        cin >> _gender;
        cout << "请输入联系电话：";
        cin >> _phone;
        cout << "请输入QQ号：";
        cin >> _QQ;
        cout << "请输入生日：";
        cin >> _birthday;
        cout << "请输入籍贯：";
        cin >> _native;
        cout << "请输入邮箱：";
        cin >> _email;
        cout << "请输入邮政编码：";
        cin >> _code;
        //新结点
        Person *p1 = new Person(_name,_gender,_phone,_QQ,_birthday,_native,_email,_code);
        p1->next = NULL;
        //新person结点加入链表
        if(person!=NULL)
        {
            Person *p2;
            p2 = person;
            while(p2->next!=NULL)
                p2 = p2->next;
            p2->next = p1;
        }
        else
        {
            person = p1;
        }
    }
}
//****查找联系人****
void AddressBook::search_Person()
{
    Person *findPerson = person;
    system("cls");
    if(findPerson==NULL)//通讯录记录为空
    {
        cout << endl << "\t------通讯录没有任何联系人------\n" << endl;
        system("pause");
        system("cls");
        return;//返回上层
    }
    //找人
    string find_name;
    cout << "请输入你要查找的人的姓名：";
    cin >> find_name;
    while(findPerson!=NULL)
    {
        if(findPerson->name==find_name)
        {
            display_Person(findPerson);
            break;
        }

        else
            findPerson = findPerson->next;
    }

    if(findPerson==NULL)
        cout << "\n\t------未找到此联系人。------\n" << endl;

    cout << "是否继续查找(y/n)?    ";
    char str1;
    cin >>str1;
    if(str1=='Y'||str1=='y')//继续循环
        search_Person();
    system("cls");
}

//****修改联系人****
void AddressBook::modify_Person()
{
    Person *changePerson = person;
    system("cls");
    if(changePerson==NULL)//通讯录记录为空
    {
        cout << endl << "\t------通讯录没有任何联系人------\n" << endl << endl;
        system("pause");
        system("cls");
        return;//返回上层
    }
    cout << "请输入要修改联系人的姓名：" ;
    string change_name;
    cin >> change_name;

    while(changePerson!=NULL)//找要修改的联系人
    {
        if(changePerson->name==change_name)
            break;
        else
            changePerson = changePerson->next;
    }

    if(changePerson!=NULL)//found
    {
        cout << "所要修改的联系人的信息如下：\n" << endl;
        display_head();
        display_Person(changePerson);
        cout << endl;
        int choice;
        do
        {
            cout << "----------------------------------------\n";
            cout << "\t1.修改姓名 \n" << "\t2.修改性别 \n" << "\t3.修改联系电话 \n" << "\t4.修改QQ号 \n"<< "\t5.修改生日 \n";
            cout  << "\t6.修改籍贯 \n" << "\t7.修改邮箱 \n" << "\t8.修改邮政编码 \n" << "\t0.退出 \n";
            cout << "----------------------------------------\n";
            cout << "请选择你要修改的信息(0-8)：";
            cin >> choice;
            if(choice!=0) cout << "\n请输入新的信息：";
            switch(choice)
            {
                case 1: cin >> changePerson->name;
                        break;
                case 2: cin >> changePerson->gender;
                        break;
                case 3: cin >> changePerson->phone;
                        break;
                case 4: cin >> changePerson->QQ;
                        break;
                case 5: cin >> changePerson->birthday;
                        break;
                case 6: cin >> changePerson->native;
                        break;
                case 7: cin >> changePerson->email;
                        break;
                case 8: cin >> changePerson->code;
                        break;
                case 0: system("cls");
                        return;
                default:cout << "输入错误。" << endl;
            }
            system("cls");
            //cout << "\n\t------修改成功------\n" << endl;
            display_head();
            display_Person(changePerson);
        }while(choice!=0);
    }
    else //not found
        cout << "\n\t------未找到此联系人。------\n" << endl;
    cout << "是否继续修改(y/n)?    ";
    char str1;
    cin >>str1;
    if(str1=='Y'||str1=='y')//继续循环
        modify_Person();
}
//****删除联系人****
void AddressBook::delete_Person()
{
    Person *currentPerson = person;//当前指针
    Person *priorPerson = person;   //前驱指针
    system("cls");
    if(currentPerson==NULL)//通讯录记录为空
    {
        cout << endl << "\t------通讯录没有任何联系人------\n" << endl << endl;
        system("pause");
        system("cls");
        return;//返回上层
    }

    int flag=0;//是否扎到的标志
    cout << "\n请输入你要删除的联系人的姓名 ：" ;
    string del_name;
    cin >> del_name;
    while(currentPerson!=NULL)//找联系人记录
    {
        if(currentPerson->name==del_name)//找到
        {
            display_Person(currentPerson);
            cout << "\n已找到要删除的联系人，是否删除?(y/n)    " ;
            char str;
            cin >> str;
            flag = 1;//找到标志
            if(str=='Y'||str=='y')//确定删除
            {
                if(currentPerson==person)
                {
                    person = currentPerson->next;
                    delete currentPerson;
                }
                else
                {
                    priorPerson->next = currentPerson->next;
                    delete currentPerson;
                }
                cout << "\n\t------已成功删除联系人。------\n" << endl;
            }
            else break; //不删除
        }
        if(flag==1) break;
        priorPerson = currentPerson;
        currentPerson = currentPerson->next;
    }
    if(flag==0)
    {
        cout << "\n\t没有此联系人。" << endl;
    }

    cout << "\n是否继续删除(y/n)?    ";
    char str1;
    cin >>str1;
    if(str1=='Y'||str1=='y')//继续循环
        delete_Person();
    system("cls");
}

//****显示所有的联系人****
void AddressBook::show_Person()
{
    Person *pPerson = person;
    system("cls");
    if(pPerson==NULL)
    {
        cout << "\n\t------通讯录中没有任何联系人。------\n" << endl;
    }
    else
    {
        display_head();
        while(pPerson!=NULL)
        {
            display_Person(pPerson);//显示单个联系人信息
            pPerson = pPerson->next;
        }
    }
    system("pause");
    system("cls");
}
//****显示联系人信息表头
void AddressBook::display_head()
{
    cout <<  setw(10) << "姓名" <<  setw(6) << "性别" <<  setw(14) << "联系电话" <<  setw(12) << "QQ" ;
    cout <<  setw(12) << "生日" <<  setw(15) << "籍贯" <<  setw(22) << "邮箱" <<  setw(10) << "邮政编码" << endl;
}
//****输出单个联系人信息****
void AddressBook::display_Person(Person *per)
{
    cout <<  setw(10) << per->name << setw(6) << per->gender << setw(14) << per->phone << setw(12) << per->QQ;
    cout << setw(12) << per->birthday << setw(15)  << per->native << setw(22) << per->email << setw(10) << per->code << endl;
}
//****清空通讯录****
void AddressBook::clear_Book()
{
    Person *currentPerson = person;
    system("cls");
    if(currentPerson==NULL)
    {
        cout << "\n\t------通讯录记录为空！------\n" << endl;
        return;
    }
    cout << "\n是否真的清空(y/n)？" << endl;
    char str1;
    cin >>str1;
    if(str1=='N'||str1=='n')
    {
        system("cls");
        return;
    }

    while(currentPerson!=NULL)
    {
        Person *temp = currentPerson->next;
        delete currentPerson;
        currentPerson = temp;
    }
    person = NULL;//清空
    cout << "\n\t------已清空通讯录！------\n" << endl;
    system("pause");
    system("cls");
}
//****保存通讯录到文件F1.txt，之前的记录更新了****
void AddressBook::save_to_file()
{
    ofstream outfile("F1.txt",ios::out);
    if(!outfile)
    {
        cerr << "F1.txt open error." << endl;
        exit(1);
    }
    Person *p = person;
    while(p!=NULL)
    {
        outfile << setw(10) << p->name ;
        outfile << setw(8) << p->gender ;
        outfile << setw(15) << p->phone ;
        outfile << setw(15) << p->QQ ;
        outfile << setw(15) << p->birthday ;
        outfile << setw(15) << p->native  ;
        outfile << setw(20) << p->email ;
        outfile << setw(12) << p->code << endl;
        p = p->next;
    }
    outfile.close();
}
//****从文件F1.txt读取通讯录****
void AddressBook::get_from_file()
{
    string name,gender,phone,QQ,birthday,native,email;
    int code;
    ifstream infile("F1.txt",ios::app);
    if(!infile)
    {
        cerr << "F1.txt open error." << endl;
        exit(1);
    }

    Person *p = person;
    while(infile >> name >> gender >> phone >> QQ >> birthday >> native >> email >> code)
    {
        p = new Person( name,gender,phone,QQ,birthday,native,email,code);
        p->next = NULL;
        if(person!=NULL)//不为头结点
        {
            Person *p_new = person;
            while(p_new->next!=NULL)
                p_new = p_new->next;
            p_new ->next = p;
        }
        else//第一个结点
            person = p;
    }
    infile.close();
}
//****主页面菜单****
void AddressBook::execute()
{
    int choice;
    get_from_file();//从文件中读取之前的记录
    do
    {
        cout << "\n\t\t     --------欢迎来到简单通讯录系统-------- \n" << endl;
        cout << "\t\t.............................................." << endl;
        cout << "\t\t.             请输入选项编号(0-6):           ." << endl;
        cout << "\t\t..............................................\n" << endl;
        cout << "\t\t.             1......录入联系人              .\n" << endl;
        cout << "\t\t.             2......查询联系人              .\n" << endl;
        cout << "\t\t.             3......修改联系人              .\n" << endl;
        cout << "\t\t.             4......删除联系人              .\n" << endl;
        cout << "\t\t.             5......浏览通讯录              .\n" << endl;
        cout << "\t\t.             6......清空联系人              .\n" << endl;
        cout << "\t\t.             0......退出系统                .\n" << endl;
        cout << "\t\t..............................................\n" << endl;
        cout << "\t\t.Please input your chonce : ";
        cin >> choice;
        switch(choice)
        {
            case 1: add_Person();        //录入函数
                    break;
            case 2: search_Person();     //查询函数
                    break;
            case 3: modify_Person();     //修改函数
                    break;
            case 4: delete_Person();     //删除函数
                    break;
            case 5: show_Person();       //浏览函数
                    break;
            case 6: clear_Book();        //清空函数
                    break;
            case 0: save_to_file();
                    system("cls");
                    cout << "\n\n\t  --------感谢使用本软件！已正常退出，按任意键结束！--------\n\n\n";
                    cout << "--------------------------------------------------------------------------------\n";
					exit(1);
            default:cout << "\n\t\t  -------输入错误，请重新输入！-------\n\n\n";
                    cout << "--------------------------------------------------------------------------------\n";
                    system("pause");
                    system("cls");
                    break;
        }
    }while(choice!=0);
}

int main()
{
    AddressBook add;
    add.execute();
    return 0;
}
