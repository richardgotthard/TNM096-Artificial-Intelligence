#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <chrono>

using namespace std;
bool h1 = true;
struct Node
{   
    Node* parent;
   
    int mat[3][3]; //current state
    int x, y; // blank tile coordinate
    int cost; //cost
    int level; //depth
    int f;
};
void printMatrix(int mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    
}

Node* newNode(int mat[3][3], int x, int y, int newX,
    int newY, int level, Node* parent)
{
    Node* node = new Node;

    node->parent = parent;
    memcpy(node->mat, mat, sizeof node->mat);

    //swap tile
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->cost = INT_MAX;
    node->level = level;
    node->x = newX;
    node->y = newY;

    return node;
}

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 }; 


int calculateCost( int initial[3][3], int final[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    //return f(s) = c(s) + h(s)
    return count;
}

int calculateManhattanCost(Node* lhs, Node* rhs, int initial[3][3], int final[3][3])
{



    int sum = 0;
    
    int goalRow;
    int goalColumn;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            for (int goalRow = 0; goalRow < 3; goalRow++)
                for (int goalColumn = 0; goalColumn < 3; goalColumn++){
                    if (initial[i][j] && initial[i][j] == final[goalRow][goalColumn]) {
                        sum = sum + abs(i - goalRow) + abs(j - goalColumn);
                        break;
                    }
                }
          
            
        }

                //return f(s) = c(s) + h(s)}


    return sum;

}


int getF(const Node* node) {
    return node->level + node->cost;
}

int validSwap(int x, int y)
{
    return (x >= 0 && x < 3&& y >= 0 && y < 3);
}

void printPath(int &counter, Node* root)
{
    if (root == nullptr)
        return;
    printPath(counter, root->parent);
    printMatrix(root->mat);
    counter++;

std::cout << "\n";
}

bool isSameMatrix(const int initial[3][3], const int final[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (initial[i][j] && initial[i][j] != final[i][j]) { return false; }

    //return f(s) = c(s) + h(s)
    return true;
}
bool isMember(const Node* lhs, const vector<Node*> closedList)
{   
    for (int i = 0; i < closedList.size(); i++) {
        if (isSameMatrix(lhs->mat, closedList[i]->mat)) {
            return true;
        }
    };
    return false;
};

struct compareT {
    bool operator()(const Node* a, const Node* b) {

        return getF(a) > getF(b);
    }
};





void solve(int initial[3][3], int x, int y,int finalX,int finaly,
    int final[3][3])
{   
    priority_queue<Node*, vector<Node*>, compareT> openList;
    vector<Node*> closedList;

    Node* start = newNode(initial, x, y, x, y, 0, nullptr);
    Node* goal = newNode(final, finalX, finaly, finalX, finaly, 0, nullptr);

    if (h1 == true) {
        start->cost = calculateCost(initial, final);

    }
    else {
        start->cost = calculateManhattanCost(start, goal, initial, final);


    }
    //start->cost = calculateManhattanCost(start->x, start->y, final->x,final->y);
    openList.push(start);


    int counter = 0;
    while (!openList.empty())
    {
        // •Remove node n with the smallest value of f(n) from OPEN and move it to list CLOSED.
      
        Node* min = openList.top();
        closedList.push_back(min);
        openList.pop();
       
        


        // if min is an answer node
        if (min->cost == 0)
        {

            // print the path from root to destination;
            printPath(counter, min);
            cout << "\n Steps: " << counter-1 << "\n";

            return;
        }
       
        //Expand children
        for (int i = 0; i < 4; i++)
        {
            //int row[] = { 1, 0, -1, 0 };
            //int col[] = { 0, -1, 0, 1 };
            if (validSwap(min->x + row[i], min->y + col[i]) )
            {
                
                
                Node* child = newNode(min->mat, min->x,
                    min->y, min->x + row[i],
                    min->y + col[i],
                    min->level + 1, min);

                if (h1 == true) {
                    child->cost = calculateCost(child->mat, final);

                }
                else {
                    child->cost = calculateManhattanCost(child, goal, child->mat, final);
                }
                if(!isMember(child, closedList)){
                    openList.push(child);
                }

               
            }
        }
    }
}

int main()
{   
    chrono::steady_clock sc;   // create an object of `steady_clock` class
    auto start = sc.now();     // start timer
    
    int initial[3][3] =
    {
        {5, 6, 7},
        {4, 0, 8},
        {3, 2, 1}
    };
    int x = 1, y = 1; //initial blank

    
    int final[3][3] =
    {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };
    int finalX = 1, finaly = 1;

    solve(initial, x, y, finalX, finaly, final);
    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast<chrono::duration<double> >(end - start);   // measure time span between start & end
    cout << "Operation took: " << time_span.count() << " seconds !!!";

    return 0;
}

