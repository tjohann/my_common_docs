my_book
=======


1
---------

With my first blog entry (https://tjohann.wordpress.com/2016/05/01/thoughts-about-embedded-devices-part-i/) I tried to give a overview of the topics I want to talk about. So the next step is to do some definitions and describe the „old“ world.

There’re different architecture aproaches for deeply embedded devices. One is the Time-Triggert-Architecture (https://en.wikipedia.org/wiki/Time-triggered_architecture) which is a subset of the more general Event-Triggered-Architecture.

The smallest entity within a embbedded system is somthing like a block. Such a block represents some functionality (regulator, ADC, sensor calulation …) and is builded by a c-function. If you devite your whole system in such blocks/functions, you know the information flow and you can calculate to duration time. Now you have something like a block diagram. With the relation between blocks and functions you can do the same for the software and buildup a fist architecture.

The next step would be to decide which architecture we want to use. With an event-triggert-architecture you define some irq handler for the different functions. This could be really complicated if you have a bigger system. So you also use a timer interrupt and group some functions in it.

An another approach would be to use a time-triggert-architecture. With that you group your functions around ticks. Ticks are the cylcle time, it is build with timer interrupts. An example could be 25ms which is common in the aircraft environment. So every 25ms an interrupt will occur.  An example would be

…- IRQ – Function A – Function B – Function C – sleep – IRQ – Function A – Function B – Function C – sleep – IRQ – ….

The list Function A – Function B – Function C will be called tick-list.  Such a tick list could also represend something like a mode. If you have a household-good like a washing machine, then you have different washing modes. So every mode would be represented by a different tick-list.

The final step is to decide if the functions are preemptive or not. So TTC is a time-triggert-cooperative system and TTP is a timer-triggert-preemptive system. A problem with TTP is priority inversion (https://en.wikipedia.org/wiki/Priority_inversion).

Now we should have a common understanding for the next steps.


2
-------

As an electrical engineer i’m quite interrested in embedded device. Actual i read a book about reliable embedded systems (http://www.safetty.net/publications/the-engineering-of-reliable-embedded-systems). The basic ideas are around a time triggert operation systems. The linux kernel already provides all needed parts like SCHED_FIFO/SCHED_RR and so i like to check the capabilities Linux provides and the thoughts/ideas in the book.

In a realtime system only one task could have „real“ realtime capabilities, because every other task can be interrupted by the „real“ realtime task (priority based system). This leads to some problems if you have a bigger system with a lot of different jobs to do.

So one common approach is to split the realtime behaviour in two different levels, one which is interrupt driven and one which describes the system behaviour (such systems are classical embedded systems as decribed in M.J. Pont`s book). The interrupt driven part are the different sensors and actors, but they do not describe the complete system (think of a mars rover or simply the washing machine).

The system itself is defined through the controller and the other „high-level“ functions. They reflect the behaviour of the system as a hole. A calculation on an ADC value ends after some time and the it causes an interrupt, but the motor controller (https://en.wikipedia.org/wiki/Motor_controller) is what describes the performance of the system.

If you have a digital controller you need a fixed dt, otherwise you can’t rely on your calculations. If you have a bigger system then you maybe have different controller (-> functions) running on your system. Again you can found some detailed info about an operation implementation for microcontroller in Pont’s embedded C book (Pont, M.J. (2002) „Embedded C“, Addison-Wesley. ISBN 0-201-79523-X)

So one basic approach is to have an interrupt driven part, which of course interrupt everthing (an ADC value is ready) and then a periodic time triggert part (the motor controller). In the periodic part your group functions which represent a controller/functionality (or what your architecture needed) around an repetition/cyclic time like 100ms. With that you can calculate the latency (if you ignore that you dont know the FIRST occurence) of the whole path.

So what is the difference between a deeply embedded system an a linux based embedded system? In Linux based systems it’s not possible to handle hardware interrupts like ADC. So all hardware related topics should reside within the kernel. An easy way is to write a kernel driver which implements a character driver with an entry in /dev. Now you can simple make a blocking read/write and you have the needed bahaviour. As an example you can take a look on my driver repo (https://github.com/tjohann/mydriver.git and https://github.com/tjohann/lcd160x_driver.git).

For the cyclic parts (in deeply embedded device) you normally use a hardware timer which causes an interrupt after the time elapsed. On Linux you can use a lot of timer which all based on an high resolution timer (need RT-PREEMPT patch).  So this can simply be handled by userspace program (https://github.com/tjohann/time_triggert_env.git). You need root rights for that, but with linux capabilities it´s easy to drop the unneeded priviledge.

Due to the fact that more and more embedded system want/will use Linux it’s interresting to check how a migration between those two worlds can be handled. One of my projects is a led-dot-matrix clock (https://github.com/tjohann/led_dot_matrix_clock.git). This is a project you normally would do with a microcontroller like an cortex-m3/4, but i want to use a linux based system.

So i start with an infrastructure library (https://github.com/tjohann/libbaalue.git) which implement important functions needed for my approach. I also implement all relevant hardware related parts in form of kernel driver (see links above).

A common basement for development are my sdk`s (https://github.com/tjohann/a20_sdk.git). In the final version i want to use an arietta or imx233 hardware (https://github.com/tjohann/arm926_sdk and https://sourceforge.net/projects/arm926sdk/).

So within the nexts weeks i will show the results.
