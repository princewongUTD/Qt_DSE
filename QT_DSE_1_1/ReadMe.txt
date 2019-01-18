===================================================================================
                 Qt_DSE v.1.1
===================================================================================

Qt_DSE is a software designed for generating and analysing the result of Design Space Exploration(DSE). It is a open source software created by Qt. The software can be used to call your own DSE process designed by different high-level synthesis tool with system call of command line built inside.

All of the work has been done by the DARClab at the Department of Electrical andComputer Engineering (ECE), at the  University of Texas at Dallas. And this is the first version of the project.

DARClab=Design Automation and Reconfigurable Computing Laboratory - www.utdallas.edu/~schaferb/darclab

More details regarding the software can be found at the authors:
Zi Wang, zxw173030@utdallas.edu
Benjamin Carrion Schafer, schaferb@utdallas.edu

Please cite this work if you use Qt_DSE for your academic work.

Qt_DSE is distributed in the hope that it will be useful. Qt_DSE is free software; you can redistribute it and/or modify it, but please remember WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. And please install Qtcreator on your machine to access and make your own modification to the project.

The following files in Qt_DSE may be important to your modification

-----------------------------------------------------------------
|   NAME              |        Description                      |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| main.cpp            | main process of the project,	        | 
|                     | used to link different object only      |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| mainwindow.cpp      | .cpp and .h file is the code for the    |
| mainwindow.h        | behaviour of the main interface, .ui    |
| mainwindow.ui       | file is the view of the interface and   | 
|                     | some parameters                         |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| newfile.cpp         | this is the dialog box that popup after |
| newfile.h           | after you hit "File"->"New", used to    |
| newfile.ui          | load .CSV file                          | 
|---------------------|-----------------------------------------|
|---------------------|-----------------------------------------|
| helpwithcommand.cpp | this is the dialog box popups after you |
| helpwithcommand.h   | hit "Help"->"Help"                      |
| helpwithcommand.ui  |                                         |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| qcustomplot.cpp     | this is the third party plot function   |
| qcustomplot.h       | used to generate the trade-off curve    |
|                     | based on the data read in .CVS file     |
|---------------------+-----------------------------------------+
|---------------------+-----------------------------------------+
| QT_DSE_1_1.pro      | this is the project file of the whole   | 
|                     | design, please use this file to load    |
|                     | the project after you install Qt        |

To use the software you need to create the DSE result by your own software. Your can use your own command line in the box "Exexutable Command" and hit "Run" button. Then the software can call your comman in terminal. 

After DSE please form your valid .CSV report file for the Qt software. The information should include
	"Method,Iteration,ATTR,AREA,state,FU,REG,MUX,DEC,pin_pair,net,max,min,ave,MISC,MEM,cp_delay,sim,Pmax,Pmin,Pave,Latency,BlockMemoryBit,DSP"

Combine all your different DSE result by copy the data together in one .CSV file. Denote your method and iteration before copy your data, which means you need to add 2 column named by "Method" and "Iteration" before your data. For example, you may firstly generate your DSE result by brute force method. So denote all your data by "BF" as "Method" and "1" for "Iteration". Then you may generate another DSE result by genetic algorithm, denote them by "GA" and "1" for method and iteration. And you may also generate another DSE result by genetic algorithm, denote them by "GA" and "2" for method and iteration. After copy all your data to one .CSV file, you can load it in the software by using the "File"->"New" and choose the directory of your .CSV file. Several valid example .CSV files is located under "example" folder in "QT_DSE_1_1", you can use it as an example about how to form your own data file. 
