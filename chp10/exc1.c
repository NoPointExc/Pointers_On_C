struct PHONE_NUM {
	int area_code;
	int station_num;
	int exchange; 
};

struct BILL_INFO{
	struct PHONE_NUM to_num;
	struct PHONE_NUM from_num;	
	struct PHONE_NUM bill_num;
}