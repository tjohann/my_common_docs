some hints about load-avrg (see also dir loadavrg)
--------------------------------------------------


http://www.admin-magazine.com/HPC/Articles/Determining-CPU-Utilization
http://stackoverflow.com/questions/3769405/determining-cpu-utilization
http://stackoverflow.com/questions/3017162/how-to-get-total-cpu-usage-in-linux-c


Notes
-----

	(watch) cat /proc/loadavg

	0.28 1.17 1.11 1/441 10548

	systemload last
	min  5min 15min number_of_active_process/overall_number_of_processes last_PID

Note: on a single core 1.00 means more or less 100% (in linux the number of processes in the waitqueue are included ... that means a number >1.00 is okay)



Code example
------------

	see ./loadavrg/system_load

Others:

	double la[3];
	getloadavg(la, 3);
	printf("%f - %f - %f", la[0], la[1], la[2]);
