#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class Obj>
void printStack(stack<Obj>leStack){
	stack<int> temp;
	while (!leStack.empty()){
		temp.push(leStack.top());
		leStack.pop();
	}
	while (!temp.empty()){
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

bool gameOver(stack<int>stack1, stack<int>stack2, stack<int>stack3){
	if (stack1.empty()){
		if (stack2.empty()){
			if (!stack3.empty()){
				cout << "You won!" << endl;
				return true;
			}
		}
	}
	return false;
}

bool movable(int first, int second){
	if (first < second){
		cout << "Moved " << endl;
		return true;
	}
	cout << "Unmovable" << endl;
	return false;
}
void move(stack<int>&stack1, stack<int>&stack2){
	if (stack1.empty()){
		cout << "There is no ring here" << endl;
		return;
	}
	int first = stack1.top();
	if (stack2.empty()){
		stack1.pop();
		stack2.push(first);
	}
	else{
		if (movable(first, stack2.top())){
			//Move ring to stack
			stack1.pop();
			stack2.push(first);
		}
	}
}


int main(){
	stack<int>stack1;
	stack<int>stack2;
	stack<int>stack3;
	stack1.push(6);
	stack1.push(5);
	stack1.push(4);
	stack1.push(3);
	stack1.push(2);
	stack1.push(1);
	int first, second;
	cout << "Welcome to the 99 cent (probably even less) version of Towers of Hanoi" << endl;
	cout << "Please input two numbers, one at a time. " << endl << "The first number is the disk in the stack you're moving from. The second is where you move it to. " << endl;

	while (!gameOver(stack1, stack2, stack3)){
		cout << "=========================" << endl;
		cout << "STACK ONE: ";
		printStack(stack1);
		cout << "STACK TWO: ";
		printStack(stack2);
		cout << "STACK THREE: ";
		printStack(stack3);

		cout << "First: ";
		cin >> first;
		cout << "Second: ";
		cin >> second;
		if (first == 1){
			if (second == 2){
				move(stack1, stack2);
			}
			else if (second == 3){
				move(stack1, stack3);
			}
		}
		else if (first == 2){
			if (second == 1){
				move(stack2, stack1);
			}
			else if (second == 3){
				move(stack2, stack3);
			}
		}
		else{
			if (second == 1){
				move(stack3, stack1);
			}
			else if (second == 2){
				move(stack3, stack2);
			}
		}

	}
	cout << "STACK ONE: ";
	printStack(stack1);
	cout << "STACK TWO: ";
	printStack(stack2);
	cout << "STACK THREE: ";
	printStack(stack3);

	system("pause");
	return 1;
}
