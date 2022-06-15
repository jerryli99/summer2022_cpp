#include <iostream>
#include <string>

//Base class StoreEmployee

class StoreEmployee {
 public:
	 StoreEmployee(int id = 0) : m_id{ id } {}
	 ~StoreEmployee() {}

	 int get_employee_id() const {
		 return m_id;
	 }
 private:
	 int m_id{};
};

class StoreManager : public StoreEmployee {
 public:
	 StoreManager(double salary = 0.0 , int employee_id = 0) 
		 : m_salary{salary}, StoreEmployee{employee_id} {}
	 ~StoreManager() {}

	 double get_manager_salary() const {
		 return m_salary;
	 }

 private:
	double m_salary;
};

class StoreAssociate : public StoreEmployee {
 public:
	 StoreAssociate(double salary = 0.0, int employee_id = 0)
		 : m_salary{ salary }, StoreEmployee{ employee_id } {}
	~StoreAssociate() {}

	double get_associate_salary() const {
		return m_salary;
	}

 private:
	 double m_salary{};
};


int main() {
	StoreAssociate Kevin{ 35.023, 123456 };
	std::cout << Kevin.get_employee_id() << "\n";
	std::cout << Kevin.get_associate_salary() << "\n";
}