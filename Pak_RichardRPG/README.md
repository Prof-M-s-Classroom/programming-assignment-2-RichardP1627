[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Richard Pak]`  
### **Student ID:** `[130109717]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
My RPG game is based on a zombie outbreak survival game where the player makes decisions to hopefully survive. It implements a binary search tree in which each event is a node in the tree, and the choices the player can make, are the children nodes. The story is loaded from an external text file ('story.txt') which holds all the events which are then loaded into a binary search tree. The game will end once the player reaches a node which only has children with values of -1, and enters -1 to end the game.

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]` 
  - The main.cpp file serves as file where the program starts and ends execution.
- **`GameDecisionTree.h`** → `[Explain what this file contains]`  
  - The GameDecisionTree.h file contains the functions that are used to construct the binary search tree using the text file and traverse through the tree as the player makes their decisions.
- **`Node.h`** → `[Explain what this file contains]`  
  - The Node.h file contains the code to create the nodes that are used in a binary search tree. It holds the values and pointers that create the node which stores my game events, and the pointers that connect the node to it's children.
- **`Story.h`** → `[Explain what this file contains]`  
  - The Story.h file contains data that each node will hold. This includes the value of the node/event, the value of the children nodes, and the decription/event that each node represents.
- **`story.txt`** → `[Explain how the game loads story events from this file]`  
  - The story.txt file contains all the events that happen in the game. Using a delimiter, it reads the different sections of each line in the file and stores them as the different variables that each node holds. Each line in the text file is read as a different node, and each node has different variables that hold the content of each line. Since each line starts with an integer to represent the event number, the different events can be iterated through as the player makes their choices in the game.

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
  - Story objects are able to be created from the text file because we have a node template class which is able to hold any object. We read each line in the text file and separate its contents into the different variables that are initialized in the Story class. We then are able to use a function which converts the string into integer when needed, and create a vector of Story objects that all each hold different values for their event number, descriptions, and children's event numbers.
- How are nodes linked based on left and right event numbers?  
  - In the text file, each line has a specific event number, description, left child event number, and right child event number which are separated by delimiters. The program looks at the specific left and right event numbers of each line/node and matches them with the line/node that has that event number. If the event number of a node matches the right or left event number of a parent node, it links the parent node with that child node through left/right pointers.
- What happens if an event has `-1` as left or right children?  
  - If an event has '-1' as the left or right child, there are no further events that could happen from the current event, or there is only 1 other path that the player can continue down. The program checks to see if a node's left or right event number is equal to '-1', and if this is the case, it will continue on to the next node without creating any links to a child node.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
  - User input determines which node/event will be visited next in the binary search tree. In each internal node, there are 2 child nodes which are presented as options to the player. The player inputs a value that is one of the two possible event numbers, and the program visits that node next.
- What happens when the player reaches a leaf node?  
  - When the player reaches a leaf node, they will be given dialogue that explains they have reached the end of the game, and will have to input the value '-1' to end recursion and reach the end of the program.
- Explain the special case where multiple events lead to the same outcome.  
  - In my story, the player would be able to choose different paths but eventually come to a point where one event/node would lead to the same event as another event/node. While my program constructed the binary search tree, it just had an instance where two separate nodes would have pointers to one child node.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
  - An ifstream object is created to open the file for reading and the function getLine is used to read through each individual line in the txt file. In each line, the program would read up until it reached the designated delimiter character and then initialize what was read in that block to the specific variable. This would happen between each delimiter that was written inside the text file.
- How do you ensure nodes are properly linked?  
  - To ensure nodes are properly linked, I made sure that the right/left event number of each line/event matches the event number of the nodes that it was linked to. I ran my program and played through the game to make sure that the chosen paths correctly resulted in the next event popping up.
- Any challenges faced while handling file input?  
  - I faced an issue where the game would have a SIGSEV error when the user input a non-integer value. To fix this, I implemented a file using line '#include <limits>' which allowed for my program to check if user input was not an integer. It would address this issue and then allow the player to input one of the two options presented to them.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
One debugging challenge that I faced was a logical one where I would run my game, but the options presented to the user, 
would not let the game progress when inputted. It would only progress when I inputted the event number of a grandchild node. 
I looked into the function that constructed the binary search tree and notices that I had written "currNode -> left -> data.leftEventNumber" which would go to the current nodes, 
left child, and get the value of that node's left child. This was the cause of why my game would only progress when the value of the grandparent node was inputted. 
I fixed this by removing the pointer to the node's left child so that it accurate retrieves the data of the child, not the grandchild.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
A zombie virus breaks out! You go to your garage and see your car and bike. Choose (2) for car or (3) for bike.
Enter your choice: 2
You take your car and spot your neighbor a couple of blocks ahead. Choose (4) to take him or (5) to leave him.
Enter your choice: 4
You take your neighbor and find out he's been infected! He attacks you. Choose (8) to fight back or (9) to run.
Enter your choice: 8
You thought you could beat a zombie? You die... Enter (-1) to end game.
Enter your choice: -1
You have completed the game! You can play again with different choices!

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  
  - O(n): The program needs to iterate through each node that is held in the vector to properly link them in the style of a binary search tree.
- **Searching for an event in the tree** → `O(?)`  
  - O(logn): The tree can be halved each time to quickly find a specific event in the tree.
- **Game traversal efficiency** → `O(?)`  
  - O(n): Since during traversal, nearly every node except for one would be visited once. My tree is also slightly imbalanced which would lead to a longer traversal efficiency.
---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
One edge case I tested was one where the root was null. If this was the case, the program would not be able to continue and would output that the story had not been loaded from the text file.

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)
- Although it has been commented out, I created a function in the main.cpp file that would serve as a test for my function that loaded the story
into a BST from the text file. It is a recursive function that prints out each node in the binary tree by pre-order traversal. 
- In the GameDecisionTree file, I created a helper function that allows the program to go through the different events of the story via recursion.
Since the provided function did not take any arguments, I had to make this helper function to perform the recursive pathing.

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
