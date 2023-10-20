This code is a blood donation management system. It allows users to register as donors, login, change their contact number and password, search for blood groups, and exit the program.

The program starts by defining a Donor struct, which contains the following fields:

username: The donor's username.
password: The donor's password.
fullName: The donor's full name.
bloodType: The donor's blood type.
contactNumber: The donor's contact number.
donations: The number of times the donor has donated blood.
bloodTypeRegistered: A flag indicating whether the donor's blood type is registered.
The program then declares an array of Donor structs called donors, which can store up to MAX_DONORS donors. The donorCount variable keeps track of the number of donors currently registered.

The program then defines the following functions:

registerDonor(): This function registers a new donor. It prompts the user to enter their username, password, full name, blood type, and contact number. It then creates a new Donor struct with this information and adds it to the donors array.
login(): This function allows a donor to login to the system. It prompts the user to enter their username and password. If the credentials are valid, the function returns the index of the donor in the donors array. Otherwise, it returns -1.
changePassword(): This function allows a donor to change their password. It takes the index of the donor in the donors array as input. It then prompts the user to enter their new password.
changeNumber(): This function allows a donor to change their contact number. It takes the index of the donor in the donors array as input. It then prompts the user to enter their new contact number.
searchBloodType(): This function allows a user to search for a specific blood type. It takes the blood type as input and returns the index of the donor with that blood type in the donors array. If the blood type is not found, it returns -1.
The main function of the program starts by initializing the donorIndex variable to -1, indicating that no donor is currently logged in. It then enters a loop, where it prompts the user to enter their choice.
