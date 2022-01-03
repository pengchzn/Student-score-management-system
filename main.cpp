#include <bits/stdc++.h>

using namespace std;

class Subjects{
protected:
    float phys;
    float c_program;
    float english;
    float math;
    float internet;
    float sport;
    float polity;
    float average;
};

class Students{
protected:
    int num;
    char name[8];
    int class_0;
    int order;
};

class Student: protected Subjects,Students{
public:
    friend void Input(Student stu[]);

    friend void Statistic(Student stu[]);

    friend void Lookup(Student stu[]);

    friend void Modify(Student stu[]);

    friend void Delete(Student stu[]);

    friend void Output(Student stu[]);

    friend void Insert(Student stu[]);

    friend void Sort(Student stu[]);

    friend void SoSortbyNum(Student stu[]);

    friend void SortbyScore(Student stu[]);

    friend void SortbyName(Student stu[]);

    friend void Write(Student stu[], int n);

    friend int Read(Student stu[]);

    friend void LookupClass(Student stu[]);
} stu[100];

void Write(Student stu[], int n) {
    fstream myFile;
    myFile.open("score.txt", ios::out | ios::binary);
    if (!myFile) {
        cout << "score.txt can't open!" << endl;
        abort();
    }
    int count = n;
    myFile << count << endl << endl;
    for (int i = 0; i < count; i++) {
        myFile << stu[i].class_0 << "\t"
               << stu[i].num << "\t"
               << stu[i].name << "\t"
               << stu[i].phys << "\t"
               << stu[i].c_program << "\t"
               << stu[i].internet << "\t"
               << stu[i].english << "\t"
               << stu[i].math << "\t"
               << stu[i].sport << "\t"
               << stu[i].polity << "\t"
               << stu[i].average << endl;
    }
    myFile.close();
}

int Read(Student stu[]) {
    fstream myFile;
    myFile.open("score.txt", ios::in | ios::binary);
    if (!myFile) {
        cout << "score.txt can't open!" << endl;
        abort();
    }
    int count;
    myFile.seekg(0);
    myFile >> count;
    for (int i = 0; i <= count; i++) {
        myFile >> stu[i].class_0 >> stu[i].num >> stu[i].name
               >> stu[i].phys >> stu[i].c_program >> stu[i].internet
               >> stu[i].english >> stu[i].math >> stu[i].sport
               >> stu[i].polity >> stu[i].average;
    }
    myFile.close();
    return count;
}

