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
    Student(string name,string id,string major,int age,float score){
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
    Student date;
    StudentNode* next;
    StudentNode(Student student):date(student),next(nullptr){}

};