void print_ledger_long(int val);
void print_ledger_detailed(int val);
void print_ledger_default(int val);

void print_ledger(int val)
{	
#if defined(OPTION_LONG)
	print_ledger_long(val);
#elif defined(OPTION_DETAILED)
	print_ledger_detailed(val);
#else
	print_ledger_default(val);
#endif
}
