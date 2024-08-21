/* ToDo List 
    Author: Muhammad Salim
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cout <<"Welcome to the Todo List application"<<endl;
    cout<<"Choose from the following commands from below"<<endl; //user options
    cout<<"C: Create a task"<<endl;
    cout<<"D: Delete a task"<<endl;
    cout<<"S: Show Todo List"<<endl;
    cout<<"Q: Quit application"<<endl;

    char userChoice;
    cout<<"Type Choice"<<endl;
    cin>>userChoice;
    userChoice = toupper(userChoice);
    vector<string> taskVector; //creates vector for task storage

    while (userChoice != 'Q'){
        if (userChoice == 'C'){
            cout<<"Type your task."<<endl;
            string userTask;
            cin.ignore();
            getline(cin, userTask);
            taskVector.push_back(userTask);
        }
        else if (userChoice == 'S'){
            if (taskVector.size() == 0){ //empty list
                cout<<"Your list is empty. "<<endl;
                cout<<"You must create a task first. "<<endl;
            }
            for (int i =1; i <= taskVector.size(); i++){
                cout<<i<<": "<<taskVector.at(i-1)<<endl;
            }
        }
        else if (userChoice == 'D'){
            if (taskVector.size() == 0){ //empty list 
                cout<<"Your list is empty. "<<endl;
                cout<<"You must create a task first. "<<endl;
            }
            else{
                cout<<"Pick what number task you would like to delete."<<endl;
                cout<<endl;
                for (int i =1; i <= taskVector.size(); i++){
                    cout<<i<<": "<<taskVector.at(i-1)<<endl;
                }
                int deleteTask;
                cout<<"Task Number To Delete: "<<endl;
                cin>>deleteTask;
                while (deleteTask < 1 || deleteTask > taskVector.size()){ //task number out of range
                    cout<<"No task exists. Please pick another number."<<endl;
                    cin>>deleteTask;
                }
                taskVector.erase(taskVector.begin() + (deleteTask - 1));
                cout<<"Your task has been deleted."<<endl;
            }

        }
        cout<<"Type New Choice."<<endl;
        cin>>userChoice;
        userChoice = toupper(userChoice);
    }
    return -1;

}