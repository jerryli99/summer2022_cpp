#pragma once

#include "stem_teacher.h"
#include "student.h"

#include <map>
/*

Map: (A stem teacher can teach 8 courses max)

"course1" -> Student* student1, Student* student2, ...
"course2" -> Student* student1, Student* student2, ...
"course3" -> Student* student1, Student* student2, ...
"course4" -> Student* student1, Student* student2, ...
   .           .                 .
   .           .                 .
   .           .                 .
"course8" -> Student* student1, Student* student2, ...

*/
class TeacherPortal {
public:
	TeacherPortal(StemTeacher* stem_teacher);
	~TeacherPortal();

	//assume all inputs are valid; that is, only 8 courses in the map.
	void AddStudent(string course_name, Student& student);
	void DisplayClassMap();

private:
	StemTeacher* m_stem_teacher;
	map<string, vector<Student>> m_class_map;
};