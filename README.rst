C++ - ASU Math Lab - Project
===========================

Intro:
-------

Math Lab Project is Written in C++ and it’s mainly depends on the “Matrix Class” as it works with matrices only, it also makes the all main operations on them with accurate results as much as you expect in its first phase and another more complex operations will be added in the next coming phases, in the next section we will go closer to which operations it can do efficiently.

Math Lab can do the following operations:
-----


•	Copy.
•	Add Column.
•	Add Row.
•	Addition.
•	Subtraction.
•	Multiplication.
•	Division.
•	Transpose.
•	Determinant.
•	Inverse.
•	Ad joint.
•	Cofactor.

Configuration:
----
There are two methods to configure with this project.The first method is to write command lines in the Terminal (console).
For example on the first method : if you want to add two matrices A and B (after entering the values of them), and put the result in matrix C the command line will be :

::

  C = A + B  
  
Hint: all operations will be the same with the change of operator '+' and put the operator of operation the you want.

The second method and the more recommended from the long calculations and operations is to enter a text file which have all your matrices and operations you want to do and make this file with extension '.m'.For Example if you text file name is "myOperations.txt" it should be "myOperations.s". 

Some **Important** notes about **Command Lines** :
----

- Define Matrix: 

::

  A = [2.2 7.3 4.8 2.4; 2.3 6.5 8.9 1.2; 4.9 3.8 7.2 7.5; 9.8 3.4 7.5 8.9]
  
  
This matrix is 4x4 matrix you write the first row then but ';' and between each element you but space ' '.

- Dont feel confused about hiting enter or continue the matrix elements int new line "our code handel all these issues".

For example:

::

  A = [8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8
  3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2
  7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2
  4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9; 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5]
  
  
- The operations **Must** go on exsisting defined matrices.
  
  For example: if you are going to make multiplication on two matrices A and B and put the result in matrix C 
  
  ::
  
    C = A * B
    
The two matrices A and B should be defined before this command with the same name and the upper case as it is **Case Sensitive** commands.

Core Operations And it's Command Lines:
----

::

  C = A + B  // Add 
  C = A - B  //Subtract
  C = A * B  //multiplication
  C = A / B  //Division
  C = A'     //Inverse
  

Fixed Bugs and Issues:
-----


  
  
