import angr
import claripy
import sys

def main(argv):
	project = angr.Project(argv[1])

	main_t = project.loader.find_symbol('main')

	start_address = main_t.rebased_addr

	init_state = project.factory.blank_state( addr = start_address, add_options = {angr.options.SYMBOL_FILL_UNCONSTRAINED_MEMORY, angr.options.SYMBOL_FILL_UNCONSTRAINED_REGISTERS} )

	argv_addr  = 0x41300000
	argv0_addr = 0x41400000
	argv1_addr = 0x41410000
	argv2_addr = 0x41420000
	argv3_addr = 0x41430000
	argv4_addr = 0x41440000

	init_state.regs.rdi = 5

	for i in range(8):
		byte = init_state.solver.BVS('byte1{}'.format(i), 8)
		#init_state.solver.add( claripy.Or( claripy.And( byte < 0x67, byte >= 0x30), byte == 0))

		init_state.memory.store(argv1_addr + i, byte)

	for i in range(8):
		byte = init_state.solver.BVS('byte2{}'.format(i), 8)
		#init_state.solver.add( claripy.Or( claripy.And( byte < 0x67, byte >= 0x30), byte == 0))

		init_state.memory.store(argv1_addr + i, byte)

	for i in range(8):
		byte = init_state.solver.BVS('byte2{}'.format(i), 8)
		#init_state.solver.add( claripy.Or( claripy.And( byte < 0x67, byte >= 0x30), byte == 0))

		init_state.memory.store(argv1_addr + i, byte)

	for i in range(8):
		byte = init_state.solver.BVS('byte2{}'.format(i), 8)
		#init_state.solver.add( claripy.Or( claripy.And( byte < 0x67, byte >= 0x30), byte == 0))

		init_state.memory.store(argv1_addr + i, byte)

	init_state.mem[argv_addr].uint64_t = argv0_addr
	init_state.mem[argv_addr+8].uint64_t = argv1_addr
	init_state.mem[argv_addr+16].uint64_t = argv2_addr
	init_state.mem[argv_addr+24].uint64_t = argv3_addr
	init_state.mem[argv_addr+32].uint64_t = argv4_addr


	init_state.regs.rsi = argv_addr

	simulation = project.factory.simgr(init_state)

	def is_successful(state):
		stdout_output = state.posix.dumps(sys.stdout.fileno())
		print(stdout_output)
		if stdout_output == b'SUCCESS!\n':
			return True

		return False

	def abort(state):
		stdout_output = state.posix.dumps(sys.stdout.fileno())
		if stdout_output == b'FAIL\n':
			return True

		return False

	simulation.explore(find=is_successful, avoid=abort)


	if simulation.found:
		ss = simulation.found[0]

		arg1 = ss.memory.load(argv1_addr, 16)

		for i in range(8):
			print(arg1[i].annotations)

		answer1 = ss.solver.eval(arg1, cast_to=bytes)
		arg2 = ss.memory.load(argv2_addr, 16)
		answer2 = ss.solver.eval(arg2, cast_to=bytes)
		arg3 = ss.memory.load(argv3_addr, 16)
		answer3 = ss.solver.eval(arg3, cast_to=bytes)
		arg4 = ss.memory.load(argv4_addr, 16)
		answer4 = ss.solver.eval(arg4, cast_to=bytes)

		print(answer1)
		print(answer2)
		print(answer3)
		print(answer4)

	else:
		raise Exception('Failed to find a solution')





if __name__ == '__main__':
	main(sys.argv)