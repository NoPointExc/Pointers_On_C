struct CASH_INFO{
	float sales_tax;
	float license_fee;
};

struct LEASE_INFO{
	float down_pay;
	float security_deposit;
	float monthly_pay;
	int lease_term;
};

struct  LOAN_INFO{
	float sales_tax;
	float license_fee;
	float down_pay;
	int loan_duration;
	float interest_rate;
	float monthly_pay;
	char bank_name[21];	
};

struct TRANSCATION {
	char customer_name[21];
	char customer_addr[21];
	char model[21];
	float suggested_price;
	float actual_price;
	union{
		 struct CASH_INFO cash_info;
		 struct LEASE_INFO lease_info;
		 struct LOAN_INFO loan_info;
	}
};
