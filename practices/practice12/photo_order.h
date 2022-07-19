#pragma once

#include "customer.h"

namespace cvs_stores {
namespace cvs_orders {

class PhotoOrder {
public:
	PhotoOrder() = default;
	PhotoOrder(unsigned int store_id, string vendor_id, Customer customer_info);
	~PhotoOrder();
private:
	unsigned int m_store_id{ 0 };
	string m_vendor_id{ "None" };
	Customer m_customer_info;

	friend std::ostream& operator<<(std::ostream& output, const PhotoOrder& photo_order);
};

} // namespace CVS_Orders
} // namespace CVS_Stores