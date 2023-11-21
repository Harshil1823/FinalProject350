# FinalProject350
To compile this project follow the steps below. 

In your command line do the following. 
Step 1: run make (this will create two executables named InputfileGenerator, Shah_Harshil_quicksort).

step 2: First you will need to generate files using InputfileGenerator. So, here is how to run that.
You need to do ./InputFileGenerator <NameOfTheFileYouLike> <number of values within file>
		so for example, ./InputFileGenerator input_1.txt 1000 

above command will create a file called input_1.txt and it will have 1000 values randomly generated from -100 to 100 inclusivley. 

step 3: run this commmand. ./Shah_Harshil_quicksort <inputFile> <outputFile>

so for inputfile you can pass in anyfile's name that is in the directory. And for outputfile you can have the results in any file name of your choice. 

		so example command, ./Shah_Harshil_quicksort input_1.txt result_1.txt 

This command will take in file called input_1.txt and read from the file and then sort the values and output them in result_1.txt. 

Also, it will create a execution time file with it. The execution file will have how long it took to the task of sorting. 

To cleanup simply call make clean. 
