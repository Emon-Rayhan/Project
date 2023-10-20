Documentation for the Blood Club System Project:

Introduction:

The provided code is a C program that appears to be a simple donor management system. It allows users to register as donors, log in, change their contact number and password, search for donors by blood type, and log out. This analysis will provide an overview of the code, highlighting its key components and discussing its structure, functionality, and potential improvements.

Code Structure

Header Files: The code includes three standard C library header files: stdio.h, string.h, and stdlib.h. These are essential for input/output, string manipulation, and dynamic memory allocation.

Constants and Definitions: The code defines a maximum size (MAX_SIZE) for various string inputs and the name of a user data file (USER_FILE). A struct Donor is defined to represent donor information, including username, password, full name, blood type, contact number, number of donations, and a flag for blood type registration.

Utility Functions: The code contains a displayError function to display error messages. It takes a message as input and prints it as an error.

Main Functions: The code has several main functions: registerDonor, login, changePassword, changeNumber, searchBloodType, and the main program main.

registerDonor Function: This function allows users to register as donors. It opens the users.txt file for appending. User input is collected for username, password, full name, blood type, and contact number. Donor data is written to the file and added to the donors array. The donorCount variable is incremented, and a success message is displayed.

login Function: This function allows users to log in. It prompts users to enter a username and password. It compares the entered credentials with those in the donors array. If a match is found, the user is considered logged in, and their index is returned. A welcome message is displayed upon successful login.

changePassword Function: This function allows logged-in users to change their password. It takes the donors array and the user's index as input. The user is prompted to enter a new password, which is then updated in the donors array.

changeNumber Function: This function allows logged-in users to change their contact number. It takes the donors array and the user's index as input. The user is prompted to enter a new contact number, which is then updated in the donors array.

searchBloodType Function: This function allows users to search for donors by blood type. It takes user input for a blood type and searches for matching donors in the donors array. If a match is found and the blood type is registered, the donor's information is displayed.

main Function

The main function is the entry point of the program. It sets up the data file, allocates memory for the donors array, and provides a menu for user interaction. Users can choose from various options like registration, login, changing password and contact number, searching for blood types, and logging out.

Code Flow

The code flow is menu-driven. Users select options from a menu, and the corresponding function is executed. The program continues to run until the user chooses to exit.

Conclusion

The provided code is a basic donor management system in C. It allows users to register as donors, log in, make profile updates, search for donors by blood type, and log out. While functional, there are opportunities for improvement in terms of error handling, security, and user experience.
