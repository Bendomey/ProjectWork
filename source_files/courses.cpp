#include <iostream>
#include <string>
#include "../libraries/courses.h"

namespace course{

	courses::courses(){
		// no parameters
	}
	// construtor with arguments
	courses::courses(std::string code, std::string title, std::string lecturerName, int level, int score, int sem){
		this->setCourseCode(code);
		this->setCourseTitle(title);
		this->setCourseLecturer(lecturerName);
		this->setLevel(level);
		this->setCourseScore(score);
		this->setSemester(sem);
	}

	// destructor
	courses::~courses(){
		// std::cout << "\nObject Destroyed";
	}

	// set values
	void courses::setCourseCode(std::string code) {
		this->CourseCode = code;
	}

	void courses::setCourseTitle(std::string title) {
		this->CourseTitle = title;
	}

	void courses::setCourseLecturer(std::string lecturerName) {
		this->CourseLecturer = lecturerName;
	}


	void courses::setLevel (int level) {
		this->Level = level;
	}

	void courses::setCourseScore(int score){
		this->CourseScore = score;
	}

	void courses::setCourseGrade(std::string grade) {
		this->CourseGrade = grade;
	}

	void courses::setSemester(int sem) {
		this->Semester = sem;
	}

	// get values

	std::string courses::getCourseCode() {
		return this->CourseCode;
	}

	std::string courses::getCourseTitle() {
		return this->CourseTitle;
	}

	std::string courses::getCourseLecturer() {
		return this->CourseLecturer;
	}

	string courses::getLevel() {
		return this->Level;
	}

	int courses::getSemester() {
		return this->Semester;
	}

	int courses::getCourseScore(){
		return this->CourseScore;
	}

	std::string courses::getCourseGrade() {
		
		if (this->getCourseScore() >= 80 && this->getCourseScore() <= 100)
		{
			this->setCourseGrade("A");
		}else
		if (this->getCourseScore() >= 75 && this->getCourseScore() < 80)
		{
			this->setCourseGrade("B+");
		}else 
		if (this->getCourseScore() >= 70 && this->getCourseScore() < 75)
		{
			this->setCourseGrade("B");
		}else 
		if (this->getCourseScore() >= 65 && this->getCourseScore() < 70)
		{
			this->setCourseGrade("C+");
		}else 
		if (this->getCourseScore() >= 60 && this->getCourseScore() < 65)
		{
			this->setCourseGrade("C");
		}else 
		if (this->getCourseScore() >= 55 && this->getCourseScore() < 60)
		{
			this->setCourseGrade("D+");
		}else 
		if (this->getCourseScore() >= 50 && this->getCourseScore() < 55)
		{
			this->setCourseGrade("D");
		}else 
		if (this->getCourseScore() >= 45 && this->getCourseScore() < 50)
		{
			this->setCourseGrade("E");
		}else
		if (this->getCourseScore() >= 0 && this->getCourseScore() < 45)
		{
			this->setCourseGrade("F");
		}

		return this->CourseGrade;

	}

}//course
