#include "I_linkedlist.h"
#include "single_linked_list.h"
#include "node.h"
#include "uni_dir_node.h"

#include <iostream>
#include <string>

using namespace j_model;

/*
	When I have "g++ prac1.cpp -S", I can see assembly code produced from GCC.

	Now, virtual function questions: can I see virtual function addresses in the assembly code? or somewhere else? 
	or how does it work in the assembly code?
   
	I know for functions, if you are writing functions in assembly code, you can: 
	allocate memory on the stack to create a stack frame, and then have the variables, 
	math operations, and return address of the last stack frame address in the current stack frame. 
	-----------------------------------------------------------------------------------------------------------
	The purpose of looking at the assembly code is not to understand it;
	I just want to observe what is in there after I compile the program.
	Assembly labels:
	_ZN4Base2f1Ev => f1() from Base

	_ZN4Base2f2Ev => f2() from Base

	_ZN7Derive12f1Ev => f1() from Derive1

	_Zn7Derive22f2Ev => f2() from Derive2

	I noticed that as I match my prac1.cpp with prac1.s, I found these label names above.
	It makes sense because there are no overrides of f2() in Derive1 and f1() in Derive2;
	so when I try to match the label "main:" in assembly code,

	(the first call of f1()) base_ptr->f1() is _ZN7Derive12f1Ev

	(the first call of f2()) base_ptr->f2() is _ZN4Base2f2Ev,

	(the second call of f1()) base_ptr->f1() is _ZN4Base2f1Ev.

	(the second call of f2()) base_ptr->f2() is _ZN7Derive22f2Ev.

	As I scroll down the prac1.s file near the buttom, I noticed some symbols like @object, @progbits, etc.
	I managed to find all the type names and virtual table names, which are:

	  
	_ZTS4Base, _ZTI4Base => type name & info Base

	_ZTS7Derive1, _ZTI7Derive1 => type name & info Derive1

	_ZTS7Derive2, _ZTI7Derive2 => type name & info Derive2

	_ZTV7Derive1, _ZTV7Derive2 => virtual table names Derive1, Derive2.


	In the virtual table part in Derive1 and Derive2, I found that there are many .quad directives (64 bits word)
	to hold the addresses of:

	Derive1 typeinfo,
	Derive1 Virtual Table:
	[0] Derive1's f1(), 
	[1] Base's f2()

	Derive2 typeinfo,
	Derive2 Virtual Table:
	[0] Base's f1(), 
	[1] Derive2's f2()

	Intrestingly, the addresses in the virtual tables have different orders.

	Also, why are there functions from Base in Derive1 and Derive2's virtual table?
	Well, my answer to this question is that Derive1 inherits Base, so when Derive1 inherits public functions
	from Base, as long as the virtual functions in Base are not overriden, the virtual function addresses
	from Base will get copied or pointed to Derive1's virtual table.

	I suspect the process follows:
	First, when Derive1 inherits Base, look for virtual functions from Base.

	Second, look for virtual functions in Derive1.
	If no virtual functions in Derive1 override virtual functions from Base,
	then add the virtual functions from Base to Derive1's virtual table.

	If there are virtual functions in Derive1 that override virtual functions from Base,
	then add the virtual functions that have overrides to Derive1's virtual table.

	Thrid, repeat step Two until all virtual functions are included.
-
	By vitualizing this process, the virtual table diagram from learncpp.com 18.6 makes sense.

	The hidden pointer to the virtual table will select member functions based on the type of 
	the object during run-time.

	The assembly concept above makes sense to me because to know where the virtual functions are
	we need to know the addresses of each function. If I never looked at the assembly code, I would
	never know what could happen. I wouldn't understand that each class will have its own virtual table.
	Before looking into the assembly code, I was assuming that everything about the virtual table will
	be created during run-time; however, it is a fact that virtual tables will get created at compiled time
	and used used at run-time. At run-time, we will need to find which virtual table to use so that we are target
	the function in virtual table.


	So, should I use virtual functions often? Will they make program execution slow?

	For Q1: I think it just depends on what I am trying to do. 
	For Q2: By observation, if you have virtual functions, then there will be virtual tables. 
	The more virtual functions you have, the larger the virtual table will be. 
	In the main section in assembly code, when I see this:

	leaq	16+_ZTV7Derive1(%rip), %rax

	and also this

	leaq	16+_ZTV7Derive2(%rip), %rax

	they tell me that we are loading the effective addresses of the virtual table's in Derive1 and Derive2 to the register %rax,
	and then have the call function instructions:

	call	_ZN7Derive12f1Ev
	call	_ZN4Base2f2Ev
	call	_ZN4Base2f1Ev
	call	_ZN7Derive22f2Ev

	so instead of directly calling the functions, we are taking sometime to find the function we are trying to call.
	However, does the compiler know which function to use? YES.
	
        By following the assembly code, it goes:
	1. Compiler creates a hidden class member *_vptr.
	2. *_vptr points to the vtable. (an array of function addresses).
	3. Get the correct function address from the vtable and store the function address into a register.
	4. Jump to the address in that register.
	5. After the jump, we are in the function section.
	6. Run function instructions.

	There are so many extra steps here compared with simply calling a function.

	This might add a little time when the program is executing.



	------------------------------------------------------------------------------------------------------------
	Worth spending time reading:

	What is typeinfo?
	According to https://itanium-cxx-abi.github.io/cxx-abi/abi.html#vtable-components, it is a pointer that points to
	the typeinfo object used for RTTI (Run-time type information). I didn't have time to read the whole documentation.
	I will spend time later this summer to finish reading this.

*/


/*
   In a relation sense, when I have a Node class, then for example, I can have
   class Node {
	public:
	  char data[n];
	  Node* next;
   }

   the part "Node* next" and the class Node's relationship is aggregation.
   
   Why?
   Uhmm, because Node is connect to another Node; a Node can still exist without another Node. 
   As many Nodes are connected, they are "gathered" together; hence the relation of Nodes is aggregation.
                     
                 (aggregation)
               __________
               |        |
           Node class   | next
		   |____|


Class relations:

                                                      (abstract class, interface)
          Node<T> (base)                                 ILinkedList<T> (base) 
              |                                               |
	      | public inheritance                            | public inheritance
	      |                                               |
          UniDirNode<T> (derived) -------------------> SingleLinkedList<T> (derived)
                                      composition


*/
int main() {
	SingleLinkedList<int>* test1 = new SingleLinkedList<int>();
	std::cout << "Add nodes: 1, 2, 3 to linkedlist\n";
	test1->AddEnd(1);
	test1->AddEnd(2);
	test1->AddEnd(3);
	test1->print_list();

	std::cout << "\nDelete the front node: \n";
	test1->RemoveFront();
	test1->print_list();

	std::cout << "\nAdd front node: 4\n";
	test1->AddFront(4);

	std::cout << "Contains 4?\n" << test1->contains(4);

	std::cout << "\nRemove the end node\n";
	test1->RemoveEnd();
	test1->print_list();

	std::cout << "\nDelete linkedlist\n";
	delete test1;

	return 0;
}
