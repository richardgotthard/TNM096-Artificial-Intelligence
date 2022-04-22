import sys
import copy
import random



class Schedule():
    def __init__(self, state:[],  classroom_size:int, timeslot_size:int, classrooms:[], timeslots:[]):
        self.state = state
        self.timeslot_size = timeslot_size
        self.classroom_size = classroom_size
        self.classrooms = classrooms
        self.timeslots = timeslots
        
    def print_state(self):
        counter = 0
        print(self.classrooms)
        for i in range(self.timeslot_size):
                print()
                print(self.timeslots[i], end=" ")
                for j in range(self.classroom_size):
                    print(self.state[counter], end=" ")
                    counter = counter + 1
        print()

    def min_conflicts(self, max_steps:int=1):
        for i in range(100):
            #if((i + 1)%10 == 0):
                #print(max_steps-1-1)

            conflicts = []
            counter = 0
            conflict_count = 0
            for row in range(self.timeslot_size):
                #print("row", row)
                for column in range(self.classroom_size):
                    if(self.is_in_conflict(row,column)):
                         conflict_count = conflict_count +1
                         conflicts.append(self.state[counter])
                    counter = counter + 1

            print(conflict_count)
            print(conflicts)

            if(conflict_count == 0):
                return


            #Pick random value from conflicts
            indexT = random.randint(1, len(conflicts))
            conflict_value = conflicts[indexT]
            print(conflict_value)
            print(self.state.index(conflict_value))

            #indexString = self.state.index(indexT)

            #1. Loop through all spots
                #2. Is the spot valid?
                #3. If true calculate the total conflict
                #4. If lower conflict then previous we have a new minimum
            #5 Swap the index with spot that give smallest conflict


            smallest_conflict = 1000
            temp = self.state
            swap_row_index = 0
            swap_column_index = 0
            for row in range(self.timeslot_size):
                # print("row", row)
                for column in range(self.classroom_size):
                    print(conflict_count)

                    if(conflict_count < smallest_conflict):
                        smallest_conflict = conflict_count
                        swap_row_index=row
                        swap_column_index=column
                        swap_classroom = self.state[column+row*3]
                    #Trying to swap the random
                    #print("Before")
                    self.print_state()
                    self.state = temp
                    swap_index = self.state.index(conflict_value)
                    self.state[swap_index] = self.state[row*3 + column]
                    self.state[row*3+column] = conflict_value
                    print("After")

                    self.print_state()


                    for rowX in range(self.timeslot_size):
                        print("row", conflict_count)
                        for columnX in range(self.classroom_size):
                            if self.is_in_conflict(rowX, columnX):
                                conflict_count = conflict_count + 1
                                conflicts.append(self.state[counter])
                            counter = counter + 1
            print(swap_classroom)



        #self.is_in_conflict(index/3, index % 3)
            #Test what value that result in least conflict

            #Switch with value that result in lowest conflicts


    def is_in_conflict(self,row:int, column:int):
        #col 0 1 2
        row = row*3
        if(column == 2):
            if(self.state[row][2] != self.state[row+column][2] or self.state[row+1][2] != self.state[row+column][2] or (self.state[row+column][2] == 5)):
                return False
        if(column == 1):
            if(self.state[row][2] != self.state[row + column][2] or self.state[row + 2][2] != self.state[row + column][2] or (self.state[row + column][2] == 5)):
                return False
        if (column == 0):
            if(self.state[row+2][2] != self.state[row + column][2] or self.state[row + 1][2] !=
                self.state[row + column][2] or (self.state[row + column][2] == 5)):
                return False

        return True



def main():
    #Input
    #MT101 MT102 MT103 MT104 MT105 MT106 MT107
    #MT201 MT202 MT203 MT204 MT205 MT206
    #MT301 MT302 MT303 MT304
    #MT401 MT402 MT403
    #MT501 MT502

    #Output
    # TP51  SP34   K3
    #9 ""    ""    MT101
    #10 MT205 MT303 MT402
    #11 MT201 MT304 MT107
    #12 MT202 MT102 MT302
    #1 MT502 MT206 MT105
    #2 MT204 MT104 MT501
    #3 MT106 MT301 MT403
    #4 MT401 MT203 MT103

    data = '"5555" "5555" MT101 MT102 MT103 MT104 MT105 MT106 MT107 MT201 MT202 MT203 MT204 MT205 MT206 MT301 MT302 MT303 MT304 MT401 MT402 MT403 MT501 MT502'
    print(data)
    classrooms_size = 3  #TP51, SP34, K3
    timeslots_size = 8 #9, 10 ,11, 12 ,1 ,2 ,3 ,4
    classrooms = 'TP51 SP34 K3'
    timeslots = '9 10 11 12 1 2 3 4'
    max_steps = 200000

    initial_state = []
    classrooms_state = []
    timeslots_state = []
    initial_state = data.split()
    classrooms_state = classrooms.split()
    timeslots_state = timeslots.split()
    row = []
    counter = 0

    schedule  = Schedule(initial_state, classrooms_size, timeslots_size, classrooms_state, timeslots_state)
    schedule.print_state()
    finish = schedule.min_conflicts(max_steps)
    #schedule.print_state()

if __name__ == "__main__": main()
