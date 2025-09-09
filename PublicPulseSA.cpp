/*
Sol Plaatje University
Introduction to Data Structures
Tracking and Maintenance of public infrastructure - Pothole & Road Damage Maintenance Planner

Group Leader:
=======================================
Unathi Spele 202517137
=======================================
Members:
=======================================
Nvula Bontes 202546741
Ncedo Ncabane 202449697
Oabile Mokhuane 202552357
Gofaone Myataza 202582174
Phathutshedzo Michelle Mahada 202524881
Sean Jayden Cupido 202541801
Jerusalem Kinfe Sarero 202566209
Nombulelo Sharlot Mahlangu 202204412
Chinwendu Lena Anthony 202572205
Katlego Mmusi  202589538
Busisiwe Tyhokolo 202416885
Nombulelo Angela Nkambule 202402946
Kgakgelo Maggie Dolo 202575611
Nthabiseng Chabalala 202552083
========================================
*/
#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include <limits>
#include <stack>

using namespace std;

struct Pothole 
{
    int id;
    string location;
    string address;
    string severity;
    int severityValue;
    string problemType;
    string status; 
    string userFirstName; 
    string userLastName;
};
// GLOBAL VARIABLES0
//=========================================================================
queue<Pothole> reportQueue;
stack<Pothole> undoStack;
int nextId = 1;
const int regionCount = 4;
const int maxTowns = 21;
string northernCape[regionCount][maxTowns] = {
    { "1. Barkly West", "2. Campbell", "3. Delportshoop", "4. Douglas", "5. Griquatown", "6. Hartswater", "7. Jan Kempdorp", "8. Kimberley", "9. Wlistenton", "10. Windsorton"},
    { "1. Andriesvale", "2. Askham", "3. Augrabies", "4. Danielskuil", "5. Groblershoop","6. Kakamas", "7. Kanoneiland", "8. Kathu", "9. Keimoes", "10. Kenhardt", "11. Kuruman",
      "12. Lime Acres", "13. Louisvale", "14. Mier", "15. Olifantshoek", "16. Onseepkans","17. Postmasburg", "18. Putsonderwater", "19. Riemvasmaak", "20. Rietfontein","21. Upington" },
    { "1. Aggeneys", "2. Alexander Bay", "3. Carolusberg", "4. Concordia", "5. Garies","6. Hondeklip", "7. Kamieskroon", "8. Kleinzee", "9. Nababeep","10. Nieuwoudtville",
      "11. Okiep", "12. Pella", "13. Pofadder", "14. Port Nolloth", "15. Soebatsfontein","16. Springbok", "17. Steinkopf"},
    { "1. Britstown", "2. Colesberg", "3. Copperton", "4. De Aar", "5. Hanover", "6. Hopetown","7. Hutchinson", "8. Loxton", "9. Marydale", "10. Norvalspont",
      "11. Noupoort", "12. Orania","13. Petrusville", "14. Philipstown", "15. Prieska", "16. Richmond", "17. Strydenburg","18. Vanderkloof", "19. Victoria West", "20. Vosburg" }
};
int townsPerRegion[regionCount] = { 10, 21, 17, 20 };
//=========================================================================
//DOUBLY LINKED LIST - ADMIN SIDE
//=========================================================================
struct CompletedNode 
{
    Pothole data;
    CompletedNode* prev;
    CompletedNode* next;
};

class CompletedRepairs 
{
public:
    CompletedNode* head;
    CompletedNode* tail;

    CompletedRepairs() : head(NULL), tail(NULL) {}

