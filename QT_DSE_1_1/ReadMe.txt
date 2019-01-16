Before using the design, you need to install Qt develop kit by yourself and load the project file in this folder. 

To use the software you need to create the DSE result by your own software. Your can use your own command line in the box "Exexutable Command" and hit "Run" button. Then the software can call your comman in terminal. 

After DSE please form your valid .CSV report file for the Qt software. The information should include

	"Method,Iteration,ATTR,AREA,state,FU,REG,MUX,DEC,pin_pair,net,max,min,ave,MISC,MEM,cp_delay,sim,Pmax,Pmin,Pave,Latency,BlockMemoryBit,DSP"

Combine all your different DSE result by copy the data together in one .CSV file. Denote your method and iteration before copy your data, which means you need to add 2 column named by "Method" and "Iteration" before your data. For example, you may firstly generate your DSE result by brute force method. So denote all your data by "BF" as "Method" and "1" for "Iteration". Then you may generate another DSE result by genetic algorithm, denote them by "GA" and "1" for method and iteration. And you may also generate another DSE result by genetic algorithm, denote them by "GA" and "2" for method and iteration. After copy all your data to one .CSV file, you can load it in the software by using the "File"->"New" and choose the directory of your .CSV file. Several valid example .CSV files is located under "example" folder in "QT_DSE_1_1", you can use it as an example about how to form your own data file. 
