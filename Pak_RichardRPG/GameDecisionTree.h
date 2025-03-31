#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T> *root;

public:
    //Node<T> *root;
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Could not open file " << filename << std::endl;
            return;
        }
        std::string line;
        std::string text;
        std::vector<Node<Story>*> storyList;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            Story story;

            if (std::getline(ss, line, delimiter)) {
                story.eventNumber = std::stoi(line);
            }
            if (std::getline(ss, line, delimiter)) {
                story.description = line;
            }
            if (std::getline(ss, line, delimiter)) {
                story.leftEventNumber = std::stoi(line);
            }
            if (std::getline(ss, line)) {
                story.rightEventNumber = std::stoi(line);
            }
            Node<Story> *newNode = new Node<Story>(story);
            storyList.push_back(newNode);
        }
        for (int i = 0; i < storyList.size(); i++) {
            Node<Story> *currNode = storyList[i];
            if (i == 0) {
                root = currNode;
            }
            if (currNode != nullptr) {
                if (currNode -> data.leftEventNumber != -1) {
                    int leftEventNumber = currNode -> data.leftEventNumber;
                    currNode -> left = storyList[leftEventNumber - 1];
                }
                if (currNode -> data.rightEventNumber != -1) {
                    int rightEventNumber = currNode -> data.rightEventNumber;
                    currNode -> right = storyList[rightEventNumber - 1];
                }
            }
        }
        file.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (root == nullptr) {
            std::cout << "Story Not Loaded" << std::endl;
            return;
        }
        playGameRecursive(root);
        cout << "You have completed the game! You can play again with different choices!" << endl;
    }
    void playGameRecursive(Node<Story> *currNode) {
        int playerChoice;
        std::cout << currNode -> data.description << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> playerChoice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (playerChoice == -1) {
            return;
        }
        else if (playerChoice != currNode -> data.leftEventNumber && playerChoice != currNode -> data.rightEventNumber) {
            cout << "Please enter one of the two choices!";
            playGameRecursive(currNode);
            return;
        }
        else {
            if (playerChoice == currNode -> data.leftEventNumber) {
                currNode = currNode -> left;
            }
            else {
                currNode = currNode -> right;
            }
            playGameRecursive(currNode);
        }
    }
};

#endif // GAMEDECISIONTREE_H