    // Add a completed pothole to the list
    void addCompleted(Pothole pothole) {
        CompletedNode* node = new CompletedNode{pothole, NULL, NULL};
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    // Display completed repairs
    void display() {
        if (!head) 
        {
            cout << "\nNo completed repairs - The streets are still plotting your demise.\n";
            return;
        }

        cout << "\n   Completed Repairs:   \n";
        CompletedNode* temp = head;

        while (temp) 
        {
            cout << "ID: " << temp->data.id << ", Problem: " << temp->data.problemType << ", Location: " << temp->data.location << ", Address: " << temp->data.address << ", Severity: " << temp->data.severity << ", Status: " << temp->data.status << "\n";
            temp = temp->next;
        }
    }
};
CompletedRepairs completedList;
//=========================================================================
//SEARCH FUNCTIONS - LINEAR AND BINARY SEARCH - USER AND ADMIN SIDE
//=========================================================================
// Linear Search - goes through reports one by one to find matching ID
// works with unsorted data, checks each element until it finds match
int linearSearchByID(int searchID) 
{
    if(reportQueue.empty()) 
    {
        cout << "\nNo reports available to search.\n";
        return -1;
    }
    
    queue<Pothole> temp = reportQueue;
    int position = 0;
    
    cout <<"\n-----------------------------";
    cout << "\nLinear Search Progress:\n";
    cout <<"-----------------------------\n";
    while(!temp.empty()) 
    {
        Pothole current = temp.front();
        temp.pop();
        cout << "Checking position " << position << " - ID: " << current.id;
        
        if(current.id == searchID) 
        {
            cout << " INFORMATION FOUND!\n";
            cout << "\nReport Details:\n";
            cout << "ID: " << current.id << ", Location: " << current.location << ", Address: " << current.address << ", Problem: " << current.problemType << ", Severity: " << current.severity << "\n";
            return position;
        }
        cout << "Not found, keep searching.\n";
        position++;
    }
    
    cout << "\nReport with ID " << searchID << " not found in pending reports.\n";
    return -1;
}
// Binary Search - splits the search area in half each time to find target
// way faster than linear search but data must be sorted first
int binarySearchBySeverity(Pothole sortedListay[], int size, int targetSeverity) 
{
    int left = 0;
    int right = size - 1;
    int foundIndex = -1;
    
    cout <<"\n-----------------------------";
    cout << "\nBinary Search Progress - looking for severity [ " << targetSeverity << "]:\n";
    cout <<"-----------------------------\n";
    while(left <= right) 
    {
        int mid = left + (right - left) / 2;
        cout << "Checking middle position " << mid << " - Severity: " << sortedListay[mid].severityValue;
        
        if(sortedListay[mid].severityValue == targetSeverity) 
        {
            cout << " INFORMATION FOUND!\n";
            foundIndex = mid;
            break;
        }
        else if(sortedListay[mid].severityValue < targetSeverity) 
        {
            cout << " Too low, search right side\n";
            left = mid + 1;
        }
        else 
        {
            cout << " Too high, search left side\n";
            right = mid - 1;
        }
    }
    
    if(foundIndex != -1) 
    {
        cout <<"\n-----------------------------";
        cout << "\nFound report with matching severity:\n";
        cout << "ID: " << sortedListay[foundIndex].id << ", Location: " << sortedListay[foundIndex].location << ", Address: " << sortedListay[foundIndex].address << ", Problem: " << sortedListay[foundIndex].problemType << ", Severity: " << sortedListay[foundIndex].severity << "\n";
        cout <<"-----------------------------\n";
        return foundIndex;
    }
    
    cout<< "\nNo report found with severity level " << targetSeverity << ".\n";
    return -1;
}

void searchReportsMenu() 
{
    if(reportQueue.empty()) 
    {
        cout << "\nNo reports available for searching!\n";
        return;
    }
    
    int choice;
    cout << "\nSearch Options:\n";
    cout << "========================================\n";
    cout << "1. Linear Search by Report ID\n2. Binary Search by Severity Level\n";
    cout << "========================================\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if(choice == 1) 
    {
        int searchID;
        cout << "Enter Report ID to search for: ";
        cin >> searchID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        linearSearchByID(searchID);
    }
    else if(choice == 2) 
    {
        // need to sort the data first for binary search to work
        Pothole list[reportQueue.size()];
        int size = reportQueue.size();
        queue<Pothole> tempQ = reportQueue;
        for(int i=0;i<size;i++)
        {
            list[i] = tempQ.front();
            tempQ.pop();
        }
        
        // sort using bubble sort 
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-i-1;j++){
                if(list[j].severityValue > list[j+1].severityValue) 
                {
                    Pothole temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }
            }
        }
        
