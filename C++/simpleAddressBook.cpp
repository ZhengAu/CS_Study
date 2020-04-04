#include<iostream>
#include<string>
#include<windows.h>
#include<iomanip>
#include<fstream>
using namespace std;

class AddressBook;
class Person        //��ϵ����Ϣ���
{
public:
    friend AddressBook;
    Person(string name,string gender,string phone,string QQ,string birthday,string native,string email,int code);
protected:
    string name;    //����
    string gender;  //�Ա�
    string phone;   //��ϵ�绰
    string QQ;      //QQ��
    string birthday;//����
    string native;  //����
    string email;   //����
    int code;       //��������
    Person *next;
};

class AddressBook   //ͨѶ¼
{
public:
    AddressBook();                   //��ʼ��ͨѶ¼
    ~AddressBook();                  //����ڴ�
    void add_Person();               //�����ϵ��
    void search_Person();            //������ϵ��
    void delete_Person();            //ɾ����ϵ��
    void modify_Person();            //�޸���ϵ����Ϣ
    void show_Person();              //��ʾ������ϵ��
    void display_head();             //��ʾ��¼��Ϣ��ͷ
    void display_Person(Person *per);//��ʾһ����ϵ��
    void clear_Book();               //���ͨѶ¼��¼
    void Read();                     //�����ļ�
    void save_to_file();             //�����ļ�
    void get_from_file();            //��ȡ��¼
    void execute();                  //ִ�к���
private:
    Person *person;
};

//��ϵ�˹��캯������ʼ������
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

//�������ϵ����Ϣ��������������
void AddressBook::add_Person()
{
    string _name,_gender,_native,_email,_birthday,_phone,_QQ;
    int _code;
    while(1)
    {
        system("cls");
        cout << "\n\t\t(*^__^*) ���� 0 ��������������! (*^__^*)\n" << endl;
        cout << "������������" ;
        cin >> _name;
        if(_name == "0")
        {
            system("cls");
            break;
        }
        cout << "�������Ա�";
        cin >> _gender;
        cout << "��������ϵ�绰��";
        cin >> _phone;
        cout << "������QQ�ţ�";
        cin >> _QQ;
        cout << "���������գ�";
        cin >> _birthday;
        cout << "�����뼮�᣺";
        cin >> _native;
        cout << "���������䣺";
        cin >> _email;
        cout << "�������������룺";
        cin >> _code;
        //�½��
        Person *p1 = new Person(_name,_gender,_phone,_QQ,_birthday,_native,_email,_code);
        p1->next = NULL;
        //��person����������
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
//****������ϵ��****
void AddressBook::search_Person()
{
    Person *findPerson = person;
    system("cls");
    if(findPerson==NULL)//ͨѶ¼��¼Ϊ��
    {
        cout << endl << "\t------ͨѶ¼û���κ���ϵ��------\n" << endl;
        system("pause");
        system("cls");
        return;//�����ϲ�
    }
    //����
    string find_name;
    cout << "��������Ҫ���ҵ��˵�������";
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
        cout << "\n\t------δ�ҵ�����ϵ�ˡ�------\n" << endl;

    cout << "�Ƿ��������(y/n)?    ";
    char str1;
    cin >>str1;
    if(str1=='Y'||str1=='y')//����ѭ��
        search_Person();
    system("cls");
}

//****�޸���ϵ��****
void AddressBook::modify_Person()
{
    Person *changePerson = person;
    system("cls");
    if(changePerson==NULL)//ͨѶ¼��¼Ϊ��
    {
        cout << endl << "\t------ͨѶ¼û���κ���ϵ��------\n" << endl << endl;
        system("pause");
        system("cls");
        return;//�����ϲ�
    }
    cout << "������Ҫ�޸���ϵ�˵�������" ;
    string change_name;
    cin >> change_name;

    while(changePerson!=NULL)//��Ҫ�޸ĵ���ϵ��
    {
        if(changePerson->name==change_name)
            break;
        else
            changePerson = changePerson->next;
    }

    if(changePerson!=NULL)//found
    {
        cout << "��Ҫ�޸ĵ���ϵ�˵���Ϣ���£�\n" << endl;
        display_head();
        display_Person(changePerson);
        cout << endl;
        int choice;
        do
        {
            cout << "----------------------------------------\n";
            cout << "\t1.�޸����� \n" << "\t2.�޸��Ա� \n" << "\t3.�޸���ϵ�绰 \n" << "\t4.�޸�QQ�� \n"<< "\t5.�޸����� \n";
            cout  << "\t6.�޸ļ��� \n" << "\t7.�޸����� \n" << "\t8.�޸��������� \n" << "\t0.�˳� \n";
            cout << "----------------------------------------\n";
            cout << "��ѡ����Ҫ�޸ĵ���Ϣ(0-8)��";
            cin >> choice;
            if(choice!=0) cout << "\n�������µ���Ϣ��";
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
                default:cout << "�������" << endl;
            }
            system("cls");
            //cout << "\n\t------�޸ĳɹ�------\n" << endl;
            display_head();
            display_Person(changePerson);
        }while(choice!=0);
    }
    else //not found
        cout << "\n\t------δ�ҵ�����ϵ�ˡ�------\n" << endl;
    cout << "�Ƿ�����޸�(y/n)?    ";
    char str1;
    cin >>str1;
    if(str1=='Y'||str1=='y')//����ѭ��
        modify_Person();
}
//****ɾ����ϵ��****
void AddressBook::delete_Person()
{
    Person *currentPerson = person;//��ǰָ��
    Person *priorPerson = person;   //ǰ��ָ��
    system("cls");
    if(currentPerson==NULL)//ͨѶ¼��¼Ϊ��
    {
        cout << endl << "\t------ͨѶ¼û���κ���ϵ��------\n" << endl << endl;
        system("pause");
        system("cls");
        return;//�����ϲ�
    }

    int flag=0;//�Ƿ������ı�־
    cout << "\n��������Ҫɾ������ϵ�˵����� ��" ;
    string del_name;
    cin >> del_name;
    while(currentPerson!=NULL)//����ϵ�˼�¼
    {
        if(currentPerson->name==del_name)//�ҵ�
        {
            display_Person(currentPerson);
            cout << "\n���ҵ�Ҫɾ������ϵ�ˣ��Ƿ�ɾ��?(y/n)    " ;
            char str;
            cin >> str;
            flag = 1;//�ҵ���־
            if(str=='Y'||str=='y')//ȷ��ɾ��
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
                cout << "\n\t------�ѳɹ�ɾ����ϵ�ˡ�------\n" << endl;
            }
            else break; //��ɾ��
        }
        if(flag==1) break;
        priorPerson = currentPerson;
        currentPerson = currentPerson->next;
    }
    if(flag==0)
    {
        cout << "\n\tû�д���ϵ�ˡ�" << endl;
    }

    cout << "\n�Ƿ����ɾ��(y/n)?    ";
    char str1;
    cin >>str1;
    if(str1=='Y'||str1=='y')//����ѭ��
        delete_Person();
    system("cls");
}

