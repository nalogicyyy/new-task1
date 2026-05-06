//学生类、链表类、链表管理类
#include <iostream>
#include <string>
using namespace std;
class Student{
  private:
    string name;
    string id;
    string major;
    int age;
    float score;
  public:
    Student(string name=" ",string id=" ",string major=" ",int age=0,float score=0.0){
        this->name=name;
        this->id=id;
        this->major=major;
        this->age=age;
        this->score=score;
    }
    friend class StudentList;
    void Showinfo()const {
        cout<<"姓名为："<<name<<"学号为："<<id<<"专业为："<<major<<"年龄为："<<age<<"分数为："<<score<<endl;
    }
};
class StudentNode{
public:
    Student data;
    StudentNode* next;
    StudentNode(Student student):data(student),next(nullptr){}

};
class StudentList{
private:
    StudentNode* head;
    int size;
    //私有工具，按学号查找结点
    StudentNode* findNodeById(const string& id) const {
        StudentNode* p=head->next;
        while (p!=nullptr){
            if(p->data.id==id){
                return p;
            }
            p=p->next;
        }
        return nullptr;
    }
public:
StudentList(){
    head=new StudentNode(Student());
    size=0;
}
~StudentList(){
    StudentNode* p=head;
    while(p!=nullptr)
    {
        head=head->next;
        delete p;
        p=head;
    }
    size=0;
}
};