        int targetSeverity;
        cout << "Enter severity level to search [1 = Low, 2 = Medium, 3 = High]: ";
        cin >> targetSeverity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(targetSeverity >= 1 && targetSeverity <= 3) 
        {
            binarySearchBySeverity(list, size, targetSeverity);
        } 
        else 
        {
            cout << "Invalid severity level!\n";
        }
    }
    else 
    {
        cout << "Invalid choice!\n";
    }
}
//=========================================================================
//USER PORTAL FUNCTIONS
//=========================================================================
//User Issues - User Menue
//=========================================
void displayRegions() 
{
    cout <<"\n                                         ==========================================\n";
    cout << "\n                                             REGIONS IN NOTHERN CAPE: \n\n";
    cout <<"                                         ==========================================\n";
    cout << "\n\n---------------------------------------------------------------------------------------------------------------------------\n";
    cout << left << setw(25) << "Diamond Fields" << setw(25) << "Green Kalahari" << setw(25) << "Namaqualand" << setw(25) << "Upper Karoo";
    cout << "\n\n---------------------------------------------------------------------------------------------------------------------------\n";

    int maxRows = 0;
    for(int index = 0; index < regionCount; index++)
        if(townsPerRegion[index] > maxRows) maxRows = townsPerRegion[index];

    for(int row=0; row<maxRows; row++) {
        for(int column=0; column<regionCount; column++) {
            if(row < townsPerRegion[column])
                cout << setw(25) << northernCape[column][row];
            else
                cout << setw(25) << " ";
        }
        cout <<'\n';
    }
}

