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
bool addStudent(const Student& s) {
        if (findNodeById(s.id) != nullptr) {
            cout << "该学号已存在，添加失败！" << endl;
            return false;
        }
        StudentNode* newNode = new StudentNode(s);
        StudentNode* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
        size++;
        cout << "学生信息添加成功！" << endl;
        return true;
    }
    bool deleteStudent(const string& id) {
        StudentNode* pre = head;
        StudentNode* cur = head->next;

        while (cur != nullptr && cur->data.id != id) {
            pre = cur;
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "未找到该学号的学生，删除失败！" << endl;
            return false;
        }

        pre->next = cur->next;
        delete cur;
        size--;
        cout << "✅ 学生信息删除成功！" << endl;
        return true;
    }
    bool updateStudent(const string& id) {
        StudentNode* node = findNodeById(id);
        if (node == nullptr) {
            cout << "未找到该学号的学生，修改失败！" << endl;
            return false;
        }

        cout << "请输入新的姓名（原：" << node->data.name << "）：";
        cin >> node->data.name;
        cout << "请输入新的年龄（原：" << node->data.age << "）：";
        cin >> node->data.age;
        cout << "请输入新的专业（原：" << node->data.major << "）：";
        cin >> node->data.major;
        cout << "请输入新的成绩（原：" << node->data.score << "）：";
        cin >> node->data.score;

        cout << "学生信息修改成功！" << endl;
        return true;
    }
    void searchStudent(int type) const {
        if (size == 0) {
            cout << "学生列表为空，无数据可查询！" << endl;
            return;
        }

        string keyword;
        if (type == 1) {
            cout << "请输入要查询的学号：";
            cin >> keyword;
            StudentNode* node = findNodeById(keyword);
            if (node != nullptr) {
                cout << "\n查询结果：" << endl;
                node->data.Showinfo();
            } else {
                cout << "未找到该学号的学生！" << endl;
            }
        } else if (type == 2) {
            cout << "请输入要查询的姓名：";
            cin >> keyword;
            StudentNode* p = head->next;
            bool found = false;
            cout << "\n查询结果：" << endl;
            while (p != nullptr) {
                if (p->data.name == keyword) {
                    p->data.Showinfo();
                    found = true;
                }
                p = p->next;
            }
            if (!found) {
                cout << "未找到该姓名的学生！" << endl;
            }
        }
    }
 void showAllStudents() const {
        if (size == 0) {
            cout << "学生列表为空，无数据可显示！" << endl;
            return;
        }

        cout << "\n所有学生信息（共" << size << "人）：" << endl;
        StudentNode* p = head->next;
        int num = 1;
        while (p != nullptr) {
            cout << "[" << num++ << "] ";
            p->data.Showinfo();
            p = p->next;
        }
    }
    void sortById() {
        if (size <= 1) {
            cout << "学生数量不足，无需排序！" << endl;
            return;
        }

        StudentNode *p, *q;
        for (int i = 0; i < size - 1; i++) {
            p = head->next;
            q = p->next;
            while (q != nullptr) {
                if (p->data.id > q->data.id) {
                    Student temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                p = q;
                q = q->next;
            }
        }
        cout << "学生信息按学号升序排序完成！" << endl;
    }
 int getStudentCount() const {
        return size;
    }

};
void showMenu() {
    cout << "  1. 新增学生信息" << endl;
    cout << "  2. 删除学生信息" << endl;
    cout << "  3. 修改学生信息" << endl;
    cout << "  4. 查询学生信息" << endl;
    cout << "  5. 显示所有学生" << endl;
    cout << "  6. 按学号排序" << endl;
    cout << "  7. 统计学生人数" << endl;
    cout << "  0. 退出系统" << endl;
    cout << "请输入您的选择：";
}
