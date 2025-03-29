#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
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
            std::string token;
            Story story;

            if (std::getline(ss, token, delimiter)) {
                story.eventNumber = std::stoi(token);
            }
            if (std::getline(ss, token, delimiter)) {
                story.description = token;
            }
            if (std::getline(ss, token, delimiter)) {
                story.leftEventNumber = std::stoi(token);
            }
            if (std::getline(ss, token)) {
                story.rightEventNumber = std::stoi(token);
            }
            Node<Story> *newNode = new Node<Story>(story);
            storyList.push_back(newNode);
        }
        for (int i = 0; i < storyList.size(); i++) {
            Node<Story> *currNode = storyList[i];
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
        root = storyList[0];
        file.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (root == nullptr) {
            std::cout << "Story Not Loaded" << std::endl;
            return;
        }
        Node<Story> *currNode = root;
        std::cout << currNode -> data.description << "Which path do you choose" <<
    }

    void playGameHelper(Node<Story> *currNode) {

    }
};

#endif // GAMEDECISIONTREE_H