#include "photo_order.h"

cvs_stores::cvs_orders::PhotoOrder::PhotoOrder(
	unsigned int store_id, 
	string vendor_id, 
	Customer customer_info
) 
	: m_store_id{ store_id }, 
	  m_vendor_id{ vendor_id }, 
	  m_customer_info{ customer_info } {};

cvs_stores::cvs_orders::PhotoOrder::~PhotoOrder(){};

std::ostream& cvs_stores::cvs_orders::operator<<(
	std::ostream& output, 
	const cvs_stores::cvs_orders::PhotoOrder& photo_order
) {
	return output << "Store id: " << photo_order.m_store_id << "\n" 
		          << "Vendor id: " << photo_order.m_vendor_id << "\n"
		          << "Customer info: \n" << photo_order.m_customer_info << "\n";
}
