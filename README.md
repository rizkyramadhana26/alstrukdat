# Algorithm and Data Structure
## What Repository Is This ?
This is a repository to document my journey of learning algorithm and data structure. Files in this repository are the work that we were doing in Algorithm and Data Structure class. In this class, we learned how to make an abstract data type (ADT) and why using them can make our code more effective. This class started with a simple ADT called 'time' and 'point'. At the end of the semester, we are introduced with more advanced ADT such as stack, queue, and tree.

## What We Learned in Detail
We were not only make the definition of ADT in C, we also made the primitive function for that ADT. For example, if we want to access an element with index 4 in a linked list, it is not a best practice to iterate from the first element until the desired element in our main program. It is better to define a function like getElement() and call them in our main program. Doing so will also make our code cleaner since the change in the future will only affect the primitive function. We do not need to change a code in our main program, it is still getElement().

We were also encouraged to always write a well-commented code. For a reminder, programmer will never work alone. We will read others code intensively. Well-commented code will make it easier to other people to read and understand it. As we can see in these files, every function always have a comment that tells us what is the input and what the function will return. Every procedure also have a block of comment that explain the initial state (I.S.) and final state (F.S.). They explain how is the program state before the procedure is executed and after the procedure is executed.

## Short Explanation for Each ADT
|ADT Name|Description|
|--------|-----------|
|time|Time stored in HH : MM : SS. Supports time comparison, addition, substraction, and print to screen|
|point|Two dimensional point in (x,y) format. Supports basic operation like comparision, translation, print to screen, and calculating distance|
|garis|Two dimensional line built on top of point ADT. Basic operation like calculating gradient, translating, and checking whether two lines is perpendicular or parallel is supported|
|vector|Two dimensional vector built on top of line ADT. It also supports basic vector operation like addition, multiply by scalar, and dot multiplication|
|matrix|Matrices as used in math. Supports matrix multiplication, addition, also more advanced operation like calculating determinant and calculating transpose,|
|node|A node that contains a value and one/two pointer to other node. This ADT will be used to build node-based ADT like linked list or tree|
|listpos|Static list stored in a contiguous array|
|listdin|Dynamic list stored in a contiguous array. Dynamic means that its size always adapt to the contents of the list so that it is not too big or too small|
|list_linked|List but built with node. Every element is a node and every node point to another node.|
|list_circular|Node-based list and the last element point to the first element. Used frequently in round-robin like process|
|list_dp|Node-based list but every element point to the next and previous element. Normal list only point to the next element.|
|list_rec|List but stored as a pointer to node so it can be processed recursively|
|queue|ADT that manages whose turn is this. Manage turn based on principle first in first out (FIFO)|
|prioqueue|Similar with queue but element with higher priority can get in front of older element|
|queue_linked|Queue but implemented with node|
|stack|ADT that manages whose turn is this. Manage turn based on principle Last in first out (LIFO)|
|stack_linked|Stack but implemented with node|

## Short Reflection
1. After learning algorithm and data structure, we learned how to be always aware that a function or a procedure may have many cases. Keep our eyes on that or our program will be failed
2. By using ADT, it makes our code cleaner, more understandable, and easier to debug
