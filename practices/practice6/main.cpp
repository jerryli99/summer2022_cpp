#include "book.h"
#include "student.h"
#include "teacher.h"
#include "stem_teacher.h"
#include "teacher_portal.h"

#include <iostream>
#include <string>

/*
                    Teacher (base)
                        |
                        | (StemTeacher public Inherits Teacher) 
                        |
    Book ---------> StemTeacher ---------> TeacherPortal <----------Student
	     (aggregation)         (aggregation)             (aggregation)


*/
int main() {
	Book* book1 = new Book("Physics1", "Dinesh J.", "0-7454-4533-2", 200, 30.45);
	Book* book2 = new Book("Physics2", "Kevin K.", "4-9822-1234-0", 240, 40.99);
	Book* book3 = new Book("Math1", "Nancy L.", "0-1212-1111-4", 100, 20.45);
	Book* book4 = new Book("Math2", "Edward Liu", "0-9698-6743-7", 300, 51.00);

	Student* student1 = new Student("John", 123456);
	Student* student2 = new Student("Alpine", 223456);
	Student* student3 = new Student("Kevin", 133456);
	Student* student4 = new Student("Emma", 125456);
	Student* student5 = new Student("Maria", 103456);
	Student* student6 = new Student("Luis", 120456);
	Student* student7 = new Student("Coul", 523456);
	Student* student8 = new Student("Tay", 723456);
	Student* student9 = new Student("Shawn", 923456);
	Student* student10 = new Student("Sean", 123006);
	Student* student11 = new Student("Queen", 123096);
	Student* student12 = new Student("Tao", 123456);
	Student* student13 = new Student("Liam", 123455);
	Student* student14 = new Student("Oliver", 788966);
	Student* student15 = new Student("Noah", 789222);
	Student* student16 = new Student("Amelia", 111111);
	Student* student17 = new Student("Charlotte", 222123);
	Student* student18 = new Student("Olivia", 454543);
	Student* student19 = new Student("Brandon", 124222);
	Student* student20 = new Student("Deneen", 879231);


	StemTeacher* stem_teacher1 = new StemTeacher("Sean", "Math, Physics, Chemistry, Biology", "PhD in Physics", 10.5);

	TeacherPortal* teacher_portal = new TeacherPortal(stem_teacher1);

	//actions
	student1->set_first_exam_score(100);
	student1->set_second_exam_score(99);
	student1->set_final_exam_score(80);

	student2->set_first_exam_score(100);
	student2->set_second_exam_score(99);
	student2->set_final_exam_score(80);

	student3->set_first_exam_score(10);
	student3->set_second_exam_score(19);
	student3->set_final_exam_score(80);

	student4->set_first_exam_score(89);
	student4->set_second_exam_score(88);
	student4->set_final_exam_score(80);

	student5->set_first_exam_score(100);
	student5->set_second_exam_score(79);
	student5->set_final_exam_score(80);

	student6->set_first_exam_score(100);
	student6->set_second_exam_score(90);
	student6->set_final_exam_score(80);

	student7->set_first_exam_score(100);
	student7->set_second_exam_score(99);
	student7->set_final_exam_score(80);

	student8->set_first_exam_score(100);
	student8->set_second_exam_score(99);
	student8->set_final_exam_score(80);

	student9->set_first_exam_score(100);
	student9->set_second_exam_score(99);
	student9->set_final_exam_score(80);

	student10->set_first_exam_score(100);
	student10->set_second_exam_score(99);
	student10->set_final_exam_score(80);

	student11->set_first_exam_score(100);
	student11->set_second_exam_score(99);
	student11->set_final_exam_score(80);

	student12->set_first_exam_score(100);
	student12->set_second_exam_score(60);
	student12->set_final_exam_score(80);

	student13->set_first_exam_score(67);
	student13->set_second_exam_score(99);
	student13->set_final_exam_score(80);

	student14->set_first_exam_score(70);
	student14->set_second_exam_score(59);
	student14->set_final_exam_score(20);


	student15->set_first_exam_score(100);
	student15->set_second_exam_score(99);
	student15->set_final_exam_score(80);

	student16->set_first_exam_score(100);
	student16->set_second_exam_score(29);
	student16->set_final_exam_score(100);

	student17->set_first_exam_score(0);
	student17->set_second_exam_score(99);
	student17->set_final_exam_score(80);

	student18->set_first_exam_score(100);
	student18->set_second_exam_score(0);
	student18->set_final_exam_score(80);

	student19->set_first_exam_score(100);
	student19->set_second_exam_score(99);
	student19->set_final_exam_score(80);

	student20->set_first_exam_score(100);
	student20->set_second_exam_score(99);
	student20->set_final_exam_score(80);


	teacher_portal->AddStudent("course1", *student1);
	teacher_portal->AddStudent("course2", *student2);
	teacher_portal->AddStudent("course3", *student3);
	teacher_portal->AddStudent("course4", *student4);
	teacher_portal->AddStudent("course5", *student5);
	teacher_portal->AddStudent("course1", *student6);
	teacher_portal->AddStudent("course2", *student7);
	teacher_portal->AddStudent("course5", *student8);
	teacher_portal->AddStudent("course6", *student9);
	teacher_portal->AddStudent("course7", *student10);
	teacher_portal->AddStudent("course8", *student11);
	teacher_portal->AddStudent("course1", *student12);
	teacher_portal->AddStudent("course2", *student13);
	teacher_portal->AddStudent("course6", *student14);
	teacher_portal->AddStudent("course8", *student15);
	teacher_portal->AddStudent("course4", *student16);
	teacher_portal->AddStudent("course1", *student17);
	teacher_portal->AddStudent("course2", *student18);
	teacher_portal->AddStudent("course3", *student19);
	teacher_portal->AddStudent("course1", *student20);

	stem_teacher1->AddBooks(*book1);
	stem_teacher1->AddBooks(*book2);
	stem_teacher1->AddBooks(*book3);
	stem_teacher1->AddBooks(*book4);
	teacher_portal->DisplayClassMap();


	return 0;
}