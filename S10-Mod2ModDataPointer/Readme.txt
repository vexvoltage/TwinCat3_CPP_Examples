TwinCAT 3 Sample Project with Data Pointer 

1. Overview

This TwinCAT 3 sample illustrates the usage of data pointers. 

The TwinCAT C++ driver TcDataPointerSampleDrv implements the classes CModuleDataAccessA and 
CModuleDataAccessB which use data pointer to access input and output data. The configuration contains 
one instance of each of these classes. Their data pointers are configured to point at the standard
data area "Data" of the CModuleDataProvider instance. This module has an input and an output data area and it
implements the ITcIoCylic interface. The method InputUpdate copies data from the Input data area to 
DataIn symbol of the standard data area "Data" and method OutputUpdate copies data from the DataOut symbol
to the ouput data area. The instance of class CModuleDataInOut acts as an simulation for real IO. 


2. Task context and sort order

All modules are configured to have the same task context, which is necessary because access through
data pointers does not provide any synchronization mechanism. The order of execution is determined by the 
sort order specified on the context configuration tab. This value is passed as parameter "SortOrder" and it
is stored in cyclic caller smart pointer (m_spCyclicCaller), which also holds the object id of the cyclic caller. 

3. Test

In order to see the sample working, one can set TcDataPointerSampleDrv_Obj4 (CModuleDataInOut)^InputSource^ValueIn 
to 1 using the Online dialog. The TcDataPointerSampleDrv_Obj4 (CModuleDataInOut)^OutputDestination^ValueOut
should be incremented. 


