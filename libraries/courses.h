/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */


#ifndef COURSES_H
#define COURSES_H

/**
 * this class is for creating courses for a semester and managing it
 */

#include <iostream>
#include <string>
using namespace std;


namespace course {
    class courses {
        public:
		courses();
		courses(string,string,string,int,int,int);
		~courses();
		void setCourseCode(string);
		void setCourseTitle(string);
		void setCourseLecturer(string);
		void setLevel(int);
		void setSemester(int);
		void setCourseScore(int);
		void setCourseGrade(string);
		// get the private values
		string getCourseCode();
		string getCourseTitle();
		string getCourseLecturer();
		string getCourseLocation();
		string getLevel();
		int getSemester();
		int getCourseScore();
		string getCourseGrade();

	private:
		string CourseCode;
		string CourseTitle;
		string CourseLecturer;
		string Level;
		int CourseScore;
		string CourseGrade;
		int Semester;

    };// courses class
    
} // course namespace


#endif //COURSES_H