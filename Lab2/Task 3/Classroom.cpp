 

 #include <iostream>
 #include <string>
 #include <vector>

 using namespace std;
 
 /*

This task is about to write an implementation of Min-Conflicts to solve the problem below.
You can use any programming language.
Classroom Scheduling
You are in charge of assigning classes to classrooms and times. You have to schedule three
classrooms: TP51, SP34 and K3. Classes start on the hour. You can only assign classes to the
hours of:
9 am 10 am 11 am
12 pm 1 pm 2 pm 3 pm 4 pm


You must schedule 22 classes:
MT101 MT102 MT103 MT104 MT105 MT106 MT107
MT201 MT202 MT203 MT204 MT205 MT206
MT301 MT302 MT303 MT304
MT401 MT402 MT403
MT501 MT502

Your schedule must not violate any of the following requirements:
1. Two classes cannot meet in the same classroom at the same time.
2. Classes whose first digit are the same (like MT102 and MT107) cannot be scheduled at
the same time because students might take them both in one semester. There is one
exception to this rule; MT501 and MT502 can be scheduled at the same time since
students can only take one of them.
Write a display function that prints the schedule you have computed.

TP51 SP34 K3
- - - - - - - - - - - -
9 MT101
10 MT205 MT303 MT402
11 MT201 MT304 MT107
12 MT202 MT102 MT302
1 MT502 MT206 MT105
2 MT204 MT104 MT501
3 MT106 MT301 MT403
4 MT401 MT203 MT103


*/

class ScheduleSolver{
    public: 

    ScheduleSolver(vector<string> classes_, vector<string> timeslots_, vector<string> classrooms_) : classes_{classes}, timeslots_{timeslots}, classrooms_{classrooms} {};

    size_t numClasses(){return classes.size()};
    size_t numClassrooms(){return classrooms.size()};
    size_t numTimeslots(){return timeslots.size()};


    // 1. Two classes cannot meet in the same classroom at the same time.
    //  2. Classes whose first digit are the same (like MT102 and MT107) cannot be scheduled at the same time because students might take them both in one semester. 
    // There is one exception to this rule; MT501 and MT502 can be scheduled at the same time since students can only take one of them.

    //pseudo kod 

    /*
    void print_Schedule(){

        for( string n: classrooms){
            cout << n << " ";
        }

        cout << "- - - - - - - - -" << endl;

        for(int i = 0; i < timeslots.size(); i++)
        {
            cout << timeslots[i];

            for (int j = 0; j < classes[i].size(); j++){

                cout << classes[i][j] << " ";
            }

        }

        }
    */
        


    


    private:

     vector<string> classrooms;
     vector<string> timeslots;
     vector<string> classes;


};
 

 int main(){

     //ScheduleSolver()

    

    // input : timeslots {"9 am", "10 am", "11 am", "12 pm", "1 pm", "2 pm", "3 pm", "4 pm"};

    // input : classes {"MT101", "MT102", "MT103", "MT104", "MT105", "MT106", "MT107", "MT201", "MT202", "MT203", "MT204", "MT205", "MT206", "MT301", "MT302", "MT303", "MT304", "MT401", "MT402", "MT403", "MT501","MT502"};

    // input : classrooms{"TP51", "SP34", "K4"}





     cout << "hello" << endl;


return 0;

 }