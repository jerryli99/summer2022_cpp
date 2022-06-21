#include "land.h"
#include "house.h"

#include <iostream>
#include <string>

/*
                                       Land
                                        |
                                        |
                                       House

There isn't really much to do in 17.6 because I had already 
written classes in 17.3, 17.4, and 17.5 with additional 
functionalities in the derived classes.

*/
int main() {
	// house_length, house_width, land's buyer_name, land_length, land_width
	House* build_house1 = new House(123.0, 111.0, "John", 200.0, 50.0);  
	House* build_house2 = new House(23.0, 22.02, "Tom", 123.0, 102.4);


	if (build_house1->OverSizedHouseArea()) {
		cout << "The house " << build_house1->get_land_buyer() << " wants to build to too big for the land.\n";
	} else {
		cout << "Let's build " << build_house1->get_land_buyer()  << "'s house1!\n";
	}

	if (build_house2->OverSizedHouseArea()) {
		cout << "The house " << build_house2->get_land_buyer() << " wants to build to too big for the land.\n";
	} else {
		cout << "Let's build " << build_house2->get_land_buyer() << "'s house2!\n";
	}

	return 0;
}
