/**
 * Single Operand
 */
struct SGL_OP{
	unsigned dst_reg: 3;
	unsigned dst_mode: 3;
	unsigned opcode: 10;
};

/**
 * Double Operand
 */
struct dpl_op{
	unsigned dst_reg: 3;
	unsigned dst_mode: 3;
	unsigned src_reg: 3;
	unsigned src_mode: 3;
	unsigned opcode: 4;
};

/**
 * Branch
 */
struct branch{
	unsigned offset:8;
	unsigned opcode:8;
};

/**
 * Register Source
 */
struct reg_src{
	unsigned dst_reg: 3;
	unsigned dst_mode: 3;
	unsigned src_reg:3;
	unsigned opcode: 7;
};

/**
 * Miscellaneous
 */
struct misc{
	unsigned opcode: 16;
};