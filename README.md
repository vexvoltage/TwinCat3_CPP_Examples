 # TwinCat3 CPP Examples
 
# Overview
These are examples from Beckhoff for my personal use. I made this repository so that I may reference it easier then searching their site. 

If you want to go ahead and fork these examples they are untouched from downloading the source codes.
Numerous samples are available – further samples follow.
https://infosys.beckhoff.com/content/1033/tc3_c/Images/png/4113152523__Web.png
This picture provides an overview in graphical form and places the emphasis on the interaction 
possibilities of a C++ module.
![enter image description here](https://infosys.beckhoff.com/content/1033/tc3_c/Images/png/4113152523__Web.png)


# Sections


01
[Sample01: cyclic with IO module](https://infosys.beckhoff.com/content/1033/tc3_c/36028797130534795.html)
This article describes the implementation of a TC3 C++ module that uses an IO module mapped with physical IO. This sample describes the quick start for the purpose of creating a C++ module that increments a counter on each cycle and assigns the counter to the logical output "Value" in the data area.  
The data area can be assigned to the physical IO or another logical input or another module instance.

02
[Sample02: cyclic with IO task](https://infosys.beckhoff.com/content/1033/tc3_c/45035996385276811.html)
Describes the flexibility of C++ code when working with IOs that are configured at the task. Thanks to this approach, a finally compiled C++ module can affect various IOs connected with the IO task much more flexibly. One application could be to check cyclic analog input channels, where the number of input channels can differ from one project to another.

03
[Sample03: ADS Server Client](https://infosys.beckhoff.com/content/1033/tc3_c/90071992660007691.html)
Describes the design and implementation of one's own ADS interface in a C++ module.  
The sample contains two parts:  
- ADS Server implemented in TC3 C++ with user-specific ADS interface.  
- ADS Client UI implemented in C#, which transmits user-specific ADS messages to the ADS server

05
[Sample05: CoE access over ADS](https://infosys.beckhoff.com/content/1033/tc3_c/45035996386305803.html)
Shows how CoE registers of EtherCAT devices can be accessed over ADS

06
[Sample06: ADS C# client uploads ADS symbols](https://infosys.beckhoff.com/content/1033/tc3_c/27021597876824843.html)
Shows how symbols in an ADS server can be accessed via the ADS interface. C# ADS client connects with a module implemented in PLC/C++/Matlab; uploading of the available symbol information and read/write subscription for process values.

07
[Sample07: Receiving ADS Notifications](https://infosys.beckhoff.com/content/1033/tc3_c/45035996764281995.html)
Describes the implementation of a TC3 C++ module that receives ADS notifications regarding data changes on other modules.

08
[Sample08: provision of ADS-RPC](https://infosys.beckhoff.com/content/1033/tc3_c/36028798996935691.html)
Describes the implementation of methods that can be called by ADS via the task.

10
[Sample10: Module communication: Use of data pointers](https://infosys.beckhoff.com/content/1033/tc3_c/36028797131566859.html)
Describes the interaction between two C++ modules with a direct data pointer. The two modules must be implemented on the same CPU core in the same real-time context.

11
[Sample11: Module communication: PLC module calls a method of a C-module](https://infosys.beckhoff.com/content/1033/tc3_c/90071992660013835.html)
This sample contains two parts
A C++ module which functions as a state machine that provides an interface with methods for starting/stopping and also for setting/maintaining the state machine.
Second PLC module for interacting with the first module by calling methods from the C++ module

11a
[Sample11a: Module communication: C-module cites a method in the C-module](https://infosys.beckhoff.com/content/1033/tc3_c/54043195641053835.html)
This sample contains two classes in one driver (can also be done between two drivers)
One module that provides a calculation method. Access is protected through a Critical section.
A second module that acts as the caller in order to use the methods in the other module

12
[Sample12: Module communication: IO mapping used](https://infosys.beckhoff.com/content/1033/tc3_c/36028797131572875.html)
Describes how two modules can interact with each other via mapping of symbols from the data area of different modules. The two modules can be executed on the same or different CPU cores.

13
[Sample13: Module communication: C-module calls PLC methods](https://infosys.beckhoff.com/content/1033/tc3_c/18014399398539403.html)
Describes how a TwinCAT C++ module calls methods of a PLC function block via TcCOM interface.

19
[Sample19: Synchronous File Access](https://infosys.beckhoff.com/content/1033/tc3_c/45035996386314891.html)
Describes how the File IO function can be used in a synchronized manner with C++ modules.  
The sample writes process values in a file. The writing of the file is triggered by a deterministic cycle - the execution of File IO is decoupled (asynchronous), i.e.: the deterministic cycle continues to run and is not hindered by writing to the file. The status of the routine for decoupled writing to the file can be checked.

20
[Sample20: FileIO-Write](https://infosys.beckhoff.com/content/1033/tc3_c/45035996386315915.html)
Describes how the File IO function can be used with C++ modules.  
The sample writes process values in a file. The writing of the file is triggered by a deterministic cycle - the execution of File IO is decoupled (asynchronous), i.e.: the deterministic cycle continues to run and is not hindered by writing to the file. The status of the routine for decoupled writing to the file can be checked.

20a
[Sample20a: FileIO-Cyclic Read / Write](https://infosys.beckhoff.com/content/1033/tc3_c/81064793665789963.html)
A more extensive sample than S20 and S19. It describes the cyclic read and/or write access to files from a TC3 C++ module.

22
[Sample22: Automation Device Driver (ADD): Access DPRAM](https://infosys.beckhoff.com/content/1033/tc3_c/36028797131575947.html)
Describes how the TwinCAT Automation Device Driver (ADD) is to be written for access to the DPRAM.

25
[Sample25: Static Library](https://infosys.beckhoff.com/content/1033/tc3_c/54043195641058955.html)
Describes how to use the TC3 C++ static library contained in another TC3 C++ module.

26
[Sample26: Execution order at one task](https://infosys.beckhoff.com/content/1033/tc3_c/45035997102521355.html)
Describes the determination of the task execution sequence, if a task is assigned to more than one module.

27
Sample27: Using the JobTask
Describes the use of a JobTask by means of four variants.

30
[Sample30: Timing Measurement](https://infosys.beckhoff.com/content/1033/tc3_c/45035996386318987.html)
Describes the measurement of the TC3 C++ cycle or execution time.

31
[Sample31: Functionblock TON in TwinCAT3 C++](https://infosys.beckhoff.com/content/1033/tc3_c/18014399543502731.html)
Describes the implementation of a behavior in C++, which is comparable to a TON function block of PLC / 61131.

37
[Sample37: Archive data](https://infosys.beckhoff.com/content/1033/tc3_c/45035996386321035.html)
Describes the loading and saving of the state of an object during the initialization and de-initialization.

TcCOM
[TcCOM samples](https://infosys.beckhoff.com/content/1033/tc3_c/9007201591219083.html)
Several samples are provided to illustrate the module communication between PLC and C++.
