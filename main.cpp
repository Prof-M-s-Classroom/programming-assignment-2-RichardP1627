#include <iostream>
#include <string>
#include "GameDecisionTree.h"
using namespace std;
/* void recursivePrint(Node<Story> *node) {
    if (node != nullptr) {
        cout << node -> data.eventNumber << ", " << node -> data.description << ", " << node -> data.leftEventNumber << ", " << node -> data.rightEventNumber << endl;
        recursivePrint(node->left);
        recursivePrint(node->right);
    }
} */

int main() {
    GameDecisionTree<Story> myGame;

    string filename = "story.txt";  // Specify the input file
    char delimiter = '|';                // '|' is the delimiter, change if needed

    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    //Node<Story> *currNode = myGame.root;
    //recursivePrint(currNode);
    // Start the game
    myGame.playGame();

    return 0;
}