#include "character_ability.h"
#include "character.h"
#include "game_user.h"

#include <iostream>
#include <string>

/*
	For now, I am only using libs from std, so I wrote using namespace std.
	If I use other libs, I would probably write std::string, std::map, etc because
	the type names could get confusing across different namespaces, like:

	namespace std {
		int number = 0;
	}

	namespace jerry {
		int number = 1;
	}

	int main() {
		cout << std::number; //or cout << number;
		cout << jerry::number;
	}
*/
using namespace std;

/*
    Object relation diagram:

    CharacterAbility -------------> Character (base)
	                 (composition)        |
                                          |   (public inheritance)
                                          |
									   GameUser (derived)
    This code is just for practice. 
	The UpdateHealth() function needs modification, for example, UpdateCharacterHealth(const Character& character).
	I can make many improvements, but it will take me a longer time to do that.

	Here, I demonstrated a virtual function override example from 18.3.
	The whole point of this program is to see what problems might appear when starting to design a big program and 
	how to fully utilize virtual functions in big programs.
*/

int main() {
	try {
		CharacterAbility* ability1 = new CharacterAbility(12345, "Fire",  "Use Fire can burn down trees.");
		CharacterAbility* ability2 = new CharacterAbility(12344, "Flood", "Use Flood can washout animals.");
		CharacterAbility* ability3 = new CharacterAbility(12222, "Speak", "Use a speaker to tell people be like a bunny.");
		CharacterAbility* ability4 = new CharacterAbility(11111, "Hide", "Become invisible for 4 seconds.");
		CharacterAbility* ability5 = new CharacterAbility(10101, "Kong Fu", "Have the ability to fight ninja fox on a 12 ft tall tree.");

		Character character1{ Character::CharacterRole::kAnnihilator };

		//create a Bunny Annihilator character
		GameUser* user1 = new GameUser("jerry", Character::CharacterRole::kBunny, 200000);

		character1.AddAbility(*ability1, 5, 90);
		character1.AddAbility(*ability2, 10, 60);
		character1.AddAbility(*ability3, 20, 10);

		character1.UpdateHealth();

		character1.ViewAbilityData();

		character1.UpdateAbilityDamage(*ability2);

		character1.ViewAbilityData();

		for (int i = 0; i < 100; i++) {
			cout << "-";
		}

		cout << "\n";
		cout << "User name: " << user1->get_user_name() << "\n"
			 << "User role: " << user1->get_user_role() << "\n"
			 << "User gold: " << user1->get_user_gold() << "\n\n";

		user1->AddAbility(*ability1, 5, 90);
		user1->AddAbility(*ability5, 10, 40);
		user1->AddAbility(*ability4, 15, 30);
		user1->AddAbility(*ability2, 20, 22);

		user1->ViewAbilityData();

		cout << "==> Update ability data\n\n";

		user1->UpdateAbilityLevel(*ability1);
		user1->UpdateAbilityDamage(*ability5);
		user1->UpdateAbilityLevel(*ability4);
		user1->UpdateAbilityDamage(*ability2);

		cout << "User gold: " << user1->get_user_gold() << "\n\n";
		user1->ViewAbilityData();

	} catch (const char* message) {
		cout << message << "\n";
	}

	/*
	  Thoughts:

	  Last time (Cpater 18.2), I memtioned that one reason to use base pointer to 
	  point a derived object is to hide the base object's variability.

	  For example, we can create a Window (base). In the Window, there are side bars, 
	  scroll bars, images, layouts, buttons, etc that all inherit from Window. 
	  Creating Window's component individually is fine, but we need to way to show these componenets are in the Window.
	  That's why using a base pointer or reference to derived objects can act like a relationship tree to show that these
	  derived objects have a relationship with this base object.


	  However, I think there is a little more behind this idea.

	  When a base object is pointing to multiple of its derived objects, we want to
	  use the member functions in the derived objects. To achieve this, a good solution is to use 
	  the virtual keyword on the member functions in the base and derived classes to ensure function override. 
	  
	  By observation, base pointer-> derived looks like:
	  
	  1. let common_funcs = Intersection{base, derived} functions 
	      => meaning: get functions in base and derived that match exactly.

	  2. Apply the common_funcs's function definitions in the derived class.

	  The word to describe this idea is orientation. We shifted our attention (which is looking for function definitions) 
	  from base to derived.

	  OK, now we know objects can have orientation. 

	  But, another question comes up: How to keep track of virtual function definitions during program runtime? 
	  There must be a data structure to give direction to which function definition to use, something like a yellow book.

	  Since there is the virtual keyword, maybe there is a virtual book or virtual table.
	  We should also have a virtual table pointer that can point to the addresses of the functions in the virtual table.
	  ---------------------------------------------------------------------------------------------------------------------
	  When I write functions in a class, I can have something like this:
	  
	  void function1(short num);
	  void function1(int num);
	  void function1(double num) const;
	  ...

	  Functions can be overloaded.

	  But here is a problem. For virtual functions to work, the base and derived class functions that have the same function name
	  should have the exact parameters and return types as they will be recorded in the virtual table. 

	  For example:

		class Base {
		 public:
			virtual void function1(short num) {
				cout << "this is function1 from base\n";
			}
		};

		class Derive : public Base {
		 public:
			virtual void function1(int num) {
				cout << "this is function1 from derive\n";
			}

			virtual void function1(double num) {
				cout << "this is function1 from derive\n";
			}
		};

		int main() {
			Derive derive{};
			Base* base{ &derive };

			base->function1(2);

			the result is "this is function1 from base"
		}
		
	  
	  This will use the function1(short num) in base because the parameter of function1 
	  in the Base class is different in the Derive class.

	  How about virtual function override?

	  I found that there is the override keyword in C++.
	  So, to rewrite:

		class Derive : public Base {
		 public:
			void function1(int num) override {
				cout << "this is function1 from derive\n";
			}

			void function1(double num) override {
				cout << "this is function1 from derive\n";
			}
		};

	  By observation, the compiler says "member function declared with 'override' 
	  does not override a base class member"

	  So, in the derived class, I still need to write the exact function with same 
	  parameters and return types. 
	  
	  void function1(short num) override {
		 //have something different than in base class
	  }
	  
	  The difference is I can redefine the virtual function 
	  from the base class.

	  But what if I really want to have overloaded virtual functions?
	  To solve this, I can just have this:

	  class Base {
		public:
			virtual void function1(short num) {
				cout << "this is function1 from base\n";
			}

			virtual void function1(int random_num, short num) {
				cout << "this is function1 from base, overloaded function1\n";
			}
		};

		class Derive : public Base {
		 public:
			void function1(short num) override{
				cout << "this is function1 from derive, version1\n";
			}

			void function1(int random_num, short num) override{
				cout << "this is function1 from derive, version2\n";
			}
		};

		int main() {
			Derive derive{};
			Base* base{ &derive };

			base->function1(2);
			base->function1(234, 2);
		}

	  The result as expected is "this is function1 from derive, version1"
	                            "this is function1 from derive, version2"
      ----------------------------------------------------------------------------------------------------------------
	  Maybe there is not just one virtual table but multiple 
	  (because that will be a super big virtual table if used only one virtual table for the classes)? 
	  
	  I will find the answer in later chapters.

	  For now, I know that overloading and overriding can represent different behaviors 
	  of the same objects and different objects. They can help us to shift our attention from 
	  one function definition to another function definition across different classes. 
	  We have the program ability to choose which definition to use.

	*/
	return 0;
}
