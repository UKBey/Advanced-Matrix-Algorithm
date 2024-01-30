    // ************************************************************************
    // ******              STUDENT NAME : Ukbe Taha ŞAHİNKAYA             *****
    // *****             STUDENT NUMBER : B211202551                      *****
    // *****               ASSIGNMENT # : 2                               *****
    // *****        I swear I didn't cheat while writing the code!        *****
    // ************************************************************************

    #include <iostream>
    #include <iomanip> //for a good designed output like setw(4)
    #include <cmath> //for complex mathematical operations like pow(x,y)
    #include <ctime> //for generating random numbers
    #include <fstream> //for operations with file
    #include <string> //for operations about string

    using namespace std;

    void optionsMenu(); //the method which takes input from the user and does the operations which is chosen by the given input
    bool isEmpty(); //the method which checks if the data.txt doesn't exist(empty)
    void inputCoreGenerator(); //the method which generates input and core matrix and write it into data.txt file
    void inputCorePrinter(); //the method which prints the input and core matrix which is read from data.txt file
    void outputCalculator(); //the method which reads input and core matrix from data.txt and calculates output matrix and prints it


    int main()
    {
        optionsMenu();//run the optionsMenu() method
        return 0;
    }



    void optionsMenu()
    {
        string input;//we will assign the taken input to this variable
        char choice;//if input form user suites the wanted input we will assign input to this variable
        //I added string to avoid bugs which happen when users enter more than 1 alphanumeric character

        while (input != "1" && input != "2" && input != "3")//while input from user doesn't suit the wanted input
        {
            cout << "Please Enter:" << endl
                << "1 - Generate new matrixes" << endl
                << "2 - Read matrixes from existing file" << endl
                << "3 - Exit" << endl
                << "Your Choice: ";
            getline(cin,input);//get whole line into input
            cout << string(50, '-') << endl;
            if (input != "1" && input != "2" && input != "3")//if input from user doesn't suit requirments
            {
                cout << "You can only enter one of the given numbers!!!" << endl
                    << string(50, '-') << endl;
            }
        }

        choice = input[0];//assign input to choice //we use these to convert our string typed variable to char typed variable by taken the first letter of the string

        switch (choice)//for the values of choice
        {
        case '1'://if user chose 1
            inputCoreGenerator();
            outputCalculator();
            break;
        case '2'://if user chose 2
            if (isEmpty())//if file is empty
            {
                cout << "The file does not exist! You will be redirected to choice 1!!!" << endl
                    << string(50, '-') << endl;
                inputCoreGenerator();
                outputCalculator();
            }
            else//if file is not emty
            {
                outputCalculator();
            }
            break;
        case '3'://if user chose 3
            cout << "You have exited..." << endl;
            break;
        }
    }



    bool isEmpty()
    {
        ifstream emptyCheck("data.txt");
        string checker;//we will assign the line to this variable
        if (getline(emptyCheck, checker))
        {
            emptyCheck.close();
            return false;
        }
        else
        {
            emptyCheck.close();
            return true;
        }
    }//if the first line of the data.txt exists it returns false (the file is not empty) else it returns true(the file is empty)



    void inputCoreGenerator()
    {
        srand(time(NULL));
        int inputSize = rand() % 16 + 5; //size of the Input Matrix
        int coreSize = rand() % 4 + 2; //size of the Core Matrix

        int** inputMatrix = new int* [inputSize];
        for (int i = 0; i < inputSize; i++)
        {
            inputMatrix[i] = new int[inputSize];
        }

        int** coreMatrix = new int* [coreSize];
        for (int i = 0; i < coreSize; i++)
        {
            coreMatrix[i] = new int[coreSize];
        }
        //assigning the input and core matrix as dynamic matrix to choose their size randomly

        ofstream writeData("data.txt", ios::out);//we use ios::out to delete data.txt and write the new matrixs

        writeData << "INPUT MATRIX" << endl;
        for (int i = 0; i < inputSize; i++) //for each rows of input
        {
            for (int j = 0; j < inputSize; j++) //for each columns of input
            {
                inputMatrix[i][j] = rand() % 11 + 10;
                writeData << setw(4) << inputMatrix[i][j];
            }
            writeData << endl;
        }//generate and write input matrix into data.txt

        writeData << "CORE MATRIX" << endl;
        for (int i = 0; i < coreSize; i++) //for each row of core
        {
            for (int j = 0; j < coreSize; j++) //for each column of core
            {
                coreMatrix[i][j] = rand() % 10 + 1;
                writeData << setw(4) << coreMatrix[i][j];
            }
            writeData << endl;
        }//generate and write core matrix into data.txt
        writeData.close();


        for (int i = 0; i < inputSize; i++) 
        {
            delete[] inputMatrix[i];
        }
        delete[] inputMatrix;

        for (int i = 0; i < coreSize; i++) 
        {
            delete[] coreMatrix[i];
        }
        delete[] coreMatrix;
        //delete input and core matrix 2d dynamic arrays to free the memory
    }



    void inputCorePrinter()
    {
        string line;//we will assign the readen line to this variable
        ifstream printData("data.txt");
        while (getline(printData, line)) //while we can read a line(there is a line)
        {
            cout << line << "\n";
        }
        printData.close();
    }//print data.txt



    void outputCalculator()
    {
        srand(time(NULL));
        ifstream readData("data.txt");
        string line;//we will assign the readen line to this variable
        int inputSize = 0, coreSize = 0; //the readen input and core matrix size will be assigned to this variable

        getline(readData, line);//to skip the first line "INPUT MATRIX"
        while (getline(readData, line) && line != "CORE MATRIX")//while the line is "CORE MATRIX"
        {
            inputSize++;
        }//increase input matrix size by 1
        //we don't add getline to skip the line because we skipped the "CORE MATRIX" line in the while at the top
        while (getline(readData, line))//while we can read a line(there is a line)
        {
            coreSize++;
        }//increase core matrix size by 1

        int** inputMatrix = new int* [inputSize];
        for (int i = 0; i < inputSize; i++)
        {
            inputMatrix[i] = new int[inputSize];
        }
        //create the input matrix as dynamic array with the size we read form data.txt
        int** coreMatrix = new int* [coreSize];
        for (int i = 0; i < coreSize; i++)
        {
            coreMatrix[i] = new int[coreSize];
        }//create the core matrix as dynamic array with the size we read form data.txt

        readData.clear();//to use seekg(0, ios::beg) 
        //I used this because when I googled why I cant go to beginning of the file, there were people saying it to clear error flag because code is at the end of the file.
        readData.seekg(0, ios::beg);//go to beginning of the file

        int element;//we will assign readen elements to this variable //Ex. readData>>element

        getline(readData, line);//skip the "INPUT MATRIX" line
        for (int i = 0; i < inputSize; i++)//for each row of Input Matrix
        {
            for (int j = 0; j < inputSize; j++)//for each column of Input Matrix
            {
                readData >> element;
                inputMatrix[i][j] = element;
            }//assign the value to input matrix
        }

        getline(readData, line);//skip to "CORE MATRIX" line from the end of the Input Matrix
        getline(readData, line);//skip the "CORE MATRIX" line
        for (int i = 0; i < coreSize; i++)//for each row of Core Matrix
        {
            for (int j = 0; j < coreSize; j++)//for each column of Core Matrix
            {
                readData >> element;
                coreMatrix[i][j] = element;
            }//assign the value to core matirx
        }
        readData.close();

        int outSize = inputSize - coreSize + 1;//assign output matrix size by the given formula
        int** outputMatrix = new int* [outSize];
        for (int i = 0; i < outSize; i++)
        {
            outputMatrix[i] = new int[outSize];
        }//assigning the output matrix as dynamic matrix because the size of output matrix is not constant

        inputCorePrinter();//print input and core matrix from data.txt

        cout << "OUTPUT MATRIX" << endl;
        for (int rowOfOut = 0; rowOfOut < outSize; rowOfOut++)//for each row in output matrix
        {
            for (int colOfOut = 0; colOfOut < outSize; colOfOut++)//for each column in output matrix
            {
                outputMatrix[rowOfOut][colOfOut] = 0;//assign the Output Matrix's element which we are at to 0
                for (int rowOfCore = 0; rowOfCore < coreSize; rowOfCore++)//for each row in core matrix
                {
                    for (int colOfCore = 0; colOfCore < coreSize; colOfCore++)//for each column in core matrix
                    {
                        outputMatrix[rowOfOut][colOfOut] += inputMatrix[(rowOfOut - rowOfCore) + (coreSize - 1)][(colOfOut - colOfCore) + (coreSize - 1)] * coreMatrix[rowOfCore][colOfCore];
                        //add the input matrix's element with core matrix's elemnt to the Output Matrix's element which we are at
                        //we find the wanted input matirx's element with the algorithm which i found
                        //if you try this algorithm on paper you can easily understand it
                        //algorithm for the row of input matrix:
                        //row number of output matrix - row number of core matrix + the size of core matrix -1
                        //algorithm for the column of input matrix:
                        //column number of output matrix - column number of core matrix + the size of core matrix -1
                    }
                }
                outputMatrix[rowOfOut][colOfOut] /= pow(coreSize, 2);//divide the element of output matrix with the square of the size of core matrix
                cout << setw(4) << outputMatrix[rowOfOut][colOfOut];
            }
            cout << endl;
        }//calculate output matrix's elements values with the algorithm I mentioned //then print the outputMatrix

        for (int i = 0; i < inputSize; ++i) 
        {
            delete[] inputMatrix[i];
        }
        delete[] inputMatrix;

        for (int i = 0; i < coreSize; ++i) 
        {
            delete[] coreMatrix[i];
        }
        delete[] coreMatrix;

        for (int i = 0; i < outSize; ++i) 
        {
            delete[] outputMatrix[i];
        }
        delete[] outputMatrix;
        //delete input, core and output matrix 2d dynamic arrays to free the memory
    }
