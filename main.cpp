#include "node.h"
#include "quee.h"
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

void push(Node* &head, char value);
char peek(Node* top);
void enqueue(Queue* &front, Queue* &tail, char value);
void printQueue(Queue* top);

int main() {
  Node* head = NULL;
  Queue* front = NULL;
  Queue* tail = NULL;
  char input[200];
  cout << "enter in your equation" << endl;
  cin.getline(input, 200);
  char tempArray[200];
  int count = 0;
  for (int i = 0; i <strlen(input); i++) {
    if (input[i] != ' ') {
      tempArray[count] = input[i];
      count++;
    }
  }
  for (int i = 0; i <strlen(input); i++) {
    input[i] = tempArray[i];
  }
  for (int i = 0; i < strlen(input); i++) {
    if (isdigit(input[i])) {
	cout << "it is a digit" << endl;
	char a = input[i];
	enqueue(front, tail, a);
	printQueue(front);
    }
    else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '(' || input[i] == ')' || input[i] == '^') {
      cout << "Is an operation" << endl;
      char a = input[i];
      push(head, a);
      cout << peek(head) << endl;
    }
  }
}

void push(Node* &head, char value) {
  Node* temp = new Node();
  temp->value = value;
  temp->next = head;
  head = temp;
}

void pop() {

}

char peek(Node* top) {
  if (top == NULL) {
    cout << "Nothng in stack" << endl;
  }
  else {
    return top->value;
  }
}

void enqueue(Queue* &front, Queue* &tail, char value) {
  Queue* temp = new Queue();
  temp->value = value;
  temp->next = NULL;
  if (front == NULL) {
    front = temp;
    tail = front;
  }
  else {
    tail->next = temp;
    tail = temp;
  }
}

void printQueue(Queue* top) {
  Queue* curr = top;
  while (curr != NULL) {
    cout << curr->value << " ";
    curr = curr->next;
  }
  cout << endl;
}
