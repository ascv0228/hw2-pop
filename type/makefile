CC:=gcc
TYPE:= char short int long float double
exe_queue:= main_queue_
obj_queue:= queue.c list.c mm.c
exe_stack:= main_stack_
obj_stack:= stack.c list.c mm.c
all: $(obj_queue)
	for i in $(TYPE); do\
		$(CC) -o $(exe_queue)$$i $(exe_queue)$$i.c $(obj_queue);\
	done
	
	for i in $(TYPE); do\
		$(CC) -o $(exe_stack)$$i $(exe_stack)$$i.c $(obj_stack);\
	done


	
.PHONY:clean
clean:
	for i in $(TYPE); do\
		rm -rf $(exe_queue)$$i;\
	done
	
	for i in $(TYPE); do\
		rm -rf $(exe_stack)$$i;\
	done

