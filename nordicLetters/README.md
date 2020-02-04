# Nordic letters from C++

This example and documentation is now updated and should cover all three platforms, Windows, macOS and linux.

## Introduction

Handling other letters than a..z and A..Z from the English alphabet can be a big challenge in C++. This example program demonstrates reading and printing Nordic letters both from and to console, as well as to and from a text file.

The example code and documentation is for students following TDT4102 at NTNU Trondheim, Norway. It assumes that you are using the standard VS Code setup described in exercise 0 of this course, spring 2020.

If you are running on **macOS or linux**, you should replace the file NordicLetters.cpp that is used under Windows with the very similar file called NordicLetters_UTF-8_cpp, but rename it with a .cpp file ending. (The reason for this is that you can only have one main() function). This is all you need, the rest of this documentation is for Windows

## Details for Windows

* Default encoding for files in our VS Code setup is UTF-8, as shown in the blue line at the lower right corner of VS Code.
* When downloading the examplecode [NordicLetters.cpp](NordicLetters.cpp) ensure that it is stored with the right encoding, which is ISO 8859-10. You can easily change the file encoding by clicking on the encoding (eg. UTF-8) and select **Save with encoding** from top of VS Code, and in the input field type Nordic, it will give you the right ISO encoding as an option. In case you fail to do this the .cpp file can look like this [image](./Capture_1.PNG).
* When compiling code containing Nordic letters you will get a lot of warnings dealing with character encoding from the compiler. These can be suppressed by the change of the **Makefile** as shown in [here](Makefile_Nordic_Encoding_Without_Warnings.PNG). (Add the \ at end of line 30, and insert new line 31. Note also that in general we ask students in the class to NOT do any changes to the Makefile).
* If you for some reason change the order of line 23 and 24, so that Windows.h is included _after_ std_lib_facilities.h you wil probably get a lot of error-messages referring to 'byte' like those shown [here](Byte_errors.PNG). To avoid this, you can change line 34 in the Makefile as shown in yellow [here](Makefile_line_HAS_STD_BYTE.PNG).
* This C++ program writes and reads a file MyFile.txt. If you open it with VS Code it will by default be opened as UTF-8 and it looks bad, as you can see [here](MyFile_as_UTF-8.PNG). This is fixed by changing its encoding, but this time using **Reopen with encoding**.

## Comments, suggestions

Please send comments and suggestions to [Lasse](https://www.ntnu.edu/employees/lasse.natvig)