int selectRegion()
{
    int regionChoice;
    while (true)
    {
        cout << "-------------------------------------------------------------------------\n";
        cout << "SELECT THE REGION: \n";
        cout << "=========================================================================\n";
        cout << "1. Diamond Fields \n2. Green Kalahari \n3. Namaqualand \n4. Upper Karoo\n";
        cout << "=========================================================================\n";
        cout << "Choice: ";

        if (!(cin >> regionChoice) || regionChoice < 1 || regionChoice > 4)
        {
            cout << "Invalid choice! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return regionChoice - 1;
    }
}

string selectTown(int regionIndex) 
{
    int choice;
    while (true)
    {
        cout << "---------------------------------------------------------------\n";
        cout << "Select town number within the region (1-" << townsPerRegion[regionIndex] << "): ";
        if (!(cin >> choice) || choice < 1 || choice > townsPerRegion[regionIndex])
        {
            cout << "Invalid choice! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n---------------------------------------------------------------\n";
        return northernCape[regionIndex][choice-1];
    }
}

//CHECK FOR DUPLICATES - Addresses
bool isDuplicateReport(const string& location, const string& address)
{
    // Check pending reports queue
    queue<Pothole> tempQueue = reportQueue;
    while (!tempQueue.empty())
    {
        Pothole p = tempQueue.front();
        tempQueue.pop();
        if (p.location == location && p.address == address)
        {
            return true; // Duplicate found
        }
    }

    // Check completed repairs list
    CompletedNode* tempNode = completedList.head;
    while (tempNode != NULL)
    {
        if (tempNode->data.location == location && tempNode->data.address == address)
        {
            return true; // Duplicate found
        }
        tempNode = tempNode->next;
    }

    return false; // No duplicates
}

void addReport() 
{
    Pothole p;
    p.status = "Pending";
    p.id = nextId++;

    cout << "Enter your First Name: ";
    getline(cin, p.userFirstName);
    cout << "Enter your Surname: ";
    getline(cin, p.userLastName);

    displayRegions();

    int regionIndex = selectRegion();
    string townChoice = selectTown(regionIndex);
    p.location = townChoice;

    cout << "Enter exact address [street name]: ";
    getline(cin, p.address);

    //checks for duplicates
    if (isDuplicateReport(p.location, p.address))
    {
        cout << "\n---------------------------------------------------------------\n";
        cout << "This address already has an existing report. Please choose a different address.\n";
        cout << "---------------------------------------------------------------\n";
        return; // Stop execution without incrementing nextId
    }

    p.id = nextId++;

    cout << "Enter the problem Type on the road [Pothole, Road Crack, Pipe Burst, etc.]: ";
    getline(cin,p.problemType);

    int severityChoice;
    do
    {
        cout << "\n---------------------------------------------------------------\n";
        cout << "Enter severity level:\n1. Low \n2. Medium \n3. High\n";
        cout << "\n===============================================================\n";
        cout << "Choice: ";
        if (!(cin >> severityChoice) || severityChoice < 1 || severityChoice > 3)
        {
            cout << "Invalid input! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
        p.severity = (severityChoice==1)?" Low ":(severityChoice==2?" Medium ":" High ");
        p.severityValue = severityChoice;
        break;
    } 
    while(true);

    reportQueue.push(p);

    cout << "\nReport was submitted successfully!\n";
    cout << "NUMERICAL - Report ID: " << p.id << " [Keep this ID to check status later]\n";
    cout << "ID: " << p.id << ", Location: " << p.location << ", Address: " << p.address << ", Severity: " << p.severity << '\n';
}

void viewReports() 
{
    if(reportQueue.empty() && completedList.head == NULL)
    {
        cout << "\nNo reports were submitted yet.\n";
        return;
    }

    cout << "\nSubmitted Reports:\n";
    //To display reports from the pending queue
    queue<Pothole> tempQueue = reportQueue;

    if (!tempQueue.empty())
    {
        cout << "\nPending Reports:\n";
        while(!tempQueue.empty())
        {
            Pothole p = tempQueue.front();
            tempQueue.pop();
            cout << "ID: " << p.id << ", Name: " << p.userFirstName << " " << p.userLastName << ", Location: " << p.location << ", Address: " << p.address << ", Problem: " << p.problemType << ", Severity: " << p.severity << ", Status: " << p.status <<'\n';
        }
    }

    //To display reports from the completed list
    CompletedNode* tempNode = completedList.head;

    if (tempNode != NULL)
    {
        cout << "\nCompleted Repairs:\n";
        while(tempNode != NULL)
        {
            Pothole p = tempNode->data;
            cout << "ID: " << p.id << ", Name: " << p.userFirstName << " " << p.userLastName << ", Location: " << p.location << ", Address: " << p.address << ", Problem: " << p.problemType << ", Severity: " << p.severity << ", Status: " << p.status <<'\n';
            tempNode = tempNode->next;
        }
    }
}

//Sorting - USER MENUE
//=========================================
int copyQueueTolistay(Pothole list[])
{
    int size = reportQueue.size();
    queue<Pothole> tempQ = reportQueue;
    for(int i=0;i<size;i++){
        list[i] = tempQ.front();
        tempQ.pop();
    }
    return size;
}

void printListStep(Pothole list[], int size) 
{
    for(int i = 0; i < size; i++)
    {
        cout << "[" << list[i].id << " | " << list[i].severity << " | " << list[i].location << "] ";
    }
    cout << "\n";
}

void bubbleSort(Pothole list[], int size) 
{
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(list[j].severityValue > list[j+1].severityValue)
            {
                Pothole temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
            printListStep(list, size);
        }
    }
}

void insertionSort(Pothole list[], int size) 
{
    for(int i=1;i<size;i++){
        Pothole key = list[i];
        int j = i-1;
        while(j>=0 && list[j].severityValue > key.severityValue)
        {
            list[j+1] = list[j];
            j--;
            printListStep(list, size);
        }
        list[j+1] = key;
        printListStep(list, size);
    }
}

void selectionSort(Pothole list[], int size) 
{
    for(int i=0;i<size-1;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<size;j++)
        {
            if(list[j].severityValue < list[minIndex].severityValue)
            {
                minIndex = j;
            }
        }
        Pothole temp = list[i];
        list[i] = list[minIndex];
        list[minIndex] = temp;
        printListStep(list, size);
    }
}

void shellSort(Pothole list[], int size) 
{
    for(int gap=size/2; gap>0; gap/=2)
    {
        for(int i=gap;i<size;i++)
        {
            Pothole temp = list[i];
            int j;
            for(j=i;j>=gap && list[j-gap].severityValue > temp.severityValue;j-=gap)
            {
                list[j] = list[j-gap];    
                printListStep(list, size);
            }
            list[j] = temp;
            printListStep(list, size);
        }
    }
}
//=========================================
void displaySortedReports(Pothole list[], int size) 
{
    cout << "\nSorted Reports by Severity [Low to High]:\n";
    for(int i=0;i<size;i++)
    {
        cout << "ID: " << list[i].id << ", Problem: " << list[i].problemType << ", Severity: " << list[i].severity << ", Location: " << list[i].location << "\n";
    }
}

void sortReportsMenu() 
{
    if(reportQueue.empty())
    {
        cout << "\nNo reports to sort!\n";
        return;
    }

    Pothole list[reportQueue.size()];
    int size = copyQueueTolistay(list);

    int choice;
    cout << "\nChoose Sorting Algorithm:\n";
    cout << "========================================\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Shell Sort\n";
    cout << "========================================\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(choice==1) bubbleSort(list, size);
    else if(choice==2) insertionSort(list, size);
    else if(choice==3) selectionSort(list, size);
    else if(choice==4) shellSort(list, size);
    else  cout << "Invalid choice!\n"; return;

    displaySortedReports(list, size);
}
//=========================================================================
//USER MENUE
//=========================================================================
void userMenu() 
{
    while(true)
    {
        int choice;
        cout << "\nWELCOME TO PUBLICPULSE SA : Where Broken Stuff Meets Accountability - Eventually\n\n";
        cout << "\nUSER PORTAL:\n";
        cout << "========================================\n";
        cout << "1. Submit Fault Report\n2. View Report Status\n3. Sort Reports by Severity\n4. Search Reports\n5. Return to Main Menu\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        if(!(cin >> choice))
        {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(choice == 1) addReport();
        else if(choice == 2) viewReports();
        else if(choice == 3) sortReportsMenu();
        else if(choice == 4) searchReportsMenu();
        else if(choice == 5) return;
        else cout << "Invalid choice.\n";
    }
}
//=========================================================================
//BINARY TREE - ADMIN SIDE
//=========================================================================
struct TreeNode 
{
    Pothole data;
    TreeNode* left;
    TreeNode* right;
};

class PotholeTree 
{
    TreeNode* root;

    // Recursive helper to insert a pothole into the tree based on severityValue
    TreeNode* insert(TreeNode* node, Pothole pothole) 
    {
        if (!node) return new TreeNode{pothole, NULL, NULL};
        if (pothole.severityValue < node->data.severityValue)
            node->left = insert(node->left, pothole);
        else
            node->right = insert(node->right, pothole);
        return node;
    }

    //Inorder traversal
    void inorder(TreeNode* node) 
    {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->data.id << ", Problem: " << node->data.problemType << ", Address: " << node->data.address << ", Severity: " << node->data.severity << ", Location: " << node->data.location << '\n';
        inorder(node->right);
    }

    //Preorder traversal
    void preorder(TreeNode* node) 
    {
        if (!node) return;
        cout << "ID: " << node->data.id << ", Problem: " << node->data.problemType << ", Address: " << node->data.address << ", Severity: " << node->data.severity << ", Location: " << node->data.location << '\n';
        preorder(node->left);
        preorder(node->right);
    }

    //Postorder traversal
    void postorder(TreeNode* node) 
    {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << "ID: " << node->data.id << ", Problem: " << node->data.problemType << ", Address: " << node->data.address << ", Severity: " << node->data.severity << ", Location: " << node->data.location << '\n';
    }
    
    void clearTree(TreeNode* node) 
    {
        if (node) 
        {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }
    
    void buildTreeFromList(CompletedNode* head) 
    {
        clearTree(root);
        root = NULL;
        CompletedNode* temp = head;
        while (temp) 
        {
            insert(temp->data);
            temp = temp->next;
        }
    }

public:
    PotholeTree() : root(NULL) {}

    // Public insert method
    void insert(Pothole pothole) 
    {
        root = insert(root, pothole);
    }

    void displayTraversals() 
    {
        buildTreeFromList(completedList.head);
        if (!root) 
        {
            cout << "\nNo completed reports to build the tree from.\n";
            return;
        }
        cout << "\n Binary Tree Traversals\n";
        cout << "==================================\n";
        cout << "--------------\n";
        cout << "\nInorder [FROM LOW TO HIGH SEVERITY]:\n"; inorder(root);
        cout << "--------------\n";
        cout << "\nPreorder:\n"; preorder(root);
        cout << "--------------\n";
        cout << "\nPostorder:\n"; postorder(root);
        cout << "--------------\n";
    }
};
PotholeTree reportTree;
//=========================================================================
//ADMIN PORTAL FUNCTIONS
//=========================================================================
void processReport() 
{
    if (reportQueue.empty()) 
    {
        cout << "\nNo pending reports to process.\n";
        return;
    }
    Pothole p = reportQueue.front();
    reportQueue.pop();
    undoStack.push(p);
    cout << "\nAssigning repair team to pothole ID: " << p.id << ", Name: " << p.userFirstName << " " << p.userLastName<< " at " << p.location << ", Address: " << p.address << ", Problem: " << p.problemType << " [Severity " << p.severity << "]\n";
}

void completeRepair() 
{ 
    if (undoStack.empty())
    {
        cout << "\nNo pothole processed to complete!\n";
        return;
    }

    Pothole p = undoStack.top();
    undoStack.pop();
    p.status = "Completed"; 
    completedList.addCompleted(p);
    cout << "\nRepair completed and recorded for pothole ID: " << p.id << ", Name: " << p.userFirstName << " " << p.userLastName << ", Problem: " << p.problemType << ", Address: " << p.address << ", Status: " << p.status << '\n';
}
//=========================================================================
//ADMIN LOGIN AND MENU
//=========================================================================
void adminLogin() 
{
    string password;
    cout << "---------------------------------------------------------------------\n";
    cout << "Enter the Password - Claim Your Throne. Admins Only Beyond This Gate.\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "Enter admin password: ";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(password=="admin123")
    {
        while(true)
        {
            int choice;
            cout << "\nADMIN PORTAL\n";
            cout << "========================================\n";
            cout << "\n1. Assign Repair Teams\n2. Complete Last Assigned Repair - [When the task is complete mark it down]\n3. Show Completed Repairs\n4. Show Reports by Severity\n5. Search Reports\n6. Exit\n";
            cout << "========================================\n";
            cout << "\nChoice: ";

            if(!(cin>>choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(choice==1) processReport();
            else if(choice==2) completeRepair();
            else if(choice==3) completedList.display();
            else if(choice==4) reportTree.displayTraversals();
            else if(choice==5) searchReportsMenu();
            else if(choice==6) return;
            else cout << "Invalid choice\n";
        }
    } 
    else 
    {
        cout << "Access denied- Consider this a mercy, some doors aren't meant for you\n";
    }
}
//=========================================================================
int main() 
{
    //MAIN MENUE
    while(true)
    {
        int choice;
        cout << "\n           PUBLICPULSE SA \n\n POTHOLE TRACKING AND ROAD MAINTENANCE";
        cout << "\n========================================\n";
        cout << "\n1. User Portal\n2. Admin Portal\n3. Exit\n";
        cout << "========================================\n";
        cout << "Choice: ";
        if(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(choice==1) userMenu();
        else if(choice==2) adminLogin();
        else if(choice==3)
        {
            cout << "Thank you for using PUBLICPULSE SA- Because Waiting Forever Isn't a Maintenance Plan.\n";
            break;
        } 
        else cout << "Invalid choice.\n";
    }
    return 0;
}