//****��ʾ���е���ϵ��****
void AddressBook::show_Person()
{
    Person *pPerson = person;
    system("cls");
    if(pPerson==NULL)
    {
        cout << "\n\t------ͨѶ¼��û���κ���ϵ�ˡ�------\n" << endl;
    }
    else
    {
        display_head();
        while(pPerson!=NULL)
        {
            display_Person(pPerson);//��ʾ������ϵ����Ϣ
            pPerson = pPerson->next;
        }
    }
    system("pause");
    system("cls");
}
//****��ʾ��ϵ����Ϣ��ͷ
void AddressBook::display_head()
{
    cout <<  setw(10) << "����" <<  setw(6) << "�Ա�" <<  setw(14) << "��ϵ�绰" <<  setw(12) << "QQ" ;
    cout <<  setw(12) << "����" <<  setw(15) << "����" <<  setw(22) << "����" <<  setw(10) << "��������" << endl;
}
//****���������ϵ����Ϣ****
void AddressBook::display_Person(Person *per)
{
    cout <<  setw(10) << per->name << setw(6) << per->gender << setw(14) << per->phone << setw(12) << per->QQ;
    cout << setw(12) << per->birthday << setw(15)  << per->native << setw(22) << per->email << setw(10) << per->code << endl;
}
//****���ͨѶ¼****
void AddressBook::clear_Book()
{
    Person *currentPerson = person;
    system("cls");
    if(currentPerson==NULL)
    {
        cout << "\n\t------ͨѶ¼��¼Ϊ�գ�------\n" << endl;
        return;
    }
    cout << "\n�Ƿ�������(y/n)��" << endl;
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
    person = NULL;//���
    cout << "\n\t------�����ͨѶ¼��------\n" << endl;
    system("pause");
    system("cls");
}
//****����ͨѶ¼���ļ�F1.txt��֮ǰ�ļ�¼������****
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
//****���ļ�F1.txt��ȡͨѶ¼****
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
        if(person!=NULL)//��Ϊͷ���
        {
            Person *p_new = person;
            while(p_new->next!=NULL)
                p_new = p_new->next;
            p_new ->next = p;
        }
        else//��һ�����
            person = p;
    }
    infile.close();
}
//****��ҳ��˵�****
void AddressBook::execute()
{
    int choice;
    get_from_file();//���ļ��ж�ȡ֮ǰ�ļ�¼
    do
    {
        cout << "\n\t\t     --------��ӭ������ͨѶ¼ϵͳ-------- \n" << endl;
        cout << "\t\t.............................................." << endl;
        cout << "\t\t.             ������ѡ����(0-6):           ." << endl;
        cout << "\t\t..............................................\n" << endl;
        cout << "\t\t.             1......¼����ϵ��              .\n" << endl;
        cout << "\t\t.             2......��ѯ��ϵ��              .\n" << endl;
        cout << "\t\t.             3......�޸���ϵ��              .\n" << endl;
        cout << "\t\t.             4......ɾ����ϵ��              .\n" << endl;
        cout << "\t\t.             5......���ͨѶ¼              .\n" << endl;
        cout << "\t\t.             6......�����ϵ��              .\n" << endl;
        cout << "\t\t.             0......�˳�ϵͳ                .\n" << endl;
        cout << "\t\t..............................................\n" << endl;
        cout << "\t\t.Please input your chonce : ";
        cin >> choice;
        switch(choice)
        {
            case 1: add_Person();        //¼�뺯��
                    break;
            case 2: search_Person();     //��ѯ����
                    break;
            case 3: modify_Person();     //�޸ĺ���
                    break;
            case 4: delete_Person();     //ɾ������
                    break;
            case 5: show_Person();       //�������
                    break;
            case 6: clear_Book();        //��պ���
                    break;
            case 0: save_to_file();
                    system("cls");
                    cout << "\n\n\t  --------��лʹ�ñ�������������˳����������������--------\n\n\n";
                    cout << "--------------------------------------------------------------------------------\n";
					exit(1);
            default:cout << "\n\t\t  -------����������������룡-------\n\n\n";
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
