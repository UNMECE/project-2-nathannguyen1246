#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Student {
	private:
		string name;
		int gpa;
		int gradYear;
		string gradSemester;
		int enrollmentYear;
		string enrollmentSemester;
		string graduationStatus;
	public:
		//Constructor
		Student () :
			name(""), gpa(0), gradYear(0), gradSemester(""), enrollmentYear(0), enrollmentSemester(""), graduationStatus("")
		{}

		virtual ~Student() {
		}

		//Setters
		void setName(string n) {
			name = n;
		}

		void setGpa(int g) {
			gpa = g;
		}

		void setGradYear(int gy) {
			gradYear = gy;
		}

		void setGradSemester(string gs) {
			gradSemester = gs;
		}

		void setEnrollmentYear(int ey) {
			enrollmentYear = ey;
		}

		void setGraduationStatus(string es) {
			enrollmentSemester = es;
		}

		//Getters
		void getName(string &n) {
			n = name;
		}

		void getGpa(int &g) {
			g = gpa;
		}

		void getGradYear(int &gy) {
			gy = gradYear;
		}

		void getGradSemester(string &gs) {
			gs = gradSemester;
		}

		void getEnrollmentYear(int &ey) {
			ey = enrollmentYear;
		}

		void getGraduationStatus(string &es) {
			es = graduationStatus;
		}

		//Print Info
		virtual void printInfo(ofstream &out) const{
			out << "Name: " << name << endl;
			out << "GPA: " << gpa << endl;
			out << "Graduation Year: " << gradYear << endl;
			out << "Graduation Semester: " << gradSemester << endl;
			out << "Enrollment Year: " << enrollmentYear << endl;
			out << "Graduation Status: " << graduationStatus << endl;
		}
};

class ArtStudent : public Student {
	private:
		string artEmphasis;
	public:
		//Constructor
		ArtStudent() :
			artEmphasis("") 
		{}

		virtual ~ArtStudent() {
		}

		//Setters
		void setArtEmphasis(string ae) {
			artEmphasis = ae;
		}

		//Getters
		void getArtEmphasis(string &ae) {
			ae = artEmphasis;
		}

		//Print Info
		void printInfo(ofstream &out) const override{
			Student::printInfo(out);
			cout << "Art Emphasis: " << artEmphasis << endl;
		}
};

class PhysicsStudent : public Student {
	private:
		string concentration;
	public:
		//Constructor
		PhysicsStudent() :
			concentration("")
		{}

		virtual ~PhysicsStudent() {
		}

		//Setters
		void setConcentration(string c) {
			concentration = c;
		}

		//Getters
		void getConcentration(string &c) {
			c = concentration;
		}

		//Print Info
		void printInfo(ofstream &out) const override{
			Student::printInfo(out);
			cout << "Concentration: " << concentration << endl;
		}

};

int main() {
	// Create sample students
	vector<ArtStudent> artStudents;
	vector<PhysicsStudent> physicsStudents;

	vector<string> artNames = { "Ava", "Liam", "Sophia", "Noah", "Mia", "Lucas", "Ella", "Ethan" };
	vector<string> physicsNames = { "Oliver", "Emma", "James", "Isabella", "Benjamin", "Harper", "Henry", "Charlotte" };

	// Sample data for Art Students
	for (int i = 0; i < 5; i++) {
		ArtStudent artStudent;
		artStudent.setName(artNames[rand() % artNames.size()]);
		artStudent.setGpa(3 + i % 2);
		artStudent.setGradYear(2022 + i);
		artStudent.setGradSemester(i % 2 == 0 ? "Fall" : "Spring");
		artStudent.setEnrollmentYear(2018 + i);
		artStudent.setGraduationStatus(i % 2 == 0 ? "Undergrad" : "Graduate");
		artStudent.setArtEmphasis(i % 2 == 0 ? "Art Studio" : "Art History");
		artStudents.push_back(artStudent);
	}

	// Sample data for Physics Students
	for (int i = 0; i < 5; i++) {
		PhysicsStudent physicsStudent;
		physicsStudent.setName(physicsNames[rand() % physicsNames.size()]);
		physicsStudent.setGpa(3 + i % 2);
		physicsStudent.setGradYear(2022 + i);
		physicsStudent.setGradSemester(i % 2 == 0 ? "Fall" : "Spring");
		physicsStudent.setEnrollmentYear(2018 + i);
		physicsStudent.setGraduationStatus(i % 2 == 0 ? "Undergrad" : "Graduate");
		physicsStudent.setConcentration(i % 2 == 0 ? "Biophysics" : "Earth and Planetary Science");
		physicsStudents.push_back(physicsStudent);
	}


	// Write art students to file
	ofstream outFile("students.txt");
	for(auto & artStudent : artStudents) {
		artStudent.printInfo(outFile);
		outFile << "------------------------" << endl;
	}

	//	 Write physics students to file
	for(auto & physicsStudent : physicsStudents) {
		physicsStudent.printInfo(outFile);
		outFile << "------------------------" << endl;
	}

	outFile.close();

	// Clean up dynamically allocated memory
	for(auto & artStudent : artStudents) {
		delete& artStudent;
	}

	for(auto & physicsStudent : physicsStudents) {
		delete& physicsStudent;
	}
	return 0;
}