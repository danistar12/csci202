# C++ Library Management System

This project implements a simple library management system using C++. It includes classes for managing books, patrons, and the library itself, utilizing linked lists and binary trees as data structures.

## Project Structure

```
cpp-library-project
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── Book.cpp          # Implementation of the Book class
│   ├── Book.h            # Definition of the Book class
│   ├── Patron.cpp        # Implementation of the Patron class
│   ├── Patron.h          # Definition of the Patron class
│   ├── Library.cpp        # Implementation of the Library class
│   ├── Library.h          # Definition of the Library class
│   ├── data_structures
│   │   ├── LinkedList.cpp # Implementation of the LinkedList class
│   │   ├── LinkedList.h   # Definition of the LinkedList class
│   │   ├── BinaryTree.cpp  # Implementation of the BinaryTree class
│   │   └── BinaryTree.h    # Definition of the BinaryTree class
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation
```

## Features

- **Book Management**: Add, remove, and retrieve book details such as title, author, and ISBN.
- **Patron Management**: Add, remove, and retrieve patron details such as name and library card number.
- **Library Management**: Manage collections of books and patrons, utilizing linked lists for patrons and binary trees for books.

## Building the Project

To build the project, follow these steps:

1. Ensure you have CMake installed on your system.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   make
   ```

## Running the Application

After building the project, you can run the application using the following command in the build directory:
```
./cpp-library-project
```

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. Your feedback and suggestions are welcome!