void Input(Student stu[]) {
    int i = 0;
    int flag;
    char sign = '0';
    cout << endl << "======>>    请输入学生成绩    <<======" << endl;
    while (sign != 'n' && sign != 'N') {
        cout << "班级：";
        cin >> stu[i].class_0;
        loop:
        cout << "学号：";
        cin >> stu[i].num;
        int c = 0;
        while (c < i) {
            c++;
            if (stu[i].num == stu[i - c].num) {
                cout << "您输入的学号已存在！请重新输入。" << endl;
                goto loop;
            }
        }
        cout << "姓名：";
        cin >> stu[i].name;
        do {
            flag = 0;
            cout << "大学物理成绩：";
            cin >> stu[i].phys;
            if (stu[i].phys > 100 || stu[i].phys < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        do {
            flag = 0;
            cout << "C++程序设计成绩：";
            cin >> stu[i].c_program;
            if (stu[i].c_program > 100 || stu[i].c_program < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        do {
            flag = 0;
            cout << "计算机网络成绩：";
            cin >> stu[i].internet;
            if (stu[i].internet > 100 || stu[i].internet < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        do {
            flag = 0;
            cout << "大学英语成绩：";
            cin >> stu[i].english;
            if (stu[i].english > 100 || stu[i].english < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        do {
            flag = 0;
            cout << "高等数学成绩：";
            cin >> stu[i].math;
            if (stu[i].math > 100 || stu[i].math < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        do {
            flag = 0;
            cout << "大学体育成绩：";
            cin >> stu[i].sport;
            if (stu[i].sport > 100 || stu[i].sport < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        do {
            flag = 0;
            cout << "马克思主义基本原理成绩：";
            cin >> stu[i].polity;
            if (stu[i].polity > 100 || stu[i].polity < 1) {
                cout << " 对不起，请输入1-100之间的数字！！\n";
            } else {
                flag = 1;
            }
        } while (flag == 0);
        stu[i].average = (stu[i].phys + stu[i].c_program + stu[i].internet + stu[i].english + stu[i].math +
                          stu[i].sport + stu[i].polity) / 7;
        cout << " 平均分为：" << stu[i].average << endl;
        cout << "======>>    提示：是否继续写入学生成绩 ?(y/n)";
        cin >> sign;
        i++;
    }
    Write(stu, i);
}

void Statistic(Student stu[]) {
    int n = Read(stu);
    cout << endl << "======>>    输出学生统计数据    <<======\n" << endl;
    cout << "---------------------------------------" << endl;
    cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t" << "平均分" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < n; i++)
        cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].average << endl;
    cout << "---------------------------------------" << endl;

}

void Lookup(Student stu[]) {
    int n = Read(stu);
    int s;
    int i = 0;
    cout << endl << "======>>    查找学生成绩    <<======" << endl;
    cout << "请输入要查找学生的学号：";
    cin >> s;
    while ((stu[i].class_0 - s) != 0 && i < n)i++;
    if (i == n) {
        cout << "======>>    对不起，无法找到该学生......    <<======" << endl;
    } else {
        cout << "----------------------------" << endl;
        cout << "班级：" << stu[i].class_0 << endl;
        cout << "学号：" << stu[i].num << endl;
        cout << "姓名：" << stu[i].name << endl;
        cout << "大学物理：" << stu[i].phys << endl;
        cout << "C++程序设计：" << stu[i].c_program << endl;
        cout << "计算机网络：" << stu[i].internet << endl;
        cout << "大学英语：" << stu[i].english << endl;
        cout << "高等数学：" << stu[i].math << endl;
        cout << "大学体育：" << stu[i].sport << endl;
        cout << "马克思主义基本原理：" << stu[i].polity << endl;
        cout << "平均分：" << stu[i].average << endl;
    }
}

void LookupClass(Student stu[]) {
    int n = Read(stu);
    int c;
    int i = 0;
    cout << endl << "======>>    查找班级    <<======" << endl;
    cout << "请输入要查找的班级：";
    cin >> c;
    for(i=0;i<=n;i++){
        if((stu[i].class_0) - c == 0) {
            cout << "----------------------------" << endl;
            cout << "班级：" << stu[i].class_0 << endl;
            cout << "学号：" << stu[i].num << endl;
            cout << "姓名：" << stu[i].name << endl;
            cout << "大学物理：" << stu[i].phys << endl;
            cout << "C++程序设计：" << stu[i].c_program << endl;
            cout << "计算机网络：" << stu[i].internet << endl;
            cout << "大学英语：" << stu[i].english << endl;
            cout << "高等数学：" << stu[i].math << endl;
            cout << "大学体育：" << stu[i].sport << endl;
            cout << "马克思主义基本原理：" << stu[i].polity << endl;
            cout << "平均分：" << stu[i].average << endl;
        } else
        {
            continue;
        }
    }
}

void Modify(Student stu[]) {
    int n = Read(stu);
    int s;
    int i = 0;
    cout << endl << "======>>    修改学生成绩    <<======" << endl;
    cout << "请输入要修改成绩学生的学号：";
    cin >> s;
    while ((stu[i].num - s) != 0 && i < n)i++;
    if (i == n) {
        cout << "======>>     对不起，无法找到该学生     <<======" << endl;
    } else {
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t"
             << "电子" << "\t" << "C++" << "\t" << "计算机网络" << "\t"
             << "英语" << "\t" << "数学" << "\t" << "体育" << "\t"
             << "政治" << "\t" << "平均分" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t"
             << stu[i].phys << "\t" << stu[i].c_program << "\t" << stu[i].internet << "\t"
             << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
             << stu[i].polity << "\t" << stu[i].average << endl;
        cout << endl << "请重新输入该学生成绩： " << endl;
        cout << "大学物理成绩：";
        cin >> stu[i].phys;
        cout << "C++成绩：";
        cin >> stu[i].c_program;
        cout << "计算机网络成绩：";
        cin >> stu[i].internet;
        cout << "大学英语成绩：";
        cin >> stu[i].english;
        cout << "高等数学成绩：";
        cin >> stu[i].math;
        cout << "大学体育成绩：";
        cin >> stu[i].sport;
        cout << "马克思主义基本原理成绩：";
        cin >> stu[i].polity;
        stu[i].average = (stu[i].phys + stu[i].c_program + stu[i].internet +
                          stu[i].english + stu[i].math + stu[i].sport + stu[i].polity) / 7;
        cout << "平均分：" << stu[i].average << endl;

        char c;
        cout << "======>>    是否保存数据 ？(y/n)";
        cin >> c;
        if (c != 'n' && c != 'N')
            Write(stu, n);
    }
}

void Delete(Student stu[]) {
    int n = Read(stu);
    int s;
    int i = 0, j;
    cout << endl << "======>>    删除学生成绩    <<======" << endl;
    cout << "请输入要删除的学生的学号：";
    cin >> s;
    while ((stu[i].num - s) != 0 && i < n)i++;
    if (i == n) {
        cout << "======>>    对不起，无法找到该学生......    <<======" << endl;
    } else {
        for (j = i; j < n - 1; j++) {
            stu[j].class_0 = stu[j + 1].class_0;
            stu[j].num = stu[j + 1].num;
            strcpy(stu[j].name, stu[j + 1].name);
            stu[j].phys = stu[j + 1].phys;
            stu[j].c_program = stu[j + 1].c_program;
            stu[j].internet = stu[j + 1].internet;
            stu[j].english = stu[j + 1].english;
            stu[j].math = stu[j + 1].math;
            stu[j].sport = stu[j + 1].sport;
            stu[j].polity = stu[j + 1].polity;
            stu[j].average = stu[j + 1].average;
        }
        cout << "======>>    提示：已成功删除！" << endl;
    }
    Write(stu, n - 1);
}

void Insert(Student stu[]) {
    int n = Read(stu);
    char s = '0';
    cout << endl << "=======>>    增加学生成绩    <<========" << endl;
    while (s != 'n' && s != 'N') {
        cout << "班级：";
        cin >> stu[n].class_0;
        cout << "学号：";
        cin >> stu[n].num;
        cout << "姓名：";
        cin >> stu[n].name;
        cout << "大学物理成绩：";
        cin >> stu[n].phys;
        cout << "C++成绩：";
        cin >> stu[n].c_program;
        cout << "计算机网络成绩：";
        cin >> stu[n].internet;
        cout << "大学英语成绩：";
        cin >> stu[n].english;
        cout << "高等数学成绩：";
        cin >> stu[n].math;
        cout << "大学体育成绩：";
        cin >> stu[n].sport;
        cout << "马克思主义基本原理成绩：";
        cin >> stu[n].polity;
        stu[n].average = (stu[n].phys + stu[n].c_program + stu[n].internet +
                          stu[n].english + stu[n].math + stu[n].sport + stu[n].polity) / 7;
        cout << "平均分：" << stu[n].average << endl;
        n++;
        cout << "======>>    是否继续插入(y/n)";
        cin >> s;
    }
    Write(stu, n);
}

int sort() {
    char c;
    do {
        cout << "******************************************************" << endl;
        cout << "    *          【1】按平均分排序                  *    " << endl;
        cout << "    *          【2】按学号排序                    *    " << endl;
        cout << "    *          【3】按姓名排序                    *    " << endl;
        cout << "******************************************************" << endl;
        cout << "请选择操作 (1-3):" << endl;
        c = getchar();
    } while (c < '1' || c > '3');
    return (c - '0');
}

void Sort(Student stu[]){
    switch (sort()) {
        case 1:
            SortbyScore(stu);
            break;
        case 2:
            SoSortbyNum(stu);
            break;
        case 3:
//            SortbyName(stu);
            break;
    }
}

void SortbyScore(Student stu[]) {
    int i, j, k,p;
    char t[20];
    float s;
    cout << endl << "======>>    降序排列    <<======" << endl;
    int n = Read(stu);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (stu[j].average < stu[j + 1].average) {
                //交换课程
                p = stu[j + 1].class_0;
                stu[j + 1].class_0 = stu[j].class_0;
                stu[j].class_0 = p;
                //num
                k = stu[j + 1].num;
                stu[j + 1].num = stu[j].num;
                stu[j].num = k;
                //name
                strcpy(t, stu[j + 1].name);
                strcpy(stu[j + 1].name, stu[j].name);
                strcpy(stu[j].name, t);
                //phys
                s = stu[j + 1].phys;
                stu[j + 1].phys = stu[j].phys;
                stu[j].phys = s;
                //c_program
                s = stu[j + 1].c_program;
                stu[j + 1].c_program = stu[j].c_program;
                stu[j].c_program = s;
                //internet
                s = stu[j + 1].internet;
                stu[j + 1].internet = stu[j].internet;
                stu[j].internet = s;
                //english
                s = stu[j + 1].english;
                stu[j + 1].english = stu[j].english;
                stu[j].english = s;
                //math
                s = stu[j + 1].math;
                stu[j + 1].math = stu[j].math;
                stu[j].math = s;
                //sport
                s = stu[j + 1].sport;
                stu[j + 1].sport = stu[j].sport;
                stu[j].sport = s;
                //polity
                s = stu[j + 1].polity;
                stu[j + 1].polity = stu[j].polity;
                stu[j].polity = s;
                //average
                s = stu[j + 1].average;
                stu[j + 1].average = stu[j].average;
                stu[j].average = s;
            }
        }
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t"
         << "电子" << "\t" << "C++" << "\t" << "计算机网络" << "\t"
         << "英语" << "\t" << "数学" << "\t" << "体育" << "\t"
         << "政治" << "\t" << "平均分" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        stu[i].order = i + 1;
        cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t"
             << stu[i].phys << "\t" << stu[i].c_program << "\t" << stu[i].internet << "\t"
             << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
             << stu[i].polity << "\t" << stu[i].average << endl;
    }
}

void SoSortbyNum(Student stu[]) {
    int i, j, k,p;
    char t[20];
    float s;
    cout << endl << "======>>    降序排列    <<======" << endl;
    int n = Read(stu);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (stu[j].num < stu[j + 1].num) {
                //交换课程
                p = stu[j + 1].class_0;
                stu[j + 1].class_0 = stu[j].class_0;
                stu[j].class_0 = p;
                //num
                k = stu[j + 1].num;
                stu[j + 1].num = stu[j].num;
                stu[j].num = k;
                //name
                strcpy(t, stu[j + 1].name);
                strcpy(stu[j + 1].name, stu[j].name);
                strcpy(stu[j].name, t);
                //phys
                s = stu[j + 1].phys;
                stu[j + 1].phys = stu[j].phys;
                stu[j].phys = s;
                //c_program
                s = stu[j + 1].c_program;
                stu[j + 1].c_program = stu[j].c_program;
                stu[j].c_program = s;
                //internet
                s = stu[j + 1].internet;
                stu[j + 1].internet = stu[j].internet;
                stu[j].internet = s;
                //english
                s = stu[j + 1].english;
                stu[j + 1].english = stu[j].english;
                stu[j].english = s;
                //math
                s = stu[j + 1].math;
                stu[j + 1].math = stu[j].math;
                stu[j].math = s;
                //sport
                s = stu[j + 1].sport;
                stu[j + 1].sport = stu[j].sport;
                stu[j].sport = s;
                //polity
                s = stu[j + 1].polity;
                stu[j + 1].polity = stu[j].polity;
                stu[j].polity = s;
                //average
                s = stu[j + 1].average;
                stu[j + 1].average = stu[j].average;
                stu[j].average = s;
            }
        }
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t"
         << "电子" << "\t" << "C++" << "\t" << "计算机网络" << "\t"
         << "英语" << "\t" << "数学" << "\t" << "体育" << "\t"
         << "政治" << "\t" << "平均分" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        stu[i].order = i + 1;
        cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t"
             << stu[i].phys << "\t" << stu[i].c_program << "\t" << stu[i].internet << "\t"
             << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
             << stu[i].polity << "\t" << stu[i].average << endl;
    }
}

void SortbyName(Student stu[]) {
    int i, j, k,p;
    char t[20];
    float s;
    cout << endl << "======>>    降序排列    <<======" << endl;
    int n = Read(stu);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (stu[j].num < stu[j + 1].num) {
                //交换课程
                p = stu[j + 1].class_0;
                stu[j + 1].class_0 = stu[j].class_0;
                stu[j].class_0 = p;
                //num
                k = stu[j + 1].num;
                stu[j + 1].num = stu[j].num;
                stu[j].num = k;
                //name
                strcpy(t, stu[j + 1].name);
                strcpy(stu[j + 1].name, stu[j].name);
                strcpy(stu[j].name, t);
                //phys
                s = stu[j + 1].phys;
                stu[j + 1].phys = stu[j].phys;
                stu[j].phys = s;
                //c_program
                s = stu[j + 1].c_program;
                stu[j + 1].c_program = stu[j].c_program;
                stu[j].c_program = s;
                //internet
                s = stu[j + 1].internet;
                stu[j + 1].internet = stu[j].internet;
                stu[j].internet = s;
                //english
                s = stu[j + 1].english;
                stu[j + 1].english = stu[j].english;
                stu[j].english = s;
                //math
                s = stu[j + 1].math;
                stu[j + 1].math = stu[j].math;
                stu[j].math = s;
                //sport
                s = stu[j + 1].sport;
                stu[j + 1].sport = stu[j].sport;
                stu[j].sport = s;
                //polity
                s = stu[j + 1].polity;
                stu[j + 1].polity = stu[j].polity;
                stu[j].polity = s;
                //average
                s = stu[j + 1].average;
                stu[j + 1].average = stu[j].average;
                stu[j].average = s;
            }
        }
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t"
         << "电子" << "\t" << "C++" << "\t" << "计算机网络" << "\t"
         << "英语" << "\t" << "数学" << "\t" << "体育" << "\t"
         << "政治" << "\t" << "平均分" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        stu[i].order = i + 1;
        cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t"
             << stu[i].phys << "\t" << stu[i].c_program << "\t" << stu[i].internet << "\t"
             << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
             << stu[i].polity << "\t" << stu[i].average << endl;
    }
}

void Output(Student stu[]) {
    int n = Read(stu);
    cout << endl << "======>>    显示全部学生成绩    <<======" << endl;
    if (!stu) {
        cout << "没有记录";
    } else {
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t"
             << "电子" << "\t" << "C++" << "\t" << "计算机网络" << "\t"
             << "英语" << "\t" << "数学" << "\t" << "体育" << "\t"
             << "政治" << "\t" << "平均分" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t"
                 << stu[i].phys << "\t" << stu[i].c_program << "\t" << stu[i].internet << "\t"
                 << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
                 << stu[i].polity << "\t" << stu[i].average << endl;
        }
        cout << "------------------------------------------------------------------------------------" << endl;
    }
}

int menu() {
    char c;
    do {
        cout << "******************************************************" << endl;
        cout << "----------------欢迎使用学生成绩管理系统---------------" << endl;
        cout << "    *          【1】输入学生成绩                  *    " << endl;
        cout << "    *          【2】显示统计数据                  *    " << endl;
        cout << "    *          【3】显示学生成绩                  *    " << endl;
        cout << "    *          【4】增添学生成绩                  *    " << endl;
        cout << "    *          【5】删除学生成绩                  *    " << endl;
        cout << "    *          【6】查找学生成绩                  *    " << endl;
        cout << "    *          【7】修改学生成绩                  *    " << endl;
        cout << "    *          【8】对数据排序                    *    " << endl;
        cout << "    *          【9】按班级分类                    *    " << endl;
        cout << "    *          【0】退出管理系统                  *    " << endl;
        cout << "******************************************************" << endl;
        cout << "请选择操作 (0-9):" << endl;
        c = getchar();
    } while (c < '0' || c > '9');
    return (c - '0');
}

int main() {
    for (;;) {
        switch (menu()) {
            case 1:
                Input(stu);
                break;
            case 2:
                Statistic(stu);
                break;
            case 3:
                Output(stu);
                break;
                    case 4:
                        Insert(stu);
                break;
            case 5:
                Delete(stu);
                break;
            case 6:
                Lookup(stu);
                break;
            case 7:
                Modify(stu);
                break;
            case 8:
                Sort(stu);
                break;
            case 9:
                LookupClass(stu);
                break;
            case 0:
                cout << endl << "================退出学生成绩管理系统==============\n" << endl;
                exit(0);
        }
    }
    return 0;